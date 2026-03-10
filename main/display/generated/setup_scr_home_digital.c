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



void setup_scr_home_digital(lv_ui *ui)
{
    //Write codes home_digital
    ui->home_digital = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_digital, 360, 360);
    lv_obj_set_scrollbar_mode(ui->home_digital, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_digital, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->home_digital, &_img_bg_digital_RGB565A8_360x360, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->home_digital, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->home_digital, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_battery_arc
    ui->home_digital_battery_arc = lv_arc_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_battery_arc, 35, 4);
    lv_obj_set_size(ui->home_digital_battery_arc, 300, 275);
    lv_arc_set_mode(ui->home_digital_battery_arc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->home_digital_battery_arc, 0, 100);
    lv_arc_set_bg_angles(ui->home_digital_battery_arc, 241, 300);
    lv_arc_set_value(ui->home_digital_battery_arc, 70);
    lv_arc_set_rotation(ui->home_digital_battery_arc, 0);

    //Write style for home_digital_battery_arc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->home_digital_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->home_digital_battery_arc, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_digital_battery_arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_digital_battery_arc, lv_color_hex(0x8b8b8b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_digital_battery_arc, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_battery_arc, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_battery_arc, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_digital_battery_arc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->home_digital_battery_arc, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_digital_battery_arc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_digital_battery_arc, lv_color_hex(0x2200ff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_digital_battery_arc, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for home_digital_battery_arc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital_battery_arc, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_digital_battery_arc, lv_color_hex(0x2200ff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_digital_battery_arc, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->home_digital_battery_arc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes home_digital_week_day
    ui->home_digital_week_day = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_week_day, 254, 191);
    lv_obj_set_size(ui->home_digital_week_day, 66, 22);
    lv_label_set_text(ui->home_digital_week_day, "星期日");
    lv_label_set_long_mode(ui->home_digital_week_day, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_week_day, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_week_day, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_week_day, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_week_day, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_week_day, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_date_text
    ui->home_digital_date_text = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_date_text, 250, 161);
    lv_obj_set_size(ui->home_digital_date_text, 73, 19);
    lv_label_set_text(ui->home_digital_date_text, "01 / 18");
    lv_label_set_long_mode(ui->home_digital_date_text, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_date_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_date_text, lv_color_hex(0x818181), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_date_text, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_date_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_date_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_battery_icon
    ui->home_digital_battery_icon = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_battery_icon, 155, 32);
    lv_obj_set_size(ui->home_digital_battery_icon, 15, 19);
    lv_obj_add_flag(ui->home_digital_battery_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_battery_icon, &_icn_flash_blue_RGB565A8_15x19);
    lv_image_set_pivot(ui->home_digital_battery_icon, 50,50);
    lv_image_set_rotation(ui->home_digital_battery_icon, 0);

    //Write style for home_digital_battery_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_battery_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_battery_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_battery_text
    ui->home_digital_battery_text = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_battery_text, 175, 32);
    lv_obj_set_size(ui->home_digital_battery_text, 54, 19);
    lv_label_set_text(ui->home_digital_battery_text, "86%");
    lv_label_set_long_mode(ui->home_digital_battery_text, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_battery_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_battery_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_battery_text, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_battery_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_battery_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_1
    ui->home_digital_img_1 = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_1, 335, 128);
    lv_obj_set_size(ui->home_digital_img_1, 10, 127);
    lv_obj_add_flag(ui->home_digital_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_pivot(ui->home_digital_img_1, 50,50);
    lv_image_set_rotation(ui->home_digital_img_1, 0);

    //Write style for home_digital_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_min
    ui->home_digital_label_min = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_label_min, 110, 366);
    lv_obj_set_size(ui->home_digital_label_min, 139, 95);
    lv_label_set_text(ui->home_digital_label_min, "39");
    lv_label_set_long_mode(ui->home_digital_label_min, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_label_min, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_min, lv_color_hex(0xff4818), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_min, &lv_font_montserratMedium_101, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_min, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_min, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_hour
    ui->home_digital_label_hour = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_label_hour, 122, -118);
    lv_obj_set_size(ui->home_digital_label_hour, 141, 112);
    lv_label_set_text(ui->home_digital_label_hour, "21");
    lv_label_set_long_mode(ui->home_digital_label_hour, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_label_hour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_hour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_hour, &lv_font_montserratMedium_110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_hour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_hour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of home_digital.


    //Update current screen layout.
    lv_obj_update_layout(ui->home_digital);

    //Init events for screen.
    events_init_home_digital(ui);
}
