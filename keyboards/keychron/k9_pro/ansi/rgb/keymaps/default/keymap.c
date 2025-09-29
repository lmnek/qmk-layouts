/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

enum layers { BASE_LINUX, BASE_WIN, MEDIA, VIM, CHARS, MICE, NUMS };

#define ESC_CHAR LT(CHARS, KC_ESC)
#define BCS_VIM LT(VIM, KC_BSPC)
#define DOT_NUM LT(NUMS, KC_DOT)
#define SEM_MICE LT(MICE, KC_SCLN)

#define CTL_RET MT(MOD_LCTL, KC_ENT)
#define WIN_SPC MT(MOD_LGUI, KC_SPC)
#define CTL_ALT_SPC MT(MOD_RCTL | MOD_RALT, KC_SPC)

#define VIM_B LCTL(KC_LEFT)
#define VIM_E LCTL(KC_RGHT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // TODO: tapdance for mouse button
    [BASE_LINUX] = LAYOUT_61_ansi(
        KC_CAPS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_VOLD,  KC_VOLU,  KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     BCS_VIM,  KC_MPLY,  XXXXXXX,
        ESC_CHAR, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     CTL_RET,  SEM_MICE,           XXXXXXX,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  DOT_NUM,  KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                WIN_SPC,                                KC_RALT,  MO(MEDIA), KC_PSCR, KC_RCTL),

    // NOTE: layout for windows (set as default with OS layout DIP switch)
    // only change so far is space hold behavior
    [BASE_WIN] = LAYOUT_61_ansi(
        KC_CAPS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_VOLD,  KC_VOLU,  KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     BCS_VIM,  KC_MPLY,  XXXXXXX,
        ESC_CHAR, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     CTL_RET,  SEM_MICE,           XXXXXXX,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  DOT_NUM,  KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                CTL_ALT_SPC,                            KC_RALT,  MO(MEDIA), KC_PSCR, KC_RCTL),

    // TODO: zoom / unzoom
    [VIM] = LAYOUT_61_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  VIM_E,    _______,  _______,  _______,  KC_PGUP,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  KC_PGDN,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,
        _______,            KC_HOME,  KC_END,   _______,  _______,  VIM_B,    _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                KC_ENT,                                 _______,  _______,  _______,  _______),

    [CHARS] = LAYOUT_61_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_TILD,  KC_HASH,  KC_LCBR,  KC_RCBR,  KC_AMPR,  KC_PIPE,  KC_UNDS,  KC_DQT,   KC_QUOT,  KC_GRV,   _______,  _______,  _______,
        _______,  KC_PERC,  KC_SCLN,  KC_LPRN,  KC_RPRN,  KC_QUES,  KC_EXLM,  KC_EQL,   KC_MINS,  KC_PLUS,  _______,  _______,            _______,
        _______,            KC_CIRC,  KC_DLR,   KC_LBRC,  KC_RBRC,  KC_AT,    KC_COLN,  KC_ASTR,  KC_LT,    KC_GT,    KC_BSLS,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [NUMS] = LAYOUT_61_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  KC_7,     KC_8,     KC_9,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_4,     KC_5,     KC_6,     _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            KC_0,     KC_1,     KC_2,     KC_3,     _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [MICE] = LAYOUT_61_ansi(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  _______,  _______,  KC_BTN3,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  KC_WH_D,  KC_WH_U,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    // keyboard rgb, media keys
    [MEDIA] = LAYOUT_61_ansi(
        KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  KC_APP,   KC_SCRL,  KC_INS,   KC_PGUP,  KC_HOME,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    // [BLANK] = LAYOUT_61_ansi(
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    //     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    //     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),
};
