/*
 * Copyright 2025 NXP
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

void setup_scr_screen_main_gif(lv_ui *ui)
{
    // Write codes screen_main_gif
    ui->screen_main_gif = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_main_gif, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_main_gif, LV_SCROLLBAR_MODE_OFF);

    // Write style for screen_main_gif, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main_gif, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main_gif, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main_gif, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_main_gif_img_index_gif
    ui->screen_main_gif_gif_index = lv_gif_create(ui->screen_main_gif);
    lv_obj_add_flag(ui->screen_main_gif_gif_index, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
    lv_img_set_src(ui->screen_main_gif_img_index_gif, "E:\\BaiduNetdiskWorkspace\\AI\\SmartUI");
#else
    lv_gif_set_src(ui->screen_main_gif_gif_index, all_config.page_gif_display.gif_path_buf);
    ESP_LOGI("main_gif", "Display gif: %s; gif_index: %d", all_config.page_gif_display.gif_path_buf, save_config.gif_display);
#endif
    lv_obj_align(ui->screen_main_gif_gif_index, LV_ALIGN_CENTER, 0, 0);
    // lv_img_set_pivot(ui->screen_main_gif_img_index_gif, 50,50);
    // lv_img_set_angle(ui->screen_main_gif_img_index_gif, 0);
    // lv_obj_set_pos(ui->screen_main_gif_img_index_gif, 0, 0);
    // lv_obj_set_size(ui->screen_main_gif_gif_index, 191, 191);

    // Write style for screen_main_gif_img_index_gif, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_main_gif_gif_index, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_main_gif_gif_index, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_main_gif_gif_index, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_main_gif_gif_index, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of screen_main_gif.

    // Update current screen layout.
    lv_obj_update_layout(ui->screen_main_gif);

    // Init events for screen.
    events_init_screen_main_gif(ui);
}
