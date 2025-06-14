#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_japanese.h"
#include "../../nicola.c"

#define x__x KC_TRNS
#define xxxx KC_NO

enum layers
{
    _DVO,
    _NICOLA,
    _MOVE,
    _MOUSE,
    // _SHIFT,
    _FUNC,
};

enum custom_keycodes {
    EPRM = SAFE_RANGE,
    SP_EQU
  }; 
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap: Basic Dvorak layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `     |   1  |   2  |   3  |   4  |   5  |      |           | scrn |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------| 英字 |           |かな  |------+------+------+------+------+--------|
 * |   BS   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * |  shift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | FUNC | win  | ALT  |マウス| 移動 |                                       |  ←  |  ↓  |  ↑  |  →  |  BS   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MEH  | del  |       |右クリ|  esc |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | HOME |       | PGUP |        |      |
 *                                 | shift| ctrl |------|       |------|  ctrl  | shift|
 *                                 | space|enter | END  |       | PGDW |  space | enter|
 *                                 `--------------------'       `----------------------'
 */
[_DVO] = LAYOUT_ergodox_pretty(
    // left hand
    KC_GRV     , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     xxxx,     KC_PSCR, KC_6, KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
    KC_TAB     , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,    CH_EN,       CH_JP, KC_F, KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH,
    KC_BSPC     , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,                        KC_D, KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS,
    KC_LSFT    , KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   ,   KC_LBRC,    KC_RBRC, KC_B, KC_M   , KC_W   , KC_V   , KC_Z   , KC_BSLS,
    MO(_FUNC)  , KC_LGUI, KC_LALT, CH_MOUSE,CH_MOVE,                              KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_BSPC  ,
                                                         KC_MEH, KC_DEL,   S(KC_F10), KC_ESC,
                                                                KC_HOME,     KC_PGUP,
                                   SFT_T(KC_SPC),CTL_T(KC_ENT), KC_END,     KC_PGDN, CTL_T(KC_SPC), SFT_T(KC_ENT)
  ),
 /* Keymap: Nicola layer    
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
*  |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | 左親 |      |------|       |------|        | 右親 |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [_NICOLA] = LAYOUT_ergodox_pretty(
    xxxx ,  NG_1 ,   NG_2,   NG_3,   NG_4,   NG_5,  x__x ,      x__x ,  NG_6 ,   NG_7,   NG_8,   NG_9,   NG_0,  x__x ,
    x__x ,  NG_Q ,   NG_W,   NG_E,   NG_R,   NG_T,  x__x ,      x__x ,  NG_Y ,   NG_U,   NG_I,   NG_O,   NG_P,  NG_SLSH ,
    x__x ,  NG_A,    NG_S,   NG_D,   NG_F,   NG_G,                      NG_H ,   NG_J,   NG_K,   NG_L,NG_SCLN,  x__x ,
    x__x ,  NG_Z,    NG_X,   NG_C,   NG_V,   NG_B,  x__x ,      x__x ,  NG_N,    NG_M,NG_COMM, NG_DOT,NG_SLSH,  x__x ,
    x__x ,  x__x ,  x__x ,  x__x ,  x__x ,                                      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,
                                            x__x ,  x__x ,      x__x ,  x__x ,
                                                    x__x ,      x__x ,
                                    NG_SHFTL,x__x,  x__x ,      x__x ,   x__x, NG_SHFTR
 ),
/* Keymap: MOVE layer    
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
*  |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [_MOVE] = LAYOUT_ergodox_pretty(
    xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  x__x ,      x__x ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,
    x__x ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  x__x ,      x__x ,KC_HOME,  xxxx ,  KC_UP,  xxxx ,  xxxx,  xxxx ,
    x__x ,  KC_A ,  KC_S ,  xxxx ,  xxxx ,  xxxx ,                     KC_END,KC_LEFT,KC_DOWN,KC_RIGHT, xxxx,  xxxx ,
  KC_LSFT,  KC_Z ,  KC_X ,  KC_C ,  KC_V ,  xxxx ,  x__x ,      x__x ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,
  KC_LCTL,  x__x ,  x__x ,  x__x ,  x__x ,                                      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,
                                            x__x ,  x__x ,      x__x ,  x__x ,
                                                    x__x ,      x__x ,
                                    x__x ,  x__x ,  x__x ,      x__x ,  x__x , x__x
 ),

 /* Keymap: MOUSE layer    
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
*  |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [_MOUSE] = LAYOUT_ergodox_pretty(
    xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  x__x ,      x__x ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,
    x__x ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  x__x ,      x__x ,  xxxx, KC_BTN3,KC_MS_U,  xxxx , xxxx,  xxxx ,
    x__x ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,                     xxxx,  KC_MS_L,KC_MS_D, KC_MS_R,xxxx,  xxxx ,
  KC_LSFT,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  x__x ,      x__x ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,
  KC_LCTL,  x__x ,  x__x ,  x__x ,  x__x ,                                      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,
                                            x__x ,  x__x ,      x__x ,  x__x ,
                                                    x__x ,      x__x ,
                                    x__x ,  x__x ,  x__x ,      x__x ,  KC_BTN2 , KC_BTN1
 ),
/* Keymap: Nomal Shift layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |  !   |  @   |  #   | $    | %    |      |           |      |  ^   | &    |  *    | (   |  )   |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   "  |  <   | >    |      |      |      |           |      |      |      |      |      |      |   ?    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
*  |        |      |      |      |      |      |------|           |------|      |      |      |      |      |   _    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  :   |      |      |      |      |      |           |      |      |      |      |      |      |   |    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |      |      |      |      |                                       |      |      |   {  |   }  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
//  [_SHIFT] = LAYOUT_ergodox_pretty(
//     // left hand
//     KC_TILD     , KC_EXLM, KC_AT     , KC_HASH, KC_DLR , KC_PERC, x__x,     x__x   , KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS ,
//     S(KC_TAB)   , KC_DQUO, KC_LABK   , KC_RABK, S(KC_P), S(KC_Y), x__x,     x__x,    S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L), KC_QUES,
//     x__x        , S(KC_A), S(KC_O)   , S(KC_E), S(KC_U), S(KC_I),                    S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S), KC_UNDS,
//     x__x        , KC_COLN, S(KC_Q)   , S(KC_J), S(KC_K), S(KC_X), x__x,   S(KC_ENT), S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z), KC_PIPE,
//     S(KC_LCTL)  , x__x   , S(KC_LALT), S(KC_LEFT),S(KC_RIGHT),                             S(KC_DOWN), x__x   , KC_LCBR, KC_RCBR,  S(KC_UP),
//                                                      x__x   , S(KC_HOME),     x__x   , x__x   ,
//                                                               S(KC_END),   S(KC_PGUP),
//                                             x__x   , x__x   , x__x   ,     S(KC_PGDN), x__x, x__x
//   ),
 /* Keymap: Function layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  | F2   | F3   |  F4  |  F5  | BOOT |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  F13 |  F14 |  F15 |  F16 |  F17 |  F18   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
*  |        | ALL  | SAVE |      |      |      |------|           |------|  F19 |  F20 |  F21 |  F22 |  F23 |  F24   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | UNDO |  CUT | COPY | PAST |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
 [_FUNC] = LAYOUT_ergodox_pretty(
    xxxx,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,QK_BOOT ,     KC_F12,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,  KC_F11,
    xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  x__x ,      x__x ,  KC_F13, KC_F14, KC_F15,KC_F16, KC_F17,  KC_F18,
    xxxx ,C(KC_A),C(KC_S),  xxxx ,C(KC_F),  xxxx ,                      KC_F19, KC_F20, KC_F21,KC_F22, KC_F23,  KC_F24,
    KC_LSFT ,C(KC_Z),C(KC_X),C(KC_C),C(KC_V), xxxx ,  x__x ,      x__x ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,  xxxx ,
    xxxx ,  xxxx ,  x__x ,  x__x ,  x__x ,                                         x__x ,  x__x ,  x__x ,  x__x ,  x__x ,
                                               x__x ,x__x,      x__x ,  x__x,
                                                     x__x,      x__x ,
                                    x__x ,  x__x,    x__x,      x__x , x__x, x__x
 ),



//  /* Keymap: base layer
//  *
//  * ,--------------------------------------------------.           ,--------------------------------------------------.
//  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
// *  |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
//  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
//  *   |      |      |      |      |      |                                       |      |      |      |      |      |
//  *   `----------------------------------'                                       `----------------------------------'
//  *                                        ,-------------.       ,-------------.
//  *                                        |      |      |       |      |        |
//  *                                 ,------|------|------|       |------+--------+------.
//  *                                 |      |      |      |       |      |        |      |
//  *                                 |      |      |------|       |------|        |      |
//  *                                 |      |      |      |       |      |        |      |
//  *                                 `--------------------'       `----------------------'
//  */
//  [SAMPLE] = LAYOUT_ergodox_pretty(
//      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,
//      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,
//      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,                      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,
//      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,  x__x ,
//      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,                                      x__x ,  x__x ,  x__x ,  x__x ,  x__x ,
//                                              x__x ,  x__x ,      x__x ,  x__x ,
//                                                      x__x ,      x__x ,
//                                      x__x ,  x__x ,  x__x ,      x__x ,  x__x , x__x


};
// clang-format on

void matrix_init_user(void)
{
    // NICOLA親指シフト
    set_nicola(_NICOLA);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed)
    {
        if (keycode > CH_LAYER && keycode < CH_LAYER_END)
        {
            layer_off(_MOVE);
            layer_off(_MOUSE);
            switch (keycode)
            {
            case CH_JP:
                nicola_on();
                return false;
            case CH_EN:
                nicola_off();
                return false;
            case CH_MOVE:
                layer_on(_MOVE);
                return false;
            case CH_MOUSE:
                layer_on(_MOUSE);
                return false;
            }
        }
    }
    
    // NICOLA親指シフトaoeaoeu
    bool a = true;
    if (nicola_state())
    {
        // nicola_mode(keycode, record);
        a = process_nicola(keycode, record);
    }
    if (a == false)
        return false;
    // NICOLA親指シフト
    return true;
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state)
{
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer)
    {
    case 0:
        break;
    case 1:
        ergodox_right_led_1_on();
        break;
    case 2:
        ergodox_right_led_2_on();
        break;
    case 3:
        ergodox_right_led_3_on();
        break;
    case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
    case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
    case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
    case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
    default:
        break;
    }

    return state;
};
