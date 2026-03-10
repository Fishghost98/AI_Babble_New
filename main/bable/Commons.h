//
// Created by 11609 on 25-12-23.
//

#ifndef COMMON_H
#define COMMON_H

#endif //COMMON_H

#include <stdbool.h>
#include <sys/unistd.h>
#include "nvs_flash.h"
#include "nvs.h"
#include "lvgl.h"
#include "esp_timer.h"

#define testBoard 1

#define power_ctrl GPIO_NUM_12
// NVS配置存储的命名空间
#define NVS_CONFIG_NAMESPACE "app_config"

#define pic_png 0
#define pic_bmp 1
#define pic_jpg 2
#define pic_gif 3

// 定义LVGL按键码（可自定义，也可用LVGL内置码）
#define LV_KEY_RETURN      LV_KEY_ESC  // 用ESC键代表返回（LVGL内置码）
// 全局输入组（需在工程初始化时创建，下面会说明）
extern lv_group_t *ui_input_group;
/********************* 音频录制相关定义 *********************/
// 录制状态枚举
typedef enum {
    RECORD_STATE_IDLE = 0,    // 空闲
    RECORD_STATE_RECORDING,   // 录制中
    RECORD_STATE_PAUSE,       // 暂停
    RECORD_STATE_FINISH       // 完成
} record_state_t;

// 录制配置
#define RECORD_SAMPLE_RATE    16000   // 采样率（与现有Audio_Driver保持一致）
#define RECORD_BITS_PER_SAMPLE 16     // 位深
#define RECORD_CHANNEL_NUM     1       // 单声道
#define AUDIO_GAIN_FACTOR 8  // 4倍增益，可修改为2、6、8等
#define RECORD_MAX_DURATION    60 * 60 * 2      // 最大录制时长（秒）
#define RECORD_FILE_DIR        "/sdcard/records/"  // 录制文件存储目录
#define RECORD_MIN_FREE_SPACE 1024*1024
// 关键：区分 C/C++ 编译器，C++ 下启用 extern "C"
#ifdef __cplusplus
extern "C" {
#endif
// 全局录制状态（供UI和录制任务通信）
extern record_state_t g_record_state;
extern uint32_t g_record_elapsed_time;  // 已录制时长（秒）
extern esp_timer_handle_t sleep_timer_handle;

// 函数声明
// ----------------音频录制相关---------------------
// 初始化WAV文件头
void commons_init_wav_header(uint8_t *wav_header, uint32_t total_samples);
// 生成带时间戳的录制文件名（如20240520_143025.wav）
char* commons_gen_record_filename(void);
// 检查SD卡剩余空间是否满足录制需求
bool check_sd_free_space();

// ----------------NVS相关---------------------
/**
 * @brief 初始化NVS存储
 * @return true-初始化成功，false-失败
 */
bool nvs_config_init(void);

/**
 * @brief 将all_config保存到NVS
 * @return true-保存成功，false-失败
 */
bool nvs_save_all_config(void);

/**
 * @brief 从NVS加载all_config
 * @return true-加载成功（或无数据使用默认值），false-加载失败
 */
bool nvs_load_all_config(void);

void gpio_init(void);

// 进入深度睡眠(延时)
void deep_sleep_gpio(uint64_t delay_ms);

// 深度睡眠，延时重启
void deep_sleep_rtc(uint64_t delay_ms);

uint32_t millis(void);

int read_key(void);
static void keypad_read_cb(lv_indev_data_t *data);
static void key_scan_task(void *arg);
void lv_keypad_init(void);
void lv_ui_group_init(void);

typedef struct{
    struct 
    {
        bool wifi_isConnected;        // 0：未连接  1：已连接

    }wifi_config;

    char pics_picture[100][300];// 读取到的SD卡内的图片信息[文件序号][文件名]
    uint16_t pic_picture_length;// 读取到的SD卡内的图片数量

    char pics_gif[100][300];    // 读取到的SD卡内的GIF信息[文件序号][文件名]
    uint16_t pic_gif_length;    // 读取到的SD卡内的GIF数量

    uint16_t clock_length;

    int mic_status;             // 0:会议录音 1：AI对话

    struct
    {
        /* data */
    }page_home;
    
    struct
    {
        int pic_main_index;     // 临时壁纸位标记
        int pic_display;        // 设置壁纸数组位
        int main_display_type;  // 显示壁纸类型：0-图片 1-GIF 2-时钟
    }page_main;
    
    struct
    {
        uint8_t battery;            // 电池电量
        uint8_t volume;             // 音量
        uint8_t backLight;          // 背光
    }page_quickConfig;

    struct
    {
        int pic_index;
        char pic_path_buf[356];
    }page_pic_display;

    struct
    {
        int gif_index;
        char gif_path_buf[356];
    }page_gif_display;

    struct
    {
        int clock_index;
    }page_clock_display;

    struct
    {
        char remind_time[50];
        char remind_date[50];
        char remind_message[50];
        bool remind_flag;
    }page_remindDetail;

    struct
    {
        int autoShutdownTime;
        uint32_t last_operation_time;
    }page_systemConfig;
}All_config;

typedef struct 
{
    int pic_display;                // 设置图片壁纸序号
    int gif_display;                // 设置GIF壁纸序号
    uint8_t clock_display;        // 设置时钟壁纸序号
    uint8_t main_display_type;      // 显示壁纸类型：0-图片 1-GIF 2-时钟
    uint8_t volume;                 // 音量
    uint8_t backLight;              // 背光
    int autoShutDownTime;           // 自动关机时间/分钟(0:从不)
}Save_config;


extern Save_config save_config;
extern All_config all_config;
#ifdef __cplusplus
} // 关闭 extern "C"
#endif