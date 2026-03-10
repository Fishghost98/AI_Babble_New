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
extern "C"
{
#endif

#include "lvgl.h"

	typedef struct
	{
		lv_obj_t *screen_main;
		bool screen_main_del;
		lv_obj_t *screen_main_img_index;
		lv_obj_t *screen_main_gif;
		bool screen_main_gif_del;
		lv_obj_t *screen_main_gif_gif_index;
		lv_obj_t *screen_quick_config;
		bool screen_quick_config_del;
		lv_obj_t *screen_quick_config_slider_volume;
		lv_obj_t *screen_quick_config_slider_backLight;
		lv_obj_t *screen_quick_config_label_volume;
		lv_obj_t *screen_quick_config_label_backLight;
		lv_obj_t *screen_quick_config_btn_power;
		lv_obj_t *screen_quick_config_btn_power_label;
		lv_obj_t *screen_quick_config_bar_battery;
		lv_obj_t *screen_quick_config_label_battery;
		lv_obj_t *screen_quick_config_btn_1;
		lv_obj_t *screen_quick_config_btn_1_label;
		lv_obj_t *screen_quick_config_img_1;
		lv_obj_t *screen_quick_config_img_2;
		lv_obj_t *screen_shutDown;
		bool screen_shutDown_del;
		lv_obj_t *screen_shutDown_slider_1;
		lv_obj_t *screen_shutDown_btn_1;
		lv_obj_t *screen_shutDown_btn_1_label;
		lv_obj_t *screen_shutDown_label_1;
		lv_obj_t *screen_shutDown_img_1;
		lv_obj_t *screen_mainConfig;
		bool screen_mainConfig_del;
		lv_obj_t *screen_mainConfig_label_1;
		lv_obj_t *screen_mainConfig_img_1;
		lv_obj_t *screen_mainConfig_img_2;
		lv_obj_t *screen_mainConfig_img_3;
		lv_obj_t *screen_picture;
		bool screen_picture_del;
		lv_obj_t *screen_picture_label_1;
		lv_obj_t *screen_picture_img_1;
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
		lv_obj_t *screen_gif_label_1;
		lv_obj_t *screen_gif_animimg_1;
		lv_obj_t *screen_clock;
		bool screen_clock_del;
		lv_obj_t *screen_clock_label_1;
		lv_obj_t *screen_clock_img_1;
		lv_obj_t *screen_clock_display;
		bool screen_clock_display_del;
		lv_obj_t *screen_clock_display_img_display;
		lv_obj_t *screen_clock_display_list_1;
		lv_obj_t *screen_clock_display_list_1_item0;
		lv_obj_t *home_analog;
		bool home_analog_del;
		lv_obj_t *home_analog_battery_arc;
		lv_obj_t *home_analog_analog_clock_1;
		lv_obj_t *home_analog_nxp_log;
		lv_obj_t *home_analog_week_day;
		lv_obj_t *home_analog_date_text;
		lv_obj_t *home_analog_battery_icon;
		lv_obj_t *home_analog_battery_text;
		lv_obj_t *home_analog_dot_list;
		lv_obj_t *home_analog_img_dot;
		lv_obj_t *home_digital;
		bool home_digital_del;
		lv_obj_t *home_digital_arc_flash;
		lv_obj_t *home_digital_label_week;
		lv_obj_t *home_digital_label_date;
		lv_obj_t *home_digital_img_flash;
		lv_obj_t *home_digital_label_flashText;
		lv_obj_t *home_digital_img_dialDot;
		lv_obj_t *home_digital_label_min;
		lv_obj_t *home_digital_label_hour;
		lv_obj_t *call_digital_clock_1;
		lv_obj_t *screen_chat;
		bool screen_chat_del;
		lv_obj_t *screen_chat_label_1;
		lv_obj_t *screen_chat_img_1;
		lv_obj_t *screen_chat_img_2;
		lv_obj_t *screen_chat_img_3;
		lv_obj_t *screen_chat_img_4;
		lv_obj_t *screen_chatDetail;
		bool screen_chatDetail_del;
		lv_obj_t *screen_chatDetail_label_;
		lv_obj_t *screen_chatDetail_img_1;
		lv_obj_t *screen_wifiDisconnect;
		bool screen_wifiDisconnect_del;
		lv_obj_t *screen_wifiDisconnect_img_1;
		lv_obj_t *screen_wifiDisconnect_label_;
		lv_obj_t *screen_wifiDisconnect_img_QR;
		lv_obj_t *screen_remind;
		bool screen_remind_del;
		lv_obj_t *screen_remind_label_1;
		lv_obj_t *screen_remind_img_1;
		lv_obj_t *screen_remind_img_2;
		lv_obj_t *screen_remind_img_3;
		lv_obj_t *screen_remind_img_4;
		lv_obj_t *screen_remindDetail;
		bool screen_remindDetail_del;
		lv_obj_t *screen_remindDetail_label_1;
		lv_obj_t *screen_remindDetail_cont_remind;
		lv_obj_t *screen_remindDetail_cont_detail4;
		lv_obj_t *screen_remindDetail_label_11;
		lv_obj_t *screen_remindDetail_sw_5;
		lv_obj_t *screen_remindDetail_label_10;
		lv_obj_t *screen_remindDetail_label_remindTime4;
		lv_obj_t *screen_remindDetail_cont_detail3;
		lv_obj_t *screen_remindDetail_label_7;
		lv_obj_t *screen_remindDetail_sw_3;
		lv_obj_t *screen_remindDetail_label_6;
		lv_obj_t *screen_remindDetail_label_remindTime3;
		lv_obj_t *screen_remindDetail_cont_detail2;
		lv_obj_t *screen_remindDetail_label_remindMessage2;
		lv_obj_t *screen_remindDetail_sw_remindBtn2;
		lv_obj_t *screen_remindDetail_label_remindDate2;
		lv_obj_t *screen_remindDetail_label_remindTime2;
		lv_obj_t *screen_remindDetail_cont_detail1;
		lv_obj_t *screen_remindDetail_label_remindMessage1;
		lv_obj_t *screen_remindDetail_sw_remindBtn1;
		lv_obj_t *screen_remindDetail_label_remindDate1;
		lv_obj_t *screen_remindDetail_label_remindTime1;
		lv_obj_t *screen_remindDetail_list_1;
		lv_obj_t *screen_remindDetail_list_1_item0;
		lv_obj_t *screen_meeting;
		bool screen_meeting_del;
		lv_obj_t *screen_meeting_label_1;
		lv_obj_t *screen_meeting_img_1;
		lv_obj_t *screen_meeting_img_2;
		lv_obj_t *screen_meeting_img_3;
		lv_obj_t *screen_meeting_img_4;
		lv_obj_t *screen_meetingDetail;
		bool screen_meetingDetail_del;
		lv_obj_t *screen_meetingDetail_btn_start;
		lv_obj_t *screen_meetingDetail_btn_start_label;
		lv_obj_t *screen_meetingDetail_bar_battery;
		lv_obj_t *screen_meetingDetail_label_battery;
		lv_obj_t *screen_meetingDetail_label_2;
		lv_obj_t *screen_meetingDetail_digital_clock_1;
		lv_obj_t *screen_systemConfig;
		bool screen_systemConfig_del;
		lv_obj_t *screen_systemConfig_label_1;
		lv_obj_t *screen_systemConfig_img_1;
		lv_obj_t *screen_systemConfig_img_2;
		lv_obj_t *screen_systemConfig_img_3;
		lv_obj_t *screen_systemConfig_img_4;
		lv_obj_t *screen_systemConfig1;
		bool screen_systemConfig1_del;
		lv_obj_t *screen_systemConfig1_cont_9;
		lv_obj_t *screen_systemConfig1_cont_7;
		lv_obj_t *screen_systemConfig1_img_8;
		lv_obj_t *screen_systemConfig1_label_6;
		lv_obj_t *screen_systemConfig1_img_7;
		lv_obj_t *screen_systemConfig1_cont_8;
		lv_obj_t *screen_systemConfig1_cont_5;
		lv_obj_t *screen_systemConfig1_img_6;
		lv_obj_t *screen_systemConfig1_label_5;
		lv_obj_t *screen_systemConfig1_img_5;
		lv_obj_t *screen_systemConfig1_cont_6;
		lv_obj_t *screen_systemConfig1_cont_3;
		lv_obj_t *screen_systemConfig1_img_4;
		lv_obj_t *screen_systemConfig1_label_4;
		lv_obj_t *screen_systemConfig1_img_3;
		lv_obj_t *screen_systemConfig1_cont_4;
		lv_obj_t *screen_systemConfig1_cont_2;
		lv_obj_t *screen_systemConfig1_img_1;
		lv_obj_t *screen_systemConfig1_label_3;
		lv_obj_t *screen_systemConfig1_img_2;
		lv_obj_t *screen_systemConfig1_cont_1;
		lv_obj_t *screen_systemConfig1_label_1;
		lv_obj_t *screen_autoShutDown;
		bool screen_autoShutDown_del;
		lv_obj_t *screen_autoShutDown_label_6;
		lv_obj_t *screen_autoShutDown_label_1;
		lv_obj_t *screen_autoShutDown_list_1;
		lv_obj_t *screen_autoShutDown_list_1_item0;
		lv_obj_t *screen_autoShutDown_list_1_item1;
		lv_obj_t *screen_autoShutDown_list_1_item2;
		lv_obj_t *screen_autoShutDown_list_1_item3;
		lv_obj_t *screen_autoShutDown_list_1_item4;
		lv_obj_t *screen_autoShutDown_list_1_item5;
		lv_obj_t *screen_device_information;
		bool screen_device_information_del;
		lv_obj_t *screen_device_information_label_1;
		lv_obj_t *screen_device_information_cont_1;
		lv_obj_t *screen_device_information_cont_2;
		lv_obj_t *screen_device_information_img_1;
		lv_obj_t *screen_device_information_label_2;
		lv_obj_t *screen_device_information_label_3;
		lv_obj_t *screen_device_information_img_2;
		lv_obj_t *screen_device_information_cont_3;
		lv_obj_t *screen_device_information_img_4;
		lv_obj_t *screen_device_information_label_5;
		lv_obj_t *screen_device_information_label_4;
		lv_obj_t *screen_device_information_img_3;
		lv_obj_t *screen_device_information_cont_4;
		lv_obj_t *screen_device_information_img_6;
		lv_obj_t *screen_device_information_label_7;
		lv_obj_t *screen_device_information_label_6;
		lv_obj_t *screen_device_information_img_5;
		lv_obj_t *screen_device_information_cont_5;
		lv_obj_t *screen_device_information_img_8;
		lv_obj_t *screen_device_information_label_9;
		lv_obj_t *screen_device_information_label_8;
		lv_obj_t *screen_device_information_img_7;
		lv_obj_t *screen_device_information_cont_6;
		lv_obj_t *screen_device_information_img_10;
		lv_obj_t *screen_device_information_label_11;
		lv_obj_t *screen_device_information_label_10;
		lv_obj_t *screen_device_information_img_9;
		lv_obj_t *screen_reset;
		bool screen_reset_del;
		lv_obj_t *screen_reset_label_1;
		lv_obj_t *screen_reset_slider_1;
		lv_obj_t *screen_reset_btn_1;
		lv_obj_t *screen_reset_img_1;
		lv_obj_t *screen_reset_btn_1_label;
		lv_obj_t *screen_home;
		bool screen_home_del;
		lv_obj_t *screen_home_label_1;
		lv_obj_t *screen_home_label_2;
		lv_obj_t *screen_home_img_2;
		lv_obj_t *screen_home_label_3;
		lv_obj_t *screen_home_animimg_1;
	} lv_ui;

	typedef void (*ui_setup_scr_t)(lv_ui *ui);

	void ui_init_style(lv_style_t *style);

	void ui_load_scr_animation(lv_ui *ui, lv_obj_t **new_scr, bool new_scr_del, bool *old_scr_del, ui_setup_scr_t setup_scr,
							   lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

	void ui_animation(void *var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
					  uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
					  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

	void init_scr_del_flag(lv_ui *ui);

	void setup_ui(lv_ui *ui);

	void init_keyboard(lv_ui *ui);

	extern lv_ui guider_ui;

	void setup_scr_screen_home(lv_ui *ui);
	void setup_scr_screen_main(lv_ui *ui);
	void setup_scr_screen_main_gif(lv_ui *ui);
	void setup_scr_screen_quick_config(lv_ui *ui);
	void setup_scr_screen_shutDown(lv_ui *ui);
	void setup_scr_screen_mainConfig(lv_ui *ui);
	void setup_scr_screen_picture(lv_ui *ui);
	void setup_scr_screen_picture_display(lv_ui *ui);
	void setup_scr_screen_gif_display(lv_ui *ui);
	void setup_scr_screen_gif(lv_ui *ui);
	void setup_scr_screen_clock(lv_ui *ui);
	void setup_scr_screen_clock_display(lv_ui *ui);
	void setup_scr_home_analog(lv_ui *ui);
	void setup_scr_home_digital(lv_ui *ui);
	void setup_scr_screen_chat(lv_ui *ui);
	void setup_scr_screen_chatDetail(lv_ui *ui);
	void setup_scr_screen_wifiDisconnect(lv_ui *ui);
	void setup_scr_screen_remind(lv_ui *ui);
	void setup_scr_screen_remindDetail(lv_ui *ui);
	void setup_scr_screen_meeting(lv_ui *ui);
	void setup_scr_screen_meetingDetail(lv_ui *ui);
	void setup_scr_screen_systemConfig(lv_ui *ui);
	void setup_scr_screen_systemConfig1(lv_ui *ui);
	void setup_scr_screen_autoShutDown(lv_ui *ui);
	void setup_scr_screen_device_information(lv_ui *ui);
	void setup_scr_screen_reset(lv_ui *ui);

	LV_IMAGE_DECLARE(_power_80x80);
	LV_IMAGE_DECLARE(_black_alpha_20x20);
	LV_IMAGE_DECLARE(_guanbi_70x70);
	LV_IMAGE_DECLARE(_main_alpha_180x180);
	LV_IMAGE_DECLARE(_duanwang_alpha_50x50);
	LV_IMAGE_DECLARE(_mic_alpha_20x20);
	LV_IMAGE_DECLARE(_selected_green_alpha_20x20);
	LV_IMAGE_DECLARE(_analog_img_alpha_250x250);
	LV_IMAGE_DECLARE(_analog_img_alpha_180x180);
	LV_IMAGE_DECLARE(_digital_img_alpha_250x250);
	LV_IMAGE_DECLARE(_img_bg_analog_360x360);
	LV_IMAGE_DECLARE(_img_bg_digital_360x360);
	LV_IMAGE_DECLARE(_img_clockwise_hour_alpha_98x18);
	LV_IMAGE_DECLARE(_img_clockwise_min_alpha_157x18);
	LV_IMAGE_DECLARE(_img_clockwise_sec_alpha_180x31);
	LV_IMAGE_DECLARE(_icn_flash_blue_alpha_15x19);
	LV_IMAGE_DECLARE(_img_menu_alpha_10x107);
	LV_IMAGE_DECLARE(_bk2_360x360);
	LV_IMAGE_DECLARE(_left1_alpha_75x290);
	LV_IMAGE_DECLARE(_reset1_alpha_50x50);
	LV_IMAGE_DECLARE(_right1_alpha_25x25);
	LV_IMAGE_DECLARE(_right2_alpha_75x290);
	LV_IMAGE_DECLARE(_dot1_alpha_50x6);
	LV_IMAGE_DECLARE(_dot2_alpha_50x6);
	LV_IMAGE_DECLARE(_dot3_alpha_50x6);
	LV_IMAGE_DECLARE(_dot4_alpha_50x6);
	LV_IMAGE_DECLARE(_dot5_alpha_50x6);
	LV_IMAGE_DECLARE(_main1_alpha_150x150);
	LV_IMAGE_DECLARE(_chat1_alpha_150x150);
	LV_IMAGE_DECLARE(_remind1_alpha_150x150);
	LV_IMAGE_DECLARE(_meeting1_alpha_150x150);
	LV_IMAGE_DECLARE(_system1_alpha_150x150);
	LV_IMAGE_DECLARE(_start1_80x80);
	LV_IMAGE_DECLARE(_pause1_80x80);
	LV_IMAGE_DECLARE(_vol1_alpha_25x25);
	LV_IMAGE_DECLARE(_sun1_alpha_25x25);
	LV_IMAGE_DECLARE(_cancel_60x60);
	LV_IMAGE_DECLARE(_reset1_70x70);
	LV_IMAGE_DECLARE(_reset1_alpha_70x70);
	LV_IMAGE_DECLARE(_reset1_alpha_52x52);
	LV_IMAGE_DECLARE(_turnoff_50x50);
	LV_IMAGE_DECLARE(_turnoff_70x70);
	LV_IMAGE_DECLARE(_turnoff_alpha_52x52);
	LV_IMAGE_DECLARE(_wifi1_50x50);
	LV_IMAGE_DECLARE(_Frame1_alpha_40x40);
	LV_IMAGE_DECLARE(_Frame4_alpha_40x40);
	LV_IMAGE_DECLARE(_Frame3_alpha_40x40);
	LV_IMAGE_DECLARE(_Frame2_alpha_40x40);
	LV_IMAGE_DECLARE(_Frame5_alpha_40x40);
	LV_IMAGE_DECLARE(_g1_alpha_70x70);
	LV_IMAGE_DECLARE(_g2_alpha_70x70);
	LV_IMAGE_DECLARE(_g3_alpha_70x70);
	LV_IMAGE_DECLARE(_chat_360x360);
	LV_IMAGE_DECLARE(_bk1_360x360);
	LV_IMAGE_DECLARE(_home_360x360);
	LV_IMAGE_DECLARE(_chat_360x360);
	LV_IMAGE_DECLARE(_remind_360x360);
	LV_IMAGE_DECLARE(_meeting_360x360);
	LV_IMAGE_DECLARE(_sys_360x360);

	LV_IMAGE_DECLARE(_home_alpha_250x250);
	LV_IMAGE_DECLARE(_sun_alpha_40x40);
	LV_IMAGE_DECLARE(_w1_alpha_40x40);
	LV_IMAGE_DECLARE(_w2_alpha_40x40);
	LV_IMAGE_DECLARE(_w3_alpha_40x40);
	LV_IMAGE_DECLARE(_w4_alpha_40x40);
	LV_IMAGE_DECLARE(_w5_alpha_40x40);
	LV_IMAGE_DECLARE(_w6_alpha_40x40);

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

	LV_FONT_DECLARE(lv_font_montserratMedium_11)
	LV_FONT_DECLARE(lv_font_montserratMedium_12)
	LV_FONT_DECLARE(lv_font_montserratMedium_14)
	LV_FONT_DECLARE(lv_font_montserratMedium_16)
	LV_FONT_DECLARE(lv_font_montserratMedium_20)
	LV_FONT_DECLARE(lv_font_montserratMedium_23)
	LV_FONT_DECLARE(lv_font_montserratMedium_30)
	LV_FONT_DECLARE(lv_font_montserratMedium_50)
	LV_FONT_DECLARE(lv_font_montserratMedium_101)
	LV_FONT_DECLARE(lv_font_montserratMedium_110)

	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_12)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_13)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_16)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_18)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_19)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_20)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_23)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_25)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_28)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_30)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_32)
	LV_FONT_DECLARE(lv_font_ZiTiQuanWeiJunHeiW22_85)

#ifdef __cplusplus
}
#endif
#endif
