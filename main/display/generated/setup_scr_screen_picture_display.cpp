/*
 * Copyright 2026 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by
 * downloading, installing, activating and/or otherwise using the software, you are agreeing that
 * you have read, and that you agree to comply with and are bound by, such license terms.  If you do
 * not agree to be bound by the applicable license terms, then you may not retain, install, activate
 * or otherwise use the software.
 */

#include <stdio.h>
#include "custom.h"
#include "events_init.h"
#include "gui_guider.h"
#include "lvgl.h"
#include "widgets_init.h"

void setup_scr_screen_picture_display(lv_ui* ui) {
    // Write codes screen_picture_display
    ui->screen_picture_display = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_picture_display, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_picture_display, LV_SCROLLBAR_MODE_OFF);

    // Write style for screen_picture_display, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_picture_display, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_picture_display, lv_color_hex(0x000000),
                              LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_picture_display, LV_GRAD_DIR_NONE,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->screen_picture_display, &_bk2_RGB565A8_360x360,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->screen_picture_display, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->screen_picture_display, 0,
                                          LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_picture_display_img_display
    ui->screen_picture_display_img_display = lv_image_create(ui->screen_picture_display);
    lv_obj_add_flag(ui->screen_picture_display_img_display, LV_OBJ_FLAG_CLICKABLE);
    static char g_pic_path_buf[356] = {0};
    snprintf(g_pic_path_buf, sizeof(g_pic_path_buf), "S:/pictures/%s",
             all_config.pics_picture[all_config.page_pic_display.pic_index]);
    lv_img_set_src(ui->screen_picture_display_img_display, g_pic_path_buf);
    lv_obj_align(ui->screen_picture_display_img_display, LV_ALIGN_CENTER, 0, 0);
    // 1. 禁用滚动：禁止图片控件自身响应滚动/滑动
    lv_obj_clear_flag(ui->screen_picture_display_img_display, LV_OBJ_FLAG_SCROLLABLE);
    // 2. 禁用按压锁定：避免滑动时误识别为“拖动控件”
    lv_obj_clear_flag(ui->screen_picture_display_img_display, LV_OBJ_FLAG_PRESS_LOCK);
    // 3. 开启事件+手势冒泡：让滑动手势透传到父容器（屏幕）
    lv_obj_add_flag(ui->screen_picture_display_img_display, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_add_flag(ui->screen_picture_display_img_display, LV_OBJ_FLAG_GESTURE_BUBBLE);
    // 4. 开启浮动：父容器滑动时，图片控件固定位置不跟随移动
    lv_obj_add_flag(ui->screen_picture_display_img_display, LV_OBJ_FLAG_FLOATING);
    // 5. 可选：忽略布局，保留图片自适应大小（不影响位置）
    lv_obj_add_flag(ui->screen_picture_display_img_display, LV_OBJ_FLAG_IGNORE_LAYOUT);

    // Write style for screen_picture_display_img_display, Part: LV_PART_MAIN, State:
    // LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_picture_display_img_display, 0,
                                       LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_picture_display_img_display, 255,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes screen_picture_display_list_1
    ui->screen_picture_display_list_1 = lv_list_create(ui->screen_picture_display);
    if ((save_config.pic_display == all_config.page_pic_display.pic_index)  && (save_config.main_display_type == 0))
    {
        ui->screen_picture_display_list_1_item0 = lv_list_add_text(ui->screen_picture_display_list_1, "已设置");
    }
    else
    {
        ui->screen_picture_display_list_1_item0 = lv_list_add_text(ui->screen_picture_display_list_1, "设置");
    }
    lv_obj_align(ui->screen_picture_display_list_1_item0, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_pos(ui->screen_picture_display_list_1, 0, 310);
    lv_obj_set_size(ui->screen_picture_display_list_1, 360, 50);
    lv_obj_set_scrollbar_mode(ui->screen_picture_display_list_1, LV_SCROLLBAR_MODE_OFF);

    // Write style state: LV_STATE_DEFAULT for
    // &style_screen_picture_display_list_1_main_main_default
    static lv_style_t style_screen_picture_display_list_1_main_main_default;
    ui_init_style(&style_screen_picture_display_list_1_main_main_default);

    lv_style_set_pad_top(&style_screen_picture_display_list_1_main_main_default, 5);
    lv_style_set_pad_left(&style_screen_picture_display_list_1_main_main_default, 130);
    lv_style_set_pad_right(&style_screen_picture_display_list_1_main_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_picture_display_list_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_screen_picture_display_list_1_main_main_default, 255);
    lv_style_set_bg_color(&style_screen_picture_display_list_1_main_main_default,
                          lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_picture_display_list_1_main_main_default,
                             LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_picture_display_list_1_main_main_default, 1);
    lv_style_set_border_opa(&style_screen_picture_display_list_1_main_main_default, 255);
    lv_style_set_border_color(&style_screen_picture_display_list_1_main_main_default,
                              lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_picture_display_list_1_main_main_default,
                             LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_picture_display_list_1_main_main_default, 3);
    lv_style_set_shadow_width(&style_screen_picture_display_list_1_main_main_default, 0);
    lv_obj_add_style(ui->screen_picture_display_list_1,
                     &style_screen_picture_display_list_1_main_main_default,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for
    // &style_screen_picture_display_list_1_main_scrollbar_default
    static lv_style_t style_screen_picture_display_list_1_main_scrollbar_default;
    ui_init_style(&style_screen_picture_display_list_1_main_scrollbar_default);

    lv_style_set_radius(&style_screen_picture_display_list_1_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_picture_display_list_1_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_picture_display_list_1_main_scrollbar_default,
                          lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_picture_display_list_1_main_scrollbar_default,
                             LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_picture_display_list_1,
                     &style_screen_picture_display_list_1_main_scrollbar_default,
                     LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for
    // &style_screen_picture_display_list_1_extra_btns_main_default
    static lv_style_t style_screen_picture_display_list_1_extra_btns_main_default;
    ui_init_style(&style_screen_picture_display_list_1_extra_btns_main_default);

    lv_style_set_pad_top(&style_screen_picture_display_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_screen_picture_display_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_screen_picture_display_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_picture_display_list_1_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_screen_picture_display_list_1_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_screen_picture_display_list_1_extra_btns_main_default,
                            lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_picture_display_list_1_extra_btns_main_default,
                           &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_picture_display_list_1_extra_btns_main_default, 255);
    lv_style_set_radius(&style_screen_picture_display_list_1_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_screen_picture_display_list_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_picture_display_list_1_extra_btns_main_default,
                          lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_picture_display_list_1_extra_btns_main_default,
                             LV_GRAD_DIR_NONE);

    // Write style state: LV_STATE_DEFAULT for
    // &style_screen_picture_display_list_1_extra_texts_main_default
    static lv_style_t style_screen_picture_display_list_1_extra_texts_main_default;
    ui_init_style(&style_screen_picture_display_list_1_extra_texts_main_default);

    lv_style_set_pad_top(&style_screen_picture_display_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_screen_picture_display_list_1_extra_texts_main_default, 33);
    lv_style_set_pad_right(&style_screen_picture_display_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_picture_display_list_1_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_screen_picture_display_list_1_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_screen_picture_display_list_1_extra_texts_main_default,
                            lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_picture_display_list_1_extra_texts_main_default,
                           &lv_font_ZiTiQuanWeiJunHeiW22_23);
    lv_style_set_text_opa(&style_screen_picture_display_list_1_extra_texts_main_default, 255);
    lv_style_set_radius(&style_screen_picture_display_list_1_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_screen_picture_display_list_1_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_screen_picture_display_list_1_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_screen_picture_display_list_1_extra_texts_main_default,
                          lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_picture_display_list_1_extra_texts_main_default,
                             LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->screen_picture_display_list_1_item0,
                     &style_screen_picture_display_list_1_extra_texts_main_default,
                     LV_PART_MAIN | LV_STATE_DEFAULT);

    // The custom code of screen_picture_display.

    // Update current screen layout.
    lv_obj_update_layout(ui->screen_picture_display);

    // Init events for screen.
    events_init_screen_picture_display(ui);
}
