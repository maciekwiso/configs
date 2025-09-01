#include "kb.h"

enum layers{
    WIN_BASE,
    WIN_FN,
    MOD1,
	MOD3,
	MOD2
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
	TD_GRV,
	TD_F5,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  KC_NO,   KC_NO,   KC_NO,   KC_6,    KC_7,  KC_8,       KC_9,    KC_0,    HM_B2,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,  KC_INS,  KC_HOME, KC_PGUP, KC_Y,    KC_U,  KC_I,       KC_O,    KC_P,    KC_RBRC,
		HM_ESC,  HM_A,    HM_S,    HM_D,    HM_F,   KC_G,  KC_DEL,  KC_END,  KC_PGDN, KC_H,    KC_J,  KC_K,       KC_L,    HM_SCLN, HM_QUOT,
		KC_LSFT, HM_Z,    HM_X,    HM_C,    HM_V,   KC_B,  KC_NO,   KC_UP,   KC_NO,   KC_N,    KC_M,  HM_COM,     HM_DOT,  HM_SLSH, KC_LSFT,
		KC_LCTL, KC_LWIN, KC_LALT, KC_BSPC, HM_SPC, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, HM_RSFT, KC_NO, MO(WIN_FN), KC_LCTL, KC_LWIN, KC_RALT),
	LAYOUT(
		KC_NO,   KC_F1,    KC_F2,     KC_F3,   KC_F4,     KC_F5,     KC_F11,  KC_F12,  KC_NO,   KC_F6,   KC_F7,   KC_F8,     KC_F9,    KC_F10,    KC_NO,
		KC_NO,   S(KC_6),  S(KC_BSLS),S(KC_7), S(KC_MINS),S(KC_4),   KC_NO,   KC_NO,   KC_NO,   KC_PGUP, KC_PGDN, KC_NO,     KC_NO,    KC_NO,     KC_NO,
		KC_NO,   KC_EQUAL, S(KC_1),   HM2_D,   HM2_F,     KC_MINS,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT,  S(KC_SCLN),S(KC_QUOT),
		KC_NO,   S(KC_3),  S(KC_2),   S(KC_5), S(KC_8),   S(KC_EQL), KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  S(KC_COMM),S(KC_DOT),KC_BSLS,   KC_TRNS,
		KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS),
	LAYOUT(
		QK_BOOT, KC_F1,    KC_F2,     KC_F3,   KC_F4,     KC_F5,     KC_F11,  KC_F12,  KC_NO,   KC_F6,   KC_F7,   KC_F8,     KC_F9,    KC_F10,    KC_NO,
		KC_NO,   KC_HOME,  KC_UP,     KC_END,  KC_PGUP,   KC_PGDN,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_7,    KC_8,      KC_9,     KC_NO,     KC_NO,
		KC_NO,   KC_LEFT,  KC_DOWN,   KC_RGHT, KC_ENT,    KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_4,    KC_5,      KC_6,     KC_NO,     KC_NO,
		KC_NO,   KC_NO,    KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_1,    KC_2,      KC_3,     KC_NO,     KC_NO,
		KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_0,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS),
	LAYOUT(
		QK_BOOT, KC_F1,    KC_F2,     KC_F3,   KC_F4,     KC_F5,     KC_F11,  KC_F12,  KC_NO,   KC_F6,   KC_F7,   KC_F8,     KC_F9,    KC_F10,    KC_NO,
		KC_NO,   KC_NO,    KC_NO,     KC_HOME, KC_END,    KC_PGUP,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_7,    KC_8,      KC_9,     KC_NO,     KC_NO,
		KC_CAPS, A(KC_TAB),C(S(KC_TAB)),C(KC_TAB),KC_ENT, KC_PGDN,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_4,    KC_5,      KC_6,     KC_NO,     KC_NO,
		KC_NO,   KC_NO,    A(KC_F4),  KC_F5,   MS_BTN4,   MS_BTN5,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_1,    KC_2,      KC_3,     KC_NO,     KC_NO,
		KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_0,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS),
	LAYOUT(
		KC_NO,   KC_NO,    KC_NO,     KC_NO,   KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,     KC_NO,
		KC_NO,   KC_NO,    KC_5,      KC_6,    KC_7,      KC_8,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,     KC_NO,
		KC_NO,   KC_NO,    KC_1,      KC_2,    KC_3,      KC_4,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,     KC_NO,
		KC_NO,   KC_LEFT,  KC_DOWN,   KC_UP,   KC_RGHT,   KC_M,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,     KC_NO,
		KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS),
};

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
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
			tap_dance_action_t *action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
			break;
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

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {{
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
{29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15},
{30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44},
{59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45},
{60, 61, 62, 63, 64, 65, 66, 67, 68, 69 ,70, 71, 72, 73, 74},
},

{
// x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
// y = 64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
{0, 0}, {16, 0}, {32, 0}, {48, 0}, {64, 0}, {80, 0}, {96, 0}, {112, 0}, {128, 0}, {144, 0}, {160, 0}, {176, 0}, {192, 0},{208, 0},{224, 0},
{224, 16}, {208, 16}, {192, 16}, {176, 16}, {160, 16}, {144, 16}, {128, 16}, {112, 16}, {96, 16}, {80, 16}, {64, 16}, {48, 16}, {32, 16}, {16, 16}, {0, 16},
{0, 32}, {16, 32}, {32, 32}, {48, 32}, {64, 32}, {80, 32}, {96, 32}, {112, 32}, {128, 32}, {144, 32}, {160, 32}, {176, 32}, {192, 32},{208, 32},{224, 32},
{224, 48}, {208, 48}, {192, 48}, {176, 48}, {160, 48}, {144, 48}, {128, 48}, {112, 48}, {96, 48}, {80, 48}, {64, 48}, {48, 48}, {32, 48}, {16, 48}, {0, 48},
{0, 64}, {16, 64}, {32, 64}, {48, 64}, {64, 64}, {80, 64}, {96, 64}, {112, 64}, {128, 64}, {144, 64}, {160, 64}, {176, 64}, {192, 64},{208, 64},{224, 64},

{232, 56}, {184, 56}, {136, 56}, {88, 56}, {40, 56}, {8, 56},
{8, 8}, {40, 8}, {88, 8}, {136, 8}, {184, 8}, {232, 8}
},


{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
};
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] =   { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    //                  Encoder 1                                     Encoder 2
};
#endif
