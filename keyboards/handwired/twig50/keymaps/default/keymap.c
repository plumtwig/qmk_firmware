#include "twig50.h"


#define LAL_NCV  LALT_T(KC_LANG2)
#define RAL_CNV  RALT_T(KC_LANG1)
#define LGU_NCV  LGUI_T(KC_LANG2)
#define RGU_ENT  RGUI_T(KC_ENT)

#define RSF_SCL  RSFT_T(KC_SCLN)
#define RCT_ESC  RCTL_T(KC_ESC)

#define LT1_SPC  LT(1, KC_SPC)
#define LT2_F    LT(2, KC_F)
#define LT2_N    LT(2, KC_N)
#define LT3_BS   LT(3, KC_BSPC)
#define LT3_V    LT(3, KC_V)
#define LT3_QOT  LT(3, KC_QUOT)
#define G_F17    LGUI(KC_F17)
#define G_F18    LGUI(KC_F18)
#define G_F19    LGUI(KC_F19)

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

  // Layer 0, Base layer
	KEYMAP(
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_BSPC,
    KC_LCTL,          KC_A,    KC_S,    KC_D,    LT2_F,   KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    RSF_SCL, LT3_QOT, KC_ENT,
    KC_LSFT, KC_BSLS, KC_Z,    KC_X,    KC_C,    LT3_V,   KC_B,         LT2_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_BTN1, KC_TRNS, KC_LALT,          LGU_NCV, LT1_SPC,               RCT_ESC, RGU_ENT, RAL_CNV, KC_TRNS, KC_TRNS,          KC_TRNS
  ),

  // Layer 1, Space-modifiers: Arrows and so on.
	KEYMAP(
    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_BTN2, KC_INT1, KC_MINS, KC_EQL,  KC_INT3, SFT_2,   KC_TRNS,
    KC_TRNS,          KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, G_F17,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,  SFT_7,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, G_F18,   G_F19,        KC_BSPC, KC_DEL,  KC_RBRC, KC_BSLS, KC_HOME,          KC_END,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          RESET
  ),

  // Layer 2, F,N-modifiers: Numerics and symbols.
	KEYMAP(
    KC_TRNS,          SFT_1,   SFT_2,   SFT_3,   SFT_4,   SFT_5,        SFT_6,   SFT_7,   SFT_8,   SFT_9,   KC_ENT , SFT_1,   KC_TRNS,
    KC_0,             KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SFT_2,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_6,    KC_7,    KC_8,    KC_8,    KC_9,         KC_BSPC, KC_MINS, SFT_4,   SFT_5,   KC_TRNS,          KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_4,                  KC_5,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
  ),

  // Layer 3, V,:-modifiers: Functions and mouse keys.
	KEYMAP(
    KC_F1,            KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
    KC_TRNS,          KC_MRWD, KC_MPLY, KC_MFFD, KC_VOLD, KC_VOLU,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_TRNS,          KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,               KC_WH_D, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
  ),

  // Layer 4, No plan.
	KEYMAP(
    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
  )
};

/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		DDRD |= (1 << 0); PORTD &= ~(1 << 0);
	} else {
		DDRD &= ~(1 << 0); PORTD &= ~(1 << 0);
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRD |= (1 << 2); PORTD &= ~(1 << 2);
	} else {
		DDRD &= ~(1 << 2); PORTD &= ~(1 << 2);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		DDRD |= (1 << 3); PORTD &= ~(1 << 3);
	} else {
		DDRD &= ~(1 << 3); PORTD &= ~(1 << 3);
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		DDRD |= (1 << 4); PORTD &= ~(1 << 4);
	} else {
		DDRD &= ~(1 << 4); PORTD &= ~(1 << 4);
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		DDRD |= (1 << 5); PORTD &= ~(1 << 5);
	} else {
		DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
	}

}
*/