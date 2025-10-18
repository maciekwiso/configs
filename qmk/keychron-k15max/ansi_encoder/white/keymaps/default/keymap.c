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
	MOD3,
    GAME1
};

enum {
    TD_B2,
	TD_COL,
	TD_QUOT,
	TD_COMM,
	TD_DOT,
	TD_SLSH,
	TD_KC9,
	TD_LBRC,
	TD_CTLX,
	TD_CTLZ,
	TD_CTLC,
	TD_CTLV,
	TD_F5,
	TD_RBRC,
	TD_UND,
	TD_MIN,
	TD_HOM,
	TD_END,
	TD_AMP,
	TD_PIP
};

#define HM_GRV KC_GRV
#define HM_Q KC_Q
#define HM_A LT(MOD2,KC_A)
#define HM_C TD(TD_CTLC)
#define HM_V TD(TD_CTLV)
#define HM_Z TD(TD_CTLZ)
#define HM_X TD(TD_CTLX)
#define HM_S LSFT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F TD(TD_RBRC)
#define HM_G TD(TD_MIN)
#define HM_R TD(TD_UND)
#define HM_E TD(TD_AMP)
#define HM_W TD(TD_PIP)
#define HM_T KC_T
#define HM_B2 TD(TD_B2)
#define HM_ESC LT(MOD1,KC_ESC)
#define HM_SPC LT(MOD3,KC_SPC)
#define HM_RSFT LT(GAME1,KC_ENT)

#define HM_J KC_J
#define HM_K KC_K
#define HM_L KC_L
#define HM_N TD(TD_HOM)
#define HM_M TD(TD_END)
#define HCOM TD(TD_COMM)
#define HM_DOT TD(TD_DOT)
#define HM_SLSH TD(TD_SLSH)
#define HM_SCLN TD(TD_COL)
#define HM_QUOT TD(TD_QUOT)
#define HM_M1 TD(TD_F5)
#define HM_M3 LSG(KC_LEFT)

#define HM2_F TD(TD_KC9)
#define HM2_D TD(TD_LBRC)
#define TLDSL LT(WIN_FN,KC_GRV)
#define SPRL LT(WIN_FN,KC_SPC)

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
        HM_M3,     HM_ESC,   HM_A,     HM_S,     HM_D,     HM_F,     HM_G,     KC_H,     HM_J,     HM_K,     HM_L,     HM_SCLN,  HM_QUOT,            KC_ENT,             KC_END,
        G(KC_UP),  KC_LSFT,            HM_Z,     HM_X,     HM_C,     HM_V,     KC_B,     HM_B2,    HM_N,     HM_M,     HCOM,     HM_DOT,   HM_SLSH,  TG(MOD1),   KC_UP,
        G(KC_DOWN),KC_LCTL,  LALT_T(KC_INS),     KC_BSPC,  HM_SPC,   KC_DEL,                                    HM_RSFT,  MO(WIN_FN),KC_LCTL,          KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_90(/* right FN */
        BL_TOGG,   _______,  BL_DOWN,  BL_UP,    KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
        _______,   A(KC_F4), KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,   KC_TAB,   S(KC_6),  S(KC_BSLS),S(KC_7), S(KC_MINS),S(KC_4), KC_PGUP,  KC_PGDN,  TLDSL,    SPRL,     XXXXXXX,  _______,  _______,  _______,            KC_PGDN,
        _______,   KC_CAPS,  KC_EQUAL, S(KC_1),  HM2_D,    HM2_F,    KC_MINS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  S(KC_SCLN),S(KC_QUOT),        _______,            KC_END,
        _______,   _______,            S(KC_3),  S(KC_2),  S(KC_5),  S(KC_8),  S(KC_EQL),BAT_LVL,  KC_HOME,  KC_END,   S(KC_COMM),S(KC_DOT),KC_BSLS, _______,    _______,
        _______,   _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,             _______,   _______,  _______),
        
    [MOD1] = LAYOUT_ansi_90(/* esc hold */
        _______,   _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   TO(GAME1),_______,            _______,
        _______,   _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,   _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  KC_PGDN,  XXXXXXX,  KC_7,      KC_8,     KC_9,    XXXXXXX,  _______,  _______,  _______,            _______,
        _______,   KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,   XXXXXXX,  XXXXXXX,  KC_4,      KC_5,     KC_6,    XXXXXXX,  _______,            _______,            _______,
        _______,   _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_1,    KC_2,     KC_3,     XXXXXXX,  _______,    _______,
        _______,   _______,  _______,            _______,  _______,  _______,                       KC_0,              XXXXXXX,  _______,            _______,    _______,  _______),
        
    [MOD3] = LAYOUT_ansi_90(/* left space hold */
        _______,   QK_BOOT,  KC_F1,    KC_F2,       KC_F3,    KC_F4,     KC_F5,      KC_F6,      KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   TO(GAME1),_______,            _______,
        _______,   _______,  KC_F1,    KC_F2,       KC_F3,    KC_F4,     KC_F5,      KC_F6,      KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,   _______,  XXXXXXX,  XXXXXXX,     KC_HOME,  KC_END,    KC_PGUP,    XXXXXXX,    KC_7,      KC_8,     KC_9,    XXXXXXX,  _______,  _______,  _______,            _______,
        _______,   KC_CAPS,  A(KC_TAB),C(S(KC_TAB)),C(KC_TAB),KC_ENT,    KC_PGDN,    XXXXXXX,    KC_4,      KC_5,     KC_6,    XXXXXXX,  _______,            _______,            _______,
        _______,   _______,            MS_BTN1,     MS_BTN2,  KC_F5,     MS_BTN4,    MS_BTN5,    XXXXXXX,   XXXXXXX,  KC_1,    KC_2,     KC_3,     XXXXXXX,  _______,    _______,
        _______,   _______,  _______,               _______,  _______,   _______,                         KC_0,              XXXXXXX,  _______,            _______,    _______,  _______),

    [MOD2] = LAYOUT_ansi_90(/* A hold */
        XXXXXXX,   XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,      KC_8,     KC_9,    KC_0,     XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_5,     KC_6,     KC_7,     KC_8,     XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,      KC_7,     KC_8,    KC_9,     KC_0,               XXXXXXX,            XXXXXXX,
        XXXXXXX,   _______,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_M,     XXXXXXX,   XXXXXXX,  _______, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    _______,
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
	[MOD3]  =    { ENCODER_CCW_CW(BL_DOWN, BL_UP)},
    [GAME1] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
#endif // ENCODER_MAP_ENABLE

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                        \
    {                                                                               \
        .fn        = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
        .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),               \
    }

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
    [TD_COL] = ACTION_TAP_DANCE_TAP_HOLD(KC_SCLN, KC_COLN),
    [TD_QUOT] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUOT, S(KC_QUOT)),
	[TD_COMM] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMM, S(KC_COMM)),
	[TD_DOT] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, S(KC_DOT)),
	[TD_SLSH] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLSH, KC_BSLS),
	[TD_KC9] = ACTION_TAP_DANCE_TAP_HOLD(S(KC_9), S(KC_0)),
	[TD_LBRC] = ACTION_TAP_DANCE_TAP_HOLD(S(KC_LBRC), S(KC_RBRC)),
	[TD_CTLX] = ACTION_TAP_DANCE_TAP_HOLD(KC_X, C(KC_X)),
	[TD_CTLZ] = ACTION_TAP_DANCE_TAP_HOLD(KC_Z, C(KC_Z)),
	[TD_CTLC] = ACTION_TAP_DANCE_TAP_HOLD(KC_C, C(KC_C)),
	[TD_CTLV] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, C(KC_V)),
	[TD_F5] = ACTION_TAP_DANCE_TAP_HOLD(KC_F5, A(KC_F4)),
	[TD_RBRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_F, S(KC_9)),
	[TD_MIN] = ACTION_TAP_DANCE_TAP_HOLD(KC_G, KC_MINS),
	[TD_UND] = ACTION_TAP_DANCE_TAP_HOLD(KC_R, S(KC_MINS)),
	[TD_HOM] = ACTION_TAP_DANCE_TAP_HOLD(KC_N, KC_HOME),
	[TD_END] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, KC_END),
	[TD_AMP] = ACTION_TAP_DANCE_TAP_HOLD(KC_E, S(KC_7)),
	[TD_PIP] = ACTION_TAP_DANCE_TAP_HOLD(KC_W, S(KC_BSLS)),
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    switch (keycode) {
		case TD(TD_COL):
		case TD(TD_QUOT):
		case TD(TD_COMM):
		case TD(TD_DOT):
		case TD(TD_SLSH):
		case TD(TD_KC9):
		case TD(TD_LBRC):
		case TD(TD_CTLX):
		case TD(TD_CTLZ):
		case TD(TD_CTLC):
		case TD(TD_CTLV):
		case TD(TD_F5):
		case TD(TD_RBRC):
		case TD(TD_MIN):
		case TD(TD_UND):
		case TD(TD_HOM):
		case TD(TD_END):
		case TD(TD_AMP):
		case TD(TD_PIP):
            tap_dance_action_t *action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
			break;
		case SPRL:
			if (record->event.pressed) {
                SEND_STRING("spring.cloud.config.label=");
                return false;
            }
		case TLDSL:
			if (record->event.pressed) {
                tap_code16(S(KC_GRV));
				tap_code16(KC_SLSH);
                return false;
            }
		case LT(MOD2,KC_A):
            if (!record->tap.count && record->event.pressed) {
				register_mods(MOD_MASK_GUI);
            } else if (!record->event.pressed) {
				unregister_mods(MOD_MASK_GUI);
			}
			break;
		case HM_RSFT:
            if (!record->tap.count && record->event.pressed) {
				register_mods(MOD_MASK_SHIFT);
            } else if (!record->event.pressed) {
				unregister_mods(MOD_MASK_SHIFT);
			}
			break;
    }
    return true;
}

const uint16_t PROGMEM esc_combo1[]   = {KC_UP, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM ALT_F4_combo1[]   = {MS_BTN2, MS_BTN4, COMBO_END};
combo_t key_combos[] = {
	COMBO(esc_combo1, KC_ESC),
	COMBO(ALT_F4_combo1, A(KC_F4)),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_RSFT:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_RSFT:
            return 140;
	}
	return TAPPING_TERM;
}