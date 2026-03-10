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

    //Write codes screen_device_information_cont_3
    ui->screen_device_information_cont_3 = lv_obj_create(ui->screen_device_information);
    lv_obj_set_pos(ui->screen_device_information_cont_3, 30, 80);
    lv_obj_set_size(ui->screen_device_information_cont_3, 300, 267);
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

    //Write codes screen_device_information_cont_10
    ui->screen_device_information_cont_10 = lv_obj_create(ui->screen_device_information_cont_3);
    lv_obj_set_pos(ui->screen_device_information_cont_10, 0, 0);
    lv_obj_set_size(ui->screen_device_information_cont_10, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_10, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_10, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_10, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_10
    ui->screen_device_information_img_10 = lv_image_create(ui->screen_device_information_cont_10);
    lv_obj_set_pos(ui->screen_device_information_img_10, 75, 5);
    lv_obj_set_size(ui->screen_device_information_img_10, 40, 40);
    lv_obj_add_flag(ui->screen_device_information_img_10, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_device_information_img_10, &_Frame1_RGB565A8_40x40);
    lv_image_set_pivot(ui->screen_device_information_img_10, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_10, 0);

    //Write style for screen_device_information_img_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_7
    ui->screen_device_information_label_7 = lv_label_create(ui->screen_device_information_cont_10);
    lv_obj_set_pos(ui->screen_device_information_label_7, 126, 12);
    lv_obj_set_size(ui->screen_device_information_label_7, 100, 25);
    lv_label_set_text(ui->screen_device_information_label_7, "设备名称");
    lv_label_set_long_mode(ui->screen_device_information_label_7, LV_LABEL_LONG_WRAP);

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

    //Write codes screen_device_information_img_9
    ui->screen_device_information_img_9 = lv_image_create(ui->screen_device_information_cont_10);
    lv_obj_set_pos(ui->screen_device_information_img_9, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_9, 300, 2);
    lv_obj_add_flag(ui->screen_device_information_img_9, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_pivot(ui->screen_device_information_img_9, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_9, 0);

    //Write style for screen_device_information_img_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->screen_device_information_img_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_8
    ui->screen_device_information_label_8 = lv_label_create(ui->screen_device_information_cont_10);
    lv_obj_set_pos(ui->screen_device_information_label_8, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_8, 300, 25);
    lv_label_set_text(ui->screen_device_information_label_8, "这是设备名称");
    lv_label_set_long_mode(ui->screen_device_information_label_8, LV_LABEL_LONG_WRAP);

    //Write style for screen_device_information_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_8, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_8, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_cont_11
    ui->screen_device_information_cont_11 = lv_obj_create(ui->screen_device_information_cont_3);
    lv_obj_set_pos(ui->screen_device_information_cont_11, 0, 122);
    lv_obj_set_size(ui->screen_device_information_cont_11, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_11, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_11, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_11, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_12
    ui->screen_device_information_img_12 = lv_image_create(ui->screen_device_information_cont_11);
    lv_obj_set_pos(ui->screen_device_information_img_12, 75, 5);
    lv_obj_set_size(ui->screen_device_information_img_12, 40, 40);
    lv_obj_add_flag(ui->screen_device_information_img_12, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_device_information_img_12, &_Frame2_RGB565A8_40x40);
    lv_image_set_pivot(ui->screen_device_information_img_12, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_12, 0);

    //Write style for screen_device_information_img_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_10
    ui->screen_device_information_label_10 = lv_label_create(ui->screen_device_information_cont_11);
    lv_obj_set_pos(ui->screen_device_information_label_10, 126, 12);
    lv_obj_set_size(ui->screen_device_information_label_10, 100, 25);
    lv_label_set_text(ui->screen_device_information_label_10, "软件版本");
    lv_label_set_long_mode(ui->screen_device_information_label_10, LV_LABEL_LONG_WRAP);

    //Write style for screen_device_information_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_10, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_11
    ui->screen_device_information_img_11 = lv_image_create(ui->screen_device_information_cont_11);
    lv_obj_set_pos(ui->screen_device_information_img_11, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_11, 300, 2);
    lv_obj_add_flag(ui->screen_device_information_img_11, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_pivot(ui->screen_device_information_img_11, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_11, 0);

    //Write style for screen_device_information_img_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->screen_device_information_img_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_9
    ui->screen_device_information_label_9 = lv_label_create(ui->screen_device_information_cont_11);
    lv_obj_set_pos(ui->screen_device_information_label_9, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_9, 300, 25);
    lv_label_set_text(ui->screen_device_information_label_9, "1.42.0258");
    lv_label_set_long_mode(ui->screen_device_information_label_9, LV_LABEL_LONG_WRAP);

    //Write style for screen_device_information_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_9, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_9, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes screen_device_information_cont_12
    ui->screen_device_information_cont_12 = lv_obj_create(ui->screen_device_information_cont_3);
    lv_obj_set_pos(ui->screen_device_information_cont_12, 0, 244);
    lv_obj_set_size(ui->screen_device_information_cont_12, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_12, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_12, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_12, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_14
    ui->screen_device_information_img_14 = lv_image_create(ui->screen_device_information_cont_12);
    lv_obj_set_pos(ui->screen_device_information_img_14, 75, 5);
    lv_obj_set_size(ui->screen_device_information_img_14, 40, 40);
    lv_obj_add_flag(ui->screen_device_information_img_14, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_device_information_img_14, &_Frame3_RGB565A8_40x40);
    lv_image_set_pivot(ui->screen_device_information_img_14, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_14, 0);

    //Write style for screen_device_information_img_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_12
    ui->screen_device_information_label_12 = lv_label_create(ui->screen_device_information_cont_12);
    lv_obj_set_pos(ui->screen_device_information_label_12, 126, 12);
    lv_obj_set_size(ui->screen_device_information_label_12, 100, 25);
    lv_label_set_text(ui->screen_device_information_label_12, "更新日期");
    lv_label_set_long_mode(ui->screen_device_information_label_12, LV_LABEL_LONG_WRAP);

    //Write style for screen_device_information_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_12, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_13
    ui->screen_device_information_img_13 = lv_image_create(ui->screen_device_information_cont_12);
    lv_obj_set_pos(ui->screen_device_information_img_13, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_13, 300, 2);
    lv_obj_add_flag(ui->screen_device_information_img_13, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_pivot(ui->screen_device_information_img_13, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_13, 0);

    //Write style for screen_device_information_img_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->screen_device_information_img_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_11
    ui->screen_device_information_label_11 = lv_label_create(ui->screen_device_information_cont_12);
    lv_obj_set_pos(ui->screen_device_information_label_11, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_11, 300, 25);
    lv_label_set_text(ui->screen_device_information_label_11, "2026.1.15");
    lv_label_set_long_mode(ui->screen_device_information_label_11, LV_LABEL_LONG_WRAP);

    //Write style for screen_device_information_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_11, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_11, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes screen_device_information_cont_13
    ui->screen_device_information_cont_13 = lv_obj_create(ui->screen_device_information_cont_3);
    lv_obj_set_pos(ui->screen_device_information_cont_13, 0, 366);
    lv_obj_set_size(ui->screen_device_information_cont_13, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_13, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_13, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_13, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_13, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_16
    ui->screen_device_information_img_16 = lv_image_create(ui->screen_device_information_cont_13);
    lv_obj_set_pos(ui->screen_device_information_img_16, 75, 5);
    lv_obj_set_size(ui->screen_device_information_img_16, 40, 40);
    lv_obj_add_flag(ui->screen_device_information_img_16, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_device_information_img_16, &_Frame4_RGB565A8_40x40);
    lv_image_set_pivot(ui->screen_device_information_img_16, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_16, 0);

    //Write style for screen_device_information_img_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_14
    ui->screen_device_information_label_14 = lv_label_create(ui->screen_device_information_cont_13);
    lv_obj_set_pos(ui->screen_device_information_label_14, 126, 12);
    lv_obj_set_size(ui->screen_device_information_label_14, 100, 25);
    lv_label_set_text(ui->screen_device_information_label_14, "设备ID");
    lv_label_set_long_mode(ui->screen_device_information_label_14, LV_LABEL_LONG_WRAP);

    //Write style for screen_device_information_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_14, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_15
    ui->screen_device_information_img_15 = lv_image_create(ui->screen_device_information_cont_13);
    lv_obj_set_pos(ui->screen_device_information_img_15, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_15, 300, 2);
    lv_obj_add_flag(ui->screen_device_information_img_15, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_pivot(ui->screen_device_information_img_15, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_15, 0);

    //Write style for screen_device_information_img_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->screen_device_information_img_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_13
    ui->screen_device_information_label_13 = lv_label_create(ui->screen_device_information_cont_13);
    lv_obj_set_pos(ui->screen_device_information_label_13, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_13, 300, 25);
    lv_label_set_text(ui->screen_device_information_label_13, "552365");
    lv_label_set_long_mode(ui->screen_device_information_label_13, LV_LABEL_LONG_WRAP);

    //Write style for screen_device_information_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_13, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_13, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_cont_14
    ui->screen_device_information_cont_14 = lv_obj_create(ui->screen_device_information_cont_3);
    lv_obj_set_pos(ui->screen_device_information_cont_14, 0, 488);
    lv_obj_set_size(ui->screen_device_information_cont_14, 300, 100);
    lv_obj_set_scrollbar_mode(ui->screen_device_information_cont_14, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_device_information_cont_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_cont_14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_device_information_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_device_information_cont_14, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_device_information_cont_14, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_18
    ui->screen_device_information_img_18 = lv_image_create(ui->screen_device_information_cont_14);
    lv_obj_set_pos(ui->screen_device_information_img_18, 75, 5);
    lv_obj_set_size(ui->screen_device_information_img_18, 40, 40);
    lv_obj_add_flag(ui->screen_device_information_img_18, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_device_information_img_18, &_Frame5_RGB565A8_40x40);
    lv_image_set_pivot(ui->screen_device_information_img_18, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_18, 0);

    //Write style for screen_device_information_img_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_16
    ui->screen_device_information_label_16 = lv_label_create(ui->screen_device_information_cont_14);
    lv_obj_set_pos(ui->screen_device_information_label_16, 126, 12);
    lv_obj_set_size(ui->screen_device_information_label_16, 100, 25);
    lv_label_set_text(ui->screen_device_information_label_16, "MAC地址");
    lv_label_set_long_mode(ui->screen_device_information_label_16, LV_LABEL_LONG_WRAP);

    //Write style for screen_device_information_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_16, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_16, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_img_17
    ui->screen_device_information_img_17 = lv_image_create(ui->screen_device_information_cont_14);
    lv_obj_set_pos(ui->screen_device_information_img_17, -1, 90);
    lv_obj_set_size(ui->screen_device_information_img_17, 300, 2);
    lv_obj_add_flag(ui->screen_device_information_img_17, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_pivot(ui->screen_device_information_img_17, 50,50);
    lv_image_set_rotation(ui->screen_device_information_img_17, 0);

    //Write style for screen_device_information_img_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_device_information_img_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->screen_device_information_img_17, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_device_information_img_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_15
    ui->screen_device_information_label_15 = lv_label_create(ui->screen_device_information_cont_14);
    lv_obj_set_pos(ui->screen_device_information_label_15, 0, 55);
    lv_obj_set_size(ui->screen_device_information_label_15, 300, 25);
    lv_label_set_text(ui->screen_device_information_label_15, "DE:D4:F5:H3:V1");
    lv_label_set_long_mode(ui->screen_device_information_label_15, LV_LABEL_LONG_WRAP);

    //Write style for screen_device_information_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_device_information_label_15, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_device_information_label_15, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_device_information_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_device_information_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_device_information_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_device_information_label_1
    ui->screen_device_information_label_1 = lv_label_create(ui->screen_device_information);
    lv_obj_set_pos(ui->screen_device_information_label_1, 130, 25);
    lv_obj_set_size(ui->screen_device_information_label_1, 100, 20);
    lv_label_set_text(ui->screen_device_information_label_1, "关于本机");
    lv_label_set_long_mode(ui->screen_device_information_label_1, LV_LABEL_LONG_WRAP);

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

    //The custom code of screen_device_information.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_device_information);

    //Init events for screen.
    events_init_screen_device_information(ui);
}
