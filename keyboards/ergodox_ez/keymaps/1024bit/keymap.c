#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_jp.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

//Alias
#define C(kc) LCTL(kc)
#define A(kc) LALT(kc)
#define SC(kc) (S(C(kc)))
#define SA(kc) (S(A(kc)))
#define CC_EN LT(SYMB,KC_MHEN)
#define CC_JA LT(SYMB,KC_HENK)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: base layer for windows
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | HAN/ZEN|   1  |   2  |   3  |   4  |   5  |      |           |      |  6   |   7  |   8  |   9  |   0  |  -  =  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  @  `  |
 * |--------+------+------+------+------+------| Left |           |  Up  |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  :  *  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  | Right|           | Down |   N  |   M  |  , < |  . > |  / ? |  \  _  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Win |      | Alt  |  +L1  |                                      |  +L1 |  Alt |      |      | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | HOME |      |       |      |  END |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  Up  |       | Left |      |      |
 *                                 |Space |Delete|------|       |------| Bkspc| Enter|
 *                                 |      |      | Down |       | Right|      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        JP_ZHTG,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,      _______,
         KC_TAB,      KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,      KC_LEFT,
        _______,      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,      KC_RGHT,
        KC_LCTL,   KC_LGUI,    _______,    KC_LALT,    MO(SYMB),
                                                                     KC_HOME,    _______,
                                                                                   KC_UP,
                                                           KC_SPC,   KC_DEL,     KC_DOWN,
        // right hand
        _______,     KC_6,       KC_7,       KC_8,        KC_9,       KC_0,       KC_MINS,
          KC_UP,     KC_Y,       KC_U,       KC_I,        KC_O,       KC_P,       KC_LBRC,
                     KC_H,       KC_J,       KC_K,        KC_L,       KC_SCLN,    KC_QUOT,
        KC_DOWN,     KC_N,       KC_M,       KC_COMM,     KC_DOT,     KC_SLSH,    KC_RO,
                              MO(SYMB),      KC_RALT,     _______,     _______,    KC_RCTL,
        _______,      KC_END,
        KC_LEFT,
        KC_RGHT,     KC_BSPC,    KC_ENTER
    ),
/* Keymap 1: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  ^ ~ |  ¥  |  | 
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | BtnL |  MsU | BtnR |      |      |           |      |      |      |  Up  |      |      |  [  {  |
 * |--------+------+------+------+------+------| WhU  |           | BtnL |------+------+------+------+------+--------|
 * |        |      |  MsL |  MsD |  MsR |      |------|           |------|      | Left | Down | Right|      |  ]  }  |
 * |--------+------+------+------+------+------| WhD  |           | BtnR |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |Ct+A+D|                                       |Ct+A+D|      |  F10 |  F11 |  F12 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |PrtScr| RESET|       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | BtnL |      |------|       |------|      | BtnR |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
        KC_ESC,       KC_F1,      KC_F2,      KC_F3,     KC_F4,      KC_F5,   _______,
       _______,     _______,    KC_BTN1,    KC_MS_U,   KC_BTN2,    _______,   KC_WH_U,
       _______,     _______,    KC_MS_L,    KC_MS_D,   KC_MS_R,    _______,
       _______,     _______,    _______,    _______,   _______,    _______,   KC_WH_D,
       _______,     _______,    _______,    _______,   _______,
                                                                   KC_PSCR,     RESET,
                                                                              _______,
                                                       KC_BTN1,    _______,   LALT(LCTL(KC_DEL)),
       // right hand
       _______,      KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_EQL,   KC_JYEN,
       KC_BTN1,    _______,    _______,      KC_UP,    _______,    _______,   KC_RBRC,
                   _______,    KC_LEFT,    KC_DOWN,   KC_RIGHT,    _______,   KC_BSLS,
       KC_BTN2,    _______,    _______,    _______,    _______,    _______,   _______,
                    RALT(RCTL(KC_DEL)),    _______,     KC_F10,     KC_F11,    KC_F12,
       _______,    _______,
       _______,
       RALT(RCTL(KC_DEL)),    _______,      KC_BTN2
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
