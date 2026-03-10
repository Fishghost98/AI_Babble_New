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

int home_analog_analog_clock_1_hour_value = 9;
int home_analog_analog_clock_1_min_value = 45;
int home_analog_analog_clock_1_sec_value = 45;
void setup_scr_home_analog(lv_ui *ui)
{
    // Write codes home_analog
    ui->home_analog = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_analog, 360, 360);
    lv_obj_set_scrollbar_mode(ui->home_analog, LV_SCROLLBAR_MODE_OFF);

    // Write style for home_analog, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->home_analog, &_img_bg_analog_360x360, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->home_analog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->home_analog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_analog_battery_arc
    ui->home_analog_battery_arc = lv_arc_create(ui->home_analog);
    lv_arc_set_mode(ui->home_analog_battery_arc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->home_analog_battery_arc, 0, 100);
    lv_arc_set_bg_angles(ui->home_analog_battery_arc, 238, 300);
    lv_arc_set_value(ui->home_analog_battery_arc, all_config.page_quickConfig.battery);
    lv_arc_set_rotation(ui->home_analog_battery_arc, 0);
    lv_obj_set_pos(ui->home_analog_battery_arc, 42, 4);
    lv_obj_set_size(ui->home_analog_battery_arc, 300, 275);

    // Write style for home_analog_battery_arc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_battery_arc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->home_analog_battery_arc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->home_analog_battery_arc, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_analog_battery_arc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_analog_battery_arc, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_battery_arc, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_battery_arc, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_battery_arc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_battery_arc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_battery_arc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_battery_arc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for home_analog_battery_arc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->home_analog_battery_arc, 12, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_analog_battery_arc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_analog_battery_arc, lv_color_hex(0x1000ff), LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style for home_analog_battery_arc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_battery_arc, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_analog_battery_arc, lv_color_hex(0x1000ff), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_analog_battery_arc, LV_GRAD_DIR_NONE, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->home_analog_battery_arc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write codes home_analog_analog_clock_1
    ui->home_analog_analog_clock_1 = lv_analogclock_create(ui->home_analog);
    lv_analogclock_hide_digits(ui->home_analog_analog_clock_1, true);
    lv_analogclock_hide_point(ui->home_analog_analog_clock_1, true);
    lv_analogclock_set_major_ticks(ui->home_analog_analog_clock_1, 2, 0, lv_color_hex(0x555555), 13);
    lv_analogclock_set_ticks(ui->home_analog_analog_clock_1, 6, 0, lv_color_hex(0x333333));
    lv_analogclock_set_hour_needle_img(ui->home_analog_analog_clock_1, &_img_clockwise_hour_alpha_98x18, 0, 9);
    lv_analogclock_set_min_needle_img(ui->home_analog_analog_clock_1, &_img_clockwise_min_alpha_157x18, 0, 9);
    lv_analogclock_set_sec_needle_img(ui->home_analog_analog_clock_1, &_img_clockwise_sec_alpha_180x31, 23, 15);
    lv_analogclock_set_time(ui->home_analog_analog_clock_1, datetime.hour, datetime.minute, datetime.second);

    lv_obj_set_pos(ui->home_analog_analog_clock_1, 0, 0);
    lv_obj_set_size(ui->home_analog_analog_clock_1, 360, 360);

    // Write style for home_analog_analog_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_analog_clock_1, 39, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_analog_analog_clock_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_analog_analog_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->home_analog_analog_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_analog_clock_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for home_analog_analog_clock_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->home_analog_analog_clock_1, lv_color_hex(0xff0000), LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_analog_clock_1, &lv_font_montserratMedium_11, LV_PART_TICKS | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_analog_clock_1, 255, LV_PART_TICKS | LV_STATE_DEFAULT);

    // Write style for home_analog_analog_clock_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_analog_clock_1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_analog_analog_clock_1, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_analog_analog_clock_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write codes home_analog_week_day
    ui->home_analog_week_day = lv_label_create(ui->home_analog);
    lv_label_set_text(ui->home_analog_week_day, datetime.week_day);
    lv_label_set_long_mode(ui->home_analog_week_day, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_analog_week_day, 147, 274);
    lv_obj_set_size(ui->home_analog_week_day, 66, 22);

    // Write style for home_analog_week_day, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_week_day, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_week_day, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_week_day, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_week_day, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_week_day, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_week_day, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_week_day, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_week_day, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_week_day, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_week_day, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_week_day, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_week_day, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_week_day, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_week_day, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_analog_date_text
    ui->home_analog_date_text = lv_label_create(ui->home_analog);
    lv_label_set_text(ui->home_analog_date_text, datetime.date_str);
    lv_label_set_long_mode(ui->home_analog_date_text, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_analog_date_text, 143, 249);
    lv_obj_set_size(ui->home_analog_date_text, 73, 19);

    // Write style for home_analog_date_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_date_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_date_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_date_text, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_date_text, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_date_text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_date_text, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_date_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_date_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_date_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_date_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_date_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_date_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_date_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_date_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_analog_battery_icon
    ui->home_analog_battery_icon = lv_img_create(ui->home_analog);
    lv_obj_add_flag(ui->home_analog_battery_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->home_analog_battery_icon, &_icn_flash_blue_alpha_15x19);
    lv_img_set_pivot(ui->home_analog_battery_icon, 50, 50);
    lv_img_set_angle(ui->home_analog_battery_icon, 0);
    lv_obj_set_pos(ui->home_analog_battery_icon, 135, 32);
    lv_obj_set_size(ui->home_analog_battery_icon, 15, 19);

    // Write style for home_analog_battery_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->home_analog_battery_icon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->home_analog_battery_icon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_battery_icon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->home_analog_battery_icon, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes home_analog_battery_text
    ui->home_analog_battery_text = lv_label_create(ui->home_analog);
    char battery_buf[20] = {0};
    snprintf(battery_buf, sizeof(battery_buf),
             "%d%%",
             all_config.page_quickConfig.battery);
    lv_label_set_text(ui->home_analog_battery_text, battery_buf);
    lv_label_set_long_mode(ui->home_analog_battery_text, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_analog_battery_text, 160, 32);
    lv_obj_set_size(ui->home_analog_battery_text, 65, 19);
    lv_obj_add_flag(ui->home_analog_battery_text, LV_OBJ_FLAG_CLICKABLE);

    // Write style for home_analog_battery_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_battery_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_battery_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_battery_text, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_battery_text, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_battery_text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_battery_text, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_battery_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_battery_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_battery_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_battery_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_battery_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_battery_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_battery_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_battery_text, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of home_analog.

    // Update current screen layout.
    lv_obj_update_layout(ui->home_analog);

    // Init events for screen.
    events_init_home_analog(ui);
}
