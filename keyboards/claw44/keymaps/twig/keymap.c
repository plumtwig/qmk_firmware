#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_ KC_TRNS
#define KC_RST RESET
#define KC_L_SPC LT(_LOWER, KC_SPC) // lower
#define KC_R_ENT LT(_RAISE, KC_ENT) // raise
#define KC_G_JA LGUI_T(KC_LANG1) // cmd or win
#define KC_G_EN LGUI_T(KC_LANG2) // cmd or win
#define KC_C_BS LCTL_T(KC_BSPC) // ctrl
#define KC_A_DEL ALT_T(KC_DEL) // alt


#define RSF_SCL  RSFT_T(KC_SCLN)
#define RCT_ESC  RCTL_T(KC_ESC)
#define RAL_ENT  RALT_T(KC_ENT)

#define KC_R_SPC LT(_RAISE, KC_SPC)
#define KC_L_F   LT(_LOWER, KC_F)
#define KC_L_N   LT(_LOWER, KC_N)
#define G_F17    LGUI(KC_F17)

#define SFT_1    RSFT(KC_1)
#define SFT_2    RSFT(KC_2)
#define SFT_3    RSFT(KC_3)
#define SFT_4    RSFT(KC_4)
#define SFT_5    RSFT(KC_5)
#define SFT_6    LSFT(KC_6)
#define SFT_7    LSFT(KC_7)
#define SFT_8    LSFT(KC_8)
#define SFT_9    LSFT(KC_9)
#define SFT_0    LSFT(KC_0)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
  //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
     KC_TAB , KC_Q   , KC_W    , KC_E   , KC_R    , KC_T   ,     KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_LBRC,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_LCTL, KC_A   , KC_S    , KC_D   , KC_L_F  , KC_G   ,     KC_H   , KC_J    , KC_K   , KC_L    , RSF_SCL, KC_QUOT,
  //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
     KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_V    , KC_B   ,     KC_L_N , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, KC_RSFT,
  //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                       KC_A_DEL, KC_G_EN, KC_R_SPC, KC_C_BS,     KC_C_BS, RCT_ESC , KC_G_JA, RAL_ENT
  //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
  ),

  //   \ ^ ! & |  @ = + * % -
  // ( # $ " ' ~  ← ↓ ↑ → ` )
  //         { [  ] }

  [_RAISE] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     _______, KC_BSLS, KC_CIRC, KC_EXLM, KC_AMPR, KC_PIPE,     _______, KC_INT1, KC_MINS, KC_EQL , KC_INT3, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     KC_LPRN, KC_HASH, KC_DLR , KC_PGUP, KC_PGDN, G_F17  ,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT , KC_DQT ,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, KC_LCBR, KC_LBRC,     KC_BSPC, KC_DEL , KC_RBRC, KC_BSLS, _______, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       _______, _______, _______, _______,     _______, _______, _______, RESET
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     _______, SFT_1  , SFT_2  , SFT_3  , SFT_4  , SFT_5  ,     SFT_6  , SFT_7  , SFT_8  , SFT_9  , SFT_0  , _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,     KC_BSPC, KC_DEL , _______, _______, _______, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       RESET  , _______, KC_4   , _______,     _______, KC_5   , _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),

  [_ADJUST] = LAYOUT( \
  //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
     KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     _______, _______, KC_COMM, KC_DOT , KC_SLSH, _______,
  //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                       RESET  , _______, KC_4   , _______,     _______, KC_5   , _______, _______
  //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
  ),
};

void matrix_init_user(void) {
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
    iota_gfx_init(!has_usb());   // turns on the display
  #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
  iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
