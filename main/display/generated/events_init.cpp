/*
 * Copyright 2026 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by
 * downloading, installing, activating and/or otherwise using the software, you are agreeing that
 * you have read, and that you agree to comply with and are bound by, such license terms.  If you do
 * not agree to be bound by the applicable license terms, then you may not retain, install, activate
 * or otherwise use the software.
 */

#include "events_init.h"
#include <stdio.h>
#include "Commons.h"
#include "audio_codec.h"
#include "board.h"
#include "lvgl.h"
#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

static void screen_mainConfig_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture,
                                  guider_ui.screen_picture_del, &guider_ui.screen_mainConfig_del,
                                  setup_scr_screen_picture, LV_SCR_LOAD_ANIM_NONE, 200, 200, false,
                                  true);
            break;
        }
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_chat,
                                          guider_ui.screen_chat_del,
                                          &guider_ui.screen_mainConfig_del, setup_scr_screen_chat,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig,
                                          guider_ui.screen_systemConfig_del,
                                          &guider_ui.screen_mainConfig_del,
                                          setup_scr_screen_systemConfig, LV_SCR_LOAD_ANIM_NONE, 200,
                                          200, false, true);
                    break;
                }
                case LV_DIR_BOTTOM: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_main,
                                          guider_ui.screen_main_del,
                                          &guider_ui.screen_mainConfig_del, setup_scr_screen_main,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_mainConfig_img_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture,
                                  guider_ui.screen_picture_del, &guider_ui.screen_mainConfig_del,
                                  setup_scr_screen_picture, LV_SCR_LOAD_ANIM_NONE, 200, 200, false,
                                  true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_mainConfig(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_mainConfig, screen_mainConfig_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_mainConfig_img_1, screen_mainConfig_img_1_event_handler,
                        LV_EVENT_ALL, ui);
}

static void screen_chat_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chatDetail,
                                  guider_ui.screen_chatDetail_del, &guider_ui.screen_chat_del,
                                  setup_scr_screen_chatDetail, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_remind,
                                          guider_ui.screen_remind_del, &guider_ui.screen_chat_del,
                                          setup_scr_screen_remind, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig,
                                          guider_ui.screen_mainConfig_del,
                                          &guider_ui.screen_chat_del, setup_scr_screen_mainConfig,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_chat_img_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_chatDetail,
                                  guider_ui.screen_chatDetail_del, &guider_ui.screen_chat_del,
                                  setup_scr_screen_chatDetail, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_chat(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_chat, screen_chat_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_chat_img_1, screen_chat_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_remind_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_remindDetail,
                                  guider_ui.screen_remindDetail_del, &guider_ui.screen_remind_del,
                                  setup_scr_screen_remindDetail, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_meeting,
                                          guider_ui.screen_meeting_del,
                                          &guider_ui.screen_remind_del, setup_scr_screen_meeting,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_chat,
                                          guider_ui.screen_chat_del, &guider_ui.screen_remind_del,
                                          setup_scr_screen_chat, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_remind_img_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_remindDetail,
                                  guider_ui.screen_remindDetail_del, &guider_ui.screen_remind_del,
                                  setup_scr_screen_remindDetail, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_remind(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_remind, screen_remind_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_remind_img_1, screen_remind_img_1_event_handler, LV_EVENT_ALL,
                        ui);
}

static void screen_meeting_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_meetingDetail,
                                  guider_ui.screen_meetingDetail_del, &guider_ui.screen_meeting_del,
                                  setup_scr_screen_meetingDetail, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig,
                                          guider_ui.screen_systemConfig_del,
                                          &guider_ui.screen_meeting_del,
                                          setup_scr_screen_systemConfig, LV_SCR_LOAD_ANIM_NONE, 200,
                                          200, false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_remind,
                                          guider_ui.screen_remind_del,
                                          &guider_ui.screen_meeting_del, setup_scr_screen_remind,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_meeting_img_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_meetingDetail,
                                  guider_ui.screen_meetingDetail_del, &guider_ui.screen_meeting_del,
                                  setup_scr_screen_meetingDetail, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_meeting(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_meeting, screen_meeting_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_meeting_img_1, screen_meeting_img_1_event_handler, LV_EVENT_ALL,
                        ui);
}

static void screen_systemConfig_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(
                &guider_ui, &guider_ui.screen_systemConfig1, guider_ui.screen_systemConfig1_del,
                &guider_ui.screen_systemConfig_del, setup_scr_screen_systemConfig1,
                LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(
                        &guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del,
                        &guider_ui.screen_systemConfig_del, setup_scr_screen_mainConfig,
                        LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(
                        &guider_ui, &guider_ui.screen_remind, guider_ui.screen_remind_del,
                        &guider_ui.screen_systemConfig_del, setup_scr_screen_remind,
                        LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_systemConfig_img_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(
                &guider_ui, &guider_ui.screen_systemConfig1, guider_ui.screen_systemConfig1_del,
                &guider_ui.screen_systemConfig_del, setup_scr_screen_systemConfig1,
                LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_systemConfig(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_systemConfig, screen_systemConfig_event_handler, LV_EVENT_ALL,
                        ui);
    lv_obj_add_event_cb(ui->screen_systemConfig_img_1, screen_systemConfig_img_1_event_handler,
                        LV_EVENT_ALL, ui);
}

static void screen_quick_config_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_TOP: {
                    lv_indev_wait_release(lv_indev_active());
                    if (all_config.page_main.main_display_type == 0) {
                        all_config.page_pic_display.pic_index = save_config.pic_display;
                        ui_load_scr_animation(
                            &guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del,
                            &guider_ui.screen_quick_config_del, setup_scr_screen_main,
                            LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
                    } else if (all_config.page_main.main_display_type == 1) {
                        all_config.page_gif_display.gif_index = save_config.gif_display;
                        ui_load_scr_animation(
                            &guider_ui, &guider_ui.screen_main_gif, guider_ui.screen_main_gif_del,
                            &guider_ui.screen_quick_config_del, setup_scr_screen_main_gif,
                            LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
                    } else if (all_config.page_main.main_display_type == 2) {
                        switch (save_config.clock_display) {
                            case 0:
                                ui_load_scr_animation(
                                    &guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del,
                                    &guider_ui.screen_mainConfig_del, setup_scr_home_analog,
                                    LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                                break;
                            case 1:
                                ui_load_scr_animation(
                                    &guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del,
                                    &guider_ui.screen_mainConfig_del, setup_scr_home_digital,
                                    LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                                break;
                            case 2:
                                ui_load_scr_animation(
                                    &guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del,
                                    &guider_ui.screen_mainConfig_del, setup_scr_screen_home,
                                    LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_quick_config_slider_volume_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_VALUE_CHANGED: {
            auto& board = Board::GetInstance();
            lv_obj_t* slider = static_cast<lv_obj_t*>(lv_event_get_target(e));
            uint8_t Volume = lv_slider_get_value(slider);
            auto codec = board.GetAudioCodec();
            codec->SetOutputVolume(Volume);
            save_config.volume = all_config.page_quickConfig.volume = Volume;
            nvs_save_all_config();
            break;
        }
        default:
            break;
    }
}

static void screen_quick_config_slider_backLight_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_VALUE_CHANGED: {
            auto& board = Board::GetInstance();
            lv_obj_t* slider = static_cast<lv_obj_t*>(lv_event_get_target(e));
            uint8_t Backlight = lv_slider_get_value(slider);
            board.GetBacklight()->SetBrightness(Backlight, true);
            save_config.backLight = all_config.page_quickConfig.backLight = Backlight;
            nvs_save_all_config();
            break;
        }
        default:
            break;
    }
}

static void screen_quick_config_btn_power_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_shutDown,
                                  guider_ui.screen_shutDown_del, &guider_ui.screen_quick_config_del,
                                  setup_scr_screen_shutDown, LV_SCR_LOAD_ANIM_NONE, 200, 200, false,
                                  true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_quick_config(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_quick_config, screen_quick_config_event_handler, LV_EVENT_ALL,
                        ui);
    lv_obj_add_event_cb(ui->screen_quick_config_slider_volume,
                        screen_quick_config_slider_volume_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_quick_config_slider_backLight,
                        screen_quick_config_slider_backLight_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_quick_config_btn_power,
                        screen_quick_config_btn_power_event_handler, LV_EVENT_ALL, ui);
}

static void screen_shutDown_btn_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config,
                                  guider_ui.screen_quick_config_del, &guider_ui.screen_shutDown_del,
                                  setup_scr_screen_quick_config, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        default:
            break;
    }
}

static void screen_shutDown_slider_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_VALUE_CHANGED: {
            break;
        }
        default:
            break;
    }
}

void events_init_screen_shutDown(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_shutDown_btn_1, screen_shutDown_btn_1_event_handler,
                        LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_shutDown_slider_1, screen_shutDown_slider_1_event_handler,
                        LV_EVENT_ALL, ui);
}

static void screen_picture_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture_display,
                                  guider_ui.screen_picture_display_del,
                                  &guider_ui.screen_picture_del, setup_scr_screen_picture_display,
                                  LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif,
                                          guider_ui.screen_gif_del, &guider_ui.screen_picture_del,
                                          setup_scr_screen_gif, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(
                        &guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del,
                        &guider_ui.screen_picture_del, setup_scr_screen_mainConfig,
                        LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_picture_img_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture_display,
                                  guider_ui.screen_picture_display_del,
                                  &guider_ui.screen_picture_del, setup_scr_screen_picture_display,
                                  LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_picture(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_picture, screen_picture_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_picture_img_1, screen_picture_img_1_event_handler, LV_EVENT_ALL,
                        ui);
}

static void screen_picture_display_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_BOTTOM: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(
                        &guider_ui, &guider_ui.screen_picture, guider_ui.screen_picture_del,
                        &guider_ui.screen_picture_display_del, setup_scr_screen_picture,
                        LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_picture_display_img_display_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del,
                                  &guider_ui.screen_picture_display_del, setup_scr_screen_main,
                                  LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

static void screen_picture_display_list_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

void events_init_screen_picture_display(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_picture_display, screen_picture_display_event_handler,
                        LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_picture_display_img_display,
                        screen_picture_display_img_display_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_picture_display_list_1,
                        screen_picture_display_list_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_gif_display_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_BOTTOM: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif,
                                          guider_ui.screen_gif_del,
                                          &guider_ui.screen_gif_display_del, setup_scr_screen_gif,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_gif_display_img_display_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_main_gif,
                                  guider_ui.screen_main_gif_del, &guider_ui.screen_gif_display_del,
                                  setup_scr_screen_main_gif, LV_SCR_LOAD_ANIM_NONE, 200, 200, false,
                                  true);
            break;
        }
        default:
            break;
    }
}

static void screen_gif_display_list_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

void events_init_screen_gif_display(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_gif_display, screen_gif_display_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_gif_display_img_display,
                        screen_gif_display_img_display_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_gif_display_list_1, screen_gif_display_list_1_event_handler,
                        LV_EVENT_ALL, ui);
}

static void screen_gif_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif_display,
                                  guider_ui.screen_gif_display_del, &guider_ui.screen_gif_del,
                                  setup_scr_screen_gif_display, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_clock,
                                          guider_ui.screen_clock_del, &guider_ui.screen_gif_del,
                                          setup_scr_screen_clock, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_picture,
                                          guider_ui.screen_picture_del, &guider_ui.screen_gif_del,
                                          setup_scr_screen_picture, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_gif_img_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif_display,
                                  guider_ui.screen_gif_display_del, &guider_ui.screen_gif_del,
                                  setup_scr_screen_gif_display, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_gif(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_gif, screen_gif_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_gif_img_1, screen_gif_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_clock_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_clock_display, guider_ui.screen_clock_display_del,
                                  &guider_ui.screen_clock_del, setup_scr_screen_gif,
                                  LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_gif,
                                          guider_ui.screen_gif_del, &guider_ui.screen_clock_del,
                                          setup_scr_screen_gif, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_clock_img_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_home, guider_ui.screen_home_del,
                                  &guider_ui.screen_clock_del, setup_scr_screen_home,
                                  LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_clock(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_clock, screen_clock_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_clock_img_1, screen_clock_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_systemConfig1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig,
                                          guider_ui.screen_systemConfig_del,
                                          &guider_ui.screen_systemConfig1_del,
                                          setup_scr_screen_systemConfig, LV_SCR_LOAD_ANIM_NONE, 200,
                                          200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_systemConfig1_cont_2_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(
                &guider_ui, &guider_ui.screen_autoShutDown, guider_ui.screen_autoShutDown_del,
                &guider_ui.screen_systemConfig1_del, setup_scr_screen_autoShutDown,
                LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

static void screen_systemConfig1_cont_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(
                &guider_ui, &guider_ui.screen_autoShutDown, guider_ui.screen_autoShutDown_del,
                &guider_ui.screen_systemConfig1_del, setup_scr_screen_autoShutDown,
                LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

static void screen_systemConfig1_cont_4_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

static void screen_systemConfig1_cont_5_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

static void screen_systemConfig1_cont_6_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_reset, guider_ui.screen_reset_del,
                                  &guider_ui.screen_systemConfig1_del, setup_scr_screen_reset,
                                  LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

static void screen_systemConfig1_cont_7_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_reset, guider_ui.screen_reset_del,
                                  &guider_ui.screen_systemConfig1_del, setup_scr_screen_reset,
                                  LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

static void screen_systemConfig1_cont_8_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(
                &guider_ui, &guider_ui.screen_device_information,
                guider_ui.screen_device_information_del, &guider_ui.screen_systemConfig1_del,
                setup_scr_screen_device_information, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

static void screen_systemConfig1_cont_9_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(
                &guider_ui, &guider_ui.screen_device_information,
                guider_ui.screen_device_information_del, &guider_ui.screen_systemConfig1_del,
                setup_scr_screen_device_information, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
            break;
        }
        default:
            break;
    }
}

void events_init_screen_systemConfig1(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_systemConfig1, screen_systemConfig1_event_handler, LV_EVENT_ALL,
                        ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_2, screen_systemConfig1_cont_2_event_handler,
                        LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_1, screen_systemConfig1_cont_1_event_handler,
                        LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_4, screen_systemConfig1_cont_4_event_handler,
                        LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_5, screen_systemConfig1_cont_5_event_handler,
                        LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_6, screen_systemConfig1_cont_6_event_handler,
                        LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_7, screen_systemConfig1_cont_7_event_handler,
                        LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_8, screen_systemConfig1_cont_8_event_handler,
                        LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_systemConfig1_cont_9, screen_systemConfig1_cont_9_event_handler,
                        LV_EVENT_ALL, ui);
}

static void screen_autoShutDown_list_1_item0_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

static void screen_autoShutDown_list_1_item1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

static void screen_autoShutDown_list_1_item2_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

static void screen_autoShutDown_list_1_item3_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

static void screen_autoShutDown_list_1_item4_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

static void screen_autoShutDown_list_1_item5_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

void events_init_screen_autoShutDown(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item0,
                        screen_autoShutDown_list_1_item0_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item1,
                        screen_autoShutDown_list_1_item1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item2,
                        screen_autoShutDown_list_1_item2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item3,
                        screen_autoShutDown_list_1_item3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item4,
                        screen_autoShutDown_list_1_item4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_autoShutDown_list_1_item5,
                        screen_autoShutDown_list_1_item5_event_handler, LV_EVENT_ALL, ui);
}

static void screen_reset_btn_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig1,
                                  guider_ui.screen_systemConfig1_del, &guider_ui.screen_reset_del,
                                  setup_scr_screen_systemConfig1, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                  false, true);
            break;
        }
        default:
            break;
    }
}

static void screen_reset_slider_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_VALUE_CHANGED: {
            break;
        }
        default:
            break;
    }
}

void events_init_screen_reset(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_reset_btn_1, screen_reset_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_reset_slider_1, screen_reset_slider_1_event_handler,
                        LV_EVENT_ALL, ui);
}

static void screen_device_information_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_systemConfig1,
                                          guider_ui.screen_systemConfig1_del,
                                          &guider_ui.screen_device_information_del,
                                          setup_scr_screen_systemConfig1, LV_SCR_LOAD_ANIM_NONE,
                                          200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void events_init_screen_device_information(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_device_information, screen_device_information_event_handler,
                        LV_EVENT_ALL, ui);
}

static void screen_home_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog,
                                          guider_ui.home_analog_del, &guider_ui.screen_home_del,
                                          setup_scr_home_analog, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital,
                                          guider_ui.home_digital_del, &guider_ui.screen_home_del,
                                          setup_scr_home_digital, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                case LV_DIR_BOTTOM: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config,
                                          guider_ui.screen_quick_config_del,
                                          &guider_ui.screen_home_del, setup_scr_screen_quick_config,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                case LV_DIR_TOP: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig,
                                          guider_ui.screen_mainConfig_del,
                                          &guider_ui.screen_home_del, setup_scr_screen_mainConfig,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void events_init_screen_home(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_home, screen_home_event_handler, LV_EVENT_ALL, ui);
}

static void home_analog_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_digital,
                                          guider_ui.home_digital_del, &guider_ui.home_analog_del,
                                          setup_scr_home_digital, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home,
                                          guider_ui.screen_home_del, &guider_ui.home_analog_del,
                                          setup_scr_screen_home, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                case LV_DIR_TOP: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig,
                                          guider_ui.screen_mainConfig_del,
                                          &guider_ui.home_analog_del, setup_scr_screen_mainConfig,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                case LV_DIR_BOTTOM: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config,
                                          guider_ui.screen_quick_config_del,
                                          &guider_ui.home_analog_del, setup_scr_screen_quick_config,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void events_init_home_analog(lv_ui* ui) {
    lv_obj_add_event_cb(ui->home_analog, home_analog_event_handler, LV_EVENT_ALL, ui);
}

static void home_digital_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_SCREEN_LOADED: {
            ui_animation(guider_ui.home_digital_label_hour, 0, 800,
                         lv_obj_get_x(guider_ui.home_digital_label_hour), 122, &lv_anim_path_bounce,
                         0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
            ui_animation(guider_ui.home_digital_label_hour, 0, 800,
                         lv_obj_get_y(guider_ui.home_digital_label_hour), 82, &lv_anim_path_bounce,
                         0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
            ui_animation(guider_ui.home_digital_label_min, 800, 0,
                         lv_obj_get_x(guider_ui.home_digital_label_min), 122, &lv_anim_path_bounce,
                         0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
            ui_animation(guider_ui.home_digital_label_min, 0, 800,
                         lv_obj_get_y(guider_ui.home_digital_label_min), 208, &lv_anim_path_bounce,
                         0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
            break;
        }
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_LEFT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_home,
                                          guider_ui.screen_home_del, &guider_ui.home_digital_del,
                                          setup_scr_screen_home, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.home_analog,
                                          guider_ui.home_analog_del, &guider_ui.home_digital_del,
                                          setup_scr_home_analog, LV_SCR_LOAD_ANIM_NONE, 200, 200,
                                          false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void events_init_home_digital(lv_ui* ui) {
    lv_obj_add_event_cb(ui->home_digital, home_digital_event_handler, LV_EVENT_ALL, ui);
}

static void screen_main_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_TOP: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_mainConfig,
                                          guider_ui.screen_mainConfig_del,
                                          &guider_ui.screen_main_del, setup_scr_screen_mainConfig,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                case LV_DIR_BOTTOM: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config,
                                          guider_ui.screen_quick_config_del,
                                          &guider_ui.screen_main_del, setup_scr_screen_quick_config,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void events_init_screen_main(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_main, screen_main_event_handler, LV_EVENT_ALL, ui);
}

static void screen_main_gif_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_TOP: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(
                        &guider_ui, &guider_ui.screen_mainConfig, guider_ui.screen_mainConfig_del,
                        &guider_ui.screen_main_gif_del, setup_scr_screen_mainConfig,
                        LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                case LV_DIR_BOTTOM: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_quick_config,
                                          guider_ui.screen_quick_config_del,
                                          &guider_ui.screen_main_gif_del,
                                          setup_scr_screen_quick_config, LV_SCR_LOAD_ANIM_NONE, 200,
                                          200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void events_init_screen_main_gif(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_main_gif, screen_main_gif_event_handler, LV_EVENT_ALL, ui);
}

static void screen_chatDetail_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(&guider_ui, &guider_ui.screen_chat,
                                          guider_ui.screen_chat_del,
                                          &guider_ui.screen_chatDetail_del, setup_scr_screen_chat,
                                          LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void events_init_screen_chatDetail(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_chatDetail, screen_chatDetail_event_handler, LV_EVENT_ALL, ui);
}

static void screen_remindDetail_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(
                        &guider_ui, &guider_ui.screen_remind, guider_ui.screen_remind_del,
                        &guider_ui.screen_remindDetail_del, setup_scr_screen_remind,
                        LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void events_init_screen_remindDetail(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_remindDetail, screen_remindDetail_event_handler, LV_EVENT_ALL,
                        ui);
}

static void screen_meetingDetail_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE: {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
            switch (dir) {
                case LV_DIR_RIGHT: {
                    lv_indev_wait_release(lv_indev_active());
                    ui_load_scr_animation(
                        &guider_ui, &guider_ui.screen_meeting, guider_ui.screen_meeting_del,
                        &guider_ui.screen_meetingDetail_del, setup_scr_screen_meeting,
                        LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void screen_meetingDetail_btn_1_event_handler(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED: {
            break;
        }
        default:
            break;
    }
}

void events_init_screen_meetingDetail(lv_ui* ui) {
    lv_obj_add_event_cb(ui->screen_meetingDetail, screen_meetingDetail_event_handler, LV_EVENT_ALL,
                        ui);
    lv_obj_add_event_cb(ui->screen_meetingDetail_btn_1, screen_meetingDetail_btn_1_event_handler,
                        LV_EVENT_ALL, ui);
}

void events_init(lv_ui* ui) {}
