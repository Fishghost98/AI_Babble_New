/*
 * Copyright 2025 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "events_init.h"
#include "widgets_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

// #include "LVGL_Driver.h"
// #include "PCM5101.h"
#include "Audio_Record.h"
#include "Commons.h"

lv_timer_t *dclock_handle;

void LVGL_volume_adjustment(uint8_t Volume)
{
    // Volume_adjustment(Volume);
}
void LVGL_Backlight_adjustment(uint8_t Backlight)
{
    // Set_Backlight(Backlight);
}

static void screen_main_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_LONG_PRESSED:
    {
        // ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_main_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config, guider_ui.screen_quick_config_del, &guider_ui.screen_main_del, setup_scr_screen_quick_config, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_main_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // 边界检查：无图片时直接返回
            if (all_config.pic_picture_length <= 0)
            {
                ESP_LOGW("event", "No pictures to display");
                break;
            }

            // 安全更新索引（避免负数）
            all_config.page_main.pic_main_index--;
            if (all_config.page_main.pic_main_index < 0)
            {
                all_config.page_main.pic_main_index = all_config.pic_picture_length - 1;
            }
            int pic_index = all_config.page_main.pic_main_index;

            static char g_pic_path_buf[356] = {0};
            snprintf(g_pic_path_buf, sizeof(g_pic_path_buf),
                     "S:/pictures/%s",
                     all_config.pics_picture[pic_index]);
            lv_img_set_src(guider_ui.screen_main_img_index, g_pic_path_buf);
            lv_obj_align(guider_ui.screen_main_img_index, LV_ALIGN_CENTER, 0, 0);
            ESP_LOGI("events_init", "Display picture: %s; pic_index: %d", g_pic_path_buf, pic_index);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // 边界检查：无图片时直接返回
            if (all_config.pic_picture_length <= 0)
            {
                ESP_LOGW("event", "No pictures to display");
                break;
            }

            // 安全更新索引（避免负数）
            all_config.page_main.pic_main_index =
                (all_config.page_main.pic_main_index + 1) % all_config.pic_picture_length;
            int pic_index = all_config.page_main.pic_main_index;

            static char g_pic_path_buf[356] = {0};
            snprintf(g_pic_path_buf, sizeof(g_pic_path_buf),
                     "S:/pictures/%s",
                     all_config.pics_picture[pic_index]);

            lv_img_set_src(guider_ui.screen_main_img_index, g_pic_path_buf);
            lv_obj_align(guider_ui.screen_main_img_index, LV_ALIGN_CENTER, 0, 0);
            ESP_LOGI("events_init", "Display picture: %s; pic_index: %d", g_pic_path_buf, pic_index);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_main_img_index_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_LONG_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_main_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_main(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_main, screen_main_event_handler, LV_EVENT_GESTURE, ui);
    // lv_obj_add_event_cb(ui->screen_main_img_index, screen_main_img_index_event_handler, LV_EVENT_ALL, ui);
}

static void screen_main_gif_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_LONG_PRESSED:
    {
        // ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_main_gif_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // 边界检查：无图片时直接返回
            if (all_config.pic_gif_length <= 0)
            {
                ESP_LOGW("event", "No gifs to display");
                break;
            }

            // 安全更新索引（避免负数）
            all_config.page_main.pic_main_index--;
            if (all_config.page_main.pic_main_index < 0)
            {
                all_config.page_main.pic_main_index = all_config.pic_gif_length - 1;
            }
            int pic_index = all_config.page_main.pic_main_index;

            static char g_pic_path_buf[356] = {0};
            snprintf(g_pic_path_buf, sizeof(g_pic_path_buf),
                     "S:/gifs/%s",
                     all_config.pics_gif[pic_index]);

            // ===== 新增：LVGL 文件操作排查 =====
            lv_fs_file_t file;
            lv_fs_res_t res = lv_fs_open(&file, g_pic_path_buf, LV_FS_MODE_RD);
            if (res != LV_FS_RES_OK)
            {
                ESP_LOGE("LVGL_FS", "LVGL 打开文件失败！路径：%s，错误码：%d", g_pic_path_buf, res);
                // 错误码含义：LV_FS_RES_NOT_EXIST=2（路径/文件不存在）、LV_FS_RES_INV_PATH=3（路径格式错误）等
                break;
            }
            ESP_LOGI("LVGL_FS", "LVGL 成功打开文件：%s", g_pic_path_buf);
            lv_fs_close(&file);

            lv_gif_set_src(guider_ui.screen_main_gif_gif_index, g_pic_path_buf);
            lv_obj_align(guider_ui.screen_main_gif_gif_index, LV_ALIGN_CENTER, 0, 0);
            ESP_LOGI("screen_main_gif", "Display gif: %s; pic_index: %d", g_pic_path_buf, pic_index);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // 边界检查：无图片时直接返回
            if (all_config.pic_gif_length <= 0)
            {
                ESP_LOGW("event", "No gifs to display");
                break;
            }

            // 安全更新索引（避免负数）
            all_config.page_main.pic_main_index =
                (all_config.page_main.pic_main_index + 1) % all_config.pic_gif_length;
            int pic_index = all_config.page_main.pic_main_index;

            static char g_pic_path_buf[356] = {0};
            snprintf(g_pic_path_buf, sizeof(g_pic_path_buf),
                     "S:/gifs/%s",
                     all_config.pics_gif[pic_index]);

            // ===== 新增：LVGL 文件操作排查 =====
            lv_fs_file_t file;
            lv_fs_res_t res = lv_fs_open(&file, g_pic_path_buf, LV_FS_MODE_RD);
            if (res != LV_FS_RES_OK)
            {
                ESP_LOGE("LVGL_FS", "LVGL 打开文件失败！路径：%s，错误码：%d", g_pic_path_buf, res);
                // 错误码含义：LV_FS_RES_NOT_EXIST=2（路径/文件不存在）、LV_FS_RES_INV_PATH=3（路径格式错误）等
                break;
            }
            ESP_LOGI("LVGL_FS", "LVGL 成功打开文件：%s", g_pic_path_buf);
            lv_fs_close(&file);

            lv_gif_set_src(guider_ui.screen_main_gif_gif_index, g_pic_path_buf);
            lv_obj_align(guider_ui.screen_main_gif_gif_index, LV_ALIGN_CENTER, 0, 0);
            ESP_LOGI("screen_main_gif", "Display gif: %s; pic_index: %d", g_pic_path_buf, pic_index);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config, guider_ui.screen_quick_config_del, &guider_ui.screen_main_gif_del, setup_scr_screen_quick_config, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_main_gif_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_main_gif(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_main_gif, screen_main_gif_event_handler, LV_EVENT_ALL, ui);
}

static void screen_quick_config_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            if (save_config.main_display_type == 0)
            {
                all_config.page_pic_display.pic_index = save_config.pic_display;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_quick_config_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 1)
            {
                all_config.page_gif_display.gif_index = save_config.gif_display;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del, &guider_ui.screen_quick_config_del, setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 2)
            {
                switch (save_config.clock_display)
                {
                case 0:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_mainConfig_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 1:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_mainConfig_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 2:
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                default:
                    break;
                }
            }
        }
        break;
    }

    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            if (all_config.page_main.main_display_type == 0)
            {
                all_config.page_pic_display.pic_index = save_config.pic_display;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_quick_config_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
            }
            else if (all_config.page_main.main_display_type == 1)
            {
                all_config.page_gif_display.gif_index = save_config.gif_display;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del, &guider_ui.screen_quick_config_del, setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
            }
            else if (all_config.page_main.main_display_type == 2)
            {
                switch (save_config.clock_display)
                {
                case 0:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_mainConfig_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 1:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_mainConfig_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 2:
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                default:
                    break;
                }
            }
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_quick_config_slider_volume_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
    {
        uint8_t Volume = lv_slider_get_value(lv_event_get_target(e));
        if (Volume <= Volume_MAX)
        {
            lv_slider_set_value(guider_ui.screen_quick_config_slider_volume, Volume, LV_ANIM_ON);
            LVGL_volume_adjustment(Volume);
            save_config.volume = all_config.page_quickConfig.volume = Volume;
            nvs_save_all_config();
            printf("Volume:%d\r\n", Volume);
        }
        else
            printf("Volume out of range: %d\n", Volume);
        break;
    }
    default:
        break;
    }
}

static void screen_quick_config_slider_backLight_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
    {
        uint8_t Backlight = lv_slider_get_value(lv_event_get_target(e));
        if (Backlight <= Backlight_MAX)
        {
            lv_slider_set_value(guider_ui.screen_quick_config_slider_backLight, Backlight, LV_ANIM_ON);
            LCD_Backlight = Backlight;
            save_config.backLight = all_config.page_quickConfig.backLight = Backlight;
            LVGL_Backlight_adjustment(Backlight);
            nvs_save_all_config();
            printf("Backlight value: %d\n", all_config.page_quickConfig.backLight);
        }
        else
            printf("Backlight out of range: %d\n", Backlight);
        break;
    }
    default:
        break;
    }
}

static void screen_quick_config_btn_power_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_shutDown, guider_ui.screen_shutDown_del, &guider_ui.screen_quick_config_del, setup_scr_screen_shutDown, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_quick_config(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_quick_config, screen_quick_config_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_quick_config_slider_volume, screen_quick_config_slider_volume_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_quick_config_slider_backLight, screen_quick_config_slider_backLight_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_quick_config_btn_power, screen_quick_config_btn_power_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_quick_config);
        lv_group_focus_obj(ui->screen_quick_config);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_shutDown_slider_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
    {
        
        uint8_t shutDownValue = lv_slider_get_value(lv_event_get_target(e));
        // lv_obj_set_x(guider_ui.screen_shutDown_img_1, shutDownValue);
        if (shutDownValue == 100)
        {
            deep_sleep_gpio(2000);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_shutDown_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config, guider_ui.screen_quick_config_del, &guider_ui.screen_shutDown_del, setup_scr_screen_quick_config, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_shutDown(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_shutDown_slider_1, screen_shutDown_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_shutDown_btn_1, screen_shutDown_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_mainConfig_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            if (save_config.main_display_type == 0)
            {
                all_config.page_main.pic_main_index = all_config.page_pic_display.pic_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 1)
            {
                all_config.page_main.pic_main_index = all_config.page_gif_display.gif_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 2)
            {
                switch (save_config.clock_display)
                {
                case 0:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_mainConfig_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 1:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_mainConfig_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 2:
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                default:
                    break;
                }
            }
        }
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture, guider_ui.screen_picture_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_picture, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chat, guider_ui.screen_chat_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_chat, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);

            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig, guider_ui.screen_systemConfig_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_systemConfig, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);

            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            if (all_config.page_main.main_display_type == 0)
            {
                all_config.page_main.pic_main_index = all_config.page_pic_display.pic_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (all_config.page_main.main_display_type == 1)
            {
                all_config.page_main.pic_main_index = all_config.page_gif_display.gif_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (all_config.page_main.main_display_type == 2)
            {
                switch (all_config.page_clock_display.clock_index)
                {
                case 0:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_mainConfig_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 1:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_mainConfig_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 2:
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                default:
                    break;
                }
            }
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_mainConfig_img_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture, guider_ui.screen_picture_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_picture, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_mainConfig(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_mainConfig, screen_mainConfig_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_mainConfig_img_1, screen_mainConfig_img_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_mainConfig);
        lv_group_focus_obj(ui->screen_mainConfig);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_picture_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_picture_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture_display, guider_ui.screen_picture_display_del, &guider_ui.screen_picture_del, setup_scr_screen_picture_display, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif, guider_ui.screen_gif_del, &guider_ui.screen_picture_del, setup_scr_screen_gif, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_clock, guider_ui.screen_clock_del, &guider_ui.screen_picture_del, setup_scr_screen_clock, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_picture_img_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture_display, guider_ui.screen_picture_display_del, &guider_ui.screen_picture_del, setup_scr_screen_picture_display, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_picture(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_picture, screen_picture_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_picture_img_1, screen_picture_img_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_picture);
        lv_group_focus_obj(ui->screen_picture);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_picture_display_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture, guider_ui.screen_picture_del, &guider_ui.screen_picture_display_del, setup_scr_screen_picture, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture, guider_ui.screen_picture_del, &guider_ui.screen_picture_display_del, setup_scr_screen_picture, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // 边界检查：无图片时直接返回
            if (all_config.pic_picture_length <= 0)
            {
                ESP_LOGW("event", "No pictures to display");
                break;
            }

            // 安全更新索引（避免负数）
            all_config.page_pic_display.pic_index--;
            if (all_config.page_pic_display.pic_index < 0)
            {
                all_config.page_pic_display.pic_index = all_config.pic_picture_length - 1;
            }
            snprintf(all_config.page_pic_display.pic_path_buf, sizeof(all_config.page_pic_display.pic_path_buf),
                     "S:/pictures/%s",
                     all_config.pics_picture[all_config.page_pic_display.pic_index]);
            lv_img_set_src(guider_ui.screen_picture_display_img_display, all_config.page_pic_display.pic_path_buf);
            if (save_config.pic_display == all_config.page_pic_display.pic_index && all_config.page_main.main_display_type == 0)
            {
                lv_label_set_text(guider_ui.screen_picture_display_list_1_item0, "已设置");
            }
            else
            {
                lv_label_set_text(guider_ui.screen_picture_display_list_1_item0, "设置");
            }
            ESP_LOGI("picture_display", "Display picture: %s; pic_index: %d", all_config.page_pic_display.pic_path_buf, all_config.page_pic_display.pic_index);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // 边界检查：无图片时直接返回
            if (all_config.pic_picture_length <= 0)
            {
                ESP_LOGW("event", "No pictures to display");
                break;
            }

            // 安全更新索引（避免负数）
            all_config.page_pic_display.pic_index =
                (all_config.page_pic_display.pic_index + 1) % all_config.pic_picture_length;
            snprintf(all_config.page_pic_display.pic_path_buf, sizeof(all_config.page_pic_display.pic_path_buf),
                     "S:/pictures/%s",
                     all_config.pics_picture[all_config.page_pic_display.pic_index]);

            lv_img_set_src(guider_ui.screen_picture_display_img_display, all_config.page_pic_display.pic_path_buf);
            if (save_config.pic_display == all_config.page_pic_display.pic_index && all_config.page_main.main_display_type == 0)
            {
                lv_label_set_text(guider_ui.screen_picture_display_list_1_item0, "已设置");
            }
            else
            {
                lv_label_set_text(guider_ui.screen_picture_display_list_1_item0, "设置");
            }
            ESP_LOGI("picture_display", "Display picture: %s; pic_index: %d", all_config.page_pic_display.pic_path_buf, all_config.page_pic_display.pic_index);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_picture_display_list_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_label_set_text(guider_ui.screen_picture_display_list_1_item0, "已设置");
        save_config.main_display_type = all_config.page_main.main_display_type = 0;
        save_config.pic_display = all_config.page_pic_display.pic_index;
        ESP_LOGI("picture_display", "Set picture: %s", all_config.pics_picture[all_config.page_pic_display.pic_index]);
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_picture_display_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        nvs_save_all_config();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_picture_display(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_picture_display, screen_picture_display_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_picture_display_list_1, screen_picture_display_list_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_picture_display);
        lv_group_focus_obj(ui->screen_picture_display);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_gif_display_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif, guider_ui.screen_gif_del, &guider_ui.screen_gif_display_del, setup_scr_screen_gif, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif, guider_ui.screen_gif_del, &guider_ui.screen_gif_display_del, setup_scr_screen_gif, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // 边界检查：无图片时直接返回
            if (all_config.pic_gif_length <= 0)
            {
                ESP_LOGW("event", "No gifs to display");
                break;
            }

            // 安全更新索引（避免负数）
            all_config.page_gif_display.gif_index--;
            if (all_config.page_gif_display.gif_index < 0)
            {
                all_config.page_gif_display.gif_index = all_config.pic_gif_length - 1;
            }
            snprintf(all_config.page_gif_display.gif_path_buf, sizeof(all_config.page_gif_display.gif_path_buf),
                     "S:/gifs/%s",
                     all_config.pics_gif[all_config.page_gif_display.gif_index]);

            lv_gif_set_src(guider_ui.screen_gif_display_img_display, all_config.page_gif_display.gif_path_buf);
            if (save_config.gif_display == all_config.page_gif_display.gif_index && all_config.page_main.main_display_type == 1)
            {
                lv_label_set_text(guider_ui.screen_gif_display_list_1_item0, "已设置");
            }
            else
            {
                lv_label_set_text(guider_ui.screen_gif_display_list_1_item0, "设置");
            }
            ESP_LOGI("gif_display", "Display picture: %s; pic_index: %d", all_config.page_gif_display.gif_path_buf, all_config.page_gif_display.gif_index);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            // 边界检查：无图片时直接返回
            if (all_config.pic_picture_length <= 0)
            {
                ESP_LOGW("event", "No pictures to display");
                break;
            }

            // 安全更新索引（避免负数）
            all_config.page_gif_display.gif_index =
                (all_config.page_gif_display.gif_index + 1) % all_config.pic_gif_length;
            snprintf(all_config.page_gif_display.gif_path_buf, sizeof(all_config.page_gif_display.gif_path_buf),
                     "S:/gifs/%s",
                     all_config.pics_gif[all_config.page_gif_display.gif_index]);
            lv_gif_set_src(guider_ui.screen_gif_display_img_display, all_config.page_gif_display.gif_path_buf);
            if (save_config.gif_display == all_config.page_gif_display.gif_index && all_config.page_main.main_display_type == 1)
            {
                lv_label_set_text(guider_ui.screen_gif_display_list_1_item0, "已设置");
            }
            else
            {
                lv_label_set_text(guider_ui.screen_gif_display_list_1_item0, "设置");
            }
            ESP_LOGI("gif_display", "Display picture: %s; pic_index: %d", all_config.page_gif_display.gif_path_buf, all_config.page_gif_display.gif_index);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_gif_display_list_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_label_set_text(guider_ui.screen_gif_display_list_1_item0, "已设置");
        save_config.main_display_type = all_config.page_main.main_display_type = 1;
        save_config.gif_display = all_config.page_gif_display.gif_index;
        ESP_LOGI("gif_display", "Set gif: %s", all_config.pics_gif[all_config.page_main.pic_main_index]);
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del, &guider_ui.screen_gif_display_del, setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        nvs_save_all_config();
        break;
    }
    default:
        break;
    }
}

void events_init_screen_gif_display(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_gif_display, screen_gif_display_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_gif_display_list_1, screen_gif_display_list_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_gif_display);
        lv_group_focus_obj(ui->screen_gif_display);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_gif_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_gif_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif_display, guider_ui.screen_gif_display_del, &guider_ui.screen_gif_del, setup_scr_screen_gif_display, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_clock, guider_ui.screen_clock_del, &guider_ui.screen_gif_del, setup_scr_screen_clock, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture, guider_ui.screen_picture_del, &guider_ui.screen_gif_del, setup_scr_screen_picture, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_gif_animimg_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif_display, guider_ui.screen_gif_display_del, &guider_ui.screen_gif_del, setup_scr_screen_gif_display, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_gif(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_gif, screen_gif_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_gif_animimg_1, screen_gif_animimg_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_gif);
        lv_group_focus_obj(ui->screen_gif);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_clock_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_clock_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif, guider_ui.screen_gif_del, &guider_ui.screen_clock_del, setup_scr_screen_gif, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture, guider_ui.screen_picture_del, &guider_ui.screen_clock_del, setup_scr_screen_picture, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_clock_display, guider_ui.screen_clock_display_del, &guider_ui.screen_clock_del, setup_scr_screen_clock_display, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void screen_clock_img_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_clock_display, guider_ui.screen_clock_display_del, &guider_ui.screen_clock_del, setup_scr_screen_clock_display, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_clock(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_clock, screen_clock_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_clock_img_1, screen_clock_img_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_clock);
        lv_group_focus_obj(ui->screen_clock);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_clock_display_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_clock, guider_ui.screen_clock_del, &guider_ui.screen_clock_display_del, setup_scr_screen_clock, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_clock, guider_ui.screen_clock_del, &guider_ui.screen_clock_display_del, setup_scr_screen_clock, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            if (all_config.page_clock_display.clock_index == 0)
            {
                all_config.page_clock_display.clock_index = 1;
                lv_img_set_src(guider_ui.screen_clock_display_img_display, &_digital_img_alpha_250x250);
            }
            else if (all_config.page_clock_display.clock_index == 1)
            {
                all_config.page_clock_display.clock_index = 2;
                lv_img_set_src(guider_ui.screen_clock_display_img_display, &_home_alpha_250x250);
            }
            else if (all_config.page_clock_display.clock_index == 2)
            {
                all_config.page_clock_display.clock_index = 0;
                lv_img_set_src(guider_ui.screen_clock_display_img_display, &_analog_img_alpha_250x250);
            }
            if (save_config.clock_display == all_config.page_clock_display.clock_index && all_config.page_main.main_display_type == 2)
            {
                lv_label_set_text(guider_ui.screen_clock_display_list_1_item0, "已设置");
            }
            else
            {
                lv_label_set_text(guider_ui.screen_clock_display_list_1_item0, "设置");
            }
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            if (all_config.page_clock_display.clock_index == 0)
            {
                all_config.page_clock_display.clock_index = 2;
                lv_img_set_src(guider_ui.screen_clock_display_img_display, &_home_alpha_250x250);
            }
            else if (all_config.page_clock_display.clock_index == 1)
            {
                all_config.page_clock_display.clock_index = 0;
                lv_img_set_src(guider_ui.screen_clock_display_img_display, &_analog_img_alpha_250x250);
            }
            else if (all_config.page_clock_display.clock_index == 2)
            {
                all_config.page_clock_display.clock_index = 1;
                lv_img_set_src(guider_ui.screen_clock_display_img_display, &_digital_img_alpha_250x250);
            }
            if (save_config.clock_display == all_config.page_clock_display.clock_index && all_config.page_main.main_display_type == 2)
            {
                lv_label_set_text(guider_ui.screen_clock_display_list_1_item0, "已设置");
            }
            else
            {
                lv_label_set_text(guider_ui.screen_clock_display_list_1_item0, "设置");
            }
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_clock_display_list_1_item0_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_label_set_text(guider_ui.screen_clock_display_list_1_item0, "已设置");
        save_config.main_display_type = all_config.page_main.main_display_type = 2;
        save_config.clock_display = all_config.page_clock_display.clock_index;
        ESP_LOGI("clock_display", "Set clock: %d", all_config.page_clock_display.clock_index);
        nvs_save_all_config();
        switch (all_config.page_clock_display.clock_index)
        {
        case 0:
            ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_mainConfig_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        case 1:
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_mainConfig_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        case 2:
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_mainConfig_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_clock_display(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_clock_display, screen_clock_display_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_clock_display_list_1, screen_clock_display_list_1_item0_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_clock_display);
        lv_group_focus_obj(ui->screen_clock_display);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void home_analog_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SCREEN_LOADED:
    {
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.home_analog_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.home_analog_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.home_analog_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config, guider_ui.screen_quick_config_del, &guider_ui.home_analog_del, setup_scr_screen_quick_config, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_home_analog(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_analog, home_analog_event_handler, LV_EVENT_ALL, ui);
}

static void home_digital_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.home_digital_label_min, 800, 0, lv_obj_get_x(guider_ui.home_digital_label_min), 110, &lv_anim_path_bounce, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.home_digital_label_min, 800, 0, lv_obj_get_y(guider_ui.home_digital_label_min), 203, &lv_anim_path_bounce, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.home_digital_label_hour, 800, 0, lv_obj_get_x(guider_ui.home_digital_label_hour), 110, &lv_anim_path_bounce, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.home_digital_label_hour, 800, 0, lv_obj_get_y(guider_ui.home_digital_label_hour), 77, &lv_anim_path_bounce, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.home_digital_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.home_digital_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.home_digital_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config, guider_ui.screen_quick_config_del, &guider_ui.home_digital_del, setup_scr_screen_quick_config, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_home_digital(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_digital, home_digital_event_handler, LV_EVENT_ALL, ui);
}

static void screen_home_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_SCREEN_LOADED:
    {
        
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_home_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_home_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 100, 100, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_home_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config, guider_ui.screen_quick_config_del, &guider_ui.screen_home_del, setup_scr_screen_quick_config, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_home(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_home, screen_home_event_handler, LV_EVENT_ALL, ui);
}

static void screen_chat_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            if (save_config.main_display_type == 0)
            {
                all_config.page_main.pic_main_index = all_config.page_pic_display.pic_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_chat_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 1)
            {
                all_config.page_main.pic_main_index = all_config.page_gif_display.gif_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del, &guider_ui.screen_chat_del, setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 2)
            {
                switch (save_config.clock_display)
                {
                case 0:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_chat_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 1:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_chat_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 2:
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_chat_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                default:
                    break;
                }
            }
        }
        break;
    }
    case LV_EVENT_CLICKED:
    {
        if (!all_config.wifi_config.wifi_isConnected)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_wifiDisconnect, guider_ui.screen_wifiDisconnect_del, &guider_ui.screen_chat_del, setup_scr_screen_wifiDisconnect, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        else
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chatDetail, guider_ui.screen_chatDetail_del, &guider_ui.screen_chat_del, setup_scr_screen_chatDetail, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_chat_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_remind, guider_ui.screen_remind_del, &guider_ui.screen_chat_del, setup_scr_screen_remind, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_chat_img_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_chatDetail, guider_ui.screen_chatDetail_del, &guider_ui.screen_chat_del, setup_scr_screen_chatDetail, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_chat(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_chat, screen_chat_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_chat_img_1, screen_chat_img_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_chat);
        lv_group_focus_obj(ui->screen_chat);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_chatDetail_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chat, guider_ui.screen_chat_del, &guider_ui.screen_chatDetail_del, setup_scr_screen_chat, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chat, guider_ui.screen_chat_del, &guider_ui.screen_chatDetail_del, setup_scr_screen_chat, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_chatDetail(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_chatDetail, screen_chatDetail_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_chatDetail);
        lv_group_focus_obj(ui->screen_chatDetail);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_wifiDisconnect_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chat, guider_ui.screen_chat_del, &guider_ui.screen_wifiDisconnect_del, setup_scr_screen_chat, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_wifiDisconnect(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_wifiDisconnect, screen_wifiDisconnect_event_handler, LV_EVENT_ALL, ui);
}

static void screen_remind_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            if (save_config.main_display_type == 0)
            {
                all_config.page_main.pic_main_index = all_config.page_pic_display.pic_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_remind_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 1)
            {
                all_config.page_main.pic_main_index = all_config.page_gif_display.gif_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del, &guider_ui.screen_remind_del, setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 2)
            {
                switch (save_config.clock_display)
                {
                case 0:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_remind_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 1:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_remind_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 2:
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_remind_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                default:
                    break;
                }
            }
        }
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_remindDetail, guider_ui.screen_remindDetail_del, &guider_ui.screen_remind_del, setup_scr_screen_remindDetail, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_meeting, guider_ui.screen_meeting_del, &guider_ui.screen_remind_del, setup_scr_screen_meeting, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chat, guider_ui.screen_chat_del, &guider_ui.screen_remind_del, setup_scr_screen_chat, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_remind_img_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_remindDetail, guider_ui.screen_remindDetail_del, &guider_ui.screen_remind_del, setup_scr_screen_remindDetail, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_remind(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_remind, screen_remind_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_remind_img_1, screen_remind_img_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_remind);
        lv_group_focus_obj(ui->screen_remind);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_remindDetail_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_remind, guider_ui.screen_remind_del, &guider_ui.screen_remindDetail_del, setup_scr_screen_remind, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_remind, guider_ui.screen_remind_del, &guider_ui.screen_remindDetail_del, setup_scr_screen_remind, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_remindDetail(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_remindDetail, screen_remindDetail_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_remindDetail);
        lv_group_focus_obj(ui->screen_remindDetail);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_meeting_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            if (save_config.main_display_type == 0)
            {
                all_config.page_main.pic_main_index = all_config.page_pic_display.pic_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_meeting_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 1)
            {
                all_config.page_main.pic_main_index = all_config.page_gif_display.gif_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del, &guider_ui.screen_meeting_del, setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 2)
            {
                switch (save_config.clock_display)
                {
                case 0:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_meeting_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 1:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_meeting_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 2:
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_meeting_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                default:
                    break;
                }
            }
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig, guider_ui.screen_systemConfig_del, &guider_ui.screen_meeting_del, setup_scr_screen_systemConfig, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_remind, guider_ui.screen_remind_del, &guider_ui.screen_meeting_del, setup_scr_screen_remind, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_meetingDetail, guider_ui.screen_meetingDetail_del, &guider_ui.screen_meeting_del, setup_scr_screen_meetingDetail, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void screen_meeting_img_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_meetingDetail, guider_ui.screen_meetingDetail_del, &guider_ui.screen_meeting_del, setup_scr_screen_meetingDetail, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_meeting(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_meeting, screen_meeting_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_meeting_img_1, screen_meeting_img_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_meeting);
        lv_group_focus_obj(ui->screen_meeting);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_meetingDetail_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_meeting, guider_ui.screen_meeting_del, &guider_ui.screen_meetingDetail_del, setup_scr_screen_meeting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            if (dclock_handle != NULL)
            {
                lv_timer_del(dclock_handle);
            }
            screen_meetingDetail_digital_clock_1_min_value = 0;
            screen_meetingDetail_digital_clock_1_hour_value = 0;
            screen_meetingDetail_digital_clock_1_sec_value = 0;
            ESP_LOGI("meetingDetail", "停止录音...");
            audio_record_stop();
            g_record_state = RECORD_STATE_IDLE;
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_meeting, guider_ui.screen_meeting_del, &guider_ui.screen_meetingDetail_del, setup_scr_screen_meeting, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_meetingDetail_btn_start_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        if (g_record_state == RECORD_STATE_IDLE)
        {
            audio_record_start();
            // g_record_state = RECORD_STATE_RECORDING;
            ESP_LOGI("meetingDetail", "开始录音...");
            dclock_handle = lv_timer_create(screen_meetingDetail_digital_clock_1_timer, 1000, NULL);
            lv_obj_set_style_bg_img_src(guider_ui.screen_meetingDetail_btn_start, &_pause1_80x80, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if (g_record_state == RECORD_STATE_RECORDING)
        {
            audio_record_pause(true);
            // g_record_state = RECORD_STATE_PAUSE;
            ESP_LOGI("meetingDetail", "暂停录音...");
            lv_timer_pause(dclock_handle);
            lv_obj_set_style_bg_img_src(guider_ui.screen_meetingDetail_btn_start, &_start1_80x80, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if (g_record_state == RECORD_STATE_PAUSE)
        {
            audio_record_pause(false);
            // g_record_state = RECORD_STATE_RECORDING;
            ESP_LOGI("meetingDetail", "继续录音...");
            lv_timer_resume(dclock_handle);
            lv_obj_set_style_bg_img_src(guider_ui.screen_meetingDetail_btn_start, &_pause1_80x80, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_meetingDetail(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_meetingDetail, screen_meetingDetail_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_meetingDetail_btn_start, screen_meetingDetail_btn_start_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_meetingDetail);
        lv_group_focus_obj(ui->screen_meetingDetail);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_systemConfig_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            if (save_config.main_display_type == 0)
            {
                all_config.page_main.pic_main_index = all_config.page_pic_display.pic_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_systemConfig_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 1)
            {
                all_config.page_main.pic_main_index = all_config.page_gif_display.gif_index;
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del, &guider_ui.screen_systemConfig_del, setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
            }
            else if (save_config.main_display_type == 2)
            {
                switch (save_config.clock_display)
                {
                case 0:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.screen_systemConfig_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 1:
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.screen_systemConfig_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                case 2:
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del, &guider_ui.screen_systemConfig_del, setup_scr_screen_home, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                    break;
                default:
                    break;
                }
            }
        }
        break;
    }
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig1, guider_ui.screen_systemConfig1_del, &guider_ui.screen_systemConfig_del, setup_scr_screen_systemConfig1, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_meeting, guider_ui.screen_meeting_del, &guider_ui.screen_systemConfig_del, setup_scr_screen_meeting, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del, &guider_ui.screen_systemConfig_del, setup_scr_screen_mainConfig, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_systemConfig_img_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig1, guider_ui.screen_systemConfig1_del, &guider_ui.screen_systemConfig_del, setup_scr_screen_systemConfig1, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_systemConfig(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_systemConfig, screen_systemConfig_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig_img_1, screen_systemConfig_img_1_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_systemConfig);
        lv_group_focus_obj(ui->screen_systemConfig);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_systemConfig1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig, guider_ui.screen_systemConfig_del, &guider_ui.screen_systemConfig1_del, setup_scr_screen_systemConfig, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig, guider_ui.screen_systemConfig_del, &guider_ui.screen_systemConfig1_del, setup_scr_screen_systemConfig, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_systemConfig1_cont_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_autoShutDown, guider_ui.screen_autoShutDown_del, &guider_ui.screen_systemConfig1_del, setup_scr_screen_autoShutDown, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void screen_systemConfig1_cont_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_reset, guider_ui.screen_reset_del, &guider_ui.screen_systemConfig1_del, setup_scr_screen_reset, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void screen_systemConfig1_cont_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void screen_systemConfig1_cont_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_device_information, guider_ui.screen_device_information_del, &guider_ui.screen_systemConfig1_del, setup_scr_screen_device_information, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_systemConfig1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_systemConfig1, screen_systemConfig1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_1, screen_systemConfig1_cont_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_4, screen_systemConfig1_cont_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_6, screen_systemConfig1_cont_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_8, screen_systemConfig1_cont_8_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_systemConfig1);
        lv_group_focus_obj(ui->screen_systemConfig1);
    }
    else
    {
        ESP_LOGI("screen_quick_config", "input group is null");
    }
}

static void screen_device_information_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            // 保留原有的页面切换逻辑，删除阻塞的lv_indev_wait_release
            ui_load_scr_animation(&guider_ui,
                                  &guider_ui.screen_systemConfig1,
                                  guider_ui.screen_systemConfig1_del,
                                  &guider_ui.screen_device_information_del,
                                  setup_scr_screen_systemConfig1,
                                  LV_SCR_LOAD_ANIM_FADE_ON,
                                  200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig1, guider_ui.screen_systemConfig1_del, &guider_ui.screen_device_information_del, setup_scr_screen_systemConfig1, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_screen_device_information(lv_ui *ui)
{
    // 仅监听LV_EVENT_KEY（替代原来的LV_EVENT_ALL），减少不必要的回调
    lv_obj_add_event_cb(ui->screen_device_information,
                        screen_device_information_event_handler,
                        LV_EVENT_ALL,
                        ui);

    // 3. LVGL 8.3.10适配：将页面加入输入组并设置为焦点（替代lv_obj_focus）
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_device_information);
        lv_group_focus_obj(ui->screen_device_information);
    }
    else
    {
        ESP_LOGI("device_information", "input group is null");
    }
}

static void screen_reset_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_reset_slider_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_VALUE_CHANGED:
    {
        uint8_t resetValue = lv_slider_get_value(lv_event_get_target(e));
        if (resetValue == 100)
        {
            save_config.volume = 70;
            save_config.backLight = 80;
            save_config.main_display_type = 0;
            save_config.pic_display = 0;
            save_config.gif_display = 0;
            save_config.clock_display = 0;
            save_config.autoShutDownTime = 0;
            nvs_save_all_config();
            deep_sleep_rtc(2000);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_reset_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig1, guider_ui.screen_systemConfig1_del, &guider_ui.screen_reset_del, setup_scr_screen_systemConfig1, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_reset(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_reset, screen_reset_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_reset_slider_1, screen_reset_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_reset_btn_1, screen_reset_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_autoShutDown_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_KEY:
    {
        uint32_t key = lv_event_get_key(e);
        if (key == LV_KEY_RETURN)
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig1, guider_ui.screen_systemConfig1_del, &guider_ui.screen_autoShutDown_del, setup_scr_screen_systemConfig1, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        }
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch (dir)
        {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig1, guider_ui.screen_systemConfig1_del, &guider_ui.screen_autoShutDown_del, setup_scr_screen_systemConfig1, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_autoShutDown_list_1_item0_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        save_config.autoShutDownTime = all_config.page_systemConfig.autoShutdownTime = 0;
        nvs_save_all_config();
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item0, &_selected_green_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item1, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item2, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item3, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item4, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item5, &_black_alpha_20x20);
        ESP_LOGI("autoShutDown_list", "set auto shut down:%d", save_config.autoShutDownTime);
        break;
    }
    default:
        break;
    }
}

static void screen_autoShutDown_list_1_item1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        save_config.autoShutDownTime = all_config.page_systemConfig.autoShutdownTime = 5;
        nvs_save_all_config();
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item0, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item1, &_selected_green_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item2, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item3, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item4, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item5, &_black_alpha_20x20);
        ESP_LOGI("autoShutDown_list", "set auto shut down:%d", save_config.autoShutDownTime);
        break;
    }
    default:
        break;
    }
}

static void screen_autoShutDown_list_1_item2_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        save_config.autoShutDownTime = all_config.page_systemConfig.autoShutdownTime = 10;
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item0, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item1, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item2, &_selected_green_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item3, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item4, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item5, &_black_alpha_20x20);
        ESP_LOGI("autoShutDown_list", "set auto shut down:%d", save_config.autoShutDownTime);
        nvs_save_all_config();
        break;
    }
    default:
        break;
    }
}

static void screen_autoShutDown_list_1_item3_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        save_config.autoShutDownTime = all_config.page_systemConfig.autoShutdownTime = 30;
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item0, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item1, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item2, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item3, &_selected_green_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item4, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item5, &_black_alpha_20x20);
        ESP_LOGI("autoShutDown_list", "set auto shut down:%d", save_config.autoShutDownTime);
        nvs_save_all_config();
        break;
    }
    default:
        break;
    }
}

static void screen_autoShutDown_list_1_item4_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        save_config.autoShutDownTime = all_config.page_systemConfig.autoShutdownTime = 60;
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item0, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item1, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item2, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item3, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item4, &_selected_green_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item5, &_black_alpha_20x20);
        ESP_LOGI("autoShutDown_list", "set auto shut down:%d", save_config.autoShutDownTime);
        nvs_save_all_config();
        break;
    }
    default:
        break;
    }
}

static void screen_autoShutDown_list_1_item5_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        save_config.autoShutDownTime = all_config.page_systemConfig.autoShutdownTime = 6 * 60;
        nvs_save_all_config();
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item0, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item1, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item2, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item3, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item4, &_black_alpha_20x20);
        lv_list_set_btn_img(guider_ui.screen_autoShutDown_list_1_item5, &_selected_green_alpha_20x20);
        ESP_LOGI("autoShutDown_list", "set auto shut down:%d", save_config.autoShutDownTime);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_autoShutDown(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_autoShutDown, screen_autoShutDown_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item0, screen_autoShutDown_list_1_item0_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item1, screen_autoShutDown_list_1_item1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item2, screen_autoShutDown_list_1_item2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item3, screen_autoShutDown_list_1_item3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item4, screen_autoShutDown_list_1_item4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item5, screen_autoShutDown_list_1_item5_event_handler, LV_EVENT_ALL, ui);
    if (ui_input_group != NULL)
    {
        lv_group_add_obj(ui_input_group, ui->screen_autoShutDown);
        lv_group_focus_obj(ui->screen_autoShutDown);
    }
    else
    {
        ESP_LOGI("device_information", "input group is null");
    }
}

void events_init(lv_ui *ui)
{
}
