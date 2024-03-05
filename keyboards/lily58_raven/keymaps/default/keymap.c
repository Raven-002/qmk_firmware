// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define LAYOUT LAYOUT_lily58
#define MISSING

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐                    ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │ ESC  │   1  │   2  │   3  │   4  │   5  │                    │   6  │   7  │   8  │   9  │   0  │  `   │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │ Tab  │   Q  │   W  │   E  │   R  │   T  │                    │   Y  │   U  │   I  │   O  │   P  │  -   │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤                    ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │LCTRL │   A  │   S  │   D  │   F  │   G  ├───────┐    ┌───────┤   H  │   J  │   K  │   L  │   ;  │  '   │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤   [   │    │    ]  ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │LShift│   Z  │   X  │   C  │   V  │   B  ├───────│    │───────┤   N  │   M  │   ,  │   .  │   /  │RShift│
     * └──────┴──────┴───┬──┴───┬──┴───┬──┴───┬──/       /     \      \───┬──┴───┬──┴───┬──┴───┬──┴──────┴──────┘
     *                   │ LAlt │ LGUI │Space │ /Enter  /       \Enter \  │Space │BackSP│ RALT │
     *                   │      │ WIN  │      │/       /         \      \ │      │      │      │
     *                   └──────┴──────┴──────┴───────'           '──────'┴──────┴──────┴──────┘
     */
    [_QWERTY] = LAYOUT(
        /* clang-format off */
          KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
          KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
          KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
          KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                       KC_LALT, KC_LGUI, KC_SPC, KC_ENT, KC_LBRC,             KC_RBRC, KC_ENT,  KC_SPC, KC_BSPC, KC_RALT
        /* clang-format on */
        ),
};

void keyboard_post_init_user(void) {
    if (is_keyboard_left()) {
        setrgb(255, 0, 100, (rgb_led_t *)&led[0]);
    } else {
        setrgb(100, 0, 255, (rgb_led_t *)&led[0]);
    }
    rgblight_set();
}
