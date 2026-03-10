/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include "gui_guider.h"
#include "widgets_init.h"
#include <stdlib.h>
#include <string.h>


__attribute__((unused)) void kb_event_cb (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
    if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

__attribute__((unused)) void ta_event_cb (lv_event_t *e) {
#if LV_USE_KEYBOARD
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);

    if(code == LV_EVENT_FOCUSED) {
        if(lv_indev_get_type(lv_indev_active()) != LV_INDEV_TYPE_KEYPAD) {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
        }
    } else if(code == LV_EVENT_READY) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_state(ta, LV_STATE_FOCUSED);
        lv_indev_reset(NULL, ta);
    } else if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
#endif
}

void clock_count(int *hour, int *min, int *sec)
{
    (*sec)++;
    if(*sec == 60)
    {
        *sec = 0;
        (*min)++;
    }
    if(*min == 60)
    {
        *min = 0;
        if(*hour < 12)
        {
            (*hour)++;
        } else {
            (*hour)++;
            *hour = *hour %12;
        }
    }
}

void digital_clock_count(int * hour, int * minute, int * seconds, char * meridiem)
{

    (*seconds)++;
    if(*seconds == 60) {
        *seconds = 0;
        (*minute)++;
    }
    if(*minute == 60) {
        *minute = 0;
        if(*hour < 12) {
            (*hour)++;
        }
        else {
            (*hour)++;
            (*hour) = (*hour) % 12;
        }
    }
    if(*hour == 12 && *seconds == 0 && *minute == 0) {
        if((lv_strcmp(meridiem, "PM") == 0)) {
            lv_strcpy(meridiem, "AM");
        }
        else {
            lv_strcpy(meridiem, "PM");
        }
    }
}


const lv_image_dsc_t * screen_home_animimg_1_imgs[80] = {
    &screen_home_animimg_1gif1_00,
    &screen_home_animimg_1gif1_01,
    &screen_home_animimg_1gif1_02,
    &screen_home_animimg_1gif1_03,
    &screen_home_animimg_1gif1_04,
    &screen_home_animimg_1gif1_05,
    &screen_home_animimg_1gif1_06,
    &screen_home_animimg_1gif1_07,
    &screen_home_animimg_1gif1_08,
    &screen_home_animimg_1gif1_09,
    &screen_home_animimg_1gif1_10,
    &screen_home_animimg_1gif1_11,
    &screen_home_animimg_1gif1_12,
    &screen_home_animimg_1gif1_13,
    &screen_home_animimg_1gif1_14,
    &screen_home_animimg_1gif1_15,
    &screen_home_animimg_1gif1_16,
    &screen_home_animimg_1gif1_17,
    &screen_home_animimg_1gif1_18,
    &screen_home_animimg_1gif1_19,
    &screen_home_animimg_1gif1_20,
    &screen_home_animimg_1gif1_21,
    &screen_home_animimg_1gif1_22,
    &screen_home_animimg_1gif1_23,
    &screen_home_animimg_1gif1_24,
    &screen_home_animimg_1gif1_25,
    &screen_home_animimg_1gif1_26,
    &screen_home_animimg_1gif1_27,
    &screen_home_animimg_1gif1_28,
    &screen_home_animimg_1gif1_29,
    &screen_home_animimg_1gif1_30,
    &screen_home_animimg_1gif1_31,
    &screen_home_animimg_1gif1_32,
    &screen_home_animimg_1gif1_33,
    &screen_home_animimg_1gif1_34,
    &screen_home_animimg_1gif1_35,
    &screen_home_animimg_1gif1_36,
    &screen_home_animimg_1gif1_37,
    &screen_home_animimg_1gif1_38,
    &screen_home_animimg_1gif1_39,
    &screen_home_animimg_1gif1_40,
    &screen_home_animimg_1gif1_41,
    &screen_home_animimg_1gif1_42,
    &screen_home_animimg_1gif1_43,
    &screen_home_animimg_1gif1_44,
    &screen_home_animimg_1gif1_45,
    &screen_home_animimg_1gif1_46,
    &screen_home_animimg_1gif1_47,
    &screen_home_animimg_1gif1_48,
    &screen_home_animimg_1gif1_49,
    &screen_home_animimg_1gif1_50,
    &screen_home_animimg_1gif1_51,
    &screen_home_animimg_1gif1_52,
    &screen_home_animimg_1gif1_53,
    &screen_home_animimg_1gif1_54,
    &screen_home_animimg_1gif1_55,
    &screen_home_animimg_1gif1_56,
    &screen_home_animimg_1gif1_57,
    &screen_home_animimg_1gif1_58,
    &screen_home_animimg_1gif1_59,
    &screen_home_animimg_1gif1_60,
    &screen_home_animimg_1gif1_61,
    &screen_home_animimg_1gif1_62,
    &screen_home_animimg_1gif1_63,
    &screen_home_animimg_1gif1_64,
    &screen_home_animimg_1gif1_65,
    &screen_home_animimg_1gif1_66,
    &screen_home_animimg_1gif1_67,
    &screen_home_animimg_1gif1_68,
    &screen_home_animimg_1gif1_69,
    &screen_home_animimg_1gif1_70,
    &screen_home_animimg_1gif1_71,
    &screen_home_animimg_1gif1_72,
    &screen_home_animimg_1gif1_73,
    &screen_home_animimg_1gif1_74,
    &screen_home_animimg_1gif1_75,
    &screen_home_animimg_1gif1_76,
    &screen_home_animimg_1gif1_77,
    &screen_home_animimg_1gif1_78,
    &screen_home_animimg_1gif1_79,
};
extern int home_analog_analog_clock_1_hour_value;
extern int home_analog_analog_clock_1_min_value;
extern int home_analog_analog_clock_1_sec_value;

void home_analog_analog_clock_1_timer(lv_timer_t *timer)
{
    clock_count(&home_analog_analog_clock_1_hour_value, &home_analog_analog_clock_1_min_value, &home_analog_analog_clock_1_sec_value);
    if (lv_obj_is_valid(guider_ui.home_analog_analog_clock_1))
    {
        lv_scale_set_image_needle_value(guider_ui.home_analog_analog_clock_1, guider_ui.home_analog_analog_clock_1_hour_needle, home_analog_analog_clock_1_hour_value * 5);
        lv_scale_set_image_needle_value(guider_ui.home_analog_analog_clock_1, guider_ui.home_analog_analog_clock_1_min_needle, home_analog_analog_clock_1_min_value);
        lv_scale_set_image_needle_value(guider_ui.home_analog_analog_clock_1, guider_ui.home_analog_analog_clock_1_sec_needle, home_analog_analog_clock_1_sec_value);
    }
}
const lv_image_dsc_t * screen_chatDetail_animimg_1_imgs[80] = {
    &screen_chatDetail_animimg_1gif1_00_RLE,
    &screen_chatDetail_animimg_1gif1_01_RLE,
    &screen_chatDetail_animimg_1gif1_02_RLE,
    &screen_chatDetail_animimg_1gif1_03_RLE,
    &screen_chatDetail_animimg_1gif1_04_RLE,
    &screen_chatDetail_animimg_1gif1_05_RLE,
    &screen_chatDetail_animimg_1gif1_06_RLE,
    &screen_chatDetail_animimg_1gif1_07_RLE,
    &screen_chatDetail_animimg_1gif1_08_RLE,
    &screen_chatDetail_animimg_1gif1_09_RLE,
    &screen_chatDetail_animimg_1gif1_10_RLE,
    &screen_chatDetail_animimg_1gif1_11_RLE,
    &screen_chatDetail_animimg_1gif1_12_RLE,
    &screen_chatDetail_animimg_1gif1_13_RLE,
    &screen_chatDetail_animimg_1gif1_14_RLE,
    &screen_chatDetail_animimg_1gif1_15_RLE,
    &screen_chatDetail_animimg_1gif1_16_RLE,
    &screen_chatDetail_animimg_1gif1_17_RLE,
    &screen_chatDetail_animimg_1gif1_18_RLE,
    &screen_chatDetail_animimg_1gif1_19_RLE,
    &screen_chatDetail_animimg_1gif1_20_RLE,
    &screen_chatDetail_animimg_1gif1_21_RLE,
    &screen_chatDetail_animimg_1gif1_22_RLE,
    &screen_chatDetail_animimg_1gif1_23_RLE,
    &screen_chatDetail_animimg_1gif1_24_RLE,
    &screen_chatDetail_animimg_1gif1_25_RLE,
    &screen_chatDetail_animimg_1gif1_26_RLE,
    &screen_chatDetail_animimg_1gif1_27_RLE,
    &screen_chatDetail_animimg_1gif1_28_RLE,
    &screen_chatDetail_animimg_1gif1_29_RLE,
    &screen_chatDetail_animimg_1gif1_30_RLE,
    &screen_chatDetail_animimg_1gif1_31_RLE,
    &screen_chatDetail_animimg_1gif1_32_RLE,
    &screen_chatDetail_animimg_1gif1_33_RLE,
    &screen_chatDetail_animimg_1gif1_34_RLE,
    &screen_chatDetail_animimg_1gif1_35_RLE,
    &screen_chatDetail_animimg_1gif1_36_RLE,
    &screen_chatDetail_animimg_1gif1_37_RLE,
    &screen_chatDetail_animimg_1gif1_38_RLE,
    &screen_chatDetail_animimg_1gif1_39_RLE,
    &screen_chatDetail_animimg_1gif1_40_RLE,
    &screen_chatDetail_animimg_1gif1_41_RLE,
    &screen_chatDetail_animimg_1gif1_42_RLE,
    &screen_chatDetail_animimg_1gif1_43_RLE,
    &screen_chatDetail_animimg_1gif1_44_RLE,
    &screen_chatDetail_animimg_1gif1_45_RLE,
    &screen_chatDetail_animimg_1gif1_46_RLE,
    &screen_chatDetail_animimg_1gif1_47_RLE,
    &screen_chatDetail_animimg_1gif1_48_RLE,
    &screen_chatDetail_animimg_1gif1_49_RLE,
    &screen_chatDetail_animimg_1gif1_50_RLE,
    &screen_chatDetail_animimg_1gif1_51_RLE,
    &screen_chatDetail_animimg_1gif1_52_RLE,
    &screen_chatDetail_animimg_1gif1_53_RLE,
    &screen_chatDetail_animimg_1gif1_54_RLE,
    &screen_chatDetail_animimg_1gif1_55_RLE,
    &screen_chatDetail_animimg_1gif1_56_RLE,
    &screen_chatDetail_animimg_1gif1_57_RLE,
    &screen_chatDetail_animimg_1gif1_58_RLE,
    &screen_chatDetail_animimg_1gif1_59_RLE,
    &screen_chatDetail_animimg_1gif1_60_RLE,
    &screen_chatDetail_animimg_1gif1_61_RLE,
    &screen_chatDetail_animimg_1gif1_62_RLE,
    &screen_chatDetail_animimg_1gif1_63_RLE,
    &screen_chatDetail_animimg_1gif1_64_RLE,
    &screen_chatDetail_animimg_1gif1_65_RLE,
    &screen_chatDetail_animimg_1gif1_66_RLE,
    &screen_chatDetail_animimg_1gif1_67_RLE,
    &screen_chatDetail_animimg_1gif1_68_RLE,
    &screen_chatDetail_animimg_1gif1_69_RLE,
    &screen_chatDetail_animimg_1gif1_70_RLE,
    &screen_chatDetail_animimg_1gif1_71_RLE,
    &screen_chatDetail_animimg_1gif1_72_RLE,
    &screen_chatDetail_animimg_1gif1_73_RLE,
    &screen_chatDetail_animimg_1gif1_74_RLE,
    &screen_chatDetail_animimg_1gif1_75_RLE,
    &screen_chatDetail_animimg_1gif1_76_RLE,
    &screen_chatDetail_animimg_1gif1_77_RLE,
    &screen_chatDetail_animimg_1gif1_78_RLE,
    &screen_chatDetail_animimg_1gif1_79_RLE,
};
extern int screen_meetingDetail_digital_clock_1_hour_value;
extern int screen_meetingDetail_digital_clock_1_min_value;
extern int screen_meetingDetail_digital_clock_1_sec_value;

void screen_meetingDetail_digital_clock_1_timer(lv_timer_t *timer)
{
    clock_count(&screen_meetingDetail_digital_clock_1_hour_value, &screen_meetingDetail_digital_clock_1_min_value, &screen_meetingDetail_digital_clock_1_sec_value);
    if (lv_obj_is_valid(guider_ui.screen_meetingDetail_digital_clock_1))
    {
        lv_label_set_text_fmt(guider_ui.screen_meetingDetail_digital_clock_1, "%d:%02d:%02d", screen_meetingDetail_digital_clock_1_hour_value, screen_meetingDetail_digital_clock_1_min_value, screen_meetingDetail_digital_clock_1_sec_value);
    }
}

