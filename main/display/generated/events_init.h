/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void events_init(lv_ui *ui);

void events_init_screen_main(lv_ui *ui);
void events_init_screen_main_gif(lv_ui *ui);
void events_init_screen_quick_config(lv_ui *ui);
void events_init_screen_shutDown(lv_ui *ui);
void events_init_screen_mainConfig(lv_ui *ui);
void events_init_screen_picture(lv_ui *ui);
void events_init_screen_picture_display(lv_ui *ui);
void events_init_screen_gif_display(lv_ui *ui);
void events_init_screen_gif(lv_ui *ui);
void events_init_screen_clock(lv_ui *ui);
void events_init_screen_clock_display(lv_ui *ui);
void events_init_home_analog (lv_ui *ui);
void events_init_home_digital (lv_ui *ui);
void events_init_screen_home (lv_ui *ui);
void events_init_screen_chat(lv_ui *ui);
void events_init_screen_chatDetail(lv_ui *ui);
void events_init_screen_wifiDisconnect(lv_ui *ui);
void events_init_screen_remind(lv_ui *ui);
void events_init_screen_remindDetail(lv_ui *ui);
void events_init_screen_meeting(lv_ui *ui);
void events_init_screen_meetingDetail(lv_ui *ui);
void events_init_screen_systemConfig(lv_ui *ui);
void events_init_screen_systemConfig1(lv_ui *ui);
void events_init_screen_autoShutDown(lv_ui *ui);
void events_init_screen_device_information(lv_ui *ui);
void events_init_screen_reset(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
