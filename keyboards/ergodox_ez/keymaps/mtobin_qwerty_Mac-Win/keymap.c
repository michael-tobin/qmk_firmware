// Ergodox EZ keymap
// Top row not used to emulate a smaller keyboard
// QWERTY layout for MacOS and Windows
// Home row mods have not been implemented yet


#include QMK_KEYBOARD_H

enum custom_keycodes {
    RGB_SLD = EZ_SAFE_RANGE,
};

enum layers {
    _MACOS,     // MacOS, default layer
    _WINDOWS, // Windows
    _FUNC,   // Function keys
    _NUM, // NUM
};

enum tap_dance_codes {
  SFTPRN, // Left parenthesis on tap, Left shift on hold, Caps lock on double tap
  UP, // Up arrow on tap, PgUp on double tap, Home on hold
  DWN, // Down arrow on tap, PgDn on double tap, End on hold
 // ENTER, // Enter on tap, Shift+Enter on hold
};

// ---- Combo definitions ----
enum combo_events {
  EM_EMAIL,
  OS_SWTCH,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
const uint16_t PROGMEM email_combo[] = {KC_E, KC_M, COMBO_END};
const uint16_t PROGMEM os_swtch[] = {KC_Q, KC_W, COMBO_END};


combo_t key_combos[] = {
  [EM_EMAIL] = COMBO_ACTION(email_combo),
  [OS_SWTCH] = COMBO_ACTION(os_swtch)
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

// -- end of combo definitions --

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* _MACOS: (Blue LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   Esc  |   1  |   2  |   3  |   4  |   5  |Scnsht|           |      |   6  |   7  |   8  |   9  |   0  |   `    |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |   Tab  |   Q  |   W  |   E  |   R  |   T  | Del  |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
    * |--------+------+------+------+------+------|      |           |ALFRED|------+------+------+------+------+--------|
    * | Caplock|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
    * |--------+------+------+------+------+------| Enter|           |SPACE |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |  CMD |  OPT | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |CMD-OPT| CTRL |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       | PGUP |         | HOME |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       | PGDN |         | END  |        |      |
    *                               `---------------------'         `----------------------'
    */
  [_MACOS] = LAYOUT_ergodox_pretty(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   LSG(KC_2),           KC_NO,          KC_6,  KC_7,    KC_8,     KC_9,    KC_0,      KC_GRAVE,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     T_TAB,  KC_DELETE,       LGUI(KC_SPACE), KC_Y,  U_UNDLN, I_ITLCS,  O_OPEN,  P_PRINT,   KC_BSLASH,
    KC_CAPS, KC_A,    S_SAVE,  KC_D,    F_FIND,   KC_G,                                    KC_H,  KC_J,    K_HPRLNK, KC_L,    KC_SCOLON, KC_QUOTE,
    KC_LSPO, Z_UNDO,  _X_CUT,  C_COPY,  V_PASTE,  B_BOLD, ENTER,           KC_SPACE,       N_NEW, KC_M,    KC_COMMA, KC_DOT,  KC_SLASH,  KC_RSPC,
    KC_NO,   KC_LOPT, KC_LCMD, KC_LEFT, KC_RIGHT,                                                 TD(UP),  TD(DWN),  KC_LBRC, KC_RBRC,   KC_NO,
                                         LGUI(KC_LALT), KC_LCTRL,          KC_EQL, KC_MINS,
                                                         KC_PGUP,          KC_HOME,
                           LT(_NUM,KC_SPACE), KC_BSPACE, KC_PGDN,          KC_END, LT(_FUNC,KC_DELETE), ENTER
  ),


   /* _WINDOWS:  (Red LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   Esc  |   1  |   2  |   3  |   4  |   5  |Scnsht|           |      |   6  |   7  |   8  |   9  |   0  |   `    |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |   Tab  |   Q  |   W  |   E  |   R  |   T  | Del  |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
    * |--------+------+------+------+------+------|      |           |SEARCH|------+------+------+------+------+--------|
    * | Caplock|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
    * |--------+------+------+------+------+------| Enter|           |SPACE |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      | CTRL |  WIN | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |  CTRL | ALT|         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       | PGUP |         | HOME |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       | PGDN |         | END  |        |      |
    *                               `---------------------'         `----------------------'
    */
  [_WINDOWS] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSA(KC_C),        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          LGUI(KC_S), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LGUI, KC_LCTRL, KC_TRNS, KC_TRNS,                                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_LCTRL, KC_LALT,         KC_TRNS, KC_TRNS,
                                                          KC_TRNS,          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),


    /* _FUNC: Function layer (Green LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |      |      |      |      |      | RESET  |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |  F6  |  F7  |  F8  |  F9  |  F10 |------|           |------|      |      |      |      |      |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |  F11 |  F12 |      |      |      |      |           |      |      |      |      |      |      |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      |      |      |                                       |      |      |      |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |       |      |         |      |      |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               |      |       |------|         |------|        |      |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
  [_FUNC] = LAYOUT_ergodox_pretty(
    KC_NO, KC_NO,  KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,  KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
    KC_NO, KC_F6,  KC_F7,  KC_F8, KC_F9, KC_F10,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO,  KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,  KC_NO,  KC_NO, KC_NO,                                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                          KC_NO, KC_NO,         KC_NO, KC_NO,
                                                 KC_NO,         KC_NO,
                                   KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO
  ),


      /* _NUM: Number pad Layer (Yellow LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |    ~   |      |      |   (  |   )  |      |      |           |      |      |  7&  |  8*  |  9(  |  +=  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Tab/Esc|      |      |   [  |   ]  |      |------|           |------|      |  4$  |  5%  |  6^  |  -_  |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |(/Shift |      |      |   {  |   }  |      |      |           |      |      |  1!  |  2@  |  3#  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      | Left | Right|                                       |  0)  |   .  |      |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |       |      |         |      |      |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
  [_NUM] = LAYOUT_ergodox_pretty(
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO,   KC_NO,
        KC_GRAVE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO, KC_NO, KC_7,  KC_8,   KC_9,  KC_EQL,  KC_TRNS,
        KC_TRNS,  KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_NO,                        KC_NO, KC_4,  KC_5,   KC_6,  KC_MINS, KC_TRNS,
        KC_TRNS,  KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_NO,   KC_NO,        KC_NO, KC_NO, KC_1,  KC_2,   KC_3,  KC_NO,   KC_TRNS,
        KC_NO,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_0,  KC_DOT, KC_NO, KC_NO,   KC_NO,
                                
                                                        KC_NO, KC_NO,        KC_TRNS, KC_TRNS,
                                                               KC_NO,        KC_NO,
                                             KC_TRNS, KC_TRNS, KC_NO,        KC_NO, KC_TRNS, KC_TRNS
  ),
};


//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------RGB Lighting-----------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][5] = {
    // Brain freeze (Light blue)
    [_MACOS] =      {{131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},                                       {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}},

    // Cadmium red
    [_WINDOWS] =            {{0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245},         {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, 
                            {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245},         {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, 
                            {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245},         {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, 
                            {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245},         {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, 
                            {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245},                                   {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}},

    // Harlequin (Green)
    [_FUNC] =          {{74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255},          {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255},
                        {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255},          {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255},
                        {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255},          {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255},
                        {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255},          {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, 
                        {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255},                                      {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}},

    // Cadmium Yellow
    [_NUM] =            {{41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},          {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, 
                         {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},          {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, 
                         {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},          {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, 
                         {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},          {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, 
                         {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},                                      {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}},
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case _MACOS:
            set_layer_color(_MACOS);
            break;
        case _WINDOWS:
            set_layer_color(_WINDOWS);
            break;
        case _FUNC:
            set_layer_color(_FUNC);
            break;
        case _NUM:
            set_layer_color(_NUM);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------Process keypresses-----------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------
// Helper for implementing tap vs. long-press keys. Given a tap-hold
// key event, replaces the hold function with `long_press_keycode`.
static bool process_tap_or_long_press_key(
    keyrecord_t* record, uint16_t long_press_keycode) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      tap_code16(long_press_keycode);
    }
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case B_BOLD:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_B));
            } else {
                return process_tap_or_long_press_key(record, C(KC_B));
            }
        case S_SAVE:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_S));
            } else {
                return process_tap_or_long_press_key(record, C(KC_S));
            }
        case Z_UNDO:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_Z));
            } else {
                return process_tap_or_long_press_key(record, C(KC_Z));
            }
        case _X_CUT:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_X));
            } else {
                return process_tap_or_long_press_key(record, C(KC_X));
            }
        case C_COPY:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_C));
            } else {
                return process_tap_or_long_press_key(record, C(KC_C));
            }
        case V_PASTE:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_V));
            } else {
                return process_tap_or_long_press_key(record, C(KC_V));
            }
        case F_FIND:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_F));
            } else {
                return process_tap_or_long_press_key(record, C(KC_F));
            }
        case U_UNDLN:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_M));
            } else {
                return process_tap_or_long_press_key(record, C(KC_M));
            }
        case P_PRINT:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_P));
            } else {
                return process_tap_or_long_press_key(record, C(KC_P));
            }
        case N_NEW:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_N));
            } else {
                return process_tap_or_long_press_key(record, C(KC_N));
            }
        case O_OPEN:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_O));
            } else {
                return process_tap_or_long_press_key(record, C(KC_O));
            }
        case I_ITLCS:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_I));
            } else {
                return process_tap_or_long_press_key(record, C(KC_I));
            }
        case K_HPRLNK:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_K));
            } else {
                return process_tap_or_long_press_key(record, C(KC_K));
            }
        case T_TAB:
            if (biton32(layer_state) == _MACOS){
                return process_tap_or_long_press_key(record, LGUI(KC_T));
            } else {
                return process_tap_or_long_press_key(record, C(KC_T));
            }
        case ENTER:
            return process_tap_or_long_press_key(record, LSFT(KC_ENTER));
        
            }
            //   break;
    return true;

    }

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case EM_EMAIL:
            if (pressed) {
                SEND_STRING("michael.tobin@viasat.com");
            }
            break;

        case OS_SWTCH:
            if (pressed) {
                if (layer_state & (1 << _WINDOWS)) {
                    layer_off(_WINDOWS);
                    layer_on(_MACOS);
                } else {
                    layer_off(_MACOS);
                    layer_on(_WINDOWS);
                }
            }
            break;
    }
}


//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------Tap Dance Definitions--------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------
typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[4];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}



//-------------------------------------------------------------------------------
void on_sftprn(qk_tap_dance_state_t *state, void *user_data);
void sftprn_finished(qk_tap_dance_state_t *state, void *user_data);
void sftprn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_sftprn(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void sftprn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: register_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void sftprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(15);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[0].step = 0;
}



//-------------------------------------------------------------------------------
void on_up(qk_tap_dance_state_t *state, void *user_data);
void up_finished(qk_tap_dance_state_t *state, void *user_data);
void up_reset(qk_tap_dance_state_t *state, void *user_data);

void on_up(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_UP);
        tap_code16(KC_UP);
        tap_code16(KC_UP);
    }
    if(state->count > 3) {
        tap_code16(KC_UP);
    }
}

void up_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_UP); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UP); register_code16(KC_UP);
    }
}

void up_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(15);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_UP); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UP); break;
    }
    dance_state[1].step = 0;
}


//-------------------------------------------------------------------------------
void on_dwn(qk_tap_dance_state_t *state, void *user_data);
void dwn_finished(qk_tap_dance_state_t *state, void *user_data);
void dwn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dwn(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
    }
    if(state->count > 3) {
        tap_code16(KC_DOWN);
    }
}

void dwn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_DOWN); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOWN); register_code16(KC_DOWN);
    }
}

void dwn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(15);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_DOWN); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOWN); break;
    }
    dance_state[2].step = 0;
}

/*
//-------------------------------------------------------------------------------
void on_enter(qk_tap_dance_state_t *state, void *user_data);
void enter_finished(qk_tap_dance_state_t *state, void *user_data);
void enter_reset(qk_tap_dance_state_t *state, void *user_data);

void on_enter(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void enter_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: register_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void enter_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[3].step = 0;
}
*/



qk_tap_dance_action_t tap_dance_actions[] = {
        [SFTPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_sftprn, sftprn_finished, sftprn_reset),
        [UP] = ACTION_TAP_DANCE_FN_ADVANCED(on_up, up_finished, up_reset),
        [DWN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dwn, dwn_finished, dwn_reset),
       // [ENTER] = ACTION_TAP_DANCE_FN_ADVANCED(on_enter, enter_finished, enter_reset),

};
