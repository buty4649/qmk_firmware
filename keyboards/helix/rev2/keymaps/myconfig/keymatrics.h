#define JA_1    KC_1     // 1 and !
#define JA_2    KC_2     // 2 and "
#define JA_3    KC_3     // 3 and #
#define JA_4    KC_4     // 4 and $
#define JA_5    KC_5     // 5 and %
#define JA_6    KC_6     // 6 and &
#define JA_7    KC_7     // 7 and '
#define JA_8    KC_8     // 8 and (
#define JA_9    KC_9     // 9 and )
#define JA_0    KC_0     // 0

#define JA_CLN  KC_QUOT  // : and *
#define JA_SCLN KC_SCLN  // ; and +
#define JA_MINS KC_MINS  // - and =
#define JA_AT   KC_LBRC  // @ and `
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_NUHS  // ] and }
//#define JA_RBRC KC_BSLS  // ] and }
#define JA_CIRC KC_EQL   // ^ and ~
#define JA_UNDS KC_RO    // _
#define JA_EQL  KC_UNDS  // =
#define JA_TILD KC_PLUS  // ~
#define JA_GRV  KC_LCBR  // `
#define JA_LCBR KC_RCBR  // {
#define JA_RCBR KC_PIPE  // }

#define JA_COMM KC_COMM  // , and <
#define JA_DOT  KC_DOT   // . and >
#define JA_SLSH KC_SLSH  // / and ?

#define JA_JYEN KC_INT3    // ¥
#define JA_PIPE S(KC_INT3) // |

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  Esc |  1 ! |  2 " |  3 # |  4 $ |  5 % |             |  6 & |  7 ' |  8 ( |  9 ) |   0  | - =  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | @ `  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |  ; + |  : * |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  [ { |  ] { |   N  |   M  |  , < |  . > |  / ? |  _   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust|      |      | Alt  |Lower |  GUI |Enter |Space |Raise | Bksp |      |      |      | Shift|
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = KEYMAP( \
      KC_ESC,  JA_1,    JA_2,    JA_3,    JA_4,  JA_5,                      JA_6,    JA_7,  JA_8,    JA_9,    JA_0,    JA_MINS, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,                      KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,    JA_AT,   \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,                      KC_H,    KC_J,  KC_K,    KC_L,    JA_SCLN, JA_CLN,  \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    JA_LBRC, JA_RBRC, KC_N,    KC_M,  JA_COMM, JA_DOT,  JA_SLSH, JA_UNDS, \
      ADJUST,  _______, _______, KC_LALT, LOWER, KC_LGUI, KC_ENT,  KC_SPC,  KC_BSPC, RAISE, _______, _______, _______, KC_RSFT  \
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |  ^   |  ~   |  \   |  |   |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |Eisuu | Kana |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = KEYMAP( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
      _______, _______, _______, _______, _______, _______,                     JA_CIRC, JA_TILD, JA_JYEN, JA_PIPE, _______, _______, \
      _______, _______, _______, _______, _______, _______,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, KC_LANG2, KC_LANG1, _______, _______, _______, _______, _______, _______  \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |Eisuu | Kana |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = KEYMAP( \
      _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, KC_LANG2, KC_LANG1, _______, _______, _______, _______, _______, _______  \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|      |      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff| Mac  |             | Win  |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  KEYMAP( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, RESET,   RGBRST,  _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,  \
      _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SMOD,RGB_HUD, RGB_SAD, RGB_VAD  \
      )
};
