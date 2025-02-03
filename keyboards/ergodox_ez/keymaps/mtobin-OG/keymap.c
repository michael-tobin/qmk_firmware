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
    _MAC_CM,     // MacOS Workman, default layer
    _WIN_CM,     // Windows Workman
    _MAC_QWERTY, // MacOS QWERTY
    _WIN_QWERTY, // Windows QWERTY
    _FUNC,       // Function keys
    _NUMPAD,     // Numpad
};

enum tap_dance_codes {
    UP,   // Up, PgUp, Home
    DWN,  // Down, PgDn, End
    LYR_TO_WINCM_FUNC, // Layer tap goes to _WIN_CM, hold goes to _FUNC
    LYR_TO_MACCM_FUNC, // Layer tap goes to _MAC_CM, hold goes to _FUNC
    LYR_TO_WINCM_NUM,  // Layer tap goes to _WIN_CM, hold goes to _NUMPAD
    LYR_TO_MACCM_NUM,  // Layer tap goes to _MAC_CM, hold goes to _NUMPAD
    LYR_TO_WINQT_FUNC, // Layer tap goes to _WIN_QWERTY, hold goes to _FUNC
    LYR_TO_MACQT_FUNC, // Layer tap goes to _MAC_QWERTY, hold goes to _FUNC
    LYR_TO_WINQT_NUM,  // Layer tap goes to _WIN_QWERTY, hold goes to _NUMPAD
    LYR_TO_MACQT_NUM,  // Layer tap goes to _MAC_QWERTY, hold goes to _NUMPAD
    SHFT_PRN,     // Shift + Parenthesis
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* _MAC_CM: MacOS Colemak DH Layer (Blue LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab    |   Q  |   W  |   F  |   P  |   B  | DEL  |           |ALFRED|   J  |   L  |   U  |   Y  |   ;  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Caps   |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  |   '    |
    * |--------+------+------+------+------+------| ENTER|           |Space |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | WINCM|  Opt |  CMD | Left | Right|                                       |  Up  | Down |   [  |   ]  | MACQT|
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |CMD/OPT|      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_MAC_CM] = LAYOUT_ergodox_pretty(
        KC_NO,                KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,                KC_NO,          KC_NO,    KC_NO,  KC_NO,    KC_NO,   KC_NO,     KC_NO,
        TAB_ESC,               KC_Q,    KC_W,    F_FIND,  P_PRINT,  B_BOLD,  KC_DELETE,            LGUI(KC_SPACE), KC_J,     KC_L,   U_UNDLN,  KC_Y,    KC_SCOLON, KC_BSLASH,
        KC_CAPSLOCK,          KC_A,    KC_R,    S_SAVE,  T_TAB,    KC_G,                                          KC_M,     N_NEW,  KC_E,     I_ITLCS, O_OPEN,    QTPAIR,
        TD(SHFT_PRN),         Z_UNDO,  _X_CUT,  C_COPY,  KC_D,     V_PASTE, ENTER,                KC_SPACE,       K_HPRLNK, KC_H,   KC_COMMA, KC_DOT,  KC_SLASH,  KC_RSPC,
        TD(LYR_TO_WINCM_NUM), KC_LALT, KC_LGUI, KC_LEFT, KC_RIGHT,                                                          TD(UP), TD(DWN),  BRCPAIR, PRNPAIR,   TD(LYR_TO_MACQT_FUNC),
                                                                    LGUI(KC_LALT), KC_NO,           KC_EQUAL, KC_MINUS,
                                                                                   KC_NO,           KC_NO,
                                                              KC_SPACE, KC_BSPACE, KC_NO,           KC_NO, KC_DELETE, ENTER
        ),
        
    /* _WIN_CM: Windows Colemak DH Layer (Red LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab    |   Q  |   W  |   F  |   P  |   B  | DEL  |           |Win+S |   J  |   L  |   U  |   Y  |   ;  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Caps   |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  |   '    |
    * |--------+------+------+------+------+------| ENTER|           |Space |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | MACCM|  Win | Ctrl | Left | Right|                                       |  Up  | Down |   [  |   ]  | WINQT|
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |  Win  |      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_WIN_CM] = LAYOUT_ergodox_pretty(
        KC_NO,                KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS,              KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        LGUI(KC_S), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,              KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,              KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TD(LYR_TO_MACCM_NUM), KC_LGUI, KC_LCTRL, KC_TRNS, KC_TRNS,                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TD(LYR_TO_WINQT_FUNC),
                                                                     KC_LGUI, KC_NO,        KC_TRNS, KC_TRNS,  
                                                                              KC_NO,        KC_NO,
                                                            KC_TRNS, KC_TRNS, KC_NO,        KC_NO, KC_TRNS, KC_TRNS
        ),
    /* _MAC_QWERTY: MacOS QWERTY Layer (Pink LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * | ESC    |      |      |      |      |      |      |           |      |      |      |      |      |      |   -    |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab    |   Q  |   W  |   E  |   R  |   T  | DEL  |           |ALFRED|   Y  |   U  |   I  |   O  |   P  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
    * |--------+------+------+------+------+------| ENTER|           |Space |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | WINQT|  Opt |  CMD | Left | Right|                                       |  Up  | Down |   [  |   ]  | MACCM|
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |CMD/OPT|      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space|Backsp |------|         |------|  Del   |Enter |
    *                               |      |ace    |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_MAC_QWERTY]  = LAYOUT_ergodox_pretty(
        KC_NO,                KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,               KC_NO,          KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,     KC_NO,
        KC_TRNS,              KC_Q,    KC_W,    KC_E,    KC_R,     T_TAB,  KC_DELETE,           LGUI(KC_SPACE), KC_Y,  U_UNDLN, I_ITLCS,  O_OPEN,  P_PRINT,   KC_BSLASH,
        KC_TRNS,              KC_A,    S_SAVE,  KC_D,    F_FIND,   KC_G,                                        KC_H,  KC_J,    K_HPRLNK, KC_L,    KC_SCOLON, QTPAIR,
        KC_TRNS,              Z_UNDO,  _X_CUT,   C_COPY,  V_PASTE,  B_BOLD, ENTER,               KC_TRNS,        N_NEW, KC_M,    KC_COMMA, KC_DOT,  KC_SLASH,  KC_RSPC,
        TD(LYR_TO_WINQT_NUM), KC_LALT, KC_LGUI, KC_LEFT, KC_RIGHT,                                                     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,   TD(LYR_TO_MACCM_FUNC), 
                                                                     KC_LGUI, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                                              KC_TRNS,          KC_TRNS,
                                                            KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
        ),

    /* _WIN_QWERTY: Windows QWERTY Layer (??? LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * | ESC    |      |      |      |      |      |      |           |      |      |      |      |      |      |   -    |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab    |   Q  |   W  |   E  |   R  |   T  | DEL  |           |Win+S |   Y  |   U  |   I  |   O  |   P  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
    * |--------+------+------+------+------+------| ENTER|           |Space |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | MACQT|  Win | Ctrl | Left | Right|                                       |  Up  | Down |   [  |   ]  | WINCM|
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |  Win  |      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space|Backsp |------|         |------|  Del   |Enter |
    *                               |      |ace    |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_WIN_QWERTY] = LAYOUT_ergodox_pretty(
        KC_NO,                KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,             KC_NO,      KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,     KC_NO,
        KC_TRNS,              KC_Q,    KC_W,    KC_E,    KC_R,     T_TAB,  KC_DELETE,         LGUI(KC_S), KC_Y,  U_UNDLN, I_ITLCS,  O_OPEN,  P_PRINT,   KC_BSLASH,
        KC_TRNS,              KC_A,    S_SAVE,  KC_D,    F_FIND,   KC_G,                                  KC_H,  KC_J,    K_HPRLNK, KC_L,    KC_SCOLON, QTPAIR,
        KC_TRNS,              Z_UNDO,  _X_CUT,   C_COPY,  V_PASTE,  B_BOLD, ENTER,             KC_TRNS,    N_NEW, KC_M,    KC_COMMA, KC_DOT,  KC_SLASH,  KC_RSPC,
        TD(LYR_TO_MACQT_NUM), KC_LALT, KC_LGUI, KC_LEFT, KC_RIGHT,                                               KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,   TD(LYR_TO_WINCM_FUNC), 
                                                                   KC_LGUI, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                                            KC_TRNS,          KC_TRNS,
                                                          KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
        ),

    /* _FUNC: Function layer (Green LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | ESC    |  F1  |  F2  |  F3  |  F4  |  F5  | DEL  |           |      |      |      |      |      |      | RESET  |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Caps   |  F6  |  F7  |  F8  |  F9  |  F10 |------|           |------|      |      |      |      |      |        |
    * |--------+------+------+------+------+------| ENTER|           |Space |------+------+------+------+------+--------|
    * |(/Shift |  F11 |  F12 |      |      |      |      |           |      |      |      |      |      |      |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |  Ctrl | Cmd | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
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
        KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  KC_F1,    KC_F2,  KC_F3, KC_F4, KC_F5, KC_TRNS,        KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
        KC_TRNS, KC_F6,    KC_F7,  KC_F8, KC_F9, KC_F10,                         KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_F11,   KC_F12, KC_NO, KC_NO, KC_NO, KC_TRNS,        KC_TRNS, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_LCTRL, KC_LGUI,  KC_TRNS, KC_TRNS,                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                                                   RESET, KC_NO,        KC_NO, KC_NO,
                                                          KC_NO,        KC_NO,
                                        KC_TRNS, KC_TRNS, KC_NO,        KC_NO, KC_TRNS, KC_TRNS
        ),

    /* _NUMPAD: Number pad Layer (Yellow LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | ESC    |   !  |  @   |   #  |  $   |   %  | DEL  |           |      |   ^  |   7  |  8   |  9   |   )  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Caps   |      |      |      |      |      |------|           |------|      |   4  |  5   |  6   |      |   '    |
    * |--------+------+------+------+------+------| ENTER|           |Space |------+------+------+------+------+--------|
    * |(/Shift |      |      |      |      |      |      |           |      |      |   1  |  2   |  3   |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |  Ctrl | Win | Left | Right|                                       |  0   |      |   [  |   ]  |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |   ~   |      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_NUMPAD] = LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,          KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC, KC_TRNS,        KC_NO,   KC_CIRC, KC_7,  KC_8,    KC_9,    KC_RPRN, KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,                            KC_NO,   KC_4,  KC_5,    KC_6,    KC_NO,   KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_TRNS,        KC_TRNS, KC_NO,   KC_1,  KC_2,    KC_3,    KC_NO,   KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                           KC_0,  KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
                                
                                                     KC_GRAVE, KC_NO,        KC_TRNS, KC_TRNS,
                                                               KC_NO,        KC_NO,
                                             KC_TRNS, KC_TRNS, KC_NO,        KC_NO, KC_TRNS, KC_TRNS
        ),
};

//-------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------RGB Lighting Definitions-----------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][5] = {
    // Brain freeze (Light blue)
    [_MAC_CM] =  {{131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},                                       {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}},

    // Cadmium red
    [_WIN_CM] =            {{0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245},         {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, 
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
    [_NUMPAD] =         {{41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},          {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, 
                         {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},          {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, 
                         {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},          {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, 
                         {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},          {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, 
                         {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255},                                      {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}},

    // Electric Indigo
    [_MAC_QWERTY] = {{188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255},         {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, 
                     {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255},         {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, 
                     {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255},         {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, 
                     {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255},         {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, 
                     {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255},                                       {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}},

    // Bright Magenta
    [_WIN_QWERTY] = {{219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255},         {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, 
                     {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255},         {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, 
                     {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255},         {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, 
                     {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255},         {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, 
                     {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255},                                       {219,255,255}, {219,255,255}, {219,255,255}, {219,255,255}},
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
        case _MAC_CM:
            set_layer_color(_MAC_CM);
            break;
        case _WIN_CM:
            set_layer_color(_WIN_CM);
            break;
        case _MAC_QWERTY:
            set_layer_color(_MAC_QWERTY);
            break;
        case _WIN_QWERTY:
            set_layer_color(_WIN_QWERTY);
            break;
        case _FUNC:
            set_layer_color(_FUNC);
            break;
        case _NUMPAD:
            set_layer_color(_NUMPAD);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
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
    return false;  // Skip default handling.
  }
  return true;  // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case B_BOLD:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_B));
            } else {
                return process_tap_or_long_press_key(record, C(KC_B));
            }
        case S_SAVE:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_S));
            } else {
                return process_tap_or_long_press_key(record, C(KC_S));
            }
        case Z_UNDO:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_Z));
            } else {
                return process_tap_or_long_press_key(record, C(KC_Z));
            }
        case _X_CUT:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_X));
            } else {
                return process_tap_or_long_press_key(record, C(KC_X));
            }
        case C_COPY:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_C));
            } else {
                return process_tap_or_long_press_key(record, C(KC_C));
            }
        case V_PASTE:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_V));
            } else {
                return process_tap_or_long_press_key(record, C(KC_V));
            }
        case F_FIND:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_F));
            } else {
                return process_tap_or_long_press_key(record, C(KC_F));
            }
        case U_UNDLN:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_M));
            } else {
                return process_tap_or_long_press_key(record, C(KC_M));
            }
        case P_PRINT:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_P));
            } else {
                return process_tap_or_long_press_key(record, C(KC_P));
            }
        case N_NEW:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_N));
            } else {
                return process_tap_or_long_press_key(record, C(KC_N));
            }
        case O_OPEN:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_O));
            } else {
                return process_tap_or_long_press_key(record, C(KC_O));
            }
        case I_ITLCS:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_I));
            } else {
                return process_tap_or_long_press_key(record, C(KC_I));
            }
        case K_HPRLNK:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_K));
            } else {
                return process_tap_or_long_press_key(record, C(KC_K));
            }
        case T_TAB:
            if ((biton32(layer_state) == _MAC_CM) || (biton32(layer_state) == _MAC_QWERTY)) {
                return process_tap_or_long_press_key(record, LGUI(KC_T));
            } else {
                return process_tap_or_long_press_key(record, C(KC_T));
            }
        case TAB_ESC:
                return process_tap_or_long_press_key(record, KC_ESC);
        case ENTER:
            return process_tap_or_long_press_key(record, LSFT(KC_ENTER));
        case PRNPAIR:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
         //   break;

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

static tap dance_state[11];

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
            tap_code16(KC_UP);
            register_code16(KC_UP);
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
            unregister_code16(KC_UP);
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
            tap_code16(KC_DOWN);
            register_code16(KC_DOWN);
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
            unregister_code16(KC_DOWN);
            break;
    }
    dance_state[1].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_WIN_CM + _FUNC----------------------------
// Tap to go to _WIN_CM, hold to go to _FUNC
void lyr_to_wincm_func_finished(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_wincm_func_reset(qk_tap_dance_state_t *state, void *user_data);

void lyr_to_wincm_func_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            layer_move(_WIN_CM);
            break;
        case SINGLE_HOLD:
            layer_on(_FUNC);
            break;
            //    case DOUBLE_TAP: layer_move(_WIN_CM); break;
            //    case DOUBLE_SINGLE_TAP: layer_move(_WIN_CM); break;
    }
}
void lyr_to_wincm_func_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_HOLD:
            layer_off(_FUNC);
            break;
    }
    dance_state[2].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_MAC_CM + _FUNC----------------------------
// Tap to go to _MAC_CM, hold to go to _FUNC
void lyr_to_maccm_func_finished(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_maccm_func_reset(qk_tap_dance_state_t *state, void *user_data);

void lyr_to_maccm_func_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            layer_move(_MAC_CM);
            break;
        case SINGLE_HOLD:
            layer_on(_FUNC);
            break;
            //    case DOUBLE_TAP: layer_move(_MAC_CM); break;
            //    case DOUBLE_SINGLE_TAP: layer_move(_MAC_CM); break;
    }
}
void lyr_to_maccm_func_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_HOLD:
            layer_off(_FUNC);
            break;
    }
    dance_state[3].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_WIN_CM + _NUMPAD--------------------------
// Tap to go to _WIN_CM, hold to go to _NUMPAD
void lyr_to_wincm_num_finished(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_wincm_num_reset(qk_tap_dance_state_t *state, void *user_data);

void lyr_to_wincm_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            layer_move(_WIN_CM);
            break;
        case SINGLE_HOLD:
            layer_on(_NUMPAD);
            break;
            //  case DOUBLE_TAP: layer_move(_WIN_CM); break;
            //  case DOUBLE_SINGLE_TAP: layer_move(_WIN_CM); break;
    }
}
void lyr_to_wincm_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_HOLD:
            layer_off(_NUMPAD);
            break;
    }
    dance_state[4].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_MAC_CM + _NUMPAD--------------------------
// Tap to go to _MAC_CM, hold to go to _NUMPAD
void lyr_to_maccm_num_finished(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_maccm_num_reset(qk_tap_dance_state_t *state, void *user_data);

void lyr_to_maccm_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP:
            layer_move(_MAC_CM);
            break;
        case SINGLE_HOLD:
            layer_on(_NUMPAD);
            break;
            //    case DOUBLE_TAP: layer_move(_MAC_CM); break;
            //    case DOUBLE_SINGLE_TAP: layer_move(_MAC_CM); break;
    }
}
void lyr_to_maccm_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_HOLD:
            layer_off(_NUMPAD);
            break;
    }
    dance_state[5].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_WIN_QWERTY + _FUNC------------------------
// Tap to go to _WIN_QWERTY, hold to go to _FUNC
void lyr_to_winqt_func_finished(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_winqt_func_reset(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_winqt_func_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP:
            layer_move(_WIN_QWERTY);
            break;
        case SINGLE_HOLD:
            layer_on(_FUNC);
            break;
            //    case DOUBLE_TAP: layer_move(_WIN_QWERTY); break;
            //    case DOUBLE_SINGLE_TAP: layer_move(_WIN_QWERTY); break;
    }
}
void lyr_to_winqt_func_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_HOLD:
            layer_off(_FUNC);
            break;
    }
    dance_state[6].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_MAC_QWERTY + _FUNC------------------------
// Tap to go to _MAC_QWERTY, hold to go to _FUNC
void lyr_to_macqt_func_finished(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_macqt_func_reset(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_macqt_func_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            layer_move(_MAC_QWERTY);
            break;
        case SINGLE_HOLD:
            layer_on(_FUNC);
            break;
            //    case DOUBLE_TAP: layer_move(_MAC_QWERTY); break;
            //    case DOUBLE_SINGLE_TAP: layer_move(_MAC_QWERTY); break;
    }
}
void lyr_to_macqt_func_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_HOLD:
            layer_off(_FUNC);
            break;
    }
    dance_state[7].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_WIN_QWERTY + _NUMPAD--------------------------
// Tap to go to _WIN_QWERTY, hold to go to _NUMPAD
void lyr_to_winqt_num_finished(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_winqt_num_reset(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_winqt_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            layer_move(_WIN_QWERTY);
            break;
        case SINGLE_HOLD:
            layer_on(_NUMPAD);
            break;
            //  case DOUBLE_TAP: layer_move(_WIN_QWERTY); break;
            //  case DOUBLE_SINGLE_TAP: layer_move(_WIN_QWERTY); break;
    }
}
void lyr_to_winqt_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_HOLD:
            layer_off(_NUMPAD);
            break;
    }
    dance_state[8].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_MAC_QWERTY + _NUMPAD--------------------------
// Tap to go to _MAC_QWERTY, hold to go to _NUMPAD
void lyr_to_macqt_num_finished(qk_tap_dance_state_t *state, void *user_data);
void lyr_to_macqt_num_reset(qk_tap_dance_state_t *state, void *user_data);

void lyr_to_macqt_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP:
            layer_move(_MAC_QWERTY);
            break;
        case SINGLE_HOLD:
            layer_on(_NUMPAD);
            break;
            //    case DOUBLE_TAP: layer_move(_MAC_QWERTY); break;
            //    case DOUBLE_SINGLE_TAP: layer_move(_MAC_QWERTY); break;
    }
}
void lyr_to_macqt_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_HOLD:
            layer_off(_NUMPAD);
            break;
    }
    dance_state[9].step = 0;
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
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            SEND_STRING("()");
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
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            tap_code(KC_LEFT);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LSHIFT);
            break;
    }
    dance_state[10].step = 0;
}
//-------------------------------------------------------------------------------
qk_tap_dance_action_t tap_dance_actions[] = {
    [UP]            = ACTION_TAP_DANCE_FN_ADVANCED(on_up, up_finished, up_reset),
    [DWN]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dwn, dwn_finished, dwn_reset),
    [LYR_TO_WINCM_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lyr_to_wincm_func_finished, lyr_to_wincm_func_reset),
    [LYR_TO_MACCM_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lyr_to_maccm_func_finished, lyr_to_maccm_func_reset),
    [LYR_TO_WINCM_NUM]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lyr_to_wincm_num_finished, lyr_to_wincm_num_reset),
    [LYR_TO_MACCM_NUM]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lyr_to_maccm_num_finished, lyr_to_maccm_num_reset),
    [LYR_TO_WINQT_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lyr_to_winqt_func_finished, lyr_to_winqt_func_reset),
    [LYR_TO_MACQT_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lyr_to_macqt_func_finished, lyr_to_macqt_func_reset),
    [LYR_TO_WINQT_NUM]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lyr_to_winqt_num_finished, lyr_to_winqt_num_reset),
    [LYR_TO_MACQT_NUM]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lyr_to_macqt_num_finished, lyr_to_macqt_num_reset),
    [SHFT_PRN]       = ACTION_TAP_DANCE_FN_ADVANCED(on_shft_prn, shft_prn_finished, shft_prn_reset),
};
