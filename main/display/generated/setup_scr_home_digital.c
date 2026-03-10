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
#include "PCF85063.h"

void setup_scr_home_digital(lv_ui *ui)
{
    // Write codes home_digital
    ui->home_digital = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_digital, 360, 360);
    lv_obj_set_scrollbar_mode(ui->home_digital, LV_SCROLLBAR_MODE_OFF);

    // Write style for home_digital, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->home_digital, &_img_bg_digital_360x360, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->home_digital, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->home_digital, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_digital_arc_flash
    ui->home_digital_arc_flash = lv_arc_create(ui->home_digital);
    lv_arc_set_mode(ui->home_digital_arc_flash, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->home_digital_arc_flash, 0, 100);
    lv_arc_set_bg_angles(ui->home_digital_arc_flash, 238, 300);
    lv_arc_set_value(ui->home_digital_arc_flash, all_config.page_quickConfig.battery);
    lv_arc_set_rotation(ui->home_digital_arc_flash, 0);
    lv_obj_set_pos(ui->home_digital_arc_flash, 42, 4);
    lv_obj_set_size(ui->home_digital_arc_flash, 300, 275);

    // Write style for home_digital_arc_flash, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital_arc_flash, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->home_digital_arc_flash, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->home_digital_arc_flash, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_digital_arc_flash, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_digital_arc_flash, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_arc_flash, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_arc_flash, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_arc_flash, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_arc_flash, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_arc_flash, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_arc_flash, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for home_digital_arc_flash, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->home_digital_arc_flash, 12, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_digital_arc_flash, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_digital_arc_flash, lv_color_hex(0x1000ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style for home_digital_arc_flash, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital_arc_flash, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->home_digital_arc_flash, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write codes home_digital_label_week
    ui->home_digital_label_week = lv_label_create(ui->home_digital);
    lv_label_set_text(ui->home_digital_label_week, datetime.week_day);
    lv_label_set_long_mode(ui->home_digital_label_week, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_digital_label_week, 254, 191);
    lv_obj_set_size(ui->home_digital_label_week, 66, 22);

    // Write style for home_digital_label_week, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_week, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_week, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_week, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_week, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_week, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_week, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_digital_label_date
    ui->home_digital_label_date = lv_label_create(ui->home_digital);
    lv_label_set_text(ui->home_digital_label_date, datetime.date_str);
    lv_label_set_long_mode(ui->home_digital_label_date, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_digital_label_date, 250, 161);
    lv_obj_set_size(ui->home_digital_label_date, 73, 19);

    // Write style for home_digital_label_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_date, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_date, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_date, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_date, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_date, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_digital_img_flash
    ui->home_digital_img_flash = lv_img_create(ui->home_digital);
    lv_obj_add_flag(ui->home_digital_img_flash, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->home_digital_img_flash, &_icn_flash_blue_alpha_15x19);
    lv_img_set_pivot(ui->home_digital_img_flash, 50, 50);
    lv_img_set_angle(ui->home_digital_img_flash, 0);
    lv_obj_set_pos(ui->home_digital_img_flash, 135, 32);
    lv_obj_set_size(ui->home_digital_img_flash, 15, 19);

    // Write style for home_digital_img_flash, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->home_digital_img_flash, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->home_digital_img_flash, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_img_flash, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->home_digital_img_flash, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_digital_label_flashText
    ui->home_digital_label_flashText = lv_label_create(ui->home_digital);
    char battery_buf[20] = {0};
    snprintf(battery_buf, sizeof(battery_buf),
             "%d%%",
             all_config.page_quickConfig.battery);
    lv_label_set_text(ui->home_digital_label_flashText, battery_buf);
    lv_label_set_long_mode(ui->home_digital_label_flashText, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_digital_label_flashText, 160, 32);
    lv_obj_set_size(ui->home_digital_label_flashText, 65, 19);

    // Write style for home_digital_label_flashText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_flashText, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_flashText, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_flashText, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_flashText, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_flashText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_flashText, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_flashText, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_flashText, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_flashText, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_flashText, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_flashText, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_flashText, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_flashText, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_flashText, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_digital_img_dialDot
    ui->home_digital_img_dialDot = lv_img_create(ui->home_digital);
    lv_obj_add_flag(ui->home_digital_img_dialDot, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->home_digital_img_dialDot, &_img_menu_alpha_10x107);
    lv_img_set_pivot(ui->home_digital_img_dialDot, 50, 50);
    lv_img_set_angle(ui->home_digital_img_dialDot, 0);
    lv_obj_set_pos(ui->home_digital_img_dialDot, 335, 128);
    lv_obj_set_size(ui->home_digital_img_dialDot, 10, 107);

    // Write style for home_digital_img_dialDot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->home_digital_img_dialDot, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->home_digital_img_dialDot, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_img_dialDot, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->home_digital_img_dialDot, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_digital_label_min
    ui->home_digital_label_min = lv_label_create(ui->home_digital);
    char digital_hour[5] = {0}; // 初始化数组，避免脏数据
    char digital_minute[5] = {0};
    snprintf(digital_hour, sizeof(digital_hour), "%02d", datetime.hour);
    snprintf(digital_minute, sizeof(digital_minute), "%02d", datetime.minute);
    ESP_LOGI("digital", "hour:%s, minute:%s", digital_hour, digital_minute);
    lv_label_set_text(ui->home_digital_label_min, digital_minute);
    lv_label_set_long_mode(ui->home_digital_label_min, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_digital_label_min, 110, 366);
    lv_obj_set_size(ui->home_digital_label_min, 145, 95);

    // Write style for home_digital_label_min, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_min, lv_color_hex(0xFF4818), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_min, &lv_font_montserratMedium_101, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_min, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_min, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_min, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_min, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_digital_label_hour
    ui->home_digital_label_hour = lv_label_create(ui->home_digital);
    lv_label_set_text(ui->home_digital_label_hour, digital_hour);
    lv_label_set_long_mode(ui->home_digital_label_hour, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_digital_label_hour, 122, -118);
    lv_obj_set_size(ui->home_digital_label_hour, 145, 112);

    // Write style for home_digital_label_hour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_hour, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_hour, &lv_font_montserratMedium_110, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_hour, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_hour, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_hour, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_hour, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of home_digital.

    // Update current screen layout.
    lv_obj_update_layout(ui->home_digital);

    // Init events for screen.
    events_init_home_digital(ui);
}
