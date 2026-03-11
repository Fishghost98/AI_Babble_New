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



void setup_scr_screen_remindDetail(lv_ui *ui)
{
    //Write codes screen_remindDetail
    ui->screen_remindDetail = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_remindDetail, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_remindDetail, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_remindDetail, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_remindDetail, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_remindDetail, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_remindDetail, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_remindDetail_label_1
    ui->screen_remindDetail_label_1 = lv_label_create(ui->screen_remindDetail);
    lv_obj_set_pos(ui->screen_remindDetail_label_1, 130, 25);
    lv_obj_set_size(ui->screen_remindDetail_label_1, 100, 19);
    lv_label_set_text(ui->screen_remindDetail_label_1, "AI提醒");
    lv_label_set_long_mode(ui->screen_remindDetail_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_remindDetail_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_remindDetail_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_remindDetail_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_remindDetail_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_remindDetail_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_remindDetail_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_remindDetail_cont_remind
    ui->screen_remindDetail_cont_remind = lv_obj_create(ui->screen_remindDetail);
    lv_obj_set_pos(ui->screen_remindDetail_cont_remind, 52, 70);
    lv_obj_set_size(ui->screen_remindDetail_cont_remind, 270, 179);
    lv_obj_set_scrollbar_mode(ui->screen_remindDetail_cont_remind, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_remindDetail_cont_remind, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_remindDetail_cont_remind, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_remindDetail_cont_remind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_remindDetail_cont_remind, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_remindDetail_cont_remind, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_remindDetail_cont_remind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_remindDetail_cont_remind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_remindDetail_cont_remind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_remindDetail_cont_remind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_remindDetail_cont_remind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_remindDetail_cont_remind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_remindDetail_cont_remind, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_remindDetail_cont_detail1
    ui->screen_remindDetail_cont_detail1 = lv_obj_create(ui->screen_remindDetail_cont_remind);
    lv_obj_set_pos(ui->screen_remindDetail_cont_detail1, 0, 0);
    lv_obj_set_size(ui->screen_remindDetail_cont_detail1, 260, 50);
    lv_obj_set_scrollbar_mode(ui->screen_remindDetail_cont_detail1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_remindDetail_cont_detail1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_remindDetail_cont_detail1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_remindDetail_cont_detail1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_remindDetail_cont_detail1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_remindDetail_cont_detail1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_remindDetail_cont_detail1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_remindDetail_cont_detail1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_remindDetail_cont_detail1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_remindDetail_cont_detail1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_remindDetail_cont_detail1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_remindDetail_cont_detail1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_remindDetail_cont_detail1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_remindDetail_label_3
    ui->screen_remindDetail_label_3 = lv_label_create(ui->screen_remindDetail_cont_detail1);
    lv_obj_set_pos(ui->screen_remindDetail_label_3, 67, 7);
    lv_obj_set_size(ui->screen_remindDetail_label_3, 130, 25);
    lv_label_set_text(ui->screen_remindDetail_label_3, "提醒我开会");
    lv_label_set_long_mode(ui->screen_remindDetail_label_3, LV_LABEL_LONG_WRAP);

    //Write style for screen_remindDetail_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_remindDetail_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_remindDetail_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_remindDetail_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_remindDetail_label_3, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_remindDetail_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_remindDetail_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_remindDetail_label_3, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_remindDetail_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_remindDetail_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_remindDetail_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_remindDetail_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_remindDetail_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_remindDetail_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_remindDetail_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_remindDetail_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_remindDetail_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_remindDetail_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_remindDetail_label_remindDate1
    ui->screen_remindDetail_label_remindDate1 = lv_label_create(ui->screen_remindDetail_cont_detail1);
    lv_obj_set_pos(ui->screen_remindDetail_label_remindDate1, 0, 22);
    lv_obj_set_size(ui->screen_remindDetail_label_remindDate1, 50, 20);
    lv_label_set_text(ui->screen_remindDetail_label_remindDate1, "12/21");
    lv_label_set_long_mode(ui->screen_remindDetail_label_remindDate1, LV_LABEL_LONG_WRAP);

    //Write style for screen_remindDetail_label_remindDate1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_remindDetail_label_remindDate1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_remindDetail_label_remindDate1, &lv_font_ZiTiQuanWeiJunHeiW22_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_remindDetail_label_remindDate1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_remindDetail_label_remindDate1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_remindDetail_label_remindDate1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_remindDetail_label_remindTime1
    ui->screen_remindDetail_label_remindTime1 = lv_label_create(ui->screen_remindDetail_cont_detail1);
    lv_obj_set_pos(ui->screen_remindDetail_label_remindTime1, 0, 0);
    lv_obj_set_size(ui->screen_remindDetail_label_remindTime1, 50, 20);
    lv_label_set_text(ui->screen_remindDetail_label_remindTime1, "11:25");
    lv_label_set_long_mode(ui->screen_remindDetail_label_remindTime1, LV_LABEL_LONG_WRAP);

    //Write style for screen_remindDetail_label_remindTime1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_remindDetail_label_remindTime1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_remindDetail_label_remindTime1, &lv_font_ZiTiQuanWeiJunHeiW22_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_remindDetail_label_remindTime1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_remindDetail_label_remindTime1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_remindDetail_label_remindTime1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_remindDetail_sw_1
    ui->screen_remindDetail_sw_1 = lv_switch_create(ui->screen_remindDetail_cont_detail1);
    lv_obj_set_pos(ui->screen_remindDetail_sw_1, 209, 7);
    lv_obj_set_size(ui->screen_remindDetail_sw_1, 40, 20);

    //Write style for screen_remindDetail_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_remindDetail_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_remindDetail_sw_1, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_remindDetail_sw_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_remindDetail_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_remindDetail_sw_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_remindDetail_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_remindDetail_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_remindDetail_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_remindDetail_sw_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_remindDetail_sw_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_remindDetail_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_remindDetail_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_remindDetail_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_remindDetail_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_remindDetail_sw_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_remindDetail_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_remindDetail_sw_1, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_remindDetail_list_1
    ui->screen_remindDetail_list_1 = lv_list_create(ui->screen_remindDetail);
    lv_obj_set_pos(ui->screen_remindDetail_list_1, 0, 312);
    lv_obj_set_size(ui->screen_remindDetail_list_1, 360, 48);
    lv_obj_set_scrollbar_mode(ui->screen_remindDetail_list_1, LV_SCROLLBAR_MODE_OFF);
    ui->screen_remindDetail_list_1_item0 = lv_list_add_button(ui->screen_remindDetail_list_1, &_mic_RGB565_20x20, "长按新建");

    //Write style state: LV_STATE_DEFAULT for &style_screen_remindDetail_list_1_main_main_default
    static lv_style_t style_screen_remindDetail_list_1_main_main_default;
    ui_init_style(&style_screen_remindDetail_list_1_main_main_default);

    lv_style_set_pad_top(&style_screen_remindDetail_list_1_main_main_default, 5);
    lv_style_set_pad_left(&style_screen_remindDetail_list_1_main_main_default, 120);
    lv_style_set_pad_right(&style_screen_remindDetail_list_1_main_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_remindDetail_list_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_screen_remindDetail_list_1_main_main_default, 255);
    lv_style_set_bg_color(&style_screen_remindDetail_list_1_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_remindDetail_list_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_remindDetail_list_1_main_main_default, 1);
    lv_style_set_border_opa(&style_screen_remindDetail_list_1_main_main_default, 255);
    lv_style_set_border_color(&style_screen_remindDetail_list_1_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_remindDetail_list_1_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_remindDetail_list_1_main_main_default, 3);
    lv_style_set_shadow_width(&style_screen_remindDetail_list_1_main_main_default, 0);
    lv_obj_add_style(ui->screen_remindDetail_list_1, &style_screen_remindDetail_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_remindDetail_list_1_main_scrollbar_default
    static lv_style_t style_screen_remindDetail_list_1_main_scrollbar_default;
    ui_init_style(&style_screen_remindDetail_list_1_main_scrollbar_default);

    lv_style_set_radius(&style_screen_remindDetail_list_1_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_remindDetail_list_1_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_remindDetail_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_remindDetail_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_remindDetail_list_1, &style_screen_remindDetail_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_remindDetail_list_1_extra_btns_main_default
    static lv_style_t style_screen_remindDetail_list_1_extra_btns_main_default;
    ui_init_style(&style_screen_remindDetail_list_1_extra_btns_main_default);

    lv_style_set_pad_top(&style_screen_remindDetail_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_screen_remindDetail_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_screen_remindDetail_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_remindDetail_list_1_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_screen_remindDetail_list_1_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_screen_remindDetail_list_1_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_remindDetail_list_1_extra_btns_main_default, &lv_font_ZiTiQuanWeiJunHeiW22_23);
    lv_style_set_text_opa(&style_screen_remindDetail_list_1_extra_btns_main_default, 255);
    lv_style_set_radius(&style_screen_remindDetail_list_1_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_screen_remindDetail_list_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_remindDetail_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_remindDetail_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_remindDetail_list_1_item0, &style_screen_remindDetail_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_remindDetail_list_1_extra_texts_main_default
    static lv_style_t style_screen_remindDetail_list_1_extra_texts_main_default;
    ui_init_style(&style_screen_remindDetail_list_1_extra_texts_main_default);

    lv_style_set_pad_top(&style_screen_remindDetail_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_screen_remindDetail_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_screen_remindDetail_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_remindDetail_list_1_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_screen_remindDetail_list_1_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_screen_remindDetail_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_remindDetail_list_1_extra_texts_main_default, &lv_font_montserratMedium_14);
    lv_style_set_text_opa(&style_screen_remindDetail_list_1_extra_texts_main_default, 255);
    lv_style_set_radius(&style_screen_remindDetail_list_1_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_screen_remindDetail_list_1_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_screen_remindDetail_list_1_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_screen_remindDetail_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_remindDetail_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);

    //The custom code of screen_remindDetail.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_remindDetail);

    //Init events for screen.
    events_init_screen_remindDetail(ui);
}
