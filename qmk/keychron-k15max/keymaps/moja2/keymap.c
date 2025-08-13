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
    MOD1,
	MOD2,
    GAME1
};

enum {
    TD_B2,
};

#define HM_GRV LT(WIN_BASE,KC_GRV)
#define HM_Q LT(MOD1,KC_Q)
#define HM_A LT(MOD2,KC_A)
#define HM_R LT(WIN_BASE,KC_R)
#define HM_C LT(WIN_BASE,KC_C)
#define HM_V LT(WIN_BASE,KC_V)
#define HM_Z LT(WIN_BASE,KC_Z)
#define HM_X LT(WIN_BASE,KC_X)
#define HM_S LSFT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LALT_T(KC_F)
#define HM_G KC_G
#define HM_E KC_E
#define HM_W KC_W
#define HM_T KC_T
#define HM_B2 TD(TD_B2)
#define HM_ESC LT(WIN_FN,KC_ESC)

#define HM_J KC_J
#define HM_K KC_K
#define HM_L KC_L
#define HM_M KC_M
#define HM_N KC_N
#define HCOM LALT_T(KC_COMM)
#define HM_SCLN RALT_T(KC_SCLN)
#define HM_M1 LT(WIN_BASE,KC_F5)
#define HM_M3 LSG(KC_LEFT)

#define HM2_F LT(WIN_FN,KC_9)
#define HM2_D LT(WIN_FN,KC_LBRC)
#define TLDSL LT(WIN_FN,KC_GRV)

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
        KC_MUTE,   KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_PGUP,
        HM_M1,     HM_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGDN,
        KC_FILE,   KC_TAB,   HM_Q,     HM_W,     HM_E,     HM_R,     HM_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        HM_M3,     HM_ESC,   HM_A,     HM_S,     HM_D,     HM_F,     HM_G,     KC_H,     HM_J,     HM_K,     HM_L,     HM_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        G(KC_UP),  KC_LSFT,            HM_Z,     HM_X,     HM_C,     HM_V,     KC_B,     HM_B2,    HM_N,     HM_M,     HCOM,     KC_DOT,   KC_SLSH,  TG(MOD1),   KC_UP,
        G(KC_DOWN),KC_LCTL,  KC_LWIN,            KC_BSPC,  KC_SPC,   KC_DEL,                                    KC_RSFT,  MO(WIN_FN),KC_LCTL,          KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_90(
        BL_TOGG,   _______,  BL_DOWN,  BL_UP,    KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
        _______,   A(KC_F4), KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,   KC_TAB,   S(KC_6),  S(KC_BSLS),S(KC_7), S(KC_MINS),S(KC_4), KC_PGUP,  KC_PGDN,  TLDSL,    XXXXXXX,  XXXXXXX,  _______,  _______,  _______,            KC_PGDN,
        _______,   KC_CAPS,  KC_EQUAL, S(KC_1),  HM2_D,    HM2_F,    KC_MINS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  S(KC_SCLN),S(KC_QUOT),        _______,            KC_END,
        _______,   _______,            S(KC_3),  S(KC_2),  S(KC_5),  S(KC_8),  S(KC_EQL),BAT_LVL,  KC_HOME,  KC_END,   S(KC_COMM),S(KC_DOT),KC_BSLS, _______,    _______,
        _______,   _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,             _______,   _______,  _______),
        
    [MOD1] = LAYOUT_ansi_90(
        _______,   _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   TO(GAME1),_______,            _______,
        _______,   _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,   _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  MS_UP,    KC_7,      KC_8,     KC_9,    XXXXXXX,  _______,  _______,  _______,            _______,
        _______,   KC_CAPS,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  MS_LEFT,  KC_4,      KC_5,     KC_6,    MS_RGHT,  _______,            _______,            _______,
        _______,   _______,            MS_BTN3,  MS_BTN1,  MS_BTN2,  MS_WHLU,  MS_WHLD,  XXXXXXX,   MS_DOWN,  KC_1,    KC_2,     KC_3,     XXXXXXX,  _______,    _______,
        _______,   _______,  _______,            _______,  _______,  _______,                       KC_0,              XXXXXXX,  _______,            _______,    _______,  _______),
        
    [MOD2] = LAYOUT_ansi_90(
        XXXXXXX,   XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,      KC_8,     KC_9,    KC_0,     XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_5,     KC_6,     KC_7,     KC_8,     XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,      KC_7,     KC_8,    KC_9,     KC_0,               XXXXXXX,            XXXXXXX,
        XXXXXXX,   _______,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,  XXXXXXX,   XXXXXXX,  _______, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    _______,
        XXXXXXX,   _______,  _______,            _______,  _______,  _______,                       _______,              _______,  _______,            _______,    _______,  _______),
		
    [GAME1] = LAYOUT_ansi_90(
        KC_MUTE,   KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,   KC_F9,     KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        KC_F8,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,      KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_F9,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_F10,    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,      KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_F11,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,    KC_UP,
        KC_F12,    KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,   TO(WIN_BASE),                 KC_ENT,             KC_RALT,  KC_RCTL,             KC_LEFT,   KC_DOWN,  KC_RGHT),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]  =  { ENCODER_CCW_CW(BL_DOWN, BL_UP)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_F13, KC_F14)},
    [WIN_FN]  =  { ENCODER_CCW_CW(BL_DOWN, BL_UP)},
    [MOD1]  =    { ENCODER_CCW_CW(BL_DOWN, BL_UP)},
	[MOD2]  =    { ENCODER_CCW_CW(BL_DOWN, BL_UP)},
    [GAME1] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    switch (keycode) {
		case TLDSL:
			if (record->event.pressed) {
                tap_code16(S(KC_GRV));
				tap_code16(KC_SLSH);
                return false;
            }
		case LT(WIN_FN,KC_9):
			if (record->event.pressed) {
				if (!record->tap.count) {
					tap_code16(S(KC_0));
				} else {
					tap_code16(S(KC_9));
				}
            }
            return false;
		case LT(WIN_FN,KC_LBRC):
			if (record->event.pressed) {
				if (!record->tap.count) {
					tap_code16(S(KC_RBRC));
				} else {
					tap_code16(S(KC_LBRC));
				}
            }
            return false;
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
        case LT(WIN_BASE,KC_R):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_INS);
                return false;
            }
		case LT(WIN_BASE,KC_F5):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(A(KC_F4));
                return false;
            }
		case LT(MOD2,KC_A):
            if (!record->tap.count && record->event.pressed) {
				register_mods(MOD_MASK_GUI);
            } else if (!record->event.pressed) {
				unregister_mods(MOD_MASK_GUI);
			}
    }
    return true;
}

const uint16_t PROGMEM enter_combo1[]   = {HM_J, HM_K, COMBO_END};
const uint16_t PROGMEM enter_combo2[]   = {KC_UP, KC_DOWN, COMBO_END};
const uint16_t PROGMEM enter_combo3[]   = {KC_UP, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM enter_combo6[]   = {KC_RIGHT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM enter_combo5[]   = {HM2_F, HM2_D, COMBO_END};
const uint16_t PROGMEM alttab_combo1[]  = {KC_EQUAL, S(KC_1), COMBO_END};
const uint16_t PROGMEM ctrltab_combo1[] = {S(KC_1),  HM2_D, COMBO_END};
const uint16_t PROGMEM altstab_combo1[] = {KC_EQUAL, HM2_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(enter_combo5, KC_ENT),
    COMBO(enter_combo1, KC_ENT),
    COMBO(enter_combo2, KC_ENT),
    COMBO(enter_combo6, KC_ENT),
	COMBO(enter_combo3, KC_ESC),
	COMBO(alttab_combo1, A(KC_TAB)),
	COMBO(ctrltab_combo1, C(KC_TAB)),
	COMBO(altstab_combo1, C(S(KC_TAB))),
};

void tap_dance_b2(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 4) {
        tap_code16(LGUI(KC_M));
    } else if (state->count == 3) {
        SEND_STRING("Please approve ");
        tap_code16(C(KC_V));
        tap_code16(KC_ENT);
    } else if (state->count == 2) {
        tap_code16(LCA(KC_END));
		tap_code_delay(KC_NO, 1200);
		tap_code16(KC_ENT);
    } else {
        tap_code16(KC_B);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_B2] = ACTION_TAP_DANCE_FN(tap_dance_b2),
};
