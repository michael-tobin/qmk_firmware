// Ergodox EZ keymap
// Top row not used to emulate a smaller keyboard

#include QMK_KEYBOARD_H

enum custom_keycodes {
    RGB_SLD = EZ_SAFE_RANGE,
    PRNPAIR, // Parenthesis pair ()
    BRCPAIR, // Bracket pair [], {}
    QTPAIR,  // Quote pair '', ""
    CRTPAIR, // Caret pair <>
};

enum layers {
    _MACOS,     // MacOS, default layer
    _WINDOWS, // Windows
    _FUNC,   // Function keys
    _NUM, // NUM
};

enum tap_dance_codes {
    UP,                 // Up, PgUp, Home
    DWN,                // Down, PgDn, End
    SHFT_PRN,
};

enum combo_events {
  EM_EMAIL,
  OS_SWTCH,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
const uint16_t PROGMEM email_combo[] = {KC_E, KC_M, COMBO_END};
const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSPO, COMBO_END};
const uint16_t PROGMEM os_swtch[] = {KC_Q, KC_W, COMBO_END};


combo_t key_combos[] = {
  [EM_EMAIL] = COMBO_ACTION(email_combo),
  [OS_SWTCH] = COMBO_ACTION(os_swtch)
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* MACOS:  Colemak DH Layer (Blue LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | ALFRED |   Q  |   W  |   F  |   P  |   B  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Tab/Esc|   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |  Opt | Meta | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |CMD/OPT|      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [MACOS] = LAYOUT_ergodox_pretty(
        KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,            KC_NO, KC_NO,    KC_NO,  KC_NO,    KC_NO,   KC_NO,     KC_NO,
        ALFRED, KC_Q,    KC_W,    F_FIND,  P_PRINT,  B_BOLD,  KC_NO,            KC_NO, KC_J,     KC_L,   U_UNDLN,  KC_Y,    KC_SCOLON, KC_BSLASH,
        TAB_ESC,        KC_A,    KC_R,    S_SAVE,  T_TAB,    KC_G,                             KC_M,     N_NEW,  KC_E,     I_ITLCS, O_OPEN,    QTPAIR,
        TD(SHFT_PRN),   Z_UNDO,  _X_CUT,  C_COPY,  KC_D,     V_PASTE, KC_NO,            KC_NO, K_HPRLNK, KC_H,   KC_COMMA, KC_DOT,  KC_SLASH,  KC_RSPC,
        KC_NO,          KC_LOPT, USR_MOD, KC_LEFT, KC_RIGHT,                                             TD(UP), TD(DWN),  BRCPAIR, KC_RBRC,     KC_NO,
                                                         LGUI(KC_LALT), KC_NO,           KC_EQUAL, KC_MINUS,
                                                                        KC_NO,           KC_NO,
                                         LT(_NUM, KC_SPACE), KC_BSPACE, KC_NO,           KC_NO, LT(_FUNC, KC_DELETE), ENTER
        ),
        
    /* _QWERTY: QWERTY Layer (Red LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   -    |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | ALFRED |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Tab/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |  Opt | Meta | Left | Right|                                       |  Up  | Down |   [  |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |CMD/OPT|      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space|Backsp |------|         |------|  Del   |Enter |
    *                               |      |ace    |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_QWERTY]  = LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,               KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,     KC_NO,
        KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,     T_TAB,  KC_NO,               KC_NO, KC_Y,  U_UNDLN, I_ITLCS,  O_OPEN,  P_PRINT,   KC_BSLASH,
        KC_TRNS, KC_A,    S_SAVE,  KC_D,    F_FIND,   KC_G,                               KC_H,  KC_J,    K_HPRLNK, KC_L,    KC_SCOLON, QTPAIR,
        KC_TRNS, Z_UNDO,  _X_CUT,   C_COPY, V_PASTE,  B_BOLD, KC_NO,               KC_NO, N_NEW, KC_M,    KC_COMMA, KC_DOT,  KC_SLASH,  KC_RSPC,
        KC_NO,   KC_TRNS, KC_TRNS, KC_LEFT, KC_RIGHT,                                            KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,   KC_NO, 
                                                       KC_LGUI, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                                KC_TRNS,          KC_TRNS,
                                              KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
        ),

    /* _FUNC: Function layer (Green LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | ALFRED |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |      |      |      |      |      | RESET  |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Tab/Esc|  F6  |  F7  |  F8  |  F9  |  F10 |------|           |------|      |      |      |      |      |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |(/Shift |  F11 |  F12 |      |      |      |      |           |      |      |      |      |      |      |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      | Ctrl | Meta | Left | Right|                                       |  Up  | Down |   [  |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      | RESET |      |         |      |      |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_FUNC] = LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO,        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  KC_F1,    KC_F2,  KC_F3, KC_F4, KC_F5,  KC_NO,        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
        KC_TRNS, KC_F6,    KC_F7,  KC_F8, KC_F9, KC_F10,                      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_F11,   KC_F12, KC_NO, KC_NO, KC_NO,  KC_NO,        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                                                   RESET, KC_NO,        KC_NO, KC_NO,
                                                          KC_NO,        KC_NO,
                                        KC_TRNS, KC_TRNS, KC_NO,        KC_NO, KC_TRNS, KC_TRNS
        ),

    /* _NUM: Number pad Layer (Yellow LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | ALFRED |   !  |  @   |   #  |  $   |   %  |      |           |      |   ^  |   7  |  8   |  9   |   )  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Tab/Esc|      |      |      |      |      |------|           |------|      |   4  |  5   |  6   |      |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |(/Shift |      |      |      |      |      |      |           |      |      |   1  |  2   |  3   |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      | Ctrl | Meta | Left | Right|                                       |  0   |   .  |   [  |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |   ~   |      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_NUM] = LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,        KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC, KC_NO,        KC_NO, KC_CIRC, KC_7,  KC_8,   KC_9,    KC_RPRN, KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,                        KC_NO,   KC_4,  KC_5,   KC_6,    KC_NO,   KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,        KC_NO, KC_NO,   KC_1,  KC_2,   KC_3,    KC_NO,   KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_0,  KC_DOT, KC_TRNS, KC_TRNS, KC_NO,
                                
                                                     KC_GRAVE, KC_NO,        KC_TRNS, KC_TRNS,
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
    [MACOS] =      {{131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},                                       {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}},

    // Cadmium red
    [_QWERTY] =            {{0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245},         {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, 
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
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case MACOS:
            set_layer_color(MACOS);
            break;
        case _QWERTY:
            set_layer_color(_QWERTY);
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
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case EM_EMAIL:
            if (pressed) {
                SEND_STRING("michael.tobin@viasat.com");
            }
            break;
        case OS_SWTCH:
            if (pressed) {
                if (layer_state & (1 << _QWERTY)) {
                    layer_off(_QWERTY);
                    layer_on(MACOS);
                } else {
                    layer_off(MACOS);
                    layer_on(_QWERTY);
                }
            }
            break;
    }
}

void process_platform_combo(uint16_t keycode, keyrecord_t *record) {
    uint8_t  host_os          = guess_host_os();
    uint16_t keycode_to_press = KC_NO;
    if (host_os == OS_MACOS || host_os == OS_IOS) {
        switch (keycode) {
            case USR_MOD:
                keycode_to_press = KC_LGUI;
                break;
            case ALFRED:
                keycode_to_press = MEH(KC_SPC);
                break;
        }
    } else {
        switch (keycode) {
            case USR_MOD:
                keycode_to_press = KC_LCTRL;
                break;
            case ALFRED:
                keycode_to_press = C(KC_S);
                break;
        }
    }
    if (record->event.pressed) {
        register_code16(keycode_to_press);
    } else {
        unregister_code16(keycode_to_press);
    }
}
//-------------------------------------------------------------------------------------------------------------------------
// Helper for implementing tap vs. long-press keys. Given a tap-hold
// key event, replaces the hold function with `long_press_keycode`.
static bool process_tap_or_long_press_key(
    keyrecord_t* record, uint16_t long_press_keycode) {
  if (record->tap.count == 0) {  // Key is being held.
    if (record->event.pressed) {
      tap_code16(long_press_keycode);
    }
    unregister_code16(long_press_keycode);
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t host_os = guess_host_os();

    switch (keycode) {
        case B_BOLD:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_B));
            } else {
                return process_tap_or_long_press_key(record, C(KC_B));
            }
        case S_SAVE:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_S));
            } else {
                return process_tap_or_long_press_key(record, C(KC_S));
            }
        case Z_UNDO:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_Z));
            } else {
                return process_tap_or_long_press_key(record, C(KC_Z));
            }
        case _X_CUT:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_X));
            } else {
                return process_tap_or_long_press_key(record, C(KC_X));
            }
        case C_COPY:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_C));
            } else {
                return process_tap_or_long_press_key(record, C(KC_C));
            }
        case V_PASTE:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_V));
            } else {
                return process_tap_or_long_press_key(record, C(KC_V));
            }
        case F_FIND:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_F));
            } else {
                return process_tap_or_long_press_key(record, C(KC_F));
            }
        case U_UNDLN:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_M));
            } else {
                return process_tap_or_long_press_key(record, C(KC_M));
            }
        case P_PRINT:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_P));
            } else {
                return process_tap_or_long_press_key(record, C(KC_P));
            }
        case N_NEW:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_N));
            } else {
                return process_tap_or_long_press_key(record, C(KC_N));
            }
        case O_OPEN:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_O));
            } else {
                return process_tap_or_long_press_key(record, C(KC_O));
            }
        case I_ITLCS:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_I));
            } else {
                return process_tap_or_long_press_key(record, C(KC_I));
            }
        case K_HPRLNK:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_K));
            } else {
                return process_tap_or_long_press_key(record, C(KC_K));
            }
        case T_TAB:
            if (host_os == OS_MACOS) {
                return process_tap_or_long_press_key(record, LGUI(KC_T));
            } else {
                return process_tap_or_long_press_key(record, C(KC_T));
            }
        case USR_MOD: {
            process_platform_combo(keycode, record);
            return false;
        }
        case ALFRED: {
            process_platform_combo(keycode, record);
            return false;
        }
        // Platform agnostic keys
        case TAB_ESC:
            return process_tap_or_long_press_key(record, KC_ESC);
        case ENTER:
            return process_tap_or_long_press_key(record, LSFT(KC_ENTER));

        case BRCPAIR:
            if (record->event.pressed) {
                uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                if (shifted) {
                    unregister_code(KC_LSFT);
                    unregister_code(KC_RSFT);
                    SEND_STRING("{}");
                    tap_code(KC_LEFT);
                } else {
                    SEND_STRING("[]");
                    tap_code(KC_LEFT);
                }
                return true;
            }
        case QTPAIR:
            if (record->event.pressed) {
                uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                if (shifted) {
                    unregister_code(KC_LSFT);
                    unregister_code(KC_RSFT);
                    SEND_STRING("\"\"");
                    tap_code(KC_LEFT);
                } else {
                    SEND_STRING("''");
                    tap_code(KC_LEFT);
                }
                return true;
            }
            return false;
    }
    return true;
}

//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------Tap Dance Definitions--------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------
typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

// Setting up tap dance prerequisites
enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[4];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

//-------------------------------------------------------------------------------
//-----------------------------UP/ PGUP/ HOME------------------------------------
void on_up(qk_tap_dance_state_t *state, void *user_data);
void up_finished(qk_tap_dance_state_t *state, void *user_data);
void up_reset(qk_tap_dance_state_t *state, void *user_data);

void on_up(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_UP);
        tap_code16(KC_UP);
        tap_code16(KC_UP);
    }
    if (state->count > 3) {
        tap_code16(KC_UP);
    }
}

void up_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_UP);
            break;
        case DOUBLE_TAP:
            register_code16(KC_PGUP);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_HOME);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_HOME);
            register_code16(KC_HOME);
    }
}

void up_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_UP);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_PGUP);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_HOME);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_HOME);
            break;
    }
    dance_state[0].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------DOWN/ PGDN/ END-----------------------------------
void on_dwn(qk_tap_dance_state_t *state, void *user_data);
void dwn_finished(qk_tap_dance_state_t *state, void *user_data);
void dwn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dwn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
    }
    if (state->count > 3) {
        tap_code16(KC_DOWN);
    }
}

void dwn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(KC_DOWN);
            break;
        case DOUBLE_TAP:
            register_code16(KC_PGDOWN);
            break;
        case DOUBLE_HOLD:
            register_code16(KC_END);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_END);
            register_code16(KC_END);
    }
}

void dwn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(KC_DOWN);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_PGDOWN);
            break;
        case DOUBLE_HOLD:
            unregister_code16(KC_END);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_END);
            break;
    }
    dance_state[1].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------SHFT_PRN---------------------------------------------
// Tap for (
// Hold for shift
// Double tap for CAPS
void on_shft_prn(qk_tap_dance_state_t *state, void *user_data);
void shft_prn_finished(qk_tap_dance_state_t *state, void *user_data);
void shft_prn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_shft_prn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if (state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void shft_prn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            register_code16(KC_LPRN);
            break;
        case SINGLE_HOLD:
            register_code16(KC_LSHIFT);
            break;
        case DOUBLE_TAP:
            tap_code(KC_CAPS_LOCK);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_CAPS_LOCK);
            break;
    }
}

void shft_prn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LSHIFT);
            break;
    }
    dance_state[2].step = 0;
}
//-------------------------------------------------------------------------------
qk_tap_dance_action_t tap_dance_actions[] = {
    [UP]            = ACTION_TAP_DANCE_FN_ADVANCED(on_up, up_finished, up_reset),
    [DWN]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dwn, dwn_finished, dwn_reset),
    [SHFT_PRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_shft_prn, shft_prn_finished, shft_prn_reset),

};
