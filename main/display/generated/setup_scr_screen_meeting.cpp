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



void setup_scr_screen_meeting(lv_ui *ui)
{
    //Write codes screen_meeting
    ui->screen_meeting = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_meeting, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_meeting, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_meeting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meeting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meeting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meeting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->screen_meeting, &_bk2_RGB565A8_360x360, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->screen_meeting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->screen_meeting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meeting_label_1
    ui->screen_meeting_label_1 = lv_label_create(ui->screen_meeting);
    lv_obj_set_pos(ui->screen_meeting_label_1, 130, 250);
    lv_obj_set_size(ui->screen_meeting_label_1, 100, 32);
    lv_label_set_text(ui->screen_meeting_label_1, "AI会议");
    lv_label_set_long_mode(ui->screen_meeting_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_meeting_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_meeting_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_meeting_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_meeting_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_meeting_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meeting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meeting_img_1
    ui->screen_meeting_img_1 = lv_image_create(ui->screen_meeting);
    lv_obj_set_pos(ui->screen_meeting_img_1, 105, 70);
    lv_obj_set_size(ui->screen_meeting_img_1, 150, 150);
    lv_obj_add_flag(ui->screen_meeting_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_meeting_img_1, &_meeting1_RGB565A8_150x150);
    lv_image_set_pivot(ui->screen_meeting_img_1, 50,50);
    lv_image_set_rotation(ui->screen_meeting_img_1, 0);

    //Write style for screen_meeting_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_meeting_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_meeting_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meeting_img_2
    ui->screen_meeting_img_2 = lv_image_create(ui->screen_meeting);
    lv_obj_set_pos(ui->screen_meeting_img_2, 285, 35);
    lv_obj_set_size(ui->screen_meeting_img_2, 75, 290);
    lv_obj_add_flag(ui->screen_meeting_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_meeting_img_2, &_right2_RGB565A8_75x290);
    lv_image_set_pivot(ui->screen_meeting_img_2, 50,50);
    lv_image_set_rotation(ui->screen_meeting_img_2, 0);

    //Write style for screen_meeting_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_meeting_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_meeting_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meeting_img_3
    ui->screen_meeting_img_3 = lv_image_create(ui->screen_meeting);
    lv_obj_set_pos(ui->screen_meeting_img_3, 0, 35);
    lv_obj_set_size(ui->screen_meeting_img_3, 75, 290);
    lv_obj_add_flag(ui->screen_meeting_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_meeting_img_3, &_left1_RGB565A8_75x290);
    lv_image_set_pivot(ui->screen_meeting_img_3, 50,50);
    lv_image_set_rotation(ui->screen_meeting_img_3, 0);

    //Write style for screen_meeting_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_meeting_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_meeting_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meeting_img_4
    ui->screen_meeting_img_4 = lv_image_create(ui->screen_meeting);
    lv_obj_set_pos(ui->screen_meeting_img_4, 155, 330);
    lv_obj_set_size(ui->screen_meeting_img_4, 50, 6);
    lv_obj_add_flag(ui->screen_meeting_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_meeting_img_4, &_dot4_RGB565A8_50x6);
    lv_image_set_pivot(ui->screen_meeting_img_4, 50,50);
    lv_image_set_rotation(ui->screen_meeting_img_4, 0);

    //Write style for screen_meeting_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_meeting_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_meeting_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_meeting.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_meeting);

    //Init events for screen.
    events_init_screen_meeting(ui);
}
