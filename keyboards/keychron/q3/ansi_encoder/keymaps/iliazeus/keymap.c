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

    KC_K_VOL,
    KC_K_BRI,
    KC_K_SCR,
    KC_K_TRK,
};

enum layers {
    MAC_BASE,
    MAC_FN,

    WIN_BASE,
    WIN_FN,

    MACRO_LAYER,
    F_LAYER,
};

enum knob_state {
    KNOB_SCROLL,
    KNOB_VOLUME,
    KNOB_BRIGHTNESS,
    KNOB_TRACK,
} knob_state = KNOB_SCROLL;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_KCLK,  KC_PSCR,TG(F_LAYER),OSL(MACRO_LAYER),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_f13_ansi(
        _______,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,     _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_KCLK,  KC_PSCR,TG(F_LAYER),OSL(MACRO_LAYER),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_f13_ansi(
        _______,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,     _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [MACRO_LAYER] = LAYOUT_tkl_f13_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, KC_K_VOL, KC_K_BRI, KC_K_SCR,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, KC_K_TRK,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [F_LAYER] = LAYOUT_tkl_f13_ansi(
        _______,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,     _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (knob_state) {
        case KNOB_SCROLL:
            if (clockwise) tap_code(KC_MS_WH_DOWN);
            else tap_code(KC_MS_WH_UP);
            return false;
        case KNOB_VOLUME:
            if (clockwise) tap_code(KC_AUDIO_VOL_UP);
            else tap_code(KC_AUDIO_VOL_DOWN);
            return false;
        case KNOB_BRIGHTNESS:
            if (clockwise) tap_code(KC_BRIGHTNESS_UP);
            else tap_code(KC_BRIGHTNESS_DOWN);
            return false;
        case KNOB_TRACK:
            if (clockwise) tap_code(KC_MEDIA_NEXT_TRACK);
            else tap_code(KC_MEDIA_PREV_TRACK);
            return false;
        default:
            return false;
    }
}

inline static void _set_top_row_keys_rgb(uint8_t r, uint8_t g, uint8_t b) {
    for (uint16_t i = 0; i < 16; i++) {
        rgb_matrix_set_color(g_led_config.matrix_co[0][i], r, g, b);
    }

    rgb_matrix_set_color(g_led_config.matrix_co[3][14], r, g, b);
}

inline static void _set_function_keys_rgb(uint8_t r, uint8_t g, uint8_t b) {
    for (uint16_t i = 1; i <= 12; i++) {
        rgb_matrix_set_color(g_led_config.matrix_co[0][i], r, g, b);
    }
}

inline static void _set_square_keys_rgb(uint8_t r, uint8_t g, uint8_t b) {
    rgb_matrix_set_color(g_led_config.matrix_co[0][14], r, g, b);
    rgb_matrix_set_color(g_led_config.matrix_co[0][15], r, g, b);
    rgb_matrix_set_color(g_led_config.matrix_co[3][14], r, g, b);

    rgb_matrix_set_color(g_led_config.matrix_co[1][14], r, g, b);
    rgb_matrix_set_color(g_led_config.matrix_co[1][15], r, g, b);
    rgb_matrix_set_color(g_led_config.matrix_co[3][15], r, g, b);

    rgb_matrix_set_color(g_led_config.matrix_co[2][14], r, g, b);
    rgb_matrix_set_color(g_led_config.matrix_co[2][15], r, g, b);
    rgb_matrix_set_color(g_led_config.matrix_co[3][12], r, g, b);
}

inline static void _set_top_right_key_rgb(uint8_t r, uint8_t g, uint8_t b) {
    rgb_matrix_set_color(g_led_config.matrix_co[3][14], r, g, b);
}

bool rgb_matrix_indicators_user(void) {
    if (IS_LAYER_ON(F_LAYER)) _set_function_keys_rgb(RGB_WHITE);

    switch (knob_state) {
        case KNOB_SCROLL: _set_top_right_key_rgb(RGB_BLACK); break;
        case KNOB_BRIGHTNESS: _set_top_right_key_rgb(RGB_YELLOW); break;
        case KNOB_VOLUME: _set_top_right_key_rgb(RGB_GREEN); break;
        case KNOB_TRACK: _set_top_right_key_rgb(RGB_RED); break;
    }

    if (host_keyboard_led_state().caps_lock) rgb_matrix_set_color(g_led_config.matrix_co[0][14], RGB_WHITE);
    if (host_keyboard_led_state().num_lock) rgb_matrix_set_color(g_led_config.matrix_co[0][15], RGB_WHITE);

    if (IS_LAYER_ON(MACRO_LAYER)) _set_square_keys_rgb(RGB_WHITE);

    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) switch (keycode) {
        case KC_KCLK:
            switch (knob_state) {
                case KNOB_SCROLL: tap_code(KC_MS_BTN3); return false;
                case KNOB_VOLUME: tap_code(KC_AUDIO_MUTE); return false;
                case KNOB_BRIGHTNESS: return false;
                case KNOB_TRACK: tap_code(KC_MEDIA_PLAY_PAUSE); return false;
                default: return false;
            }

        case KC_K_VOL: knob_state = KNOB_VOLUME; return false;
        case KC_K_BRI: knob_state = KNOB_BRIGHTNESS; return false;
        case KC_K_SCR: knob_state = KNOB_SCROLL; return false;
        case KC_K_TRK: knob_state = KNOB_TRACK; return false;
    }

    if (IS_LAYER_ON(MAC_BASE)) {
        if ((get_mods() & MOD_MASK_SHIFT) == MOD_MASK_SHIFT) tap_code(KC_CAPS);
    }

    return true;
}
