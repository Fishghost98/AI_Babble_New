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
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "Commons.h"



void setup_scr_screen_meetingDetail(lv_ui *ui)
{
    //Write codes screen_meetingDetail
    ui->screen_meetingDetail = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_meetingDetail, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_meetingDetail, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_meetingDetail, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meetingDetail, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meetingDetail, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meetingDetail_btn_start
    ui->screen_meetingDetail_btn_start = lv_btn_create(ui->screen_meetingDetail);
    ui->screen_meetingDetail_btn_start_label = lv_label_create(ui->screen_meetingDetail_btn_start);
    lv_label_set_text(ui->screen_meetingDetail_btn_start_label, "");
    lv_label_set_long_mode(ui->screen_meetingDetail_btn_start_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_meetingDetail_btn_start_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_meetingDetail_btn_start, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_meetingDetail_btn_start_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_meetingDetail_btn_start, 140, 263);
    lv_obj_set_size(ui->screen_meetingDetail_btn_start, 80, 80);

    //Write style for screen_meetingDetail_btn_start, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail_btn_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_meetingDetail_btn_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meetingDetail_btn_start, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meetingDetail_btn_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->screen_meetingDetail_btn_start, &_start1_80x80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->screen_meetingDetail_btn_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->screen_meetingDetail_btn_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_meetingDetail_btn_start, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_meetingDetail_btn_start, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_meetingDetail_btn_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_meetingDetail_btn_start, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meetingDetail_bar_battery
    ui->screen_meetingDetail_bar_battery = lv_bar_create(ui->screen_meetingDetail);
    lv_obj_set_style_anim_time(ui->screen_meetingDetail_bar_battery, 1000, 0);
    lv_bar_set_mode(ui->screen_meetingDetail_bar_battery, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_meetingDetail_bar_battery, 0, 100);
    lv_bar_set_value(ui->screen_meetingDetail_bar_battery, all_config.page_quickConfig.battery, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_meetingDetail_bar_battery, 153, 54);
    lv_obj_set_size(ui->screen_meetingDetail_bar_battery, 50, 20);

    //Write style for screen_meetingDetail_bar_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail_bar_battery, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meetingDetail_bar_battery, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meetingDetail_bar_battery, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meetingDetail_bar_battery, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meetingDetail_bar_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_meetingDetail_bar_battery, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail_bar_battery, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meetingDetail_bar_battery, lv_color_hex(0x2FDA64), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meetingDetail_bar_battery, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meetingDetail_bar_battery, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_meetingDetail_label_battery
    ui->screen_meetingDetail_label_battery = lv_label_create(ui->screen_meetingDetail);
    static char battery_buf[20] = {0};
    snprintf(battery_buf, sizeof(battery_buf),
             "%d%%",
             all_config.page_quickConfig.battery);
    ESP_LOGI("screen_quick_config", "battery:%d", all_config.page_quickConfig.battery);
    lv_label_set_text(ui->screen_meetingDetail_label_battery, battery_buf);
    lv_label_set_long_mode(ui->screen_meetingDetail_label_battery, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_meetingDetail_label_battery, 153, 56);
    lv_obj_set_size(ui->screen_meetingDetail_label_battery, 50, 16);

    //Write style for screen_meetingDetail_label_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_meetingDetail_label_battery, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_meetingDetail_label_battery, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_meetingDetail_label_battery, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_meetingDetail_label_battery, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meetingDetail_label_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meetingDetail_label_2
    ui->screen_meetingDetail_label_2 = lv_label_create(ui->screen_meetingDetail);
    lv_label_set_text(ui->screen_meetingDetail_label_2, "AI会议");
    lv_label_set_long_mode(ui->screen_meetingDetail_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_meetingDetail_label_2, 130, 25);
    lv_obj_set_size(ui->screen_meetingDetail_label_2, 100, 32);

    //Write style for screen_meetingDetail_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_meetingDetail_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_meetingDetail_label_2, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_meetingDetail_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_meetingDetail_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meetingDetail_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meetingDetail_digital_clock_1
    ui->screen_meetingDetail_digital_clock_1 = lv_dclock_create(ui->screen_meetingDetail, "00:00:00");
    
    lv_obj_set_pos(ui->screen_meetingDetail_digital_clock_1, 75, 135);
    lv_obj_set_size(ui->screen_meetingDetail_digital_clock_1, 230, 63);

    //Write style for screen_meetingDetail_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_meetingDetail_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_meetingDetail_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_meetingDetail_digital_clock_1, &lv_font_montserratMedium_50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_meetingDetail_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_meetingDetail_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_meetingDetail_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_meetingDetail_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_meetingDetail_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_meetingDetail_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_meetingDetail_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meetingDetail_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_meetingDetail.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_meetingDetail);

    //Init events for screen.
    events_init_screen_meetingDetail(ui);
}
