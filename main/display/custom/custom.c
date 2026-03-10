/*
 * Copyright 2023 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "lvgl.h"
#include "custom.h"
#include "Commons.h"
#include "PCF85063.h"
/*********************
 *      DEFINES
 *********************/
lv_timer_t *lvgl_loop_handle;
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    lvgl_loop_handle = lv_timer_create(lvgl_loop, 1000, NULL);
    lv_timer_create(getWeather, 10000, NULL);
}

void lvgl_loop(lv_timer_t *timer)
{
    // 更新电量显示
    static char battery_buf[20] = {0};
    snprintf(battery_buf, sizeof(battery_buf),
             "%d%%",
             all_config.page_quickConfig.battery);
    // ESP_LOGI("screen_quick_config", "battery:%d", all_config.page_quickConfig.battery);
    if (lv_obj_is_valid(guider_ui.screen_meetingDetail_bar_battery) && lv_obj_is_valid(guider_ui.screen_meetingDetail_label_battery))
    {
        lv_bar_set_value(guider_ui.screen_meetingDetail_bar_battery, all_config.page_quickConfig.battery, LV_ANIM_OFF);
        lv_label_set_text(guider_ui.screen_meetingDetail_label_battery, battery_buf);
    }
    if (lv_obj_is_valid(guider_ui.screen_quick_config_bar_battery) && lv_obj_is_valid(guider_ui.screen_quick_config_label_battery))
    {
        lv_bar_set_value(guider_ui.screen_quick_config_bar_battery, all_config.page_quickConfig.battery, LV_ANIM_OFF);
        lv_label_set_text(guider_ui.screen_quick_config_label_battery, battery_buf);
    }
    if (lv_obj_is_valid(guider_ui.home_analog_battery_arc) && lv_obj_is_valid(guider_ui.home_analog_battery_text))
    {
        lv_arc_set_value(guider_ui.home_analog_battery_arc, all_config.page_quickConfig.battery);
        lv_label_set_text(guider_ui.home_analog_battery_text, battery_buf);
    }
    if (lv_obj_is_valid(guider_ui.home_digital_arc_flash) && lv_obj_is_valid(guider_ui.home_digital_label_flashText))
    {
        lv_arc_set_value(guider_ui.home_digital_arc_flash, all_config.page_quickConfig.battery);
        lv_label_set_text(guider_ui.home_digital_label_flashText, battery_buf);
    }

    // 自动关机
    if (save_config.autoShutDownTime > 0)
    {
        uint32_t nowTime = millis();
        if (nowTime - all_config.page_systemConfig.last_operation_time > save_config.autoShutDownTime * 60 * 1000)
        {
            ESP_LOGI("lvgl_loop", "自动关机");
            deep_sleep_gpio(2000);
        }
    }

    // 时钟更新
    if (lv_obj_is_valid(guider_ui.home_analog_analog_clock_1))
    {
        // 定义转换后的12小时制小时数
        uint8_t hour_12 = 0;
        if (datetime.hour == 0)
        {
            hour_12 = 12; // 0点→12点
        }
        else if (datetime.hour > 12)
        {
            hour_12 = datetime.hour - 12; // 24小时制→12小时制
        }
        else
        {
            hour_12 = datetime.hour; // 1~12点直接使用
        }
        // lv_analogclock_set_time(guider_ui.home_analog_analog_clock_1, hour_12, datetime.minute, datetime.second);
        // ESP_LOGI("lvgl_loop", "当前时间：%d:%d:%d", datetime.hour, datetime.minute, datetime.second);
    }

    if (lv_obj_is_valid(guider_ui.home_digital_label_hour))
    {
        char digital_hour[5] = {0};
        char digital_minute[5] = {0};
        sprintf(digital_hour, "%02d", datetime.hour);
        sprintf(digital_minute, "%02d", datetime.minute);
        lv_label_set_text(guider_ui.home_digital_label_hour, digital_hour);
        lv_label_set_text(guider_ui.home_digital_label_min, digital_minute);
        // ESP_LOGI("lvgl_loop", "当前时间：%d:%d:%d", datetime.hour, datetime.minute, datetime.second);
    }

    if (lv_obj_is_valid(guider_ui.screen_home_label_1) && lv_obj_is_valid(guider_ui.screen_home_label_2))
    {
        char nowTime[20] = {0};
        sprintf(nowTime, "%02d:%02d", datetime.hour, datetime.minute);
        lv_label_set_text(guider_ui.screen_home_label_1, nowTime);
        char date[100] = {0};
        sprintf(date, "%d年%d月%d日 %s", datetime.year, datetime.month, datetime.day, datetime.week_day);
        lv_label_set_text(guider_ui.screen_home_label_2, date);
    }
}

/**
 * @brief  显示后动态缩放（备选方案）
 * @param  img_obj: 图片对象
 * @param  scale_x: x轴缩放比例（如2表示放大2倍，0.5表示缩小到一半）
 * @param  scale_y: y轴缩放比例
 */
void lv_img_dynamic_scale(lv_obj_t *img_obj, float scale_x, float scale_y)
{
}
