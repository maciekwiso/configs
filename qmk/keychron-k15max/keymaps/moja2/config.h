/* Copyright 2024 ~ 2025 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#pragma once

#ifdef LED_MATRIX_ENABLE
/* LED matrix driver configuration */
#    define LED_MATRIX_LED_COUNT 89
#    define DRIVER_CS_PINS \
        { B8 }

/* Use first 8 channels of LED driver */
#    define SNLED27351_PHASE_CHANNEL SNLED27351_SCAN_PHASE_8_CHANNEL

/* Set LED driver current */
#    define SNLED27351_CURRENT_TUNE \
        { 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C }

/* Set to infinit, which is use in USB mode by default */
#    define LED_MATRIX_TIMEOUT LED_MATRIX_TIMEOUT_INFINITE
/* Allow shutdown of led driver to save power */
#    define LED_MATRIX_DRIVER_SHUTDOWN_ENABLE
#    define LED_MATRIX_DRIVER_LOAD_ENABLE
/* Turn off backlight on low brightness to save power */
#    define LED_MATRIX_BRIGHTNESS_TURN_OFF_VAL 48

/* Indications */
#    define DIM_CAPS_LOCK
#    define CAPS_LOCK_INDEX 48
#    define LOW_BAT_IND_INDEX \
        { 81, 83 }

#    define LED_MATRIX_KEYPRESSES
#endif
#define TAPPING_TERM 250
#define DYNAMIC_KEYMAP_LAYER_COUNT 7
#define LED_MATRIX_DEFAULT_ON false
#define COMBO_TERM 30