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



int home_analog_analog_clock_1_hour_value = 3;
int home_analog_analog_clock_1_min_value = 20;
int home_analog_analog_clock_1_sec_value = 50;
void setup_scr_home_analog(lv_ui *ui)
{
    //Write codes home_analog
    ui->home_analog = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_analog, 360, 360);
    lv_obj_set_scrollbar_mode(ui->home_analog, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_analog, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->home_analog, &_img_bg_analog_RGB565A8_360x360, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->home_analog, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->home_analog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_battery_arc
    ui->home_analog_battery_arc = lv_arc_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_battery_arc, 35, 4);
    lv_obj_set_size(ui->home_analog_battery_arc, 300, 275);
    lv_arc_set_mode(ui->home_analog_battery_arc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->home_analog_battery_arc, 0, 100);
    lv_arc_set_bg_angles(ui->home_analog_battery_arc, 241, 300);
    lv_arc_set_value(ui->home_analog_battery_arc, 70);
    lv_arc_set_rotation(ui->home_analog_battery_arc, 0);

    //Write style for home_analog_battery_arc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->home_analog_battery_arc, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_analog_battery_arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_analog_battery_arc, lv_color_hex(0x8b8b8b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_analog_battery_arc, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_battery_arc, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_battery_arc, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_analog_battery_arc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->home_analog_battery_arc, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_analog_battery_arc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_analog_battery_arc, lv_color_hex(0x2200ff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_analog_battery_arc, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for home_analog_battery_arc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_battery_arc, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_analog_battery_arc, lv_color_hex(0x2200ff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_analog_battery_arc, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->home_analog_battery_arc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes home_analog_analog_clock_1
    static bool home_analog_analog_clock_1_timer_enabled = false;
    static const char * home_analog_analog_clock_1_hour_ticks[] = {"12", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", NULL};
    ui->home_analog_analog_clock_1 = lv_scale_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_analog_clock_1, 0, 0);
    lv_obj_set_size(ui->home_analog_analog_clock_1, 360, 360);
    lv_scale_set_mode(ui->home_analog_analog_clock_1, LV_SCALE_MODE_ROUND_INNER);
    lv_scale_set_angle_range(ui->home_analog_analog_clock_1, 360U);
    lv_scale_set_range(ui->home_analog_analog_clock_1, 0U, 60U);
    lv_scale_set_rotation(ui->home_analog_analog_clock_1, 270U);
    lv_obj_set_style_radius(ui->home_analog_analog_clock_1, LV_RADIUS_CIRCLE, LV_PART_MAIN);
    lv_obj_set_style_clip_corner(ui->home_analog_analog_clock_1, true, LV_PART_MAIN);
    lv_obj_set_style_arc_width(ui->home_analog_analog_clock_1, 0, LV_PART_MAIN);
    lv_scale_set_text_src(ui->home_analog_analog_clock_1, home_analog_analog_clock_1_hour_ticks);
    lv_obj_update_layout(ui->home_analog_analog_clock_1);
    ui->home_analog_analog_clock_1_hour_needle = lv_image_create(ui->home_analog_analog_clock_1);
    lv_image_set_src(ui->home_analog_analog_clock_1_hour_needle, &_img_clockwise_hour_RGB565A8_98x18);
    lv_obj_align(ui->home_analog_analog_clock_1_hour_needle, LV_ALIGN_CENTER, 49 - 0, 9 - 9);
    lv_image_set_pivot(ui->home_analog_analog_clock_1_hour_needle, 0, 9);
    lv_scale_set_image_needle_value(ui->home_analog_analog_clock_1, ui->home_analog_analog_clock_1_hour_needle, home_analog_analog_clock_1_hour_value * 5);
    ui->home_analog_analog_clock_1_min_needle = lv_image_create(ui->home_analog_analog_clock_1);
    lv_image_set_src(ui->home_analog_analog_clock_1_min_needle, &_img_clockwise_min_RGB565A8_157x18);
    lv_obj_align(ui->home_analog_analog_clock_1_min_needle, LV_ALIGN_CENTER, 79 - 0, 9 - 9);
    lv_image_set_pivot(ui->home_analog_analog_clock_1_min_needle, 0, 9);
    lv_scale_set_image_needle_value(ui->home_analog_analog_clock_1, ui->home_analog_analog_clock_1_min_needle, home_analog_analog_clock_1_min_value);
    ui->home_analog_analog_clock_1_sec_needle = lv_image_create(ui->home_analog_analog_clock_1);
    lv_image_set_src(ui->home_analog_analog_clock_1_sec_needle, &_img_clockwise_sec_RGB565A8_180x31);
    lv_obj_align(ui->home_analog_analog_clock_1_sec_needle, LV_ALIGN_CENTER, 90 - 23, 16 - 15);
    lv_image_set_pivot(ui->home_analog_analog_clock_1_sec_needle, 23, 15);
    lv_scale_set_image_needle_value(ui->home_analog_analog_clock_1, ui->home_analog_analog_clock_1_sec_needle, home_analog_analog_clock_1_sec_value);
    // create timer
    if (!home_analog_analog_clock_1_timer_enabled) {
        lv_timer_create(home_analog_analog_clock_1_timer, 1000, NULL);
        home_analog_analog_clock_1_timer_enabled = true;
    }

    //Write style for home_analog_analog_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_analog_analog_clock_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->home_analog_analog_clock_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_analog_clock_1, &lv_font_montserratMedium_14, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_analog_clock_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->home_analog_analog_clock_1, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->home_analog_analog_clock_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->home_analog_analog_clock_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->home_analog_analog_clock_1, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_length(ui->home_analog_analog_clock_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for home_analog_analog_clock_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->home_analog_analog_clock_1, 2, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->home_analog_analog_clock_1, lv_color_hex(0x000000), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->home_analog_analog_clock_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->home_analog_analog_clock_1, true, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_length(ui->home_analog_analog_clock_1, 6, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes home_analog_week_day
    ui->home_analog_week_day = lv_label_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_week_day, 147, 274);
    lv_obj_set_size(ui->home_analog_week_day, 66, 22);
    lv_label_set_text(ui->home_analog_week_day, "星期日");
    lv_label_set_long_mode(ui->home_analog_week_day, LV_LABEL_LONG_WRAP);

    //Write style for home_analog_week_day, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_week_day, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_week_day, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_week_day, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_week_day, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_date_text
    ui->home_analog_date_text = lv_label_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_date_text, 143, 249);
    lv_obj_set_size(ui->home_analog_date_text, 73, 19);
    lv_label_set_text(ui->home_analog_date_text, "01 / 18");
    lv_label_set_long_mode(ui->home_analog_date_text, LV_LABEL_LONG_WRAP);

    //Write style for home_analog_date_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_date_text, lv_color_hex(0x818181), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_date_text, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_date_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_date_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_battery_icon
    ui->home_analog_battery_icon = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_battery_icon, 155, 32);
    lv_obj_set_size(ui->home_analog_battery_icon, 15, 19);
    lv_obj_add_flag(ui->home_analog_battery_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_battery_icon, &_icn_flash_blue_RGB565A8_15x19);
    lv_image_set_pivot(ui->home_analog_battery_icon, 50,50);
    lv_image_set_rotation(ui->home_analog_battery_icon, 0);

    //Write style for home_analog_battery_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_battery_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_battery_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_battery_text
    ui->home_analog_battery_text = lv_label_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_battery_text, 175, 32);
    lv_obj_set_size(ui->home_analog_battery_text, 54, 19);
    lv_label_set_text(ui->home_analog_battery_text, "86%");
    lv_label_set_long_mode(ui->home_analog_battery_text, LV_LABEL_LONG_WRAP);

    //Write style for home_analog_battery_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_battery_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_battery_text, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_battery_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_battery_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of home_analog.


    //Update current screen layout.
    lv_obj_update_layout(ui->home_analog);

    //Init events for screen.
    events_init_home_analog(ui);
}
