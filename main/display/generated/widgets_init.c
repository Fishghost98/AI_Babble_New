/*
 * Copyright 2025 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "lvgl.h"
#include "gui_guider.h"
#include "custom.h"
#include "widgets_init.h"
#include <stdlib.h>
#include <string.h>
#include "Commons.h"

int screen_meetingDetail_digital_clock_1_min_value = 0;
int screen_meetingDetail_digital_clock_1_hour_value = 0;
int screen_meetingDetail_digital_clock_1_sec_value = 0;

__attribute__((unused)) void kb_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
    if (code == LV_EVENT_READY || code == LV_EVENT_CANCEL)
    {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

__attribute__((unused)) void ta_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
#if LV_USE_KEYBOARD || LV_USE_ZH_KEYBOARD
    lv_obj_t *ta = lv_event_get_target(e);
#endif
    lv_obj_t *kb = lv_event_get_user_data(e);
    if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED)
    {
#if LV_USE_ZH_KEYBOARD != 0
        lv_zh_keyboard_set_textarea(kb, ta);
#endif
#if LV_USE_KEYBOARD != 0
        lv_keyboard_set_textarea(kb, ta);
#endif
        lv_obj_move_foreground(kb);
        lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
    if (code == LV_EVENT_CANCEL || code == LV_EVENT_DEFOCUSED)
    {

#if LV_USE_ZH_KEYBOARD != 0
        lv_zh_keyboard_set_textarea(kb, ta);
#endif
#if LV_USE_KEYBOARD != 0
        lv_keyboard_set_textarea(kb, ta);
#endif
        lv_obj_move_background(kb);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

#if LV_USE_ANALOGCLOCK != 0
void clock_count(int *hour, int *min, int *sec)
{
    (*sec)++;
    if (*sec == 60)
    {
        *sec = 0;
        (*min)++;
    }
    if (*min == 60)
    {
        *min = 0;
        if (*hour < 12)
        {
            (*hour)++;
        }
        else
        {
            (*hour)++;
            *hour = *hour % 12;
        }
    }
}
#endif



void screen_meetingDetail_digital_clock_1_timer(lv_timer_t *timer)
{
    clock_count_24(&screen_meetingDetail_digital_clock_1_hour_value, &screen_meetingDetail_digital_clock_1_min_value, &screen_meetingDetail_digital_clock_1_sec_value);
    if (lv_obj_is_valid(guider_ui.screen_meetingDetail_digital_clock_1))
    {
        lv_dclock_set_text_fmt(guider_ui.screen_meetingDetail_digital_clock_1, "%02d:%02d:%02d", screen_meetingDetail_digital_clock_1_hour_value, screen_meetingDetail_digital_clock_1_min_value, screen_meetingDetail_digital_clock_1_sec_value);
    }
}

extern int home_analog_analog_clock_1_hour_value;
extern int home_analog_analog_clock_1_min_value;
extern int home_analog_analog_clock_1_sec_value;

void home_analog_analog_clock_1_timer(lv_timer_t *timer)
{
    clock_count(&home_analog_analog_clock_1_hour_value, &home_analog_analog_clock_1_min_value, &home_analog_analog_clock_1_sec_value);
    if (lv_obj_is_valid(guider_ui.home_analog_analog_clock_1))
    {
        // lv_analogclock_set_time(guider_ui.home_analog_analog_clock_1, home_analog_analog_clock_1_hour_value, home_analog_analog_clock_1_min_value, home_analog_analog_clock_1_sec_value);
    }
}

const lv_img_dsc_t * screen_home_animimg_1_imgs[80] = {
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



