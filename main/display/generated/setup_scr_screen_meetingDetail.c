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



int screen_meetingDetail_digital_clock_1_min_value = 25;
int screen_meetingDetail_digital_clock_1_hour_value = 11;
int screen_meetingDetail_digital_clock_1_sec_value = 50;
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
    lv_obj_set_style_bg_image_src(ui->screen_meetingDetail, &_bk2_RGB565A8_360x360, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->screen_meetingDetail, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->screen_meetingDetail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meetingDetail_btn_1
    ui->screen_meetingDetail_btn_1 = lv_button_create(ui->screen_meetingDetail);
    lv_obj_set_pos(ui->screen_meetingDetail_btn_1, 140, 263);
    lv_obj_set_size(ui->screen_meetingDetail_btn_1, 80, 80);
    ui->screen_meetingDetail_btn_1_label = lv_label_create(ui->screen_meetingDetail_btn_1);
    lv_label_set_text(ui->screen_meetingDetail_btn_1_label, "");
    lv_label_set_long_mode(ui->screen_meetingDetail_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_meetingDetail_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_meetingDetail_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_meetingDetail_btn_1_label, LV_PCT(100));

    //Write style for screen_meetingDetail_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_meetingDetail_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meetingDetail_btn_1, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meetingDetail_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->screen_meetingDetail_btn_1, &_start1_RGB565A8_80x80, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->screen_meetingDetail_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->screen_meetingDetail_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_meetingDetail_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_meetingDetail_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_meetingDetail_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_meetingDetail_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meetingDetail_bar_1
    ui->screen_meetingDetail_bar_1 = lv_bar_create(ui->screen_meetingDetail);
    lv_obj_set_pos(ui->screen_meetingDetail_bar_1, 153, 54);
    lv_obj_set_size(ui->screen_meetingDetail_bar_1, 50, 20);
    lv_obj_set_style_anim_duration(ui->screen_meetingDetail_bar_1, 1000, 0);
    lv_bar_set_mode(ui->screen_meetingDetail_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_meetingDetail_bar_1, 0, 100);
    lv_bar_set_value(ui->screen_meetingDetail_bar_1, 80, LV_ANIM_OFF);

    //Write style for screen_meetingDetail_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meetingDetail_bar_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meetingDetail_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meetingDetail_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meetingDetail_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_meetingDetail_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meetingDetail_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meetingDetail_bar_1, lv_color_hex(0x2fda64), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meetingDetail_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meetingDetail_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_meetingDetail_label_battery
    ui->screen_meetingDetail_label_battery = lv_label_create(ui->screen_meetingDetail);
    lv_obj_set_pos(ui->screen_meetingDetail_label_battery, 153, 56);
    lv_obj_set_size(ui->screen_meetingDetail_label_battery, 50, 16);
    lv_label_set_text(ui->screen_meetingDetail_label_battery, "80%");
    lv_label_set_long_mode(ui->screen_meetingDetail_label_battery, LV_LABEL_LONG_WRAP);

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
    lv_obj_set_pos(ui->screen_meetingDetail_label_2, 130, 25);
    lv_obj_set_size(ui->screen_meetingDetail_label_2, 100, 32);
    lv_label_set_text(ui->screen_meetingDetail_label_2, "AI会议");
    lv_label_set_long_mode(ui->screen_meetingDetail_label_2, LV_LABEL_LONG_WRAP);

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
    static bool screen_meetingDetail_digital_clock_1_timer_enabled = false;
    ui->screen_meetingDetail_digital_clock_1 = lv_label_create(ui->screen_meetingDetail);
    lv_obj_set_pos(ui->screen_meetingDetail_digital_clock_1, 65, 135);
    lv_obj_set_size(ui->screen_meetingDetail_digital_clock_1, 230, 63);
    lv_label_set_text(ui->screen_meetingDetail_digital_clock_1, "11:25:50");
    if (!screen_meetingDetail_digital_clock_1_timer_enabled) {
        lv_timer_create(screen_meetingDetail_digital_clock_1_timer, 1000, NULL);
        screen_meetingDetail_digital_clock_1_timer_enabled = true;
    }

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
