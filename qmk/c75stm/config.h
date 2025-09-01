#ifndef CONFIG_H
#define CONFIG_H

//#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    "qmkbuilder"
#define PRODUCT         "keyboards"
#define DESCRIPTION     "Keyboard"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

#define ENCODERS_PAD_A { B7,B7 }
#define ENCODERS_PAD_B { B13,C14}

#define ENCODER_RESOLUTIONS { 4,4 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define VIAL_KEYBOARD_UID {0xFB, 0xDD, 0xF4, 0xD2, 0xCF, 0xB4, 0x70, 0x8B}

/* key matrix pins */
#define MATRIX_ROW_PINS { B6, B5, A2, A6, A7}
#define MATRIX_COL_PINS { B0, B12, B15, B4, B8, B10, B1, C15, A5, A4, A3, A1, A0, B11, C13}
#define UNUSED_PINS

// #define LED_CAPS_LOCK_PIN 
// #define LED_PIN_ON_STATE 0

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

// #ifdef BACKLIGHT_PIN
// #define BACKLIGHT_LEVELS 3
// #endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN B14
// #ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 87
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
// #endif

// #ifdef RGB_MATRIX_ENABLE
//     // #define RGB_MATRIX_LED_COUNT          36 // Number of LEDs
//     #define DRIVER_LED_TOTAL              RGBLED_NUM
//     // #define RGB_MATRIX_SPLIT              { 18, 18 }
//      #define WS2812_DI_PIN                 GP23
//     // #define WS2812_PIO_USE_PIO1

//     #define RGB_DI_PIN A4
//     // #ifdef RGB_DI_PIN
//     // #define RGBLIGHT_ANIMATIONS
//     #define RGBLED_NUM 87
//     // #define RGBLIGHT_HUE_STEP 8
//     // #define RGBLIGHT_SAT_STEP 8
//     // #define RGBLIGHT_VAL_STEP 8

//     #define SPLIT_TRANSPORT_MIRROR
//     #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
//     #define RGB_MATRIX_KEYPRESSES
//     #define RGB_DISABLE_WHEN_USB_SUSPENDED
//     // #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
//     // #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

//     #define ENABLE_RGB_MATRIX_ALPHAS_MODS         // Static dual hue, speed is hue for secondary hue
//     #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN    // Static gradient top to bottom, speed controls how much gradient changes
//     #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right, speed controls how much gradient changes
//     #define ENABLE_RGB_MATRIX_BREATHING           // Single hue brightness cycling animation
//     #define ENABLE_RGB_MATRIX_BAND_SAT        // Single hue band fading saturation scrolling left to right
//     #define ENABLE_RGB_MATRIX_BAND_VAL        // Single hue band fading brightness scrolling left to right
//     #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT   // Single hue 3 blade spinning pinwheel fades saturation
//     #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL   // Single hue 3 blade spinning pinwheel fades brightness
//     #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT     // Single hue spinning spiral fades saturation
//     #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL     // Single hue spinning spiral fades brightness
//     #define ENABLE_RGB_MATRIX_CYCLE_ALL           // Full keyboard solid hue cycling through full gradient
//     #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT    // Full gradient scrolling left to right
//     #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN       // Full gradient scrolling top to bottom
//     #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN        // Full gradient scrolling out to in
//     #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL   // Full dual gradients scrolling out to in
//     #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON  // Full gradient Chevron shapped scrolling left to right
//     #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL      // Full gradient spinning pinwheel around center of keyboard
//     #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL        // Full gradient spinning spiral around center of keyboard
//     #define ENABLE_RGB_MATRIX_DUAL_BEACON         // Full gradient spinning around center of keyboard
//     #define ENABLE_RGB_MATRIX_RAINBOW_BEACON      // Full tighter gradient spinning around center of keyboard
//     #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS   // Full dual gradients spinning two halfs of keyboard
//     #define ENABLE_RGB_MATRIX_RAINDROPS           // Randomly changes a single key's hue
//     #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // Randomly changes a single key's hue and saturation
//     #define ENABLE_RGB_MATRIX_HUE_BREATHING       // Hue shifts up a slight ammount at the same time, then shifts back
//     #define ENABLE_RGB_MATRIX_HUE_PENDULUM        // Hue shifts up a slight ammount in a wave to the right, then back to the left
//     #define ENABLE_RGB_MATRIX_HUE_WAVE            // Hue shifts up a slight ammount and then back down in a wave to the right
//     #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL      // Single hue fractal filled keys pulsing horizontally out to edges
//     #define ENABLE_RGB_MATRIX_PIXEL_FLOW          // Pulsing RGB flow along LED wiring with random hues
//     #define ENABLE_RGB_MATRIX_PIXEL_RAIN          // Randomly light keys with random hues
//     #define ENABLE_RGB_MATRIX_TYPING_HEATMAP      // How hot is your WPM!
//     #define ENABLE_RGB_MATRIX_DIGITAL_RAIN        // That famous computer simulation
//     #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE   // Pulses keys hit to hue & value then fades value out
//     #define ENABLE_RGB_MATRIX_SOLID_REACTIVE      // Static single hue, pulses keys hit to shifted hue then fades to current hue
//     #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
//     #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
//     #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
//     #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
//     #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
//     #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
//     #define ENABLE_RGB_MATRIX_SPLASH              // Full gradient & value pulse away from a single key hit then fades value out
//     #define ENABLE_RGB_MATRIX_MULTISPLASH         // Full gradient & value pulse away from multiple key hits then fades value out
//     #define ENABLE_RGB_MATRIX_SOLID_SPLASH        // Hue & value pulse away from a single key hit then fades value out
//     #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH   // Hue & value pulse away from multiple key hits then fades value out
// #endif


#endif
