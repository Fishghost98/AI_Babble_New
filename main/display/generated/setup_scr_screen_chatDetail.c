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



void setup_scr_screen_chatDetail(lv_ui *ui)
{
    //Write codes screen_chatDetail
    ui->screen_chatDetail = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_chatDetail, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_chatDetail, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_chatDetail, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_chatDetail, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_chatDetail, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_chatDetail, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->screen_chatDetail, &_bk2_RGB565A8_360x360, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->screen_chatDetail, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->screen_chatDetail, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_chatDetail_label_chat
    ui->screen_chatDetail_label_chat = lv_label_create(ui->screen_chatDetail);
    lv_obj_set_pos(ui->screen_chatDetail_label_chat, 67, 268);
    lv_obj_set_size(ui->screen_chatDetail_label_chat, 225, 20);
    lv_label_set_text_static(ui->screen_chatDetail_label_chat, "字幕测试字幕测试字幕测试字幕测试");
    lv_label_set_long_mode(ui->screen_chatDetail_label_chat, LV_LABEL_LONG_SCROLL);

    //Write style for screen_chatDetail_label_chat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_chatDetail_label_chat, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_chatDetail_label_chat, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_chatDetail_label_chat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_chatDetail_label_chat, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_chatDetail_label_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_chatDetail_animimg_1
    ui->screen_chatDetail_animimg_1 = lv_animimg_create(ui->screen_chatDetail);
    lv_obj_set_pos(ui->screen_chatDetail_animimg_1, 80, 45);
    lv_obj_set_size(ui->screen_chatDetail_animimg_1, 200, 200);
    lv_animimg_set_src(ui->screen_chatDetail_animimg_1, (const void **) screen_chatDetail_animimg_1_imgs, 80);
    lv_animimg_set_duration(ui->screen_chatDetail_animimg_1, 30*80);
    lv_animimg_set_repeat_count(ui->screen_chatDetail_animimg_1, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui->screen_chatDetail_animimg_1);

    //The custom code of screen_chatDetail.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_chatDetail);

    //Init events for screen.
    events_init_screen_chatDetail(ui);
}
