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



void setup_scr_screen_autoShutDown(lv_ui *ui)
{
    //Write codes screen_autoShutDown
    ui->screen_autoShutDown = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_autoShutDown, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_autoShutDown, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_autoShutDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_autoShutDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_autoShutDown, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_autoShutDown, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_autoShutDown_label_1
    ui->screen_autoShutDown_label_1 = lv_label_create(ui->screen_autoShutDown);
    lv_obj_set_pos(ui->screen_autoShutDown_label_1, 102, 50);
    lv_obj_set_size(ui->screen_autoShutDown_label_1, 156, 13);
    lv_label_set_text(ui->screen_autoShutDown_label_1, "(仅在便携模式下生效)");
    lv_label_set_long_mode(ui->screen_autoShutDown_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_autoShutDown_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_autoShutDown_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_autoShutDown_label_1, &lv_font_ZiTiQuanWeiJunHeiW22_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_autoShutDown_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_autoShutDown_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_autoShutDown_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_autoShutDown_label_2
    ui->screen_autoShutDown_label_2 = lv_label_create(ui->screen_autoShutDown);
    lv_obj_set_pos(ui->screen_autoShutDown_label_2, 130, 25);
    lv_obj_set_size(ui->screen_autoShutDown_label_2, 100, 20);
    lv_label_set_text(ui->screen_autoShutDown_label_2, "自动关机");
    lv_label_set_long_mode(ui->screen_autoShutDown_label_2, LV_LABEL_LONG_WRAP);

    //Write style for screen_autoShutDown_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_autoShutDown_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_autoShutDown_label_2, &lv_font_ZiTiQuanWeiJunHeiW22_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_autoShutDown_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_autoShutDown_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_autoShutDown_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_autoShutDown_list_1
    ui->screen_autoShutDown_list_1 = lv_list_create(ui->screen_autoShutDown);
    lv_obj_set_pos(ui->screen_autoShutDown_list_1, 115, 77);
    lv_obj_set_size(ui->screen_autoShutDown_list_1, 130, 280);
    lv_obj_set_scrollbar_mode(ui->screen_autoShutDown_list_1, LV_SCROLLBAR_MODE_OFF);
    ui->screen_autoShutDown_list_1_item0 = lv_list_add_button(ui->screen_autoShutDown_list_1, &_selected_green_RGB565_20x20, "从不");
    ui->screen_autoShutDown_list_1_item1 = lv_list_add_button(ui->screen_autoShutDown_list_1, &_black_RGB565_20x20, "5分钟");
    ui->screen_autoShutDown_list_1_item2 = lv_list_add_button(ui->screen_autoShutDown_list_1, &_black_RGB565_20x20, "10分钟");
    ui->screen_autoShutDown_list_1_item3 = lv_list_add_button(ui->screen_autoShutDown_list_1, &_black_RGB565_20x20, "30分钟");
    ui->screen_autoShutDown_list_1_item4 = lv_list_add_button(ui->screen_autoShutDown_list_1, &_black_RGB565_20x20, "1小时");
    ui->screen_autoShutDown_list_1_item5 = lv_list_add_button(ui->screen_autoShutDown_list_1, &_black_RGB565_20x20, "6小时");

    //Write style state: LV_STATE_DEFAULT for &style_screen_autoShutDown_list_1_main_main_default
    static lv_style_t style_screen_autoShutDown_list_1_main_main_default;
    ui_init_style(&style_screen_autoShutDown_list_1_main_main_default);

    lv_style_set_pad_top(&style_screen_autoShutDown_list_1_main_main_default, 5);
    lv_style_set_pad_left(&style_screen_autoShutDown_list_1_main_main_default, 5);
    lv_style_set_pad_right(&style_screen_autoShutDown_list_1_main_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_autoShutDown_list_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_screen_autoShutDown_list_1_main_main_default, 0);
    lv_style_set_border_width(&style_screen_autoShutDown_list_1_main_main_default, 1);
    lv_style_set_border_opa(&style_screen_autoShutDown_list_1_main_main_default, 0);
    lv_style_set_border_color(&style_screen_autoShutDown_list_1_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_autoShutDown_list_1_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_autoShutDown_list_1_main_main_default, 3);
    lv_style_set_shadow_width(&style_screen_autoShutDown_list_1_main_main_default, 0);
    lv_obj_add_style(ui->screen_autoShutDown_list_1, &style_screen_autoShutDown_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_autoShutDown_list_1_main_scrollbar_default
    static lv_style_t style_screen_autoShutDown_list_1_main_scrollbar_default;
    ui_init_style(&style_screen_autoShutDown_list_1_main_scrollbar_default);

    lv_style_set_radius(&style_screen_autoShutDown_list_1_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_autoShutDown_list_1_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_autoShutDown_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_autoShutDown_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_autoShutDown_list_1, &style_screen_autoShutDown_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_autoShutDown_list_1_extra_btns_main_default
    static lv_style_t style_screen_autoShutDown_list_1_extra_btns_main_default;
    ui_init_style(&style_screen_autoShutDown_list_1_extra_btns_main_default);

    lv_style_set_pad_top(&style_screen_autoShutDown_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_screen_autoShutDown_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_screen_autoShutDown_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_autoShutDown_list_1_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_screen_autoShutDown_list_1_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_screen_autoShutDown_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_screen_autoShutDown_list_1_extra_btns_main_default, &lv_font_ZiTiQuanWeiJunHeiW22_23);
    lv_style_set_text_opa(&style_screen_autoShutDown_list_1_extra_btns_main_default, 255);
    lv_style_set_radius(&style_screen_autoShutDown_list_1_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_screen_autoShutDown_list_1_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_autoShutDown_list_1_item5, &style_screen_autoShutDown_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_autoShutDown_list_1_item4, &style_screen_autoShutDown_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_autoShutDown_list_1_item3, &style_screen_autoShutDown_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_autoShutDown_list_1_item2, &style_screen_autoShutDown_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_autoShutDown_list_1_item1, &style_screen_autoShutDown_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->screen_autoShutDown_list_1_item0, &style_screen_autoShutDown_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_autoShutDown_list_1_extra_texts_main_default
    static lv_style_t style_screen_autoShutDown_list_1_extra_texts_main_default;
    ui_init_style(&style_screen_autoShutDown_list_1_extra_texts_main_default);

    lv_style_set_pad_top(&style_screen_autoShutDown_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_screen_autoShutDown_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_screen_autoShutDown_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_autoShutDown_list_1_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_screen_autoShutDown_list_1_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_screen_autoShutDown_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_autoShutDown_list_1_extra_texts_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_autoShutDown_list_1_extra_texts_main_default, 255);
    lv_style_set_radius(&style_screen_autoShutDown_list_1_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_screen_autoShutDown_list_1_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_screen_autoShutDown_list_1_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_screen_autoShutDown_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_autoShutDown_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);

    //The custom code of screen_autoShutDown.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_autoShutDown);

    //Init events for screen.
    events_init_screen_autoShutDown(ui);
}
