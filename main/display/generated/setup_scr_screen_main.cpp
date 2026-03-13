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



void setup_scr_screen_main(lv_ui *ui)
{
    //Write codes screen_main
    ui->screen_main = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_main, 360, 360);
    lv_obj_set_scrollbar_mode(ui->screen_main, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_main, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_main, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_main_img_index
    ui->screen_main_img_index = lv_image_create(ui->screen_main);
    lv_obj_set_pos(ui->screen_main_img_index, 0, 0);
    lv_obj_set_size(ui->screen_main_img_index, 360, 360);
    lv_obj_add_flag(ui->screen_main_img_index, LV_OBJ_FLAG_CLICKABLE);
    // 1. 禁用滚动：禁止图片控件自身响应滚动/滑动
    lv_obj_clear_flag(ui->screen_main_img_index, LV_OBJ_FLAG_SCROLLABLE);
    // 2. 禁用按压锁定：避免滑动时误识别为“拖动控件”
    lv_obj_clear_flag(ui->screen_main_img_index, LV_OBJ_FLAG_PRESS_LOCK);
    // 3. 开启事件+手势冒泡：让滑动手势透传到父容器（屏幕）
    lv_obj_add_flag(ui->screen_main_img_index, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_add_flag(ui->screen_main_img_index, LV_OBJ_FLAG_GESTURE_BUBBLE);
    // 4. 开启浮动：父容器滑动时，图片控件固定位置不跟随移动
    lv_obj_add_flag(ui->screen_main_img_index, LV_OBJ_FLAG_FLOATING);
    // 5. 可选：忽略布局，保留图片自适应大小（不影响位置）
    lv_obj_add_flag(ui->screen_main_img_index, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_img_set_src(ui->screen_main_img_index, all_config.page_pic_display.pic_path_buf);
    lv_obj_align(ui->screen_main_img_index, LV_ALIGN_CENTER, 0, 0);
    ESP_LOGI("main_img", "Display picture: %s; pic_index: %d", all_config.page_pic_display.pic_path_buf, all_config.page_main.pic_main_index);
    lv_image_set_pivot(ui->screen_main_img_index, 50,50);
    lv_image_set_rotation(ui->screen_main_img_index, 0);

    //Write style for screen_main_img_index, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_main_img_index, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_main_img_index, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_main.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_main);

    //Init events for screen.
    events_init_screen_main(ui);
}
