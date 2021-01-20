/* Copyright 2019
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

enum layers {
  _BASE = 0,
  _FN1,
  _FN2,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define CMD_W    LGUI(KC_W)
#define CMD_Q    LGUI(KC_Q)
#define MT_LG_L  LGUI_T(KC_LEFT)
#define MT_LS_U  LSFT_T(KC_UP)
#define MT_RA_D  RALT_T(KC_DOWN)
#define MT_RG_R  RGUI_T(KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
    KC_LSFT,  KC_LGUI,  KC_LCTL,  KC_TAB,  \
    MO(_FN1), MO(_FN2), KC_VOLD,  KC_VOLU, \
    MT_LG_L,  MT_LS_U,  MT_RA_D,  MT_RG_R, \
    CMD_W,    CMD_Q,    KC_RCTL,  KC_BTN1  \
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    RESET,    _______,  _______,  _______, \
    _______,  _______,  _______,  _______, \
    _______,  _______,  _______,  _______, \
    _______,  _______,  KC_ENT,   KC_SPC   \
  ),
  [_FN2] = LAYOUT_ortho_4x4(
    _______,  _______,  _______,  _______, \
    _______,  _______,  _______,  _______, \
    _______,  _______,  _______,  _______, \
    _______,  _______,  _______,  _______  \
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}
