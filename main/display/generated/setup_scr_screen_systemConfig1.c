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



void setup_scr_screen_systemConfig1(lv_ui *ui)
{
    //Write codes screen_systemConfig1
    ui->screen_systemConfig1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_systemConfig1, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_systemConfig1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_systemConfig1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_cont_9
    ui->screen_systemConfig1_cont_9 = lv_obj_create(ui->screen_systemConfig1);
    lv_obj_set_pos(ui->screen_systemConfig1_cont_9, 2, 57);
    lv_obj_set_size(ui->screen_systemConfig1_cont_9, 356, 280);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1_cont_9, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1_cont_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_cont_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_systemConfig1_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_systemConfig1_cont_9, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_systemConfig1_cont_9, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_cont_7
    ui->screen_systemConfig1_cont_7 = lv_obj_create(ui->screen_systemConfig1_cont_9);
    lv_obj_set_pos(ui->screen_systemConfig1_cont_7, 20, 319);
    lv_obj_set_size(ui->screen_systemConfig1_cont_7, 320, 95);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1_cont_7, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1_cont_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_systemConfig1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_systemConfig1_cont_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_systemConfig1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_systemConfig1_cont_7, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_systemConfig1_cont_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_img_8
    ui->screen_systemConfig1_img_8 = lv_img_create(ui->screen_systemConfig1_cont_7);
    lv_obj_add_flag(ui->screen_systemConfig1_img_8, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_systemConfig1_img_8, &_g3_alpha_70x70);
    lv_img_set_pivot(ui->screen_systemConfig1_img_8, 50,50);
    lv_img_set_angle(ui->screen_systemConfig1_img_8, 0);
    lv_obj_set_pos(ui->screen_systemConfig1_img_8, 6, 9);
    lv_obj_set_size(ui->screen_systemConfig1_img_8, 70, 70);

    //Write style for screen_systemConfig1_img_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_systemConfig1_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_systemConfig1_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_systemConfig1_img_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_label_6
    ui->screen_systemConfig1_label_6 = lv_label_create(ui->screen_systemConfig1_cont_7);
    lv_label_set_text(ui->screen_systemConfig1_label_6, "关于本机");
    lv_label_set_long_mode(ui->screen_systemConfig1_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_systemConfig1_label_6, 110, 30);
    lv_obj_set_size(ui->screen_systemConfig1_label_6, 120, 28);

    //Write style for screen_systemConfig1_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_systemConfig1_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_systemConfig1_label_6, &lv_font_ZiTiQuanWeiJunHeiW22_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_systemConfig1_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_systemConfig1_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_img_7
    ui->screen_systemConfig1_img_7 = lv_img_create(ui->screen_systemConfig1_cont_7);
    lv_obj_add_flag(ui->screen_systemConfig1_img_7, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_systemConfig1_img_7, &_right1_alpha_25x25);
    lv_img_set_pivot(ui->screen_systemConfig1_img_7, 50,50);
    lv_img_set_angle(ui->screen_systemConfig1_img_7, 0);
    lv_obj_set_pos(ui->screen_systemConfig1_img_7, 260, 32);
    lv_obj_set_size(ui->screen_systemConfig1_img_7, 25, 25);

    //Write style for screen_systemConfig1_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_systemConfig1_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_systemConfig1_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_systemConfig1_img_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_cont_8
    ui->screen_systemConfig1_cont_8 = lv_obj_create(ui->screen_systemConfig1_cont_7);
    lv_obj_set_pos(ui->screen_systemConfig1_cont_8, 0, 2);
    lv_obj_set_size(ui->screen_systemConfig1_cont_8, 310, 85);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1_cont_8, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1_cont_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_cont_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_systemConfig1_cont_8, 89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_systemConfig1_cont_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_systemConfig1_cont_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_cont_8, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_cont_5
    ui->screen_systemConfig1_cont_5 = lv_obj_create(ui->screen_systemConfig1_cont_9);
    lv_obj_set_pos(ui->screen_systemConfig1_cont_5, 20, 113);
    lv_obj_set_size(ui->screen_systemConfig1_cont_5, 320, 95);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1_cont_5, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_cont_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_systemConfig1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_systemConfig1_cont_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_systemConfig1_cont_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_img_6
    ui->screen_systemConfig1_img_6 = lv_img_create(ui->screen_systemConfig1_cont_5);
    lv_obj_add_flag(ui->screen_systemConfig1_img_6, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_systemConfig1_img_6, &_g2_alpha_70x70);
    lv_img_set_pivot(ui->screen_systemConfig1_img_6, 50,50);
    lv_img_set_angle(ui->screen_systemConfig1_img_6, 0);
    lv_obj_set_pos(ui->screen_systemConfig1_img_6, 6, 9);
    lv_obj_set_size(ui->screen_systemConfig1_img_6, 70, 70);

    //Write style for screen_systemConfig1_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_systemConfig1_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_systemConfig1_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_systemConfig1_img_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_label_5
    ui->screen_systemConfig1_label_5 = lv_label_create(ui->screen_systemConfig1_cont_5);
    lv_label_set_text(ui->screen_systemConfig1_label_5, "使用说明");
    lv_label_set_long_mode(ui->screen_systemConfig1_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_systemConfig1_label_5, 110, 30);
    lv_obj_set_size(ui->screen_systemConfig1_label_5, 120, 28);

    //Write style for screen_systemConfig1_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_systemConfig1_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_systemConfig1_label_5, &lv_font_ZiTiQuanWeiJunHeiW22_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_systemConfig1_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_systemConfig1_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_img_5
    ui->screen_systemConfig1_img_5 = lv_img_create(ui->screen_systemConfig1_cont_5);
    lv_obj_add_flag(ui->screen_systemConfig1_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_systemConfig1_img_5, &_right1_alpha_25x25);
    lv_img_set_pivot(ui->screen_systemConfig1_img_5, 50,50);
    lv_img_set_angle(ui->screen_systemConfig1_img_5, 0);
    lv_obj_set_pos(ui->screen_systemConfig1_img_5, 260, 32);
    lv_obj_set_size(ui->screen_systemConfig1_img_5, 25, 25);

    //Write style for screen_systemConfig1_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_systemConfig1_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_systemConfig1_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_systemConfig1_img_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_cont_6
    ui->screen_systemConfig1_cont_6 = lv_obj_create(ui->screen_systemConfig1_cont_5);
    lv_obj_set_pos(ui->screen_systemConfig1_cont_6, 1, 2);
    lv_obj_set_size(ui->screen_systemConfig1_cont_6, 310, 85);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1_cont_6, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1_cont_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_cont_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_systemConfig1_cont_6, 89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_systemConfig1_cont_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_systemConfig1_cont_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_cont_6, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_cont_3
    ui->screen_systemConfig1_cont_3 = lv_obj_create(ui->screen_systemConfig1_cont_9);
    lv_obj_set_pos(ui->screen_systemConfig1_cont_3, 20, 216);
    lv_obj_set_size(ui->screen_systemConfig1_cont_3, 320, 95);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_systemConfig1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_systemConfig1_cont_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_systemConfig1_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_img_4
    ui->screen_systemConfig1_img_4 = lv_img_create(ui->screen_systemConfig1_cont_3);
    lv_obj_add_flag(ui->screen_systemConfig1_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_systemConfig1_img_4, &_reset1_alpha_70x70);
    lv_img_set_pivot(ui->screen_systemConfig1_img_4, 50,50);
    lv_img_set_angle(ui->screen_systemConfig1_img_4, 0);
    lv_obj_set_pos(ui->screen_systemConfig1_img_4, 6, 9);
    lv_obj_set_size(ui->screen_systemConfig1_img_4, 70, 70);

    //Write style for screen_systemConfig1_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_systemConfig1_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_systemConfig1_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_systemConfig1_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_label_4
    ui->screen_systemConfig1_label_4 = lv_label_create(ui->screen_systemConfig1_cont_3);
    lv_label_set_text(ui->screen_systemConfig1_label_4, "出厂设置");
    lv_label_set_long_mode(ui->screen_systemConfig1_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_systemConfig1_label_4, 110, 30);
    lv_obj_set_size(ui->screen_systemConfig1_label_4, 120, 28);

    //Write style for screen_systemConfig1_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_systemConfig1_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_systemConfig1_label_4, &lv_font_ZiTiQuanWeiJunHeiW22_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_systemConfig1_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_systemConfig1_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_img_3
    ui->screen_systemConfig1_img_3 = lv_img_create(ui->screen_systemConfig1_cont_3);
    lv_obj_add_flag(ui->screen_systemConfig1_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_systemConfig1_img_3, &_right1_alpha_25x25);
    lv_img_set_pivot(ui->screen_systemConfig1_img_3, 50,50);
    lv_img_set_angle(ui->screen_systemConfig1_img_3, 0);
    lv_obj_set_pos(ui->screen_systemConfig1_img_3, 260, 32);
    lv_obj_set_size(ui->screen_systemConfig1_img_3, 25, 25);

    //Write style for screen_systemConfig1_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_systemConfig1_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_systemConfig1_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_systemConfig1_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_cont_4
    ui->screen_systemConfig1_cont_4 = lv_obj_create(ui->screen_systemConfig1_cont_3);
    lv_obj_set_pos(ui->screen_systemConfig1_cont_4, 1, 2);
    lv_obj_set_size(ui->screen_systemConfig1_cont_4, 310, 85);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_cont_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_systemConfig1_cont_4, 89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_systemConfig1_cont_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_systemConfig1_cont_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_cont_4, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_cont_2
    ui->screen_systemConfig1_cont_2 = lv_obj_create(ui->screen_systemConfig1_cont_9);
    lv_obj_set_pos(ui->screen_systemConfig1_cont_2, 20, 10);
    lv_obj_set_size(ui->screen_systemConfig1_cont_2, 320, 95);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_systemConfig1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_systemConfig1_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_systemConfig1_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_img_1
    ui->screen_systemConfig1_img_1 = lv_img_create(ui->screen_systemConfig1_cont_2);
    lv_obj_add_flag(ui->screen_systemConfig1_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_systemConfig1_img_1, &_g1_alpha_70x70);
    lv_img_set_pivot(ui->screen_systemConfig1_img_1, 50,50);
    lv_img_set_angle(ui->screen_systemConfig1_img_1, 0);
    lv_obj_set_pos(ui->screen_systemConfig1_img_1, 6, 9);
    lv_obj_set_size(ui->screen_systemConfig1_img_1, 70, 70);

    //Write style for screen_systemConfig1_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_systemConfig1_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_systemConfig1_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_systemConfig1_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_label_3
    ui->screen_systemConfig1_label_3 = lv_label_create(ui->screen_systemConfig1_cont_2);
    lv_label_set_text(ui->screen_systemConfig1_label_3, "自动关机");
    lv_label_set_long_mode(ui->screen_systemConfig1_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_systemConfig1_label_3, 110, 30);
    lv_obj_set_size(ui->screen_systemConfig1_label_3, 120, 28);

    //Write style for screen_systemConfig1_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_systemConfig1_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_systemConfig1_label_3, &lv_font_ZiTiQuanWeiJunHeiW22_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_systemConfig1_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_systemConfig1_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_img_2
    ui->screen_systemConfig1_img_2 = lv_img_create(ui->screen_systemConfig1_cont_2);
    lv_obj_add_flag(ui->screen_systemConfig1_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_systemConfig1_img_2, &_right1_alpha_25x25);
    lv_img_set_pivot(ui->screen_systemConfig1_img_2, 50,50);
    lv_img_set_angle(ui->screen_systemConfig1_img_2, 0);
    lv_obj_set_pos(ui->screen_systemConfig1_img_2, 260, 32);
    lv_obj_set_size(ui->screen_systemConfig1_img_2, 25, 25);

    //Write style for screen_systemConfig1_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_systemConfig1_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_systemConfig1_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_systemConfig1_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_cont_1
    ui->screen_systemConfig1_cont_1 = lv_obj_create(ui->screen_systemConfig1_cont_2);
    lv_obj_set_pos(ui->screen_systemConfig1_cont_1, 0, 2);
    lv_obj_set_size(ui->screen_systemConfig1_cont_1, 310, 85);
    lv_obj_set_scrollbar_mode(ui->screen_systemConfig1_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_systemConfig1_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_systemConfig1_cont_1, 89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_systemConfig1_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_systemConfig1_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_cont_1, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_systemConfig1_label_1
    ui->screen_systemConfig1_label_1 = lv_label_create(ui->screen_systemConfig1);
    lv_label_set_text(ui->screen_systemConfig1_label_1, "系统设置");
    lv_label_set_long_mode(ui->screen_systemConfig1_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_systemConfig1_label_1, 130, 25);
    lv_obj_set_size(ui->screen_systemConfig1_label_1, 100, 20);

    //Write style for screen_systemConfig1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_systemConfig1_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_systemConfig1_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_systemConfig1_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_systemConfig1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_systemConfig1_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_systemConfig1.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_systemConfig1);

    //Init events for screen.
    events_init_screen_systemConfig1(ui);
}
