/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _NUM,
  _MEDIA,
  _ARROWS
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TGNUM TG(_NUM)
#define MEDIA MO(_MEDIA)
#define ARROWS MO(_ARROWS)
#define TGARRO TG(_ARROWS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   q  |   w  |   e  |   r  |   t  |   z  |   u  |   i  |   o  |   p  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   "  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   y  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   ;  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |ARROWS|  GUI | Alt  |LOWER |    Space    |RAISE |Left  |Right |MEDIA | Play |
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
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,   KC_I,      KC_O,     KC_P,       KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,      KC_L,     S(KC_QUOT), KC_ENT,
    KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,   KC_DOT,   KC_SCLN,    KC_MINS,
    KC_LCTL, ARROWS,  KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,  KC_LEFT,   KC_RGHT,  MEDIA,      KC_MPLY
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  Del |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   €  |   $  |   :  |      |      |   -  |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   #  |   %  |      |      |      |   +  |   1  |   2  |   3  |   /  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGNUM |TGArro|      |      |      |      .      |   0  |      |      |      |   ,  | 
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
	KC_DEL,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, LCA(KC_5),KC_DLR,  KC_COLN, _______, _______, KC_PMNS, KC_4,    KC_5,    KC_6,    KC_PAST, _______,
    KC_CAPS, KC_HASH,  KC_PERC, _______, _______, _______, KC_PPLS, KC_1,    KC_2,    KC_3,    KC_PSLS, KC_EQL,
    TGNUM,   TGARRO,   _______, _______, _______, _______, KC_DOT,  KC_0,    _______, _______, _______, KC_COMM
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  Del |   !  |   ^  |   `  |   ~  |      |      |   =  |   [  |   ]  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   @  |   &  |   :  |   /  |      |      |   -  |   (  |   )  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   %  |   |  |   \  |   '  |   "  |   +  | Left | Right|  Up  | Down |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_DEL,  KC_EXLM, KC_CIRC, KC_GRV,  KC_TILD, _______, _______,    KC_EQL,  KC_LBRC, KC_RBRC, KC_QUES, _______,
    _______, KC_AT,   KC_AMPR, KC_COLN, KC_SLSH, _______, _______,    KC_PMNS, KC_LPRN, KC_RPRN, KC_ASTR, _______, 
    _______, KC_HASH, KC_PERC, KC_PIPE, KC_BSLS, KC_QUOT, S(KC_QUOT), KC_PPLS, KC_LEFT, KC_RGHT, KC_UP,   KC_DOWN,
    _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
),

/* 'NUM'
 * ,-----------------------------------------------------------------------------------.
 * |  ESC |  No  |  No  |  No  |  No  |  No  |  No  |   7  |   8  |   9  |  No  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CALC |   €  |   $  |  No  |  No  |  No  |   -  |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   #  |   %  |  No  |  No  |  No  |   +  |   1  |   2  |   3  |   /  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGNUM |  No  |  No  |      |Raise |      .      |   0  |  No  |  No  |  No  |   ,  |
 * `-----------------------------------------------------------------------------------'
*/
[_NUM] = LAYOUT_planck_grid(
	KC_ESC,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_KP_7, KC_KP_8,  KC_KP_9, KC_NO,   _______,
    KC_CALC, LCA(KC_5),KC_DLR,  KC_NO,   KC_NO,   KC_NO,   KC_PMNS,  KC_KP_4, KC_KP_5,  KC_KP_6, KC_PAST, _______,
    _______, KC_HASH,  KC_PERC, KC_NO,   KC_NO,   KC_NO,   KC_PPLS,  KC_KP_1, KC_KP_2,  KC_KP_3, KC_PSLS, KC_EQL,
    TGNUM,   KC_NO,    KC_NO,   _______, KC_NO,   _______, KC_DOT,   KC_KP_0, KC_NO,    KC_NO,   KC_NO,   KC_COMM
),

/* 'MEDIA'
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F2  |  F4  |      |      |      |      |      | Print|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      | Mute |      |      | Vol+ | Vol- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Prev | Next |      | Play |
 * `-----------------------------------------------------------------------------------'
*/
[_MEDIA] = LAYOUT_planck_grid(
	_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, KC_PSCR, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_MUTE, _______, _______, KC_VOLU, KC_VOLD,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______, KC_MPLY
),

/* Arrows
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  Up  |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Left | Right|  Up  | Down |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Arrows|      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROWS] = LAYOUT_planck_grid(
    _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT, KC_UP,   KC_DOWN,
    _______, ARROWS,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      |      |Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, RESET,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  PLOVER,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, KC_MPRV,  KC_MNXT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};





#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

