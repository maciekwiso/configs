/* Copyright 2024 ~ 2025 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
	MOD1
};

#define HM_GRV LT(WIN_BASE,KC_GRV)
#define HM_Q LT(MOD1,KC_Q)
#define HM_A LT(WIN_FN,KC_A) 
#define HM_C LT(WIN_BASE,KC_C)
#define HM_V LT(WIN_BASE,KC_V)
#define HM_Z LT(WIN_BASE,KC_Z)
#define HM_X LT(WIN_BASE,KC_X)
#define HM_S LALT_T(KC_S)  // S acts as Alt when held
#define HM_D LSFT_T(KC_D)  // D acts as Shift when held
#define HM_F LCTL_T(KC_F)  // F acts as Ctrl when held
#define HM_E LT(WIN_BASE,KC_E)
#define HM_W LCTL_T(KC_W)

#define HM_J RCTL_T(KC_J)  // J acts as Ctrl when held
#define HM_K RSFT_T(KC_K)  // K acts as Shift when held
#define HM_L LALT_T(KC_L)  // L acts as Alt when held
#define HM_M KC_M
#define HM_N RGUI_T(KC_N)
#define HM_SCLN LT(WIN_FN, KC_SCLN)

#define HM2_F LCTL_T(KC_0)
#define HM2_D LSFT_T(KC_9)
#define HM2_S LALT_T(KC_1)
#define HM2_A KC_EQUAL
#define HM2_W S(KC_7)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_90(
        KC_MUTE,  KC_ESC,   BL_DOWN,  BL_UP,    KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY, KC_MNXT,   KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_INS,             KC_DEL,
        MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,      KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,      KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,     KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,  MO(MAC_FN),                    KC_SPC,             KC_RCMMD, KC_RCTL,             KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_90(
        BL_TOGG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11, KC_F12,   _______,            _______,
        _______,  _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  BL_DOWN,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_PGDN,
        _______,  _______,            _______,  _______,  _______,  _______,  BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_90(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        KC_F15,   HM_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,     KC_TAB,   HM_Q,     HM_W,     HM_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_END,
        MC_3,     KC_ESC,   HM_A,     HM_S,     HM_D,     HM_F,     KC_G,     KC_H,     HM_J,     HM_K,     HM_L,     HM_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,     KC_LSFT,            HM_Z,     HM_X,     HM_C,     HM_V,     KC_B,     KC_B,     HM_N,     HM_M,     KC_COMM,  KC_DOT,   KC_SLSH,  TG(MOD1),  KC_UP,
        KC_F16,   KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  TG(WIN_FN),                    MO(WIN_FN),             KC_RALT,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_90(
        BL_TOGG,  _______,  BL_DOWN,  BL_UP,    KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            KC_PGUP,
        _______,  _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,    KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______,            _______,
        _______,  BL_TOGG,  S(KC_BSLS),  HM2_W,    S(KC_LBRC),  S(KC_RBRC),  S(KC_MINS),  S(KC_2),  KC_PGUP,  KC_PGDN,  S(KC_3),  S(KC_4),  S(KC_8),  _______,  _______,            KC_PGDN,
        _______,  KC_CAPS,  HM2_A,  HM2_S,  HM2_D,  HM2_F,  S(KC_QUOT),  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  KC_BSPC,  KC_DEL,            _______,            KC_END,
        _______,  _______,            KC_MINS,  S(KC_EQUAL),  KC_LBRC,  KC_RBRC,  KC_QUOT,  BAT_LVL,  KC_HOME,  KC_END,  S(KC_5),  S(KC_6),  KC_BSLS,  KC_RSFT,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),
		
	[MOD1] = LAYOUT_ansi_90(
        _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11, KC_F12,   _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  KC_HOME,    KC_UP,  KC_END,  KC_DEL,  XXXXXXX,  KC_7,  KC_8,  KC_9,  XXXXXXX,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_BSPC,  XXXXXXX,  KC_4,  KC_5,  KC_6,  XXXXXXX,  _______,            _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  KC_1,  KC_2,  KC_3,  XXXXXXX,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                      KC_0,            XXXXXXX,  _______,            _______,  _______,  _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]  =  { ENCODER_CCW_CW(BL_DOWN, BL_UP)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_F13, KC_F14)},
    [WIN_FN]  =  { ENCODER_CCW_CW(BL_DOWN, BL_UP)},
    [MOD1]  =  { ENCODER_CCW_CW(BL_DOWN, BL_UP)}
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
	switch (keycode) {
		case LALT_T(KC_1):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LSFT(KC_1));
                return false;
            }
            break;
        case LCTL_T(KC_0):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LSFT(KC_0));
                return false;
            }
            break;
		case LSFT_T(KC_9):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LSFT(KC_9));
                return false;
            }
            break;
		case LT(WIN_BASE,KC_X):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(WIN_BASE,KC_C):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(WIN_BASE,KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
                return false;
            }
		case LT(WIN_BASE,KC_Z):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Z));
                return false;
            }
			break;
		case LT(WIN_BASE,KC_GRV):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(A(KC_LEFT));
                return false;
            }
			break;
		case LT(WIN_BASE,KC_E):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_INS);
				return false;
            }
    }
    return true;
}

const uint16_t PROGMEM enter_combo[] = {HM_J, HM_K, COMBO_END};
const uint16_t PROGMEM enter_combo2[] = {KC_UP, KC_DOWN, COMBO_END};
const uint16_t PROGMEM enter_combo6[] = {KC_RIGHT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM enter_combo3[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM enter_combo4[] = {HM_F, HM_D, COMBO_END};
const uint16_t PROGMEM enter_combo5[] = {HM2_F, HM2_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(enter_combo4, KC_ENT),
    COMBO(enter_combo5, KC_ENT),
    COMBO(enter_combo, KC_ENT),
    COMBO(enter_combo2, KC_ENT),
    COMBO(enter_combo3, KC_ENT),
	COMBO(enter_combo6, KC_ENT),
};

