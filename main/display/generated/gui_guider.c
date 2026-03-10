/*
 * Copyright 2026 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "widgets_init.h"
#include "Commons.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "gg_external_data.h"
#endif

void ui_init_style(lv_style_t *style)
{
    if (style->prop_cnt > 1)
        lv_style_reset(style);
    else
        lv_style_init(style);
}

void ui_load_scr_animation(lv_ui *ui, lv_obj_t **new_scr, bool new_scr_del, bool *old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del)
{
    lv_obj_t *act_scr = lv_scr_act();

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
    if (auto_del)
    {
        gg_edata_task_clear(act_scr);
    }
#endif
    if (auto_del && is_clean)
    {
        lv_obj_clean(act_scr);
    }
    if (new_scr_del)
    {
        setup_scr(ui);
    }
    lv_scr_load_anim(*new_scr, anim_type, time, delay, auto_del);
    *old_scr_del = auto_del;
}

void ui_animation(void *var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb)
{
    lv_anim_t anim;
    lv_anim_init(&anim);
    lv_anim_set_var(&anim, var);
    lv_anim_set_exec_cb(&anim, exec_cb);
    lv_anim_set_values(&anim, start_value, end_value);
    lv_anim_set_time(&anim, duration);
    lv_anim_set_delay(&anim, delay);
    lv_anim_set_path_cb(&anim, path_cb);
    lv_anim_set_repeat_count(&anim, repeat_cnt);
    lv_anim_set_repeat_delay(&anim, repeat_delay);
    lv_anim_set_playback_time(&anim, playback_time);
    lv_anim_set_playback_delay(&anim, playback_delay);
    if (start_cb)
    {
        lv_anim_set_start_cb(&anim, start_cb);
    }
    if (ready_cb)
    {
        lv_anim_set_ready_cb(&anim, ready_cb);
    }
    if (deleted_cb)
    {
        lv_anim_set_deleted_cb(&anim, deleted_cb);
    }
    lv_anim_start(&anim);
}

void init_scr_del_flag(lv_ui *ui)
{

    ui->screen_main_del = true;
    ui->screen_main_gif_del = true;
    ui->screen_quick_config_del = true;
    ui->screen_shutDown_del = true;
    ui->screen_mainConfig_del = true;
    ui->screen_picture_del = true;
    ui->screen_picture_display_del = true;
    ui->screen_gif_display_del = true;
    ui->screen_gif_del = true;
    ui->screen_clock_del = true;
    ui->screen_clock_display_del = true;
    ui->home_analog_del = true;
    ui->home_digital_del = true;
    ui->screen_home_del = true;
    ui->screen_chat_del = true;
    ui->screen_chatDetail_del = true;
    ui->screen_wifiDisconnect_del = true;
    ui->screen_remind_del = true;
    ui->screen_remindDetail_del = true;
    ui->screen_meeting_del = true;
    ui->screen_meetingDetail_del = true;
    ui->screen_systemConfig_del = true;
    ui->screen_systemConfig1_del = true;
    ui->screen_autoShutDown_del = true;
    ui->screen_device_information_del = true;
    ui->screen_reset_del = true;
}

void setup_ui(lv_ui *ui)
{
    init_scr_del_flag(ui);
    init_keyboard(ui);
    if (all_config.wifi_config.wifi_isConnected)
    {
        if (all_config.page_main.main_display_type == 0)
        {
            setup_scr_screen_main(ui);
            lv_scr_load(ui->screen_main);
        }
        else if (all_config.page_main.main_display_type == 1)
        {
            setup_scr_screen_main_gif(ui);
            lv_scr_load(ui->screen_main_gif);
        }
        else if (all_config.page_main.main_display_type == 2)
        {
            switch (all_config.page_clock_display.clock_index)
            {
            case 0:
            {
                setup_scr_home_analog(ui);
                lv_scr_load(ui->home_analog);
                break;
            }
            case 1:
            {
                setup_scr_home_digital(ui);
                lv_scr_load(ui->home_digital);
                break;
            }
            case 2:
            {
                setup_scr_screen_home(ui);
                lv_scr_load(ui->screen_home);
                break;
            }
            default:
                break;
            }
        }
    }
    else
    {
        setup_scr_screen_wifiDisconnect(ui);
        lv_scr_load(ui->screen_wifiDisconnect);
    }
}

void init_keyboard(lv_ui *ui)
{
}
