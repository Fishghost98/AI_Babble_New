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
#include "Commons.h"

void setup_scr_screen_quick_config(lv_ui *ui)
{
    // Write codes screen_quick_config
    ui->screen_quick_config = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_quick_config, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_quick_config, LV_SCROLLBAR_MODE_OFF);

    // Write style for screen_quick_config, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_quick_config, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_quick_config, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_slider_volume
    ui->screen_quick_config_slider_volume = lv_slider_create(ui->screen_quick_config);
    lv_slider_set_range(ui->screen_quick_config_slider_volume, 0, 100);
    lv_slider_set_mode(ui->screen_quick_config_slider_volume, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->screen_quick_config_slider_volume, all_config.page_quickConfig.volume, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_quick_config_slider_volume, 91, 56);
    lv_obj_set_size(ui->screen_quick_config_slider_volume, 50, 160);

    // Write style for screen_quick_config_slider_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_slider_volume, 120, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_quick_config_slider_volume, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_quick_config_slider_volume, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_slider_volume, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_quick_config_slider_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_quick_config_slider_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for screen_quick_config_slider_volume, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_slider_volume, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_quick_config_slider_volume, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_quick_config_slider_volume, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_slider_volume, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style for screen_quick_config_slider_volume, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_slider_volume, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_slider_volume, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_slider_backLight
    ui->screen_quick_config_slider_backLight = lv_slider_create(ui->screen_quick_config);
    lv_slider_set_range(ui->screen_quick_config_slider_backLight, 5, 100);
    lv_slider_set_mode(ui->screen_quick_config_slider_backLight, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->screen_quick_config_slider_backLight, all_config.page_quickConfig.backLight, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_quick_config_slider_backLight, 220, 56);
    lv_obj_set_size(ui->screen_quick_config_slider_backLight, 50, 160);

    // Write style for screen_quick_config_slider_backLight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_slider_backLight, 129, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_quick_config_slider_backLight, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_quick_config_slider_backLight, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_slider_backLight, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_quick_config_slider_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_quick_config_slider_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for screen_quick_config_slider_backLight, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_slider_backLight, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_quick_config_slider_backLight, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_quick_config_slider_backLight, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_slider_backLight, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style for screen_quick_config_slider_backLight, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_slider_backLight, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_slider_backLight, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_label_volume
    ui->screen_quick_config_label_volume = lv_label_create(ui->screen_quick_config);
    lv_label_set_text(ui->screen_quick_config_label_volume, "音量");
    lv_label_set_long_mode(ui->screen_quick_config_label_volume, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_quick_config_label_volume, 66, 225);
    lv_obj_set_size(ui->screen_quick_config_label_volume, 100, 23);

    // Write style for screen_quick_config_label_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_quick_config_label_volume, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_quick_config_label_volume, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_quick_config_label_volume, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_quick_config_label_volume, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_quick_config_label_volume, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_label_backLight
    ui->screen_quick_config_label_backLight = lv_label_create(ui->screen_quick_config);
    lv_label_set_text(ui->screen_quick_config_label_backLight, "亮度");
    lv_label_set_long_mode(ui->screen_quick_config_label_backLight, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_quick_config_label_backLight, 194, 225);
    lv_obj_set_size(ui->screen_quick_config_label_backLight, 100, 23);

    // Write style for screen_quick_config_label_backLight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_quick_config_label_backLight, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_quick_config_label_backLight, &lv_font_ZiTiQuanWeiJunHeiW22_23, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_quick_config_label_backLight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_quick_config_label_backLight, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_quick_config_label_backLight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_btn_power
    ui->screen_quick_config_btn_power = lv_btn_create(ui->screen_quick_config);
    ui->screen_quick_config_btn_power_label = lv_label_create(ui->screen_quick_config_btn_power);
    lv_label_set_text(ui->screen_quick_config_btn_power_label, "");
    lv_label_set_long_mode(ui->screen_quick_config_btn_power_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_quick_config_btn_power_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_quick_config_btn_power, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_quick_config_btn_power_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_quick_config_btn_power, 91, 280);
    lv_obj_set_size(ui->screen_quick_config_btn_power, 50, 50);

    // Write style for screen_quick_config_btn_power, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_btn_power, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_quick_config_btn_power, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_btn_power, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_quick_config_btn_power, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->screen_quick_config_btn_power, &_turnoff_50x50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->screen_quick_config_btn_power, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->screen_quick_config_btn_power, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_quick_config_btn_power, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_quick_config_btn_power, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_quick_config_btn_power, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_quick_config_btn_power, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_bar_battery
    ui->screen_quick_config_bar_battery = lv_bar_create(ui->screen_quick_config);
    lv_obj_set_style_anim_time(ui->screen_quick_config_bar_battery, 1000, 0);
    lv_bar_set_mode(ui->screen_quick_config_bar_battery, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_quick_config_bar_battery, 0, 100);
    lv_bar_set_value(ui->screen_quick_config_bar_battery, 80, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_quick_config_bar_battery, 153, 23);
    lv_obj_set_size(ui->screen_quick_config_bar_battery, 50, 20);

    // Write style for screen_quick_config_bar_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_bar_battery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_quick_config_bar_battery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_quick_config_bar_battery, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_bar_battery, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_quick_config_bar_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style for screen_quick_config_bar_battery, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_bar_battery, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_quick_config_bar_battery, lv_color_hex(0x2FDA64), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_quick_config_bar_battery, LV_GRAD_DIR_NONE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_bar_battery, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_label_battery
    ui->screen_quick_config_label_battery = lv_label_create(ui->screen_quick_config);
    static char battery_buf[20] = {0};
    snprintf(battery_buf, sizeof(battery_buf),
             "%d%%",
             all_config.page_quickConfig.battery);
    ESP_LOGI("screen_quick_config", "battery:%d", all_config.page_quickConfig.battery);
    lv_label_set_text(ui->screen_quick_config_label_battery, battery_buf);
    lv_label_set_long_mode(ui->screen_quick_config_label_battery, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_quick_config_label_battery, 153, 25);
    lv_obj_set_size(ui->screen_quick_config_label_battery, 50, 16);

    // Write style for screen_quick_config_label_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_quick_config_label_battery, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_quick_config_label_battery, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_quick_config_label_battery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_quick_config_label_battery, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_quick_config_label_battery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_btn_1
    ui->screen_quick_config_btn_1 = lv_btn_create(ui->screen_quick_config);
    ui->screen_quick_config_btn_1_label = lv_label_create(ui->screen_quick_config_btn_1);
    lv_label_set_text(ui->screen_quick_config_btn_1_label, "");
    lv_label_set_long_mode(ui->screen_quick_config_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_quick_config_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_quick_config_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_quick_config_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_quick_config_btn_1, 219, 280);
    lv_obj_set_size(ui->screen_quick_config_btn_1, 50, 50);

    // Write style for screen_quick_config_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_quick_config_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_quick_config_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_btn_1, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_quick_config_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->screen_quick_config_btn_1, &_wifi1_50x50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->screen_quick_config_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->screen_quick_config_btn_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_quick_config_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_quick_config_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_quick_config_btn_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_quick_config_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_img_1
    ui->screen_quick_config_img_1 = lv_img_create(ui->screen_quick_config);
    lv_obj_add_flag(ui->screen_quick_config_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_quick_config_img_1, &_vol1_alpha_25x25);
    lv_img_set_pivot(ui->screen_quick_config_img_1, 50, 50);
    lv_img_set_angle(ui->screen_quick_config_img_1, 0);
    lv_obj_set_pos(ui->screen_quick_config_img_1, 103, 180);
    lv_obj_set_size(ui->screen_quick_config_img_1, 25, 25);

    // Write style for screen_quick_config_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_quick_config_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_quick_config_img_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_img_1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_quick_config_img_1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_quick_config_img_2
    ui->screen_quick_config_img_2 = lv_img_create(ui->screen_quick_config);
    lv_obj_add_flag(ui->screen_quick_config_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_quick_config_img_2, &_sun1_alpha_25x25);
    lv_img_set_pivot(ui->screen_quick_config_img_2, 50, 50);
    lv_img_set_angle(ui->screen_quick_config_img_2, 0);
    lv_obj_set_pos(ui->screen_quick_config_img_2, 232, 180);
    lv_obj_set_size(ui->screen_quick_config_img_2, 25, 25);

    // Write style for screen_quick_config_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_quick_config_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_quick_config_img_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_quick_config_img_2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_quick_config_img_2, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of screen_quick_config.

    // Update current screen layout.
    lv_obj_update_layout(ui->screen_quick_config);

    // Init events for screen.
    events_init_screen_quick_config(ui);
}
