#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | RALT | LAlt | LGUI | /Enter  /       \Space \  |LOWER |RAISE | RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
      KC_TILD,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
       KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
CTL_T(KC_ESC),   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
OSM(MOD_LSFT),   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS),
                         KC_RALT, KC_LALT, KC_LGUI,     RSFT_T(KC_ENT), KC_SPC,   MO(_LOWER), MO(_RAISE), KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |      |      |      |      |      |                    |      |      |      |      |      |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |  !   |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   _  |   +  |   <  |   >  |   ?  |   |  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   6  |   7  |   8  |   9  |   0  |-------|    |-------|   -  |   =  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | RALT | LAlt | LGUI | /Enter  /       \Space \  |LOWER |RAISE | RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
      KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,
      KC_TAB,  KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
CTL_T(KC_ESC),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_UNDS, KC_PLUS,   KC_LT,   KC_GT, KC_QUES, KC_PIPE,
OSM(MOD_LSFT),    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_LBRC, KC_RCBR, KC_MINS,  KC_EQL, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
                         KC_RALT, KC_LALT, KC_LGUI,     RSFT_T(KC_ENT), KC_SPC,   MO(_LOWER), MO(_RAISE), KC_RALT
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | MPRV | MNXT | MPLY |      | PSCR |                    | BRID | BRIU | MUTE | VOLD | VOLU | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  F1  |  F2  |  F3  |  F4  |  F5  |-------.    ,-------| Left | Down |  Up  |Right | Home | PG_UP|
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|  F6  |  F7  |  F8  |  F9  | F10  |-------|    |-------| F11  | F12  |      |      | End  | PG_DN|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | RALT | LAlt | LGUI | /Enter  /       \Space \  |LOWER |RAISE | RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       KC_TAB, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX, KC_PSCR,                   KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSPC,
CTL_T(KC_ESC),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_PGUP,
OSM(MOD_LSFT),   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_LBRC, KC_RBRC,  KC_F11,  KC_F12, XXXXXXX,  XXXXXXX, KC_END, KC_PGDN,
                         KC_RALT, KC_LALT, KC_LGUI,     RSFT_T(KC_ENT), KC_SPC,   MO(_LOWER), MO(_RAISE), KC_RALT
)
};

