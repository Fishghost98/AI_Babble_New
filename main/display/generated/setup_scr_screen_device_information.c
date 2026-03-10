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



void setup_scr_screen_device_information(lv_ui *ui)
{
    //Write codes screen_device_information
    ui->screen_device_information = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_device_information, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_device_information, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_device_information, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_device_information, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_device_information, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->screen_device_information, &_bk2_360x360, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->screen_device_information, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->screen_device_information, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_1
    ui->screen_device_information_label_1 = lv_label_create(ui->screen_device_information);
    lv_label_set_text(ui->screen_device_information_label_1, "关于本机");
    lv_label_set_long_mode(ui->screen_device_information_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_1, 132, 25);
    lv_obj_set_size(ui->screen_device_information_label_1, 100, 20);

    //Write style for screen_device_information_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_cont_1
    ui->screen_device_information_cont_1 = lv_obj_create(ui->screen_device_information);
    lv_obj_set_pos(ui->screen_device_information_cont_1, 30, 80);
    lv_obj_set_size(ui->screen_device_information_cont_1, 300, 267);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_cont_2
    ui->screen_device_information_cont_2 = lv_obj_create(ui->screen_device_information_cont_1);
    lv_obj_set_pos(ui->screen_device_information_cont_2, 0, 0);
    lv_obj_set_size(ui->screen_device_information_cont_2, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_1
    ui->screen_device_information_img_1 = lv_img_create(ui->screen_device_information_cont_2);
    lv_obj_add_flag(ui->screen_device_information_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_device_information_img_1, &_Frame1_alpha_40x40);
    lv_img_set_pivot(ui->screen_device_information_img_1, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_1, 0);
    lv_obj_set_pos(ui->screen_device_information_img_1, 75, 5);
    lv_obj_set_size(ui->screen_device_information_img_1, 40, 40);

    //Write style for screen_device_information_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_2
    ui->screen_device_information_label_2 = lv_label_create(ui->screen_device_information_cont_2);
    lv_label_set_text(ui->screen_device_information_label_2, "设备名称");
    lv_label_set_long_mode(ui->screen_device_information_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_2, 126, 12);
    lv_obj_set_size(ui->screen_device_information_label_2, 100, 25);

    //Write style for screen_device_information_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_2, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_3
    ui->screen_device_information_label_3 = lv_label_create(ui->screen_device_information_cont_2);
    lv_label_set_text(ui->screen_device_information_label_3, "这是设备名称");
    lv_label_set_long_mode(ui->screen_device_information_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_3, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_3, 300, 25);

    //Write style for screen_device_information_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_3, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_3, 177, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_2
    ui->screen_device_information_img_2 = lv_img_create(ui->screen_device_information_cont_2);
    lv_obj_add_flag(ui->screen_device_information_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_pivot(ui->screen_device_information_img_2, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_2, 0);
    lv_obj_set_pos(ui->screen_device_information_img_2, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_2, 300, 2);

    //Write style for screen_device_information_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->screen_device_information_img_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_cont_3
    ui->screen_device_information_cont_3 = lv_obj_create(ui->screen_device_information_cont_1);
    lv_obj_set_pos(ui->screen_device_information_cont_3, 0, 366);
    lv_obj_set_size(ui->screen_device_information_cont_3, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_4
    ui->screen_device_information_img_4 = lv_img_create(ui->screen_device_information_cont_3);
    lv_obj_add_flag(ui->screen_device_information_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_device_information_img_4, &_Frame4_alpha_40x40);
    lv_img_set_pivot(ui->screen_device_information_img_4, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_4, 0);
    lv_obj_set_pos(ui->screen_device_information_img_4, 75, 5);
    lv_obj_set_size(ui->screen_device_information_img_4, 40, 40);

    //Write style for screen_device_information_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_device_information_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_5
    ui->screen_device_information_label_5 = lv_label_create(ui->screen_device_information_cont_3);
    lv_label_set_text(ui->screen_device_information_label_5, "设备ID");
    lv_label_set_long_mode(ui->screen_device_information_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_5, 126, 12);
    lv_obj_set_size(ui->screen_device_information_label_5, 100, 25);

    //Write style for screen_device_information_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_5, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_4
    ui->screen_device_information_label_4 = lv_label_create(ui->screen_device_information_cont_3);
    lv_label_set_text(ui->screen_device_information_label_4, "552365");
    lv_label_set_long_mode(ui->screen_device_information_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_4, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_4, 300, 25);

    //Write style for screen_device_information_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_4, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_4, 193, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_3
    ui->screen_device_information_img_3 = lv_img_create(ui->screen_device_information_cont_3);
    lv_obj_add_flag(ui->screen_device_information_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_pivot(ui->screen_device_information_img_3, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_3, 0);
    lv_obj_set_pos(ui->screen_device_information_img_3, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_3, 300, 2);

    //Write style for screen_device_information_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_device_information_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->screen_device_information_img_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_cont_4
    ui->screen_device_information_cont_4 = lv_obj_create(ui->screen_device_information_cont_1);
    lv_obj_set_pos(ui->screen_device_information_cont_4, 0, 244);
    lv_obj_set_size(ui->screen_device_information_cont_4, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_6
    ui->screen_device_information_img_6 = lv_img_create(ui->screen_device_information_cont_4);
    lv_obj_add_flag(ui->screen_device_information_img_6, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_device_information_img_6, &_Frame3_alpha_40x40);
    lv_img_set_pivot(ui->screen_device_information_img_6, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_6, 0);
    lv_obj_set_pos(ui->screen_device_information_img_6, 75, 5);
    lv_obj_set_size(ui->screen_device_information_img_6, 40, 40);

    //Write style for screen_device_information_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_7
    ui->screen_device_information_label_7 = lv_label_create(ui->screen_device_information_cont_4);
    lv_label_set_text(ui->screen_device_information_label_7, "更新日期");
    lv_label_set_long_mode(ui->screen_device_information_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_7, 126, 12);
    lv_obj_set_size(ui->screen_device_information_label_7, 100, 25);

    //Write style for screen_device_information_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_7, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_6
    ui->screen_device_information_label_6 = lv_label_create(ui->screen_device_information_cont_4);
    lv_label_set_text(ui->screen_device_information_label_6, "2026.1.15");
    lv_label_set_long_mode(ui->screen_device_information_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_6, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_6, 300, 25);

    //Write style for screen_device_information_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_6, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_6, 199, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_5
    ui->screen_device_information_img_5 = lv_img_create(ui->screen_device_information_cont_4);
    lv_obj_add_flag(ui->screen_device_information_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_pivot(ui->screen_device_information_img_5, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_5, 0);
    lv_obj_set_pos(ui->screen_device_information_img_5, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_5, 300, 2);

    //Write style for screen_device_information_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->screen_device_information_img_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_cont_5
    ui->screen_device_information_cont_5 = lv_obj_create(ui->screen_device_information_cont_1);
    lv_obj_set_pos(ui->screen_device_information_cont_5, 0, 122);
    lv_obj_set_size(ui->screen_device_information_cont_5, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_5, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_8
    ui->screen_device_information_img_8 = lv_img_create(ui->screen_device_information_cont_5);
    lv_obj_add_flag(ui->screen_device_information_img_8, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_device_information_img_8, &_Frame2_alpha_40x40);
    lv_img_set_pivot(ui->screen_device_information_img_8, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_8, 0);
    lv_obj_set_pos(ui->screen_device_information_img_8, 75, 5);
    lv_obj_set_size(ui->screen_device_information_img_8, 40, 40);

    //Write style for screen_device_information_img_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_9
    ui->screen_device_information_label_9 = lv_label_create(ui->screen_device_information_cont_5);
    lv_label_set_text(ui->screen_device_information_label_9, "软件版本");
    lv_label_set_long_mode(ui->screen_device_information_label_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_9, 126, 12);
    lv_obj_set_size(ui->screen_device_information_label_9, 100, 25);

    //Write style for screen_device_information_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_9, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_8
    ui->screen_device_information_label_8 = lv_label_create(ui->screen_device_information_cont_5);
    lv_label_set_text(ui->screen_device_information_label_8, "1.42.0258");
    lv_label_set_long_mode(ui->screen_device_information_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_8, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_8, 300, 25);

    //Write style for screen_device_information_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_8, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_8, 199, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_7
    ui->screen_device_information_img_7 = lv_img_create(ui->screen_device_information_cont_5);
    lv_obj_add_flag(ui->screen_device_information_img_7, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_pivot(ui->screen_device_information_img_7, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_7, 0);
    lv_obj_set_pos(ui->screen_device_information_img_7, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_7, 300, 2);

    //Write style for screen_device_information_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->screen_device_information_img_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_cont_6
    ui->screen_device_information_cont_6 = lv_obj_create(ui->screen_device_information_cont_1);
    lv_obj_set_pos(ui->screen_device_information_cont_6, 0, 488);
    lv_obj_set_size(ui->screen_device_information_cont_6, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_6, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_10
    ui->screen_device_information_img_10 = lv_img_create(ui->screen_device_information_cont_6);
    lv_obj_add_flag(ui->screen_device_information_img_10, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_device_information_img_10, &_Frame5_alpha_40x40);
    lv_img_set_pivot(ui->screen_device_information_img_10, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_10, 0);
    lv_obj_set_pos(ui->screen_device_information_img_10, 75, 6);
    lv_obj_set_size(ui->screen_device_information_img_10, 40, 40);

    //Write style for screen_device_information_img_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_device_information_img_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_10, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_11
    ui->screen_device_information_label_11 = lv_label_create(ui->screen_device_information_cont_6);
    lv_label_set_text(ui->screen_device_information_label_11, "MAC地址");
    lv_label_set_long_mode(ui->screen_device_information_label_11, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_11, 126, 13);
    lv_obj_set_size(ui->screen_device_information_label_11, 120, 25);

    //Write style for screen_device_information_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_11, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_10
    ui->screen_device_information_label_10 = lv_label_create(ui->screen_device_information_cont_6);
    lv_label_set_text(ui->screen_device_information_label_10, "DE:D4:F5:H3:V1");
    lv_label_set_long_mode(ui->screen_device_information_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_device_information_label_10, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_10, 300, 25);

    //Write style for screen_device_information_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_10, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_10, 198, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_9
    ui->screen_device_information_img_9 = lv_img_create(ui->screen_device_information_cont_6);
    lv_obj_add_flag(ui->screen_device_information_img_9, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_pivot(ui->screen_device_information_img_9, 50,50);
    lv_img_set_angle(ui->screen_device_information_img_9, 0);
    lv_obj_set_pos(ui->screen_device_information_img_9, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_9, 300, 2);

    //Write style for screen_device_information_img_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_device_information_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_device_information_img_9, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_device_information_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->screen_device_information_img_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_device_information_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_device_information.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_device_information);

    //Init events for screen.
    events_init_screen_device_information(ui);
}
