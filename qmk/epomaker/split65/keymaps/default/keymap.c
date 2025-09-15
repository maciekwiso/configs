// Copyright 2025 EPOMAKER (@Epomaker)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgb_record/rgb_record.h"

enum layers {
    WIN_BASE,
    WIN_FN,
    MOD1,
	MOD2,
	MOD3,
	GAME1,
};

#define ______ HS_BLACK

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
	TD_F1,
	TD_F2,
	TD_F3,
	TD_F4,
	TD_F5,
	TD_F6,
	TD_F7,
	TD_F8,
	TD_F9,
	TD_F10,
	TD_F11,
	TD_F12,
};

#define HM_A LT(MOD2,KC_A)
#define HM_C TD(TD_CTLC)
#define HM_V TD(TD_CTLV)
#define HM_Z TD(TD_CTLZ)
#define HM_X TD(TD_CTLX)
#define HM_S LSFT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LALT_T(KC_F)
#define HM_B2 TD(TD_B2)
#define HM_ESC LT(MOD1,KC_ESC)
#define HM_SPC LT(MOD3,KC_SPC)
#define HM_RSFT LSFT_T(KC_ENT)
#define HM_COM TD(TD_COMM)
#define HM_DOT TD(TD_DOT)
#define HM_SLSH TD(TD_SLSH)
#define HM_SCLN TD(TD_COL)
#define HM_QUOT TD(TD_QUOT)
#define HM2_F TD(TD_KC9)
#define HM2_D TD(TD_LBRC)
#define TLDSL LT(WIN_FN,KC_GRV)
#define SPRL LT(WIN_FN,KC_SPC)
#define HM_LALT LALT_T(KC_DEL)
#define HM_LCTL LCTL_T(KC_INS)
#define HM_1 TD(TD_F1)
#define HM_2 TD(TD_F2)
#define HM_3 TD(TD_F3)
#define HM_4 TD(TD_F4)
#define HM_5 TD(TD_F5)
#define HM_6 TD(TD_F6)
#define HM_7 TD(TD_F7)
#define HM_8 TD(TD_F8)
#define HM_9 TD(TD_F9)
#define HM_10 TD(TD_F10)
#define HM_11 TD(TD_F11)
#define HM_12 TD(TD_F12)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_BASE] = LAYOUT( /* Base */
        KC_GRV,   HM_1,     HM_2,     HM_3,     HM_4,     HM_5,               HM_6,     HM_7,     HM_8,     HM_9,     HM_10,    HM_11,    HM_12,   KC_BSPC, KC_F15,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, HM_B2,   
        HM_ESC,   HM_A,     HM_S,     HM_D,     HM_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     HM_SCLN,  HM_QUOT,  KC_ENT,            KC_PGUP,
        KC_LSFT,  HM_Z,     HM_X,     HM_C,     HM_V,     KC_B,               KC_N,     KC_M,     HM_COM,   HM_DOT,   HM_SLSH,            KC_RSFT,  KC_UP,   KC_PGDN,
        HM_LCTL,  HM_LALT,  KC_BSPC,  HM_SPC,                                 HM_RSFT,  MO(WIN_FN),KC_LCTL, KC_RALT,                      KC_LEFT,  KC_DOWN, KC_RGHT),

    [WIN_FN] = LAYOUT( /* right FN */
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,  KC_F12,   EE_CLR,   _______,
        KC_TAB,   S(KC_6),  S(KC_BSLS),S(KC_7), S(KC_MINS),S(KC_4),           KC_PGUP,  KC_PGDN,  TLDSL,    SPRL,      XXXXXXX,  RGB_HUD, RGB_HUI,  _______,  KC_INS,  
        KC_CAPS,  KC_EQUAL, S(KC_1),  HM2_D,    HM2_F,    KC_MINS,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  S(KC_SCLN),S(KC_QUOT),_______,          KC_HOME, 
        _______,  S(KC_3),  S(KC_2),  S(KC_5),  S(KC_8),  S(KC_EQL),          KC_HOME,  KC_END,   S(KC_COMM),S(KC_DOT),KC_BSLS,           _______,  RGB_VAI,  KC_END,
        _______,  _______,  _______,  _______,                                _______,  _______,  _______, _______,                       RGB_SPD,  RGB_VAD,  RGB_SPI),

    [MOD1] = LAYOUT( /* esc hold */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_BSPC, KC_MUTE,
        KC_TAB,   KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  KC_PGDN,            XXXXXXX,  KC_7,     KC_8,     KC_9,     XXXXXXX,  KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,   
        KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_ENT,   XXXXXXX,            XXXXXXX,  KC_4,     KC_5,     KC_6,     XXXXXXX,  KC_QUOT,  KC_ENT,            KC_PGUP,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,            KC_RSFT,  KC_UP,   KC_PGDN,
        _______,  _______,  _______,  _______,                                KC_0,     XXXXXXX,  XXXXXXX,  XXXXXXX,                      KC_LEFT,  KC_DOWN, KC_RGHT),
		
    [MOD3] = LAYOUT( /* left space hold */
        QK_BOOT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,  KC_F12,   TO(GAME1), _______,
        _______,  XXXXXXX,  XXXXXXX,  KC_HOME,  KC_END,   KC_PGUP,            XXXXXXX,  KC_7,     KC_8,     KC_9,      XXXXXXX,  RGB_HUD, RGB_HUI,  _______,  KC_INS,  
        KC_CAPS,  A(KC_TAB),C(S(KC_TAB)),C(KC_TAB),KC_ENT,KC_PGDN,            XXXXXXX,  KC_4,     KC_5,     KC_6,      XXXXXXX,  RGB_SAI, _______,            KC_HOME, 
        _______,  XXXXXXX,  A(KC_F4), KC_F5,    MS_BTN4,  MS_BTN5,            XXXXXXX,  KC_1,     KC_2,     KC_3,      XXXXXXX,           _______,  RGB_VAI,  KC_END,
        _______,  _______,  _______,  _______,                                KC_0,     XXXXXXX,  XXXXXXX, XXXXXXX,                       RGB_SPD,  RGB_VAD,  RGB_SPI),

    [MOD2] = LAYOUT( /* A hold */
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,  KC_F12,   EE_CLR,   _______,
        XXXXXXX,  XXXXXXX,  KC_5,     KC_6,     KC_7,     KC_8,               XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,  RGB_HUD, RGB_HUI,  _______,  KC_INS,  
        XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,               KC_5,     KC_6,     KC_7,    KC_8,       KC_9,     KC_0,    _______,            KC_HOME, 
        _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_M,               XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,           _______,  RGB_VAI,  KC_END,
        _______,  _______,  S(KC_LEFT),_______,                                _______,  _______,  _______, _______,                       RGB_SPD,  RGB_VAD,  RGB_SPI),
		
    [GAME1] = LAYOUT( /* Base */
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQUAL, KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,   
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGUP,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,                                 KC_SPC,   KC_RALT,  TG(GAME1),KC_RCTL,                      KC_LEFT,  KC_DOWN, KC_RGHT),

};


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_F13, KC_F14)},
    [1] = {ENCODER_CCW_CW(_______, _______)},
    [2] = {ENCODER_CCW_CW(_______, _______)},
    [3] = {ENCODER_CCW_CW(_______, _______)},
    [4] = {ENCODER_CCW_CW(_______, _______)},
    [5] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif
// clang-format on

bool is_keyboard_master(void) {
    setPinInput(SPLIT_HAND_PIN);
    return readPin(SPLIT_HAND_PIN);
}

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
        tap_code16(KC_DEL);
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
	[TD_F1] = ACTION_TAP_DANCE_TAP_HOLD(KC_1, KC_F1),
	[TD_F2] = ACTION_TAP_DANCE_TAP_HOLD(KC_2, KC_F2),
	[TD_F3] = ACTION_TAP_DANCE_TAP_HOLD(KC_3, KC_F3),
	[TD_F4] = ACTION_TAP_DANCE_TAP_HOLD(KC_4, KC_F4),
	[TD_F5] = ACTION_TAP_DANCE_TAP_HOLD(KC_5, KC_F5),
	[TD_F6] = ACTION_TAP_DANCE_TAP_HOLD(KC_6, KC_F6),
	[TD_F7] = ACTION_TAP_DANCE_TAP_HOLD(KC_7, KC_F7),
	[TD_F8] = ACTION_TAP_DANCE_TAP_HOLD(KC_8, KC_F8),
	[TD_F9] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, KC_F9),
	[TD_F10] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, KC_F10),
	[TD_F11] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, KC_F11),
	[TD_F12] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQL, KC_F12),
};

// clang-format on
bool process_record_user_keymap(uint16_t keycode, keyrecord_t *record) {
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
		case TD(TD_F1):
		case TD(TD_F2):
		case TD(TD_F3):
		case TD(TD_F4):
		case TD(TD_F5):
		case TD(TD_F6):
		case TD(TD_F7):
		case TD(TD_F8):
		case TD(TD_F9):
		case TD(TD_F10):
		case TD(TD_F11):
		case TD(TD_F12):
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
    }
    return true;
}

const uint16_t PROGMEM enter_combo3[]   = {KC_UP, KC_RIGHT, COMBO_END};
combo_t key_combos[] = {
	COMBO(enter_combo3, KC_ESC),
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
            return 100;
	}
	return TAPPING_TERM;
}
