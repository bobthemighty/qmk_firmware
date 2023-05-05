/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"
#include "keymap_uk.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
    NUM, //numeric
    i3,
};

#define W_UP LGUI(KC_UP)
#define W_LEFT LGUI(KC_LEFT)
#define W_DOWN LGUI(KC_DOWN)
#define W_RIGHT LGUI(KC_RIGHT)
#define W_TAB LGUI(KC_W)
#define W_STAC LGUI(KC_S)
#define W_TOGG LGUI(KC_E)
#define W_FSC LGUI(KC_F)
#define WS_1 LGUI(KC_1)
#define WS_2 LGUI(KC_2)
#define WS_3 LGUI(KC_3)
#define WS_4 LGUI(KC_4)
#define WS_5 LGUI(KC_5)
#define WS_6 LGUI(KC_6)
#define WS_7 LGUI(KC_7)
#define WS_8 LGUI(KC_8)
#define WS_9 LGUI(KC_9)

#define DMENU LGUI(KC_D)


enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        DB_TOGG,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ASRP,
        KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),         TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    CAPS_WORD,
        LT(i3, KC_ESCAPE), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN),CAPS_WORD,
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    LT(SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT, KC_ASDN,    KC_ASUP,   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                            LT(NUM, KC_SPC),  KC_BSPC, DMENU,           KC_LALT,  LT(i3, KC_TAB),  LT(SYMB, KC_ENT)
    ),

    [SYMB] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, UK_AT,   KC_LCBR, KC_RCBR, UK_PIPE, _______,           _______, _______, UK_DQUO, KC_QUOTE,KC_GRAVE, KC_ASTR, KC_F12,
        _______, KC_COLN, KC_DLR,  KC_LPRN, KC_RPRN, KC_PLUS, _______,           _______, UK_TILD, KC_UNDS, KC_EQUAL,UK_LABK,  UK_RABK, _______,
        _______, UK_HASH, KC_CIRC, KC_LBRC, KC_RBRC, KC_PERCENT,                          KC_AMPR, KC_MINUS,UK_QUES, KC_SLASH, KC_NUBS, _______,
        EEP_RST, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI,           _______, _______, _______
    ),

    [MDIA] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,          _______,           _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [NUM] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______,           _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______,           _______, _______, KC_4,    KC_5,    KC_6,    KC_0,    KC_MPLY,
        _______, _______, KC_PGDN, _______, KC_PGUP, _______,                             _______, KC_1,    KC_2,    KC_3,    _______, KC_MPLY,
        _______, _______, _______, KC_BTN1, KC_BTN2,          _______,           _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [i3] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, W_TOGG,  W_FSC,   W_STAC,  _______,  QK_BOOT,
        _______, _______, WS_7   , WS_8   , WS_9   , _______, _______,           _______, _______, _______, W_UP,    _______, _______,  _______,
        _______, _______, WS_4   , WS_5   , WS_6   , _______, _______,           _______, _______, W_LEFT,  W_DOWN,  W_RIGHT, _______,  KC_MPLY,
        _______, _______, WS_1   , WS_2   , WS_3   , _______,                    _______, _______, LGUI(LSFT(KC_Q)),    _______, _______,  _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         LGUI(UK_L),         _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, LGUI(KC_ENTER)
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}


/* layer_state_t layer_state_set_user(layer_state_t state) { */

/*   switch(get_highest_layer(state)){ */
/*       case BASE: */
/*           autoshift_enable(); */
/*           break; */
/*         default: */
/*             autoshift_disable(); */
/*             break; */
/*   } */

/*   return state; */
/* }; */

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_ENT:
        return false;
#    ifndef NO_AUTO_SHIFT_ALPHA
        case KC_A ... KC_Z:
#    endif
#    ifndef NO_AUTO_SHIFT_NUMERIC
        case KC_1 ... KC_0:
#    endif
#    ifndef NO_AUTO_SHIFT_SPECIAL
        case KC_TAB:
        case KC_MINUS ... KC_SLASH:
        case KC_NONUS_BACKSLASH:
#    endif
            return true;
    }
    return get_custom_auto_shifted_key(keycode, record);
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
