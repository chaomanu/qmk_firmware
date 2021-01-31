/* Copyright 2018 sevenseacat
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

#define _______ KC_TRNS

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KBD4X = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   q  |   w  |   e  |   r  |   t  |   z  |   u  |   i  |   o  |   p  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   '  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   y  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   ;  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |FNLEFT|  GUI | Alt  |LOWER |    Space    |RAISE |Left  |Right |FNRGHT| Play |
 * `-----------------------------------------------------------------------------------'
 *
 * Shift
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   "  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   <  |   >  |   :  |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,     KC_L,    KC_QUOT,  KC_ENT,
    KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SCLN,  KC_MINS,
    KC_LCTL, MO(4),   KC_LGUI, KC_LALT, MO(1),   KC_SPACE,         MO(2),  KC_LEFT,  KC_RGHT, MO(5),   KC_MPLY
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  Del |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   €  |   $  |   :  |      |      |   -  |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   #  |   %  |      |      |      |   +  |   1  |   2  |   3  |   /  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGNUM |      |      |      |      |      .      |   0  |   ,  |   ,  |      |      | 
 * `-----------------------------------------------------------------------------------'
 */
[1] = LAYOUT_planck_mit(
    KC_DEL,  KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,  KC_8,    KC_9,    KC_0,     _______,
    _______, LCA(KC_5), KC_DLR,  KC_COLN, _______, _______, KC_PMNS, KC_4,  KC_5,    KC_6,    KC_PAST,  _______,
    KC_CAPS, KC_HASH,   KC_PERC, _______, _______, _______, KC_PPLS, KC_1,  KC_2,    KC_3,    KC_PSLS,  KC_EQL,
    TG(3),   _______,   _______, _______, _______, KC_DOT,           KC_0,  KC_COMM, KC_COMM, _______,  _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  Del |   !  |   '  |   [  |   ]  |   <  |   >  |   (  |   )  |   "  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   *  |   @  |   &  |   :  |   /  |   ^  |   `  | Left | Right|  Up  | Down |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   %  |   |  |   \  |   ~  |   +  |   =  |   ,  |   .  |   ;  |   _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[2] = LAYOUT_planck_mit(
    KC_DEL,  KC_EXLM, KC_QUOT, KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_DQT,  KC_QUES, _______,
    KC_ASTR, KC_AT,   KC_AMPR, KC_COLN, KC_SLSH, KC_CIRC, KC_GRV,  KC_LEFT, KC_RGHT, KC_UP,   KC_DOWN, _______,
    _______, KC_HASH, KC_PERC, KC_PIPE, KC_BSLS, KC_TILD, KC_PPLS, KC_EQL,  KC_COMM, KC_DOT,  KC_SCLN, KC_UNDS,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
),                  

/* 'NUM'
 * ,-----------------------------------------------------------------------------------.
 * |  ESC |  No  |  No  |   ;  |  No  |  No  |  No  |   7  |   8  |   9  |  No  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CALC |   €  |   $  |   :  |  No  |  No  |   -  |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   %  |  No  |  No  |  No  |   +  |   1  |   2  |   3  |   /  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGNUM |  No  |  No  |      |Raise |      .      |   0  |  No  |   ,  |   ,  |      |
 * `-----------------------------------------------------------------------------------'
*/
[3] = LAYOUT_planck_mit(
    KC_ESC,  KC_NO,    KC_NO,   KC_SCLN, KC_NO,   KC_NO,   KC_NO,    KC_KP_7, KC_KP_8,   KC_KP_9, KC_NO,   _______,
    KC_CALC, LCA(KC_5),KC_DLR,  KC_COLN, KC_NO,   KC_NO,   KC_PMNS,  KC_KP_4, KC_KP_5,   KC_KP_6, KC_PAST, _______,
    _______, KC_HASH,  KC_PERC, KC_NO,   KC_NO,   KC_NO,   KC_PPLS,  KC_KP_1, KC_KP_2,   KC_KP_3, KC_PSLS, KC_EQL,
    TG(3),   KC_NO,    KC_NO,   _______, KC_NO,   KC_DOT,            KC_KP_0, KC_NO,     KC_COMM, KC_COMM, KC_NO
),

/* 'FNLEFT'
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F2  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      | Left | Right|  Up  | Down |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
*/
[4] = LAYOUT_planck_mit(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,  BL_TOGG, RGB_MOD, RGB_HUD, RGB_HUI,  RESET,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______,  RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI,  _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, _______,
    _______, _______, _______, _______, _______, _______,           RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G,  RGB_M_T
),

/* 'FNRGHT'
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F2  |  F4  |      |      |      |      |      | Print| Reset|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      | Mute |      |      | Vol+ | Vol- |
 * |------+------+------+------+-----+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Prev | Next |      | Play |
 * `-----------------------------------------------------------------------------------'
*/
[5] = LAYOUT_planck_mit(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, KC_PSCR, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_MUTE, _______, _______, KC_VOLU, KC_VOLD,
    _______, _______, _______, _______, _______, _______,          _______, KC_MPRV, KC_MNXT, _______, KC_MPLY
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}