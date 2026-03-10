/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif
#ifndef COMMON_H
#define COMMON_H
#endif
#include "gui_guider.h"
#include "esp_log.h"
#include <stdio.h>

void custom_init(lv_ui *ui);
void lvgl_loop(lv_timer_t *timer);
void getWeather(lv_timer_t *timer);
void lv_img_dynamic_scale(lv_obj_t *img_obj, float scale_x, float scale_y);
#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
