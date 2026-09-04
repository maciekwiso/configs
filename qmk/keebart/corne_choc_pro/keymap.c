#include QMK_KEYBOARD_H

enum layers {
    WIN_BASE,
    WIN_FN,
    MOD1,
	MOD2,
	MOD3,
	MOD4,
	GAME1,
};

enum {
    TD_FUN1,
	TD_FUN2,
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
	TD_SQBRC,
	TD_RBRC,
	TD_UND,
	TD_MIN,
	TD_HOM,
	TD_END,
	TD_ARR,
	TD_AMP,
	TD_PIP
};

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
#define HM_N TD(TD_HOM)
#define HM_M TD(TD_END)
#define HM_FUN1 TD(TD_FUN1)
#define HM_FUN2 TD(TD_FUN2)
#define HM_ESC LT(MOD1,KC_ESC)
#define HM_SPC LT(MOD3,KC_SPC)
#define HM_RSFT LT(GAME1,KC_ENT)
#define HM_COM TD(TD_COMM)
#define HM_DOT TD(TD_DOT)
#define HM_SLSH TD(TD_SLSH)
#define HM_SCLN TD(TD_COL)
#define HM_QUOT TD(TD_QUOT)
#define HM_ARR TD(TD_ARR)
#define HM2_F TD(TD_KC9)
#define HM2_D TD(TD_LBRC)
#define HM_LBRC TD(TD_SQBRC)
#define TLDSL LT(WIN_FN,KC_GRV)
#define SPRL LT(WIN_FN,KC_SPC)
#define HM_LALT LALT_T(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
             KC_TAB,  KC_Q,    HM_W,    HM_E,    HM_R,    KC_T,   KC_LWIN,    MO(MOD4),   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, HM_LBRC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            HM_ESC,  HM_A,    HM_S,    HM_D,    HM_F,    HM_G,    HM_FUN1,    HM_FUN2,    KC_H,    KC_J,    KC_K,    KC_L, HM_SCLN, HM_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
            HM_LALT, HM_Z,    HM_X,    HM_C,    HM_V,    KC_B,                            HM_N,    HM_M,    HM_COM,  HM_DOT,  HM_SLSH, HM_ARR,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                                KC_BSPC, HM_SPC,  KC_DEL,      KC_LCTL, HM_RSFT, MO(WIN_FN)
                                            //`--------------------------'  `--------------------------'
    ),

    [WIN_FN] = LAYOUT_split_3x6_3_ex2(/* right FN */
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
             KC_TAB,  S(KC_6), S(KC_BSLS),S(KC_7),S(KC_MINS),S(KC_4),XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, TLDSL,   SPRL,    XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_CAPS, KC_EQUAL,S(KC_1), HM2_D,   HM2_F,   KC_MINS,XXXXXXX,     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, S(KC_SCLN),S(KC_QUOT),
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
            _______, S(KC_3), S(KC_2), S(KC_5), S(KC_8), S(KC_EQL),                    KC_HOME, KC_END,  S(KC_COMM),S(KC_DOT),KC_BSLS,_______,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,     XXXXXXX, KC_ENT, XXXXXXX
                                            //`--------------------------'  `--------------------------'
    ),

    [MOD1] = LAYOUT_split_3x6_3_ex2(/* esc hold */
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
             KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PGDN,XXXXXXX,    XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  KC_MINS, RM_NEXT,    XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
            RM_TOGG, S(KC_3), S(KC_2), S(KC_5), S(KC_8),S(KC_EQL),                     XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, HM2_F,      KC_0,    KC_0,    KC_DOT
                                            //`--------------------------'  `--------------------------'
    ),

    [MOD3] = LAYOUT_split_3x6_3_ex2(/* left space hold */
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
            KC_GRV,   KC_LSFT, KC_LCTL, KC_HOME, KC_END,  KC_PGUP,KC_F14,    XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, TO(GAME1),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_CAPS,A(KC_TAB),C(S(KC_TAB)),C(KC_TAB),KC_ENT,KC_PGDN,KC_F13,  XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
            _______,LCG(KC_LEFT),LCG(KC_RIGHT),KC_F5,MS_BTN4, MS_BTN5,                 XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,     KC_0,    KC_0,    KC_DOT
                                            //`--------------------------'  `--------------------------'
    ),
	
    [MOD2] = LAYOUT_split_3x6_3_ex2(/* A hold */
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
             XXXXXXX, KC_9,    KC_5,    KC_6,    KC_7,    KC_8, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    XXXXXXX,    XXXXXXX, C(KC_D), C(KC_LEFT),C(KC_RIGHT),C(KC_F4),XXXXXXX,XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                       C(KC_LEFT),S(KC_LEFT),C(KC_RIGHT),     XXXXXXX, KC_TAB,    XXXXXXX
                                            //`--------------------------'  `--------------------------'
    ),
	
	[MOD4] = LAYOUT_split_3x6_3_ex2(/* F keys */
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
             KC_F1, KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                               KC_LCTL, KC_LSFT, KC_LALT,     KC_LWIN, KC_LSFT, KC_LALT
                                            //`--------------------------'  `--------------------------'
    ),

    [GAME1] = LAYOUT_split_3x6_3_ex2(/* clean */
        //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
             KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LCTL,    KC_RCTL,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, HM_LBRC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LALT,    KC_RALT,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
            KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
        //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                                KC_BSPC, KC_SPC,  KC_DEL,     TG(GAME1),LSFT_T(KC_ENT),KC_ENT
                                            //`--------------------------'  `--------------------------'
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [1] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [2] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [3] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
	[4] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
	[5] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
	[6] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
};
#endif

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

void tap_dance_fun1(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 4) {
        tap_code16(LCA(KC_BRK));
		tap_code_delay(KC_NO, 100);
		tap_code16(KC_DOWN);
		tap_code_delay(KC_NO, 100);
		tap_code16(KC_ENT);
    } else if (state->count == 3) {
        SEND_STRING("Please approve ");
        tap_code16(C(KC_V));
        tap_code16(KC_ENT);
    } else if (state->count == 2) {
        tap_code16(LSG(KC_LEFT));
    } else {
        tap_code16(LCS(KC_1));
    }
}

void tap_dance_fun2(tap_dance_state_t *state, void *user_data) {
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
        tap_code16(C(KC_D));
    }
}

tap_dance_action_t tap_dance_actions[] = {
	[TD_FUN1] = ACTION_TAP_DANCE_FN(tap_dance_fun1),
	[TD_FUN2] = ACTION_TAP_DANCE_FN(tap_dance_fun2),
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
	[TD_SQBRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_LBRC, KC_RBRC),
	[TD_RBRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_F, S(KC_9)),
	[TD_MIN] = ACTION_TAP_DANCE_TAP_HOLD(KC_G, KC_MINS),
	[TD_UND] = ACTION_TAP_DANCE_TAP_HOLD(KC_R, S(KC_MINS)),
	[TD_HOM] = ACTION_TAP_DANCE_TAP_HOLD(KC_N, KC_HOME),
	[TD_END] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, KC_END),
	[TD_ARR] = ACTION_TAP_DANCE_TAP_HOLD(KC_UP, KC_DOWN),
	[TD_AMP] = ACTION_TAP_DANCE_TAP_HOLD(KC_E, S(KC_7)),
	[TD_PIP] = ACTION_TAP_DANCE_TAP_HOLD(KC_W, S(KC_BSLS)),
};

// clang-format on
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
		case TD(TD_SQBRC):
		case TD(TD_RBRC):
		case TD(TD_MIN):
		case TD(TD_UND):
		case TD(TD_HOM):
		case TD(TD_END):
		case TD(TD_ARR):
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
const uint16_t PROGMEM ALT_F4_combo1[]   = {LCG(KC_RIGHT), MS_BTN4, COMBO_END};
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
