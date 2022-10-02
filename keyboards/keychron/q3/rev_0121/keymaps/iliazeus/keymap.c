/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "undef_rgb_matrix_effects.h"

enum custom_keycodes {
    KC_KNOB = SAFE_RANGE,
    KC_KCLK,
    KC_MACL,
};

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,

    MACRO_LAYER,
};

enum knob_mode {
    KNOB_WHEEL,
    KNOB_BRIGHTNESS,
    KNOB_VOLUME,
    KNOB_TRACK,

    _KNOB_MODE_COUNT,
};

enum knob_mode knob_mode = KNOB_WHEEL;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_88(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_KCLK,  KC_PSCR,  KC_PAUS,  KC_KNOB,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_88(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    KC_MACL,  KC_CAPS,  KC_NUM,   KC_KNOB,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_88(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_KCLK,  KC_PSCR,  KC_PAUS,  KC_KNOB,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_88(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    KC_MACL,  KC_CAPS,  KC_NUM,   KC_KNOB,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
    
    [MACRO_LAYER] = LAYOUT_ansi_88(
        KC_MACL,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,     KC_KCLK,  KC_F16,   KC_F17,   KC_F18,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_F19,   KC_F20,   KC_F21,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_F22,   KC_F23,   KC_F24,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (knob_mode) {
        case KNOB_WHEEL:
            if (clockwise) tap_code(KC_MS_WH_DOWN);
            else tap_code(KC_MS_WH_UP);
            break;
        case KNOB_BRIGHTNESS:
            if (clockwise) tap_code(KC_BRIGHTNESS_UP);
            else tap_code(KC_BRIGHTNESS_DOWN);
            break;
        case KNOB_VOLUME:
            if (clockwise) tap_code(KC_AUDIO_VOL_UP);
            else tap_code(KC_AUDIO_VOL_DOWN);
            break;
        case KNOB_TRACK:
            if (clockwise) tap_code(KC_MEDIA_NEXT_TRACK);
            else tap_code(KC_MEDIA_PREV_TRACK);
            break;
        case _KNOB_MODE_COUNT:
            break;
    }

    return false;
}


void rgb_matrix_indicators_user(void) {
    if (IS_LAYER_ON(MACRO_LAYER)) {
        for (uint16_t i = 0; i < 16; i++) {
            rgb_matrix_set_color(g_led_config.matrix_co[0][i], RGB_CYAN);
        }
        rgb_matrix_set_color(g_led_config.matrix_co[3][14], RGB_CYAN);

        rgb_matrix_set_color(g_led_config.matrix_co[1][14], RGB_CYAN);
        rgb_matrix_set_color(g_led_config.matrix_co[1][15], RGB_CYAN);
        rgb_matrix_set_color(g_led_config.matrix_co[3][15], RGB_CYAN);

        rgb_matrix_set_color(g_led_config.matrix_co[2][14], RGB_CYAN);
        rgb_matrix_set_color(g_led_config.matrix_co[2][15], RGB_CYAN);
        rgb_matrix_set_color(g_led_config.matrix_co[3][12], RGB_CYAN);

        return;
    }

    if (host_keyboard_led_state().caps_lock) rgb_matrix_set_color(g_led_config.matrix_co[0][14], RGB_WHITE);
    if (host_keyboard_led_state().num_lock) rgb_matrix_set_color(g_led_config.matrix_co[0][15], RGB_WHITE);

    #define SET_KNOB_MODE_RGB(color) rgb_matrix_set_color(g_led_config.matrix_co[3][14], color)

    switch (knob_mode) {
        case KNOB_WHEEL:
            SET_KNOB_MODE_RGB(RGB_BLACK);
            break;
        case KNOB_BRIGHTNESS:
            SET_KNOB_MODE_RGB(RGB_YELLOW);
            break;
        case KNOB_VOLUME:
            SET_KNOB_MODE_RGB(RGB_GREEN);
            break;
        case KNOB_TRACK:
            SET_KNOB_MODE_RGB(RGB_RED);
            break;
        case _KNOB_MODE_COUNT:
            break;
    }

    #undef KNOB_MODE_RGB
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case KC_KNOB:
            if (!record->event.pressed) {
                knob_mode += 1;
                if (knob_mode == _KNOB_MODE_COUNT) knob_mode = (enum knob_mode) 0;
            }
            return false;

        case KC_KCLK:
            if (!record->event.pressed) {
                if (IS_LAYER_ON(MACRO_LAYER)) {
                    layer_invert(MACRO_LAYER);
                    return false;
                }

                switch (knob_mode) {
                    case KNOB_WHEEL:
                        tap_code(KC_MS_BTN3);
                        break;
                    case KNOB_BRIGHTNESS:
                        break;
                    case KNOB_VOLUME:
                        tap_code(KC_AUDIO_MUTE);
                        break;
                    case KNOB_TRACK:
                        tap_code(KC_MEDIA_PLAY_PAUSE);
                        break;
                    case _KNOB_MODE_COUNT:
                        break;
                }
            }
            return false;

        case KC_MACL:
            if (!record->event.pressed) layer_invert(MACRO_LAYER);
            return false;
    }

    if (IS_LAYER_ON(MAC_BASE)) {
        if ((get_mods() & MOD_MASK_SHIFT) == MOD_MASK_SHIFT) tap_code(KC_CAPS);
    }

    return true;
};
