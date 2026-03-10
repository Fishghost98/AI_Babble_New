#include "Commons.h"
#include "PCF85063/pcf85063.h" // 引入RTC驱动，生成时间戳
#include "SD_Card/SD_MMC.h"    // 引入SD卡驱动，检查剩余空间
#include <string.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sleep.h"
#include "driver/gpio.h"
#include "driver/rtc_io.h"
#include "TCA9554PWR.h"
#define TAG "Commons"

// #define testBoard 1
// 配置唤醒引脚
#if testBoard
#define WAKEUP_GPIO_PIN GPIO_NUM_0
#else
#define WAKEUP_GPIO_PIN GPIO_NUM_1
#endif
// 唤醒触发方式：此处选择低电平触发（可修改为高电平/边沿触发）
#define WAKEUP_TRIGGER_LEVEL 0
lv_group_t *ui_input_group = NULL;
// 全局输入设备对象
static lv_indev_t *keypad_indev;
// 保存当前按键状态
static lv_indev_state_t keypad_state = LV_INDEV_STATE_REL;
static uint32_t last_key_code = 0;

// 全局变量
esp_timer_handle_t sleep_timer_handle = NULL; // 超时定时器句柄

Save_config save_config;

All_config all_config = {
    .wifi_config.wifi_isConnected = 1,
    .mic_status = 0,
    .page_main.pic_main_index = 0,
    .page_main.main_display_type = 0,
    .page_quickConfig.backLight = 80,
    .page_quickConfig.volume = 70,
    .page_quickConfig.battery = 80,
    .page_pic_display.pic_index = 0,
    .page_gif_display.gif_index = 0,
    .page_clock_display.clock_index = 0,
    .clock_length = 2,
    .page_systemConfig.autoShutdownTime = 0,
};

// 全局录制状态
record_state_t g_record_state = RECORD_STATE_IDLE;
uint32_t g_record_elapsed_time = 0;

/**
 * @brief 初始化WAV文件头
 * @param wav_header 存储WAV头的缓冲区
 * @param total_samples 总采样数
 */
void commons_init_wav_header(uint8_t *header, uint32_t total_samples)
{
    // WAV头格式：ChunkID, ChunkSize, Format, Subchunk1ID, Subchunk1Size, AudioFormat, NumChannels, SampleRate, ByteRate, BlockAlign, BitsPerSample, Subchunk2ID, Subchunk2Size
    uint32_t subchunk2_size = total_samples * RECORD_CHANNEL_NUM * (RECORD_BITS_PER_SAMPLE / 8);
    uint32_t chunk_size = 36 + subchunk2_size;

    // 填充WAV头
    memcpy(header, "RIFF", 4);
    memcpy(header + 4, &chunk_size, 4);
    memcpy(header + 8, "WAVE", 4);
    memcpy(header + 12, "fmt ", 4);
    uint32_t subchunk1_size = 16;
    memcpy(header + 16, &subchunk1_size, 4);
    uint16_t audio_format = 1; // PCM
    memcpy(header + 20, &audio_format, 2);
    uint16_t num_channels = RECORD_CHANNEL_NUM;
    memcpy(header + 22, &num_channels, 2);
    uint32_t sample_rate = RECORD_SAMPLE_RATE;
    memcpy(header + 24, &sample_rate, 4);
    uint32_t byte_rate = RECORD_SAMPLE_RATE * RECORD_CHANNEL_NUM * (RECORD_BITS_PER_SAMPLE / 8);
    memcpy(header + 28, &byte_rate, 4);
    uint16_t block_align = RECORD_CHANNEL_NUM * (RECORD_BITS_PER_SAMPLE / 8);
    memcpy(header + 32, &block_align, 2);
    uint16_t bits_per_sample = RECORD_BITS_PER_SAMPLE;
    memcpy(header + 34, &bits_per_sample, 2);
    memcpy(header + 36, "data", 4);
    memcpy(header + 40, &subchunk2_size, 4);
}

/**
 * @brief 生成带时间戳的录制文件名（如20240520_143025.wav）
 * @return 文件名缓冲区（静态变量，无需释放）
 */
char *commons_gen_record_filename(void)
{
    static char filename[64] = {0};
    // 从RTC获取当前时间（需确保PCF85063已初始化）
    datetime_t now = {0};
    PCF85063_Read_Time(&now);
    // 拼接文件名：目录+时间戳+后缀
    snprintf(filename, sizeof(filename), "%s%04d%02d%02d_%02d%02d%02d.wav",
             RECORD_FILE_DIR,
             now.year, now.month, now.day,
             now.hour, now.minute, now.second);
    return filename;
}

/**
 * @brief 检查SD卡剩余空间是否满足录制要求
 * @return true-有足够空间（大于最小阈值），false-空间不足/获取失败
 */
bool check_sd_free_space(void)
{
    FATFS *fs;                // 文件系统对象
    DWORD free_clusters;      // 空闲簇数
    uint64_t free_space_byte; // 剩余空间（字节）

    // 1. 获取SD卡文件系统信息（"0:" 对应SD_MMC的默认挂载点，需和项目实际挂载点一致）
    FRESULT res = f_getfree("0:", &free_clusters, &fs);
    if (res != FR_OK)
    {
        ESP_LOGE(TAG, "获取SD卡空间失败，错误码：%d", res);
        return false;
    }

    // 2. 计算剩余空间（字节）：空闲簇数 * 每簇扇区数 * 每扇区字节数
    // fs->csize: 每簇扇区数；fs->ssize: 每扇区512字节（SD卡默认）
    free_space_byte = (uint64_t)free_clusters * fs->csize * fs->ssize * 512;

    // 3. 打印调试信息（可选）
    // ESP_LOGI(TAG, "SD卡剩余空间：%llu KB（最小阈值：%d KB）", free_space_byte / 1024, RECORD_MIN_FREE_SPACE / 1024);

    // 4. 判断是否满足最小空间要求
    return (free_space_byte > RECORD_MIN_FREE_SPACE);
}

// 初始化NVS
bool nvs_config_init(void)
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        // NVS分区需要擦除，重新初始化
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "NVS初始化失败: %s", esp_err_to_name(err));
        return false;
    }
    return true;
}

// 保存all_config到NVS
bool nvs_save_all_config(void)
{
    nvs_handle_t nvs_handle;
    esp_err_t err;

    // 打开NVS命名空间
    err = nvs_open(NVS_CONFIG_NAMESPACE, NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "打开NVS失败: %s", esp_err_to_name(err));
        return false;
    }

    // 写入all_config结构体（以blob形式存储）
    err = nvs_set_blob(nvs_handle, "save_config", &save_config, sizeof(Save_config));
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "写入配置失败: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return false;
    }

    // 提交写入
    err = nvs_commit(nvs_handle);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "提交配置失败: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return false;
    }

    // 关闭NVS
    nvs_close(nvs_handle);
    ESP_LOGI(TAG, "配置已保存到NVS");
    return true;
}

// 从NVS加载all_config
bool nvs_load_all_config(void)
{
    nvs_handle_t nvs_handle;
    esp_err_t err;

    // 打开NVS命名空间
    err = nvs_open(NVS_CONFIG_NAMESPACE, NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "打开NVS失败: %s", esp_err_to_name(err));
        return false;
    }

    // 获取配置大小并读取
    size_t config_size = sizeof(Save_config);
    err = nvs_get_blob(nvs_handle, "save_config", &save_config, &config_size);
    if (err == ESP_ERR_NVS_NOT_FOUND)
    {
        // NVS中无配置，使用默认值
        ESP_LOGI(TAG, "NVS无配置，使用默认值");
        snprintf(all_config.page_pic_display.pic_path_buf, sizeof(all_config.page_pic_display.pic_path_buf),
                 "S:/pictures/%s",
                 all_config.pics_picture[0]);
        snprintf(all_config.page_gif_display.gif_path_buf, sizeof(all_config.page_gif_display.gif_path_buf),
                 "S:/gifs/%s",
                 all_config.pics_gif[0]);
        all_config.page_quickConfig.backLight = 80;
        all_config.page_quickConfig.volume = 70;
        nvs_close(nvs_handle);
        return false;
    }
    else if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "读取配置失败: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return false;
    }

    all_config.page_quickConfig.backLight = save_config.backLight;
    all_config.page_quickConfig.volume = save_config.volume;
    if(save_config.main_display_type > 2 || save_config.main_display_type < 0){
        save_config.main_display_type = all_config.page_main.main_display_type = 0;
    }else{
        all_config.page_main.main_display_type = save_config.main_display_type;
    }
    
    // all_config.page_main.pic_display = save_config.pic_display;
    // all_config.page_main.pic_main_index = all_config.page_main.pic_display;
    all_config.page_gif_display.gif_index = save_config.gif_display;
    all_config.page_pic_display.pic_index = save_config.pic_display;
    all_config.page_clock_display.clock_index = save_config.clock_display;
    all_config.page_systemConfig.autoShutdownTime = save_config.autoShutDownTime;
    ESP_LOGI(TAG, "pic_display:%d, gif_display:%d", save_config.pic_display, save_config.gif_display);
    ESP_LOGI(TAG, "pic_path_buf:%s, gif_path_buf:%s", all_config.pics_picture[save_config.pic_display], all_config.pics_gif[save_config.gif_display]);
    snprintf(all_config.page_pic_display.pic_path_buf, sizeof(all_config.page_pic_display.pic_path_buf),
             "S:/pictures/%s",
             all_config.pics_picture[save_config.pic_display]);
    snprintf(all_config.page_gif_display.gif_path_buf, sizeof(all_config.page_gif_display.gif_path_buf),
             "S:/gifs/%s",
             all_config.pics_gif[save_config.gif_display]);
    // 关闭NVS
    nvs_close(nvs_handle);
    ESP_LOGI(TAG, "配置已从NVS加载");
    return true;
}

void gpio_init(void)
{
    // 配置 GPIO 0 为输入模式，启用上拉电阻
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << WAKEUP_GPIO_PIN), // GPIO 0
        .mode = GPIO_MODE_INPUT,                   // 输入模式
        .pull_up_en = GPIO_PULLUP_ENABLE,          // 使能上拉电阻
        .pull_down_en = GPIO_PULLDOWN_DISABLE,     // 禁用下拉电阻
        .intr_type = GPIO_INTR_DISABLE,            // 禁用中断
    };
    gpio_config(&io_conf);

    gpio_config_t io_conf2 = {
        .pin_bit_mask = (1ULL << power_ctrl),  // 选择要配置的引脚
        .mode = GPIO_MODE_OUTPUT,             // 设置为输出模式
        .pull_up_en = GPIO_PULLUP_ENABLE,     // 使能上拉电阻（可选，根据需求）
        .pull_down_en = GPIO_PULLDOWN_DISABLE,// 禁用下拉电阻
        .intr_type = GPIO_INTR_DISABLE,        // 禁用中断（输出模式无需中断）
    };

    // 应用 GPIO 配置
    gpio_config(&io_conf2);

    // 2. 将引脚拉高（输出高电平）
    gpio_set_level(power_ctrl, 1);  // 第二个参数 1 = 高电平，0 = 低电平
}

// 深度睡眠，GPIO唤醒
void deep_sleep_gpio(uint64_t delay_ms)
{
    // 配置 EXT0 唤醒（GPIO 0 高电平触发）
    esp_err_t ret = esp_sleep_enable_ext0_wakeup(WAKEUP_GPIO_PIN, WAKEUP_TRIGGER_LEVEL);
    if (ret != ESP_OK)
    {
        printf("GPIO唤醒配置失败，错误码：%d\n", ret);
        return;
    }

    printf("即将进入深度休眠，等待GPIO%d低电平唤醒...\n", WAKEUP_GPIO_PIN);
    // 延时2秒，确保日志打印完成（避免休眠过快导致日志丢失）
    vTaskDelay(pdMS_TO_TICKS(delay_ms));

    // 启动深度休眠（调用后芯片立即进入低功耗状态，直到被唤醒）
    printf("进入深度休眠...\n");
    esp_deep_sleep_start();
}

// 深度睡眠，延时重启
void deep_sleep_rtc(uint64_t delay_ms)
{
    vTaskDelay(pdMS_TO_TICKS(2000));
    printf("进入深度休眠，%lld毫秒后唤醒\n", delay_ms);
    esp_sleep_enable_timer_wakeup(delay_ms * 1000);
    esp_deep_sleep_start();
}

uint32_t millis(void)
{
    // 获取系统启动以来的微秒数，转换为毫秒
    return (uint32_t)(esp_timer_get_time() / 1000);
}

int read_key(void)
{
        int key_id = -1;
    // 按键1：GPIO0，低电平有效
    if (gpio_get_level(WAKEUP_GPIO_PIN) == 0) {
        vTaskDelay(pdMS_TO_TICKS(10)); // 防抖
        if (gpio_get_level(WAKEUP_GPIO_PIN) == 0) {
            key_id = LV_KEY_ESC; // 按键ID为1
        }
    }
    // 按键2：GPIO1，低电平有效
    // else if (gpio_get_level(GPIO_NUM_1) == 0) {
    //     vTaskDelay(pdMS_TO_TICKS(10));
    //     if (gpio_get_level(GPIO_NUM_1) == 0) {
    //         key_id = 2; // 按键ID为2
    //     }
    // }
    return key_id; // 无按键返回-1
}

/**
 * @brief LVGL按键读取回调函数（核心接口）
 * LVGL会周期性调用此函数获取按键状态
 */
static void keypad_read_cb(lv_indev_data_t *data)
{
    static uint32_t last_btn = 0; // 初始化为无按键值
    int btn_pr = read_key();

    if (btn_pr >= 0)
    { // 有按键按下
        last_btn = btn_pr;
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {                           // 无按键按下/释放
        last_btn = 0; // ❶ 重置为无按键值
        data->state = LV_INDEV_STATE_RELEASED;
    }

    data->key = last_btn;
    // ❷ 仅在有按键时打印日志（可选，避免无意义输出）
    if (last_btn != 0)
    {
        // ESP_LOGI(TAG, "Key pressed: %d", data->key);
    }
}

/**
 * @brief 按键扫描任务（检测按键状态并更新给LVGL）
 */
static void key_scan_task(void *arg)
{
    static bool last_key_level = 1;
    static TickType_t last_press_tick = 0;

    while (1)
    {
        // 读取当前按键电平
        bool curr_key_level = gpio_get_level(WAKEUP_GPIO_PIN);

        // 消抖处理（20ms）
        if (curr_key_level != last_key_level &&
            (xTaskGetTickCount() - last_press_tick) > pdMS_TO_TICKS(20))
        {

            last_press_tick = xTaskGetTickCount();
            last_key_level = curr_key_level;

            // 按键按下
            if (curr_key_level == WAKEUP_TRIGGER_LEVEL)
            {
                keypad_state = LV_INDEV_STATE_PR; // 设置为按下状态
                last_key_code = LV_KEY_RETURN;    // 标记为返回键
            }
        }

        vTaskDelay(pdMS_TO_TICKS(10)); // 10ms扫描一次
    }
}

/**
 * @brief 注册LVGL按键输入设备
 */
void lv_keypad_init(void)
{
    // 1. 初始化按键硬件
    gpio_init();

    // 2. 注册按键输入设备驱动
    static lv_indev_drv_t keypad_drv;
    lv_indev_drv_init(&keypad_drv);
    keypad_drv.type = LV_INDEV_TYPE_KEYPAD; // 类型：键盘/按键
    keypad_drv.read_cb = keypad_read_cb;    // 设置读取回调
    keypad_indev = lv_indev_drv_register(&keypad_drv);
    if (keypad_indev == NULL)
    {
        ESP_LOGE("LVGL", "Key1 indev is NULL!");
    }
    // 3. 创建按键扫描任务
    // xTaskCreate(key_scan_task, "key_scan", 4096, NULL, 10, NULL);
}

/**
 * @brief 初始化输入组（LVGL 8.3.10焦点管理核心，需在工程初始化时调用一次）
 * 建议放在lv_init()之后，UI初始化之前
 */
void lv_ui_group_init(void)
{
    // 创建全局输入组（LVGL 8.x必须通过组管理焦点）
    ui_input_group = lv_group_create();
    lv_group_set_default(ui_input_group);
    if (keypad_indev == NULL)
    {
        ESP_LOGE("LVGL", "Key indev is NULL!");
        lv_group_del(ui_input_group); // 释放已创建的group，避免内存泄漏
        return;
    }
    // 将输入组绑定到当前活动的输入设备（按键/编码器等）
    lv_indev_set_group(keypad_indev, ui_input_group);
    // lv_group_focus_obj(ui_input_group);          //分组聚焦到对象
    lv_group_set_editing(ui_input_group, true); // 编辑模式
}