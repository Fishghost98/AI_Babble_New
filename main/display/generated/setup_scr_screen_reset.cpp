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



void setup_scr_screen_reset(lv_ui *ui)
{
    //Write codes screen_reset
    ui->screen_reset = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_reset, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_reset, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_reset, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_reset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_reset, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_reset, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_reset_label_1
    ui->screen_reset_label_1 = lv_label_create(ui->screen_reset);
    lv_obj_set_pos(ui->screen_reset_label_1, 125, 147);
    lv_obj_set_size(ui->screen_reset_label_1, 150, 25);
    lv_label_set_text(ui->screen_reset_label_1, "恢复出厂设置");
    lv_label_set_long_mode(ui->screen_reset_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_reset_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_reset_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_reset_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_reset_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_reset_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_reset_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_reset_btn_1
    ui->screen_reset_btn_1 = lv_button_create(ui->screen_reset);
    lv_obj_set_pos(ui->screen_reset_btn_1, 150, 230);
    lv_obj_set_size(ui->screen_reset_btn_1, 60, 60);
    ui->screen_reset_btn_1_label = lv_label_create(ui->screen_reset_btn_1);
    lv_label_set_text(ui->screen_reset_btn_1_label, "");
    lv_label_set_long_mode(ui->screen_reset_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_reset_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_reset_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_reset_btn_1_label, LV_PCT(100));

    //Write style for screen_reset_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_reset_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_reset_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_reset_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_reset_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->screen_reset_btn_1, &_cancel_RGB565A8_60x60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->screen_reset_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->screen_reset_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_reset_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_reset_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_reset_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_reset_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_reset_slider_1
    ui->screen_reset_slider_1 = lv_slider_create(ui->screen_reset);
    lv_obj_set_pos(ui->screen_reset_slider_1, 55, 129);
    lv_obj_set_size(ui->screen_reset_slider_1, 250, 60);
    lv_slider_set_range(ui->screen_reset_slider_1, 0, 100);
    lv_slider_set_mode(ui->screen_reset_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->screen_reset_slider_1, 12, LV_ANIM_OFF);

    //Write style for screen_reset_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_reset_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_reset_slider_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_reset_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_reset_slider_1, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_reset_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_reset_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_reset_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_reset_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_reset_slider_1, lv_color_hex(0x989898), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_reset_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_reset_slider_1, 30, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_reset_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_reset_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->screen_reset_slider_1, &_turnoff_RGB565A8_70x70, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->screen_reset_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->screen_reset_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_reset_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //The custom code of screen_reset.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_reset);

    //Init events for screen.
    events_init_screen_reset(ui);
}
