#include "Commons.h"
#include <stdio.h>
#include <string.h>
#include "driver/gpio.h"
#include "driver/rtc_io.h"
#include "esp_log.h"
#include <errno.h>
#include "dirent.h"
#include "esp_sleep.h"
#include "esp_flash.h" 
#include "sdmmc_cmd.h"
#include "driver/sdmmc_host.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define TAG "Commons"

uint32_t Flash_Size = 0;
uint32_t SDCard_Size = 0;

// #define testBoard 1
// 配置唤醒引脚
#if testBoard
#define WAKEUP_GPIO_PIN GPIO_NUM_0
#else
#define WAKEUP_GPIO_PIN GPIO_NUM_1
#endif
// 唤醒触发方式：此处选择低电平触发（可修改为高电平/边沿触发）
#define WAKEUP_TRIGGER_LEVEL 0

// 全局变量
esp_timer_handle_t sleep_timer_handle = NULL;  // 超时定时器句柄

Save_config save_config;

All_config all_config = {
    .wifi_config = {.wifi_isConnected = 1},
    .mic_status = 0,
    .page_main = {.pic_main_index = 0, .main_display_type = 0},
    .page_quickConfig = {.backLight = 80},
    .page_pic_display = {.pic_index = 0},
    .page_gif_display = {.gif_index = 0},
    .page_clock_display = {.clock_index = 0},
    .page_systemConfig = {.autoShutdownTime = 0},
};

// 初始化NVS
bool nvs_config_init(void) {
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS分区需要擦除，重新初始化
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "NVS初始化失败: %s", esp_err_to_name(err));
        return false;
    }
    return true;
}

// 保存all_config到NVS
bool nvs_save_all_config(void) {
    nvs_handle_t nvs_handle;
    esp_err_t err;

    // 打开NVS命名空间
    err = nvs_open(NVS_CONFIG_NAMESPACE, NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "打开NVS失败: %s", esp_err_to_name(err));
        return false;
    }

    // 写入all_config结构体（以blob形式存储）
    err = nvs_set_blob(nvs_handle, "save_config", &save_config, sizeof(Save_config));
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "写入配置失败: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return false;
    }

    // 提交写入
    err = nvs_commit(nvs_handle);
    if (err != ESP_OK) {
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
bool nvs_load_all_config(void) {
    nvs_handle_t nvs_handle;
    esp_err_t err;

    // 打开NVS命名空间
    err = nvs_open(NVS_CONFIG_NAMESPACE, NVS_READWRITE, &nvs_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "打开NVS失败: %s", esp_err_to_name(err));
        return false;
    }

    // 获取配置大小并读取
    size_t config_size = sizeof(Save_config);
    err = nvs_get_blob(nvs_handle, "save_config", &save_config, &config_size);
    if (err == ESP_ERR_NVS_NOT_FOUND) {
        // NVS中无配置，使用默认值
        ESP_LOGI(TAG, "NVS无配置，使用默认值");
        snprintf(all_config.page_pic_display.pic_path_buf,
                 sizeof(all_config.page_pic_display.pic_path_buf), "S:/pictures/%s",
                 all_config.pics_picture[0]);
        snprintf(all_config.page_gif_display.gif_path_buf,
                 sizeof(all_config.page_gif_display.gif_path_buf), "S:/gifs/%s",
                 all_config.pics_gif[0]);
        all_config.page_quickConfig.backLight = 80;
        all_config.page_quickConfig.volume = 70;
        nvs_close(nvs_handle);
        return false;
    } else if (err != ESP_OK) {
        ESP_LOGE(TAG, "读取配置失败: %s", esp_err_to_name(err));
        nvs_close(nvs_handle);
        return false;
    }

    all_config.page_quickConfig.backLight = save_config.backLight;
    all_config.page_quickConfig.volume = save_config.volume;
    if (save_config.main_display_type > 2 || save_config.main_display_type < 0) {
        save_config.main_display_type = all_config.page_main.main_display_type = 0;
    } else {
        all_config.page_main.main_display_type = save_config.main_display_type;
    }

    // all_config.page_main.pic_display = save_config.pic_display;
    // all_config.page_main.pic_main_index = all_config.page_main.pic_display;
    all_config.page_gif_display.gif_index = save_config.gif_display;
    all_config.page_pic_display.pic_index = save_config.pic_display;
    all_config.page_clock_display.clock_index = save_config.clock_display;
    all_config.page_systemConfig.autoShutdownTime = save_config.autoShutDownTime;
    ESP_LOGI(TAG, "pic_display:%d, gif_display:%d", save_config.pic_display,
             save_config.gif_display);
    ESP_LOGI(TAG, "pic_path_buf:%s, gif_path_buf:%s",
             all_config.pics_picture[save_config.pic_display],
             all_config.pics_gif[save_config.gif_display]);
    snprintf(all_config.page_pic_display.pic_path_buf,
             sizeof(all_config.page_pic_display.pic_path_buf), "S:/pictures/%s",
             all_config.pics_picture[save_config.pic_display]);
    snprintf(all_config.page_gif_display.gif_path_buf,
             sizeof(all_config.page_gif_display.gif_path_buf), "S:/gifs/%s",
             all_config.pics_gif[save_config.gif_display]);
    // 关闭NVS
    nvs_close(nvs_handle);
    ESP_LOGI(TAG, "配置已从NVS加载");
    return true;
}

void gpio_init(void) {
    // 配置 GPIO 0 为输入模式，启用上拉电阻
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << WAKEUP_GPIO_PIN),  // GPIO 0
        .mode = GPIO_MODE_INPUT,                    // 输入模式
        .pull_up_en = GPIO_PULLUP_ENABLE,           // 使能上拉电阻
        .pull_down_en = GPIO_PULLDOWN_DISABLE,      // 禁用下拉电阻
        .intr_type = GPIO_INTR_DISABLE,             // 禁用中断
    };
    gpio_config(&io_conf);

    gpio_config_t io_conf2 = {
        .pin_bit_mask = (1ULL << power_ctrl),   // 选择要配置的引脚
        .mode = GPIO_MODE_OUTPUT,               // 设置为输出模式
        .pull_up_en = GPIO_PULLUP_ENABLE,       // 使能上拉电阻（可选，根据需求）
        .pull_down_en = GPIO_PULLDOWN_DISABLE,  // 禁用下拉电阻
        .intr_type = GPIO_INTR_DISABLE,         // 禁用中断（输出模式无需中断）
    };

    // 应用 GPIO 配置
    gpio_config(&io_conf2);

    // 2. 将引脚拉高（输出高电平）
    gpio_set_level(power_ctrl, 1);  // 第二个参数 1 = 高电平，0 = 低电平
}

// 深度睡眠，GPIO唤醒
void deep_sleep_gpio(uint64_t delay_ms) {
    // 配置 EXT0 唤醒（GPIO 0 高电平触发）
    esp_err_t ret = esp_sleep_enable_ext0_wakeup(WAKEUP_GPIO_PIN, WAKEUP_TRIGGER_LEVEL);
    if (ret != ESP_OK) {
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
void deep_sleep_rtc(uint64_t delay_ms) {
    vTaskDelay(pdMS_TO_TICKS(2000));
    printf("进入深度休眠，%lld毫秒后唤醒\n", delay_ms);
    esp_sleep_enable_timer_wakeup(delay_ms * 1000);
    esp_deep_sleep_start();
}

uint32_t millis(void) {
    // 获取系统启动以来的微秒数，转换为毫秒
    return (uint32_t)(esp_timer_get_time() / 1000);
}

void Flash_Searching(void)
{
    if (esp_flash_get_physical_size(NULL, &Flash_Size) == ESP_OK)
    {
        Flash_Size = Flash_Size / (uint32_t)(1024 * 1024);
        printf("Flash size: %ld MB\n", Flash_Size);
    }
    else
    {
        printf("Get flash size failed\n");
    }
}

#define MAX_PATH_SIZE 512 
// 读取SD卡中指定路径下指定类型文件
int Read_GIF(const char *directory, char File_Name[][MAX_FILE_NAME_SIZE], int maxFiles)
{
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        ESP_LOGE("SD_MMC", "Path: <%s> does not exist", directory);
        ESP_LOGE("SD_MMC", "opendir failed: errno=%d, 0x%x", errno, esp_err_to_name(errno));
        return 0;
    }

    uint16_t fileCount = 0;
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL && fileCount < maxFiles)
    {

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        const char *dot = strrchr(entry->d_name, '.');
        if (dot != NULL && dot != entry->d_name)
        {

            if (strcasecmp(dot, ".gif") == 0)
            {
                strncpy(File_Name[fileCount], entry->d_name, MAX_FILE_NAME_SIZE - 1);
                File_Name[fileCount][MAX_FILE_NAME_SIZE - 1] = '\0';

                char filePath[MAX_PATH_SIZE];
                snprintf(filePath, MAX_PATH_SIZE, "%s%s", directory, entry->d_name);

                printf("File found: %s\r\n", filePath);
                fileCount++;
            }
        }
        else
        {

            // printf("No extension found for file: %s\r\n", entry->d_name);
        }
    }

    closedir(dir);

    if (fileCount > 0)
    {
        ESP_LOGI("SD_MMC", "Retrieved %d GIFs", fileCount);
    }
    else
    {
        ESP_LOGW("SD_MMC", "No gif found in directory: %s", directory);
    }

    return fileCount;
}

int Read_Picture(const char *directory, char File_Name[][MAX_FILE_NAME_SIZE], int maxFiles)
{
    DIR *dir = opendir(directory);
    if (dir == NULL)
    {
        ESP_LOGE("SD_MMC", "Path: <%s> does not exist", directory);
        return 0;
    }

    uint16_t fileCount = 0;
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL && fileCount < maxFiles)
    {

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        const char *dot = strrchr(entry->d_name, '.');
        if (dot != NULL && dot != entry->d_name)
        {

            if (strcasecmp(dot, ".png") == 0 || strcasecmp(dot, ".bmp") == 0 || strcasecmp(dot, ".jpg") == 0)
            {
                strncpy(File_Name[fileCount], entry->d_name, MAX_FILE_NAME_SIZE - 1);
                File_Name[fileCount][MAX_FILE_NAME_SIZE - 1] = '\0';

                char filePath[MAX_PATH_SIZE];
                snprintf(filePath, MAX_PATH_SIZE, "%s%s", directory, entry->d_name);

                printf("File found: %s\r\n", filePath);
                fileCount++;
            }
        }
        else
        {
            // printf("No extension found for file: %s\r\n", entry->d_name);
        }
    }

    closedir(dir);

    if (fileCount > 0)
    {
        ESP_LOGI("SD_MMC", "Retrieved %d pictures", fileCount);
    }
    else
    {
        ESP_LOGW("SD_MMC", "No picture found in directory: %s", directory);
    }

    return fileCount;
}
