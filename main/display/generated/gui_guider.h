/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *screen_mainConfig;
	bool screen_mainConfig_del;
	lv_obj_t *screen_mainConfig_img_1;
	lv_obj_t *screen_mainConfig_img_2;
	lv_obj_t *screen_mainConfig_img_3;
	lv_obj_t *screen_mainConfig_label_1;
	lv_obj_t *screen_mainConfig_img_4;
	lv_obj_t *screen_chat;
	bool screen_chat_del;
	lv_obj_t *screen_chat_label_1;
	lv_obj_t *screen_chat_img_1;
	lv_obj_t *screen_chat_img_2;
	lv_obj_t *screen_chat_img_3;
	lv_obj_t *screen_chat_img_4;
	lv_obj_t *screen_remind;
	bool screen_remind_del;
	lv_obj_t *screen_remind_label_1;
	lv_obj_t *screen_remind_img_1;
	lv_obj_t *screen_remind_img_2;
	lv_obj_t *screen_remind_img_3;
	lv_obj_t *screen_remind_img_4;
	lv_obj_t *screen_meeting;
	bool screen_meeting_del;
	lv_obj_t *screen_meeting_label_1;
	lv_obj_t *screen_meeting_img_1;
	lv_obj_t *screen_meeting_img_2;
	lv_obj_t *screen_meeting_img_3;
	lv_obj_t *screen_meeting_img_4;
	lv_obj_t *screen_systemConfig;
	bool screen_systemConfig_del;
	lv_obj_t *screen_systemConfig_label_1;
	lv_obj_t *screen_systemConfig_img_1;
	lv_obj_t *screen_systemConfig_img_2;
	lv_obj_t *screen_systemConfig_img_3;
	lv_obj_t *screen_systemConfig_img_4;
	lv_obj_t *screen_quick_config;
	bool screen_quick_config_del;
	lv_obj_t *screen_quick_config_slider_volume;
	lv_obj_t *screen_quick_config_slider_backLight;
	lv_obj_t *screen_quick_config_img_1;
	lv_obj_t *screen_quick_config_img_2;
	lv_obj_t *screen_quick_config_label_volume;
	lv_obj_t *screen_quick_config_label_backLight;
	lv_obj_t *screen_quick_config_btn_power;
	lv_obj_t *screen_quick_config_btn_power_label;
	lv_obj_t *screen_quick_config_bar_battery;
	lv_obj_t *screen_quick_config_label_battery;
	lv_obj_t *screen_quick_config_btn_1;
	lv_obj_t *screen_quick_config_btn_1_label;
	lv_obj_t *screen_shutDown;
	bool screen_shutDown_del;
	lv_obj_t *screen_shutDown_label_1;
	lv_obj_t *screen_shutDown_btn_1;
	lv_obj_t *screen_shutDown_btn_1_label;
	lv_obj_t *screen_shutDown_slider_1;
	lv_obj_t *screen_picture;
	bool screen_picture_del;
	lv_obj_t *screen_picture_img_1;
	lv_obj_t *screen_picture_label_1;
	lv_obj_t *screen_picture_display;
	bool screen_picture_display_del;
	lv_obj_t *screen_picture_display_img_display;
	lv_obj_t *screen_picture_display_list_1;
	lv_obj_t *screen_picture_display_list_1_item0;
	lv_obj_t *screen_gif_display;
	bool screen_gif_display_del;
	lv_obj_t *screen_gif_display_img_display;
	lv_obj_t *screen_gif_display_list_1;
	lv_obj_t *screen_gif_display_list_1_item0;
	lv_obj_t *screen_gif;
	bool screen_gif_del;
	lv_obj_t *screen_gif_img_1;
	lv_obj_t *screen_gif_label_1;
	lv_obj_t *screen_clock;
	bool screen_clock_del;
	lv_obj_t *screen_clock_img_1;
	lv_obj_t *screen_clock_screen_systemConfig1;
	lv_obj_t *screen_systemConfig1;
	bool screen_systemConfig1_del;
	lv_obj_t *screen_systemConfig1_cont_3;
	lv_obj_t *screen_systemConfig1_cont_2;
	lv_obj_t *screen_systemConfig1_img_1;
	lv_obj_t *screen_systemConfig1_label_3;
	lv_obj_t *screen_systemConfig1_img_2;
	lv_obj_t *screen_systemConfig1_cont_1;
	lv_obj_t *screen_systemConfig1_cont_4;
	lv_obj_t *screen_systemConfig1_img_4;
	lv_obj_t *screen_systemConfig1_label_4;
	lv_obj_t *screen_systemConfig1_img_3;
	lv_obj_t *screen_systemConfig1_cont_5;
	lv_obj_t *screen_systemConfig1_cont_6;
	lv_obj_t *screen_systemConfig1_img_6;
	lv_obj_t *screen_systemConfig1_label_5;
	lv_obj_t *screen_systemConfig1_img_5;
	lv_obj_t *screen_systemConfig1_cont_7;
	lv_obj_t *screen_systemConfig1_cont_8;
	lv_obj_t *screen_systemConfig1_img_8;
	lv_obj_t *screen_systemConfig1_label_6;
	lv_obj_t *screen_systemConfig1_img_7;
	lv_obj_t *screen_systemConfig1_cont_9;
	lv_obj_t *screen_systemConfig1_label_1;
	lv_obj_t *screen_autoShutDown;
	bool screen_autoShutDown_del;
	lv_obj_t *screen_autoShutDown_label_1;
	lv_obj_t *screen_autoShutDown_label_2;
	lv_obj_t *screen_autoShutDown_list_1;
	lv_obj_t *screen_autoShutDown_list_1_item0;
	lv_obj_t *screen_autoShutDown_list_1_item1;
	lv_obj_t *screen_autoShutDown_list_1_item2;
	lv_obj_t *screen_autoShutDown_list_1_item3;
	lv_obj_t *screen_autoShutDown_list_1_item4;
	lv_obj_t *screen_autoShutDown_list_1_item5;
	lv_obj_t *screen_reset;
	bool screen_reset_del;
	lv_obj_t *screen_reset_label_1;
	lv_obj_t *screen_reset_btn_1;
	lv_obj_t *screen_reset_btn_1_label;
	lv_obj_t *screen_reset_slider_1;
	lv_obj_t *screen_device_information;
	bool screen_device_information_del;
	lv_obj_t *screen_device_information_cont_3;
	lv_obj_t *screen_device_information_cont_10;
	lv_obj_t *screen_device_information_img_10;
	lv_obj_t *screen_device_information_label_7;
	lv_obj_t *screen_device_information_img_9;
	lv_obj_t *screen_device_information_label_8;
	lv_obj_t *screen_device_information_cont_11;
	lv_obj_t *screen_device_information_img_12;
	lv_obj_t *screen_device_information_label_10;
	lv_obj_t *screen_device_information_img_11;
	lv_obj_t *screen_device_information_label_9;
	lv_obj_t *screen_device_information_cont_12;
	lv_obj_t *screen_device_information_img_14;
	lv_obj_t *screen_device_information_label_12;
	lv_obj_t *screen_device_information_img_13;
	lv_obj_t *screen_device_information_label_11;
	lv_obj_t *screen_device_information_cont_13;
	lv_obj_t *screen_device_information_img_16;
	lv_obj_t *screen_device_information_label_14;
	lv_obj_t *screen_device_information_img_15;
	lv_obj_t *screen_device_information_label_13;
	lv_obj_t *screen_device_information_cont_14;
	lv_obj_t *screen_device_information_img_18;
	lv_obj_t *screen_device_information_label_16;
	lv_obj_t *screen_device_information_img_17;
	lv_obj_t *screen_device_information_label_15;
	lv_obj_t *screen_device_information_label_1;
	lv_obj_t *screen_home;
	bool screen_home_del;
	lv_obj_t *screen_home_label_1;
	lv_obj_t *screen_home_img_1;
	lv_obj_t *screen_home_label_2;
	lv_obj_t *screen_home_label_3;
	lv_obj_t *screen_home_animimg_1;
	lv_obj_t *home_analog;
	bool home_analog_del;
	lv_obj_t *home_analog_battery_arc;
	lv_obj_t *home_analog_analog_clock_1;
	lv_obj_t *home_analog_analog_clock_1_hour_needle;
	lv_obj_t *home_analog_analog_clock_1_min_needle;
	lv_obj_t *home_analog_analog_clock_1_sec_needle;
	lv_obj_t *home_analog_week_day;
	lv_obj_t *home_analog_date_text;
	lv_obj_t *home_analog_battery_icon;
	lv_obj_t *home_analog_battery_text;
	lv_obj_t *home_digital;
	bool home_digital_del;
	lv_obj_t *home_digital_battery_arc;
	lv_obj_t *home_digital_week_day;
	lv_obj_t *home_digital_date_text;
	lv_obj_t *home_digital_battery_icon;
	lv_obj_t *home_digital_battery_text;
	lv_obj_t *home_digital_img_1;
	lv_obj_t *home_digital_label_min;
	lv_obj_t *home_digital_label_hour;
	lv_obj_t *screen_main;
	bool screen_main_del;
	lv_obj_t *screen_main_img_1;
	lv_obj_t *screen_main_gif;
	bool screen_main_gif_del;
	lv_obj_t *screen_main_gif_img_1;
	lv_obj_t *screen_chatDetail;
	bool screen_chatDetail_del;
	lv_obj_t *screen_chatDetail_label_chat;
	lv_obj_t *screen_chatDetail_animimg_1;
	lv_obj_t *screen_remindDetail;
	bool screen_remindDetail_del;
	lv_obj_t *screen_remindDetail_label_1;
	lv_obj_t *screen_remindDetail_cont_remind;
	lv_obj_t *screen_remindDetail_cont_detail1;
	lv_obj_t *screen_remindDetail_label_3;
	lv_obj_t *screen_remindDetail_label_remindDate1;
	lv_obj_t *screen_remindDetail_label_remindTime1;
	lv_obj_t *screen_remindDetail_sw_1;
	lv_obj_t *screen_remindDetail_list_1;
	lv_obj_t *screen_remindDetail_list_1_item0;
	lv_obj_t *screen_meetingDetail;
	bool screen_meetingDetail_del;
	lv_obj_t *screen_meetingDetail_btn_1;
	lv_obj_t *screen_meetingDetail_btn_1_label;
	lv_obj_t *screen_meetingDetail_bar_1;
	lv_obj_t *screen_meetingDetail_label_battery;
	lv_obj_t *screen_meetingDetail_label_2;
	lv_obj_t *screen_meetingDetail_digital_clock_1;
	lv_obj_t *screen_clock_display;
	bool screen_clock_display_del;
	lv_obj_t *screen_clock_display_img_display;
	lv_obj_t *screen_clock_display_list_1;
	lv_obj_t *screen_clock_display_list_1_item0;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen_mainConfig(lv_ui *ui);
void setup_scr_screen_chat(lv_ui *ui);
void setup_scr_screen_remind(lv_ui *ui);
void setup_scr_screen_meeting(lv_ui *ui);
void setup_scr_screen_systemConfig(lv_ui *ui);
void setup_scr_screen_quick_config(lv_ui *ui);
void setup_scr_screen_shutDown(lv_ui *ui);
void setup_scr_screen_picture(lv_ui *ui);
void setup_scr_screen_picture_display(lv_ui *ui);
void setup_scr_screen_gif_display(lv_ui *ui);
void setup_scr_screen_gif(lv_ui *ui);
void setup_scr_screen_clock(lv_ui *ui);
void setup_scr_screen_systemConfig1(lv_ui *ui);
void setup_scr_screen_autoShutDown(lv_ui *ui);
void setup_scr_screen_reset(lv_ui *ui);
void setup_scr_screen_device_information(lv_ui *ui);
void setup_scr_screen_home(lv_ui *ui);
void setup_scr_home_analog(lv_ui *ui);
void setup_scr_home_digital(lv_ui *ui);
void setup_scr_screen_main(lv_ui *ui);
void setup_scr_screen_main_gif(lv_ui *ui);
void setup_scr_screen_chatDetail(lv_ui *ui);
void setup_scr_screen_remindDetail(lv_ui *ui);
void setup_scr_screen_meetingDetail(lv_ui *ui);
void setup_scr_screen_clock_display(lv_ui *ui);

LV_IMAGE_DECLARE(_bk2_RGB565A8_360x360);
LV_IMAGE_DECLARE(_main1_RGB565A8_150x150);
LV_IMAGE_DECLARE(_right2_RGB565A8_75x290);
LV_IMAGE_DECLARE(_dot1_RGB565A8_50x6);
LV_IMAGE_DECLARE(_left1_RGB565A8_75x290);
LV_IMAGE_DECLARE(_chat1_RGB565A8_150x150);
LV_IMAGE_DECLARE(_dot2_RGB565A8_50x6);
LV_IMAGE_DECLARE(_remind1_RGB565A8_150x150);
LV_IMAGE_DECLARE(_dot3_RGB565A8_50x6);
LV_IMAGE_DECLARE(_meeting1_RGB565A8_150x150);
LV_IMAGE_DECLARE(_dot4_RGB565A8_50x6);
LV_IMAGE_DECLARE(_system1_RGB565A8_150x150);
LV_IMAGE_DECLARE(_dot5_RGB565A8_50x6);
LV_IMAGE_DECLARE(_vol1_RGB565A8_25x25);
LV_IMAGE_DECLARE(_sun1_RGB565A8_25x25);

LV_IMAGE_DECLARE(_turnoff_RGB565A8_50x50);

LV_IMAGE_DECLARE(_wifi1_RGB565A8_50x50);

LV_IMAGE_DECLARE(_cancel_RGB565A8_60x60);

LV_IMAGE_DECLARE(_turnoff_RGB565A8_70x70);
LV_IMAGE_DECLARE(_main_RGB565A8_180x180_RLE);
LV_IMAGE_DECLARE(_main_RGB565A8_250x250);
LV_IMAGE_DECLARE(_analog_img_RGB565A8_180x180_RLE);
LV_IMAGE_DECLARE(_g1_RGB565A8_70x70);
LV_IMAGE_DECLARE(_right1_RGB565A8_25x25);
LV_IMAGE_DECLARE(_g2_RGB565A8_70x70);
LV_IMAGE_DECLARE(_reset1_RGB565A8_70x70);
LV_IMAGE_DECLARE(_g3_RGB565A8_70x70);
LV_IMAGE_DECLARE(_selected_green_RGB565_20x20);
LV_IMAGE_DECLARE(_black_RGB565_20x20);
LV_IMAGE_DECLARE(_Frame1_RGB565A8_40x40);
LV_IMAGE_DECLARE(_Frame2_RGB565A8_40x40);
LV_IMAGE_DECLARE(_Frame3_RGB565A8_40x40);
LV_IMAGE_DECLARE(_Frame4_RGB565A8_40x40);
LV_IMAGE_DECLARE(_Frame5_RGB565A8_40x40);

LV_IMAGE_DECLARE(_bk1_RGB565A8_360x360);
LV_IMAGE_DECLARE(_sun1_RGB565A8_40x40);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_00);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_01);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_02);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_03);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_04);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_05);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_06);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_07);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_08);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_09);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_10);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_11);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_12);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_13);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_14);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_15);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_16);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_17);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_18);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_19);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_20);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_21);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_22);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_23);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_24);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_25);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_26);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_27);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_28);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_29);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_30);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_31);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_32);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_33);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_34);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_35);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_36);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_37);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_38);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_39);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_40);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_41);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_42);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_43);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_44);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_45);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_46);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_47);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_48);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_49);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_50);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_51);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_52);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_53);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_54);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_55);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_56);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_57);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_58);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_59);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_60);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_61);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_62);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_63);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_64);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_65);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_66);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_67);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_68);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_69);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_70);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_71);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_72);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_73);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_74);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_75);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_76);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_77);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_78);
LV_IMAGE_DECLARE(screen_home_animimg_1gif1_79);

LV_IMAGE_DECLARE(_img_bg_analog_RGB565A8_360x360);
LV_IMAGE_DECLARE(_img_clockwise_hour_RGB565A8_98x18);
LV_IMAGE_DECLARE(_img_clockwise_min_RGB565A8_157x18);
LV_IMAGE_DECLARE(_img_clockwise_sec_RGB565A8_180x31);
LV_IMAGE_DECLARE(_icn_flash_blue_RGB565A8_15x19);

LV_IMAGE_DECLARE(_img_bg_digital_RGB565A8_360x360);
LV_IMAGE_DECLARE(_img_menu_RGB565A8_10x127);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_00_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_01_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_02_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_03_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_04_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_05_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_06_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_07_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_08_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_09_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_10_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_11_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_12_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_13_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_14_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_15_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_16_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_17_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_18_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_19_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_20_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_21_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_22_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_23_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_24_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_25_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_26_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_27_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_28_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_29_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_30_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_31_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_32_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_33_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_34_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_35_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_36_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_37_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_38_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_39_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_40_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_41_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_42_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_43_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_44_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_45_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_46_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_47_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_48_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_49_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_50_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_51_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_52_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_53_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_54_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_55_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_56_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_57_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_58_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_59_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_60_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_61_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_62_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_63_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_64_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_65_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_66_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_67_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_68_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_69_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_70_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_71_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_72_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_73_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_74_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_75_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_76_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_77_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_78_RLE);
LV_IMAGE_DECLARE(screen_chatDetail_animimg_1gif1_79_RLE);
LV_IMAGE_DECLARE(_mic_RGB565_20x20);

LV_IMAGE_DECLARE(_start1_RGB565A8_80x80);
LV_IMAGE_DECLARE(_analog_img_RGB565A8_250x250);

LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_30)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_23)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_25)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_32)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_28)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_20)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_13)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_85)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_101)
LV_FONT_DECLARE(lv_font_montserratMedium_110)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_19)
LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_16)
LV_FONT_DECLARE(lv_font_montserratMedium_50)


#ifdef __cplusplus
}
#endif
#endif
