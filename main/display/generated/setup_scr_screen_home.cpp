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



void setup_scr_screen_home(lv_ui *ui)
{
    //Write codes screen_home
    ui->screen_home = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_home, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_home, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_home, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_home, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->screen_home, &_bk1_RGB565A8_360x360, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->screen_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->screen_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_home_label_1
    ui->screen_home_label_1 = lv_label_create(ui->screen_home);
    lv_obj_set_pos(ui->screen_home_label_1, 65, 90);
    lv_obj_set_size(ui->screen_home_label_1, 230, 82);
    lv_label_set_text(ui->screen_home_label_1, "10:35");
    lv_label_set_long_mode(ui->screen_home_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_home_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_home_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_home_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_85, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_home_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_home_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_home_img_1
    ui->screen_home_img_1 = lv_image_create(ui->screen_home);
    lv_obj_set_pos(ui->screen_home_img_1, 115, 34);
    lv_obj_set_size(ui->screen_home_img_1, 40, 40);
    lv_obj_add_flag(ui->screen_home_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_home_img_1, &_sun1_RGB565A8_40x40);
    lv_image_set_pivot(ui->screen_home_img_1, 50,50);
    lv_image_set_rotation(ui->screen_home_img_1, 0);

    //Write style for screen_home_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_home_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_home_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_home_label_2
    ui->screen_home_label_2 = lv_label_create(ui->screen_home);
    lv_obj_set_pos(ui->screen_home_label_2, 159, 41);
    lv_obj_set_size(ui->screen_home_label_2, 110, 25);
    lv_label_set_text(ui->screen_home_label_2, "-3℃ 晴");
    lv_label_set_long_mode(ui->screen_home_label_2, LV_LABEL_LONG_WRAP);

    //Write style for screen_home_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_home_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_home_label_2, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_home_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_home_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_home_label_3
    ui->screen_home_label_3 = lv_label_create(ui->screen_home);
    lv_obj_set_pos(ui->screen_home_label_3, 75, 190);
    lv_obj_set_size(ui->screen_home_label_3, 210, 20);
    lv_label_set_text(ui->screen_home_label_3, "2026年1月18日 星期日");
    lv_label_set_long_mode(ui->screen_home_label_3, LV_LABEL_LONG_WRAP);

    //Write style for screen_home_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_home_label_3, lv_color_hex(0x9f9f9f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_home_label_3, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_home_label_3, 205, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_home_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_home_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_home_animimg_1
    ui->screen_home_animimg_1 = lv_animimg_create(ui->screen_home);
    lv_obj_set_pos(ui->screen_home_animimg_1, 140, 240);
    lv_obj_set_size(ui->screen_home_animimg_1, 80, 80);
    lv_animimg_set_src(ui->screen_home_animimg_1, (const void **) screen_home_animimg_1_imgs, 80);
    lv_animimg_set_duration(ui->screen_home_animimg_1, 30*80);
    lv_animimg_set_repeat_count(ui->screen_home_animimg_1, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui->screen_home_animimg_1);

    //The custom code of screen_home.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_home);

    //Init events for screen.
    events_init_screen_home(ui);
}
