/*
Copyright 2024 NEO

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum keyboard_layers { BASE_L, FUNC_L, GAME_L, DANGER_L };

#define MO_FN MO(FUNC_L)
#define MO_DGR MO(DANGER_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [BASE_L] = LAYOUT_wired(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, _______, KC_ENT ,
        KC_LSFT, _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, MO_FN  , MO_FN,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC ,                            KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT
    ),

    // https://docs.qmk.fm/#/keycodes
    //   [  ~  ]  [  1  ]  [  2  ]  [  3  ]  [  4  ]  [  5  ]  [  6  ]  [  7  ]  [  8  ]  [  9  ]  [  0  ]  [  -  ]  [  =  ]  [  ?  ]  [  ?  ]
    //   [ TAB ]  [  Q  ]  [  W  ]  [  E  ]  [  R  ]  [  T  ]  [  Y  ]  [  U  ]  [  I  ]  [  O  ]  [  P  ]  [  {  ]  [  }  ]  [ \|  ]
    //   [ ESC ]  [  A  ]  [  S  ]  [  D  ]  [  F  ]  [  G  ]  [  H  ]  [  J  ]  [  K  ]  [  L  ]  [  ;  ]  [  "  ]  [    ENTER     ]
    //   [ SFT ]  [  Z  ]  [  X  ]  [  C  ]  [  V  ]  [  B  ]  [  N  ]  [  M  ]  [ ,<  ]  [ .>  ]  [  /  ]  [   R SHIFT    ]
    //   [ CTL ]  [ ALT ]  [ CMD ]  [                       SPACE                      ]  [  ←  ]  [  ↓  ]  [  ↑  ]  [  →  ]

    [FUNC_L] = LAYOUT_wired(
        MO_DGR , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, KC_DEL ,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX,
        _______, _______, _______,                         DF(GAME_L),                            _______, _______, _______, _______
    ),

    [GAME_L] = LAYOUT_wired(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, _______, KC_ENT ,
        KC_LSFT, _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, DF(BASE_L), DF(BASE_L),
        KC_LCTL, KC_LALT, KC_BSLS,                            KC_SPC ,                            KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT
    ),

    [DANGER_L] = LAYOUT_wired(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )

    // clang-format on
};

const key_override_t delete_key_override =
    ko_make_basic(MOD_BIT_LCTRL, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &delete_key_override,
};

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LBRC: // Map "← + [" to be "cmd + ["
            if (record->event.pressed && is_key_pressed(KC_LEFT)) {
                register_code(KC_RGUI);
                tap_code(KC_LBRC);
                unregister_code(KC_RGUI);
                return false;
            }
        case KC_RBRC: // Map "← + ]" to be "cmd + ]"
            if (record->event.pressed && is_key_pressed(KC_LEFT)) {
                register_code(KC_RGUI);
                tap_code(KC_RBRC);
                unregister_code(KC_RGUI);
                return false;
            }
        default:
            return true;
    }
}

// These overrides save memory space.
// clang-format off
uint16_t keycode_config(uint16_t keycode) { return keycode; }
uint8_t mod_config(uint8_t mod) { return mod; }
// clang-format on
