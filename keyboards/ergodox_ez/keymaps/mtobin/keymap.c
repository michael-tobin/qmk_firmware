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
    _MAC_WM,
    _WIN_WM,
    _MAC_QWERTY,
    _WIN_QWERTY,
    _FUNC,
    _NUMPAD,
};

enum tap_dance_codes {
    DANCE_MACB,   // Cmd + B
    DANCE_MACS,   // Cmd + S
    DANCE_MACZ,   // Cmd + Z
    DANCE_MACX,   // Cmd + X
    DANCE_MACC,   // Cmd + C
    DANCE_MACV,   // Cmd + V
    DANCE_MACF,   // Cmd + F
    DANCE_MACU,   // Cmd + U
    DANCE_MACP,   // Cmd + P
    DANCE_MACN,   // Cmd + N
    DANCE_MACO,   // Cmd + O
    DANCE_MACI,   // Cmd + I
    DANCE_MACK,   // Cmd + K
    DANCE_ENTR,   // Enter, Shift + Enter
    DANCE_UP,     // Up, PgUp, Home
    DANCE_DWN,    // Down, PgDn, End
    DANCE_WINB,   // Ctrl + B
    DANCE_WINS,   // Ctrl + S
    DANCE_WINZ,   // Ctrl + Z
    DANCE_WINX,   // Ctrl + X
    DANCE_WINC,   // Ctrl + C
    DANCE_WINV,   // Ctrl + V
    DANCE_WINF,   // Ctrl + F
    DANCE_WINU,   // Ctrl + U
    DANCE_WINP,   // Ctrl + P
    DANCE_WINN,   // Ctrl + N
    DANCE_WINO,   // Ctrl + O
    DANCE_WINI,   // Ctrl + I
    DANCE_WINK,   // Ctrl + K
    
    DANCE_TO_WINWM_FUNC, // Layer tap goes to _WIN_WM, hold goes to _FUNC
    DANCE_TO_MACWM_FUNC, // Layer tap goes to _MAC_WM, hold goes to _FUNC
    DANCE_TO_WINWM_NUM, // Layer tap goes to _WIN_WM, hold goes to _NUMPAD
    DANCE_TO_MACWM_NUM, // Layer tap goes to _MAC_WM, hold goes to _NUMPAD
    
    DANCE_TO_WINQT_FUNC, // Layer tap goes to _WIN_QWERTY, hold goes to _FUNC
    DANCE_TO_MACQT_FUNC, // Layer tap goes to _MAC_QWERTY, hold goes to _FUNC
    DANCE_TO_WINQT_NUM, // Layer tap goes to _WIN_QWERTY, hold goes to _NUMPAD
    DANCE_TO_MACQT_NUM, // Layer tap goes to _MAC_QWERTY, hold goes to _NUMPAD
    DANCE_SFT_PRN,       // Shift + Parenthesis
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _MAC_WM: MacOS Workman Layer (Blue LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab    |   Q  |   D  |   R  |   W  |   B  | DEL  |           |ALFRED|   J  |   F  |   U  |   P  |   ;  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Caps   |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   '    |
    * |--------+------+------+------+------+------| ENTER|           |Space |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | WINWM|  Opt |  CMD | Left | Right|                                       |  Up  | Down |   [  |   ]  | MACQT|
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |CMD/OPT|      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_MAC_WM] = LAYOUT_ergodox_pretty(
        KC_NO,                  KC_NO,          KC_NO,          KC_NO,   KC_NO,          KC_NO,          KC_NO,                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_TAB,                 KC_Q,           KC_D,           KC_R,    KC_W,           TD(DANCE_MACB), KC_DELETE,             LGUI(KC_SPACE), KC_J,           TD(DANCE_MACF), TD(DANCE_MACU), TD(DANCE_MACP), KC_SCOLON,      KC_BSLASH,
        KC_CAPSLOCK,            KC_A,           TD(DANCE_MACS), KC_H,    KC_T,           KC_G,                                                  KC_Y,           TD(DANCE_MACN), KC_E,           TD(DANCE_MACO), TD(DANCE_MACI), QTPAIR,
        TD(DANCE_SFT_PRN),                TD(DANCE_MACZ), TD(DANCE_MACX), KC_M,    TD(DANCE_MACC), TD(DANCE_MACV), TD(DANCE_ENTR),        KC_SPACE,       TD(DANCE_MACK), KC_L,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,
        TD(DANCE_TO_WINWM_NUM), KC_LALT,        KC_LGUI,        KC_LEFT, KC_RIGHT,                                                                              TD(DANCE_UP),   TD(DANCE_DWN),  BRCPAIR,        PRNPAIR,        TD(DANCE_TO_MACQT_FUNC),
                                                                                                   LGUI(KC_LALT), KC_NO,        KC_EQUAL, KC_MINUS,
                                                                                                                  KC_NO,        KC_NO,
                                                                                             KC_SPACE, KC_BSPACE, KC_NO,        KC_NO, KC_DELETE, TD(DANCE_ENTR)
        ),
        
    /* _WIN_WM: Windows Workman Layer (Red LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab    |   Q  |   D  |   R  |   W  |   B  | DEL  |           |Win+S |   J  |   F  |   U  |   P  |   ;  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Caps   |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   '    |
    * |--------+------+------+------+------+------| ENTER|           |Space |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | MACWM|  Win | Ctrl | Left | Right|                                       |  Up  | Down |   [  |   ]  | WINQT|
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |  Win  |      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_WIN_WM] = LAYOUT_ergodox_pretty(
        KC_NO,                  KC_NO,          KC_NO,          KC_NO,   KC_NO,          KC_NO,          KC_NO,          KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_TRNS,                KC_TRNS,        KC_TRNS,        KC_TRNS, KC_TRNS,        TD(DANCE_WINB), KC_TRNS,        LGUI(KC_S), KC_TRNS,        TD(DANCE_WINF), TD(DANCE_WINU), TD(DANCE_WINP), KC_TRNS,        KC_TRNS,
        KC_TRNS,                KC_TRNS,        TD(DANCE_WINS), KC_TRNS, KC_TRNS,        KC_TRNS,                                    KC_TRNS,        TD(DANCE_WINN), KC_TRNS,        TD(DANCE_WINO), TD(DANCE_WINI), KC_TRNS,
        KC_TRNS,                TD(DANCE_WINZ), TD(DANCE_WINX), KC_TRNS, TD(DANCE_WINC), TD(DANCE_WINV), KC_TRNS,        KC_TRNS,    TD(DANCE_WINK), KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        TD(DANCE_TO_MACWM_NUM), KC_LGUI,        KC_LCTRL,       KC_TRNS, KC_TRNS,                                                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TD(DANCE_TO_WINQT_FUNC),
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
    *   | WINQT|  Opt |  CMD | Left | Right|                                       |  Up  | Down |   [  |   ]  | MACWM|
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |CMD/OPT|      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space|Backsp |------|         |------|  Del   |Enter |
    *                               |      |ace    |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
    [_MAC_QWERTY] = LAYOUT_ergodox_pretty(
        KC_NO,                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_TAB,                 KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DELETE,               LGUI(KC_SPACE), KC_Y,           TD(DANCE_MACU), TD(DANCE_MACI), TD(DANCE_MACO), TD(DANCE_MACP), KC_BSLASH,
        KC_CAPSLOCK,            KC_A,           TD(DANCE_MACS), KC_D,           TD(DANCE_MACF), KC_G,                                                    KC_H,           KC_J,           TD(DANCE_MACK), KC_L,           KC_SCOLON,      QTPAIR,
        KC_LSPO,                TD(DANCE_MACZ), TD(DANCE_MACX), TD(DANCE_MACC), TD(DANCE_MACV), TD(DANCE_MACB), TD(DANCE_ENTR),          KC_SPACE,       TD(DANCE_MACN), KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,
        TD(DANCE_TO_WINQT_NUM), KC_LALT,        KC_LGUI,        KC_LEFT,        KC_RIGHT,                                                                                KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TD(DANCE_TO_MACWM_FUNC), 
                                                                                                        LGUI(KC_LALT), KC_TRNS,          KC_TRNS, KC_TRNS,
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
    *   | MACQT|  Win | Ctrl | Left | Right|                                       |  Up  | Down |   [  |   ]  | WINWM|
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
        KC_NO,                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                   KC_NO,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_TAB,                 KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DELETE,               LGUI(KC_S), KC_Y,           TD(DANCE_WINU), TD(DANCE_WINI), TD(DANCE_WINO), TD(DANCE_WINP), KC_BSLASH,
        KC_CAPSLOCK,            KC_A,           TD(DANCE_WINS), KC_D,           TD(DANCE_WINF), KC_G,                                                KC_H,           KC_J,           TD(DANCE_WINK), KC_L,           KC_SCOLON,      QTPAIR,
        KC_LSPO,                TD(DANCE_WINZ), TD(DANCE_WINX), TD(DANCE_WINC), TD(DANCE_WINV), TD(DANCE_WINB), TD(DANCE_ENTR),          KC_TRNS,    TD(DANCE_WINN), KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,
        TD(DANCE_TO_MACQT_NUM), KC_LALT,        KC_LGUI,        KC_LEFT,        KC_RIGHT,                                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TD(DANCE_TO_WINWM_FUNC), 
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
    [_MAC_WM] =  {{131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},         {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, 
                  {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255},                                       {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}},

    // Cadmium red
    [_WIN_WM] =            {{0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245},         {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, 
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
        case _MAC_WM:
            set_layer_color(_MAC_WM);
            break;
        case _WIN_WM:
            set_layer_color(_WIN_WM);
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
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
        case PRNPAIR:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            break;
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
                // break;
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

static tap dance_state[39];

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
//-----------------------------MAC-B---------------------------------------------
void on_dance_macb(qk_tap_dance_state_t *state, void *user_data);
void dance_macb_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macb_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macb(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_B);
        tap_code16(KC_B);
        tap_code16(KC_B);
    }
    if (state->count > 3) {
        tap_code16(KC_B);
    }
}

void dance_macb_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_B);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_B));
            break;
        case DOUBLE_TAP:
            register_code16(KC_B);
            register_code16(KC_B);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_B);
            register_code16(KC_B);
    }
}

void dance_macb_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_B);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_B));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_B);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_B);
            break;
    }
    dance_state[0].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-S---------------------------------------------
void on_dance_macs(qk_tap_dance_state_t *state, void *user_data);
void dance_macs_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macs_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macs(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_S);
        tap_code16(KC_S);
        tap_code16(KC_S);
    }
    if (state->count > 3) {
        tap_code16(KC_S);
    }
}

void dance_macs_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(KC_S);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_S));
            break;
        case DOUBLE_TAP:
            register_code16(KC_S);
            register_code16(KC_S);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_S);
            register_code16(KC_S);
    }
}

void dance_macs_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(KC_S);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_S));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_S);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_S);
            break;
    }
    dance_state[1].step = 0;
}


//-------------------------------------------------------------------------------
//-----------------------------MAC-Z---------------------------------------------
void on_dance_macz(qk_tap_dance_state_t *state, void *user_data);
void dance_macz_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macz_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macz(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if (state->count > 3) {
        tap_code16(KC_Z);
    }
}

void dance_macz_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            register_code16(KC_Z);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_Z));
            break;
        case DOUBLE_TAP:
            register_code16(KC_Z);
            register_code16(KC_Z);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_Z);
            register_code16(KC_Z);
    }
}

void dance_macz_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            unregister_code16(KC_Z);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_Z));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_Z);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_Z);
            break;
    }
    dance_state[2].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-X---------------------------------------------
void on_dance_macx(qk_tap_dance_state_t *state, void *user_data);
void dance_macx_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macx_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macx(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if (state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_macx_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            register_code16(KC_X);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_X));
            break;
        case DOUBLE_TAP:
            register_code16(KC_X);
            register_code16(KC_X);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_X);
            register_code16(KC_X);
    }
}

void dance_macx_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            unregister_code16(KC_X);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_X));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_X);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_X);
            break;
    }
    dance_state[3].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-C---------------------------------------------
void on_dance_macc(qk_tap_dance_state_t *state, void *user_data);
void dance_macc_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macc_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macc(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if (state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_macc_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            register_code16(KC_C);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_C));
            break;
        case DOUBLE_TAP:
            register_code16(KC_C);
            register_code16(KC_C);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_C);
            register_code16(KC_C);
    }
}

void dance_macc_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            unregister_code16(KC_C);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_C));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_C);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_C);
            break;
    }
    dance_state[4].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-V---------------------------------------------
void on_dance_macv(qk_tap_dance_state_t *state, void *user_data);
void dance_macv_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macv_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macv(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if (state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_macv_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP:
            register_code16(KC_V);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_V));
            break;
        case DOUBLE_TAP:
            register_code16(KC_V);
            register_code16(KC_V);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_V);
            register_code16(KC_V);
    }
}

void dance_macv_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP:
            unregister_code16(KC_V);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_V));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_V);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_V);
            break;
    }
    dance_state[5].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-F---------------------------------------------
void on_dance_macf(qk_tap_dance_state_t *state, void *user_data);
void dance_macf_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macf_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macf(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F);
        tap_code16(KC_F);
        tap_code16(KC_F);
    }
    if (state->count > 3) {
        tap_code16(KC_F);
    }
}

void dance_macf_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP:
            register_code16(KC_F);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_F));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F);
            register_code16(KC_F);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F);
            register_code16(KC_F);
    }
}

void dance_macf_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_F));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F);
            break;
    }
    dance_state[6].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-U---------------------------------------------
void on_dance_macu(qk_tap_dance_state_t *state, void *user_data);
void dance_macu_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macu_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macu(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if (state->count > 3) {
        tap_code16(KC_U);
    }
}

void dance_macu_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            register_code16(KC_U);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_U));
            break;
        case DOUBLE_TAP:
            register_code16(KC_U);
            register_code16(KC_U);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_U);
            register_code16(KC_U);
    }
}

void dance_macu_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            unregister_code16(KC_U);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_U));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_U);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_U);
            break;
    }
    dance_state[7].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-P---------------------------------------------
void on_dance_macp(qk_tap_dance_state_t *state, void *user_data);
void dance_macp_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macp_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macp(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if (state->count > 3) {
        tap_code16(KC_P);
    }
}

void dance_macp_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            register_code16(KC_P);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_P));
            break;
        case DOUBLE_TAP:
            register_code16(KC_P);
            register_code16(KC_P);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_P);
            register_code16(KC_P);
    }
}

void dance_macp_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            unregister_code16(KC_P);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_P));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_P);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_P);
            break;
    }
    dance_state[8].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-N---------------------------------------------
void on_dance_macn(qk_tap_dance_state_t *state, void *user_data);
void dance_macn_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_macn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_macn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if (state->count > 3) {
        tap_code16(KC_N);
    }
}

void dance_macn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP:
            register_code16(KC_N);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_N));
            break;
        case DOUBLE_TAP:
            register_code16(KC_N);
            register_code16(KC_N);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_N);
            register_code16(KC_N);
    }
}

void dance_macn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP:
            unregister_code16(KC_N);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_N));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_N);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_N);
            break;
    }
    dance_state[9].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-O---------------------------------------------
void on_dance_maco(qk_tap_dance_state_t *state, void *user_data);
void dance_maco_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_maco_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_maco(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if (state->count > 3) {
        tap_code16(KC_O);
    }
}

void dance_maco_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            register_code16(KC_O);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_O));
            break;
        case DOUBLE_TAP:
            register_code16(KC_O);
            register_code16(KC_O);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_O);
            register_code16(KC_O);
    }
}

void dance_maco_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            unregister_code16(KC_O);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_O));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_O);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_O);
            break;
    }
    dance_state[10].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-I---------------------------------------------
void on_dance_maci(qk_tap_dance_state_t *state, void *user_data);
void dance_maci_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_maci_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_maci(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if (state->count > 3) {
        tap_code16(KC_I);
    }
}

void dance_maci_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP:
            register_code16(KC_I);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_I));
            break;
        case DOUBLE_TAP:
            register_code16(KC_I);
            register_code16(KC_I);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_I);
            register_code16(KC_I);
    }
}

void dance_maci_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP:
            unregister_code16(KC_I);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_I));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_I);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_I);
            break;
    }
    dance_state[11].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------MAC-K---------------------------------------------
void on_dance_mack(qk_tap_dance_state_t *state, void *user_data);
void dance_mack_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_mack_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_mack(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if (state->count > 3) {
        tap_code16(KC_K);
    }
}

void dance_mack_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP:
            register_code16(KC_K);
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_K));
            break;
        case DOUBLE_TAP:
            register_code16(KC_K);
            register_code16(KC_K);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_K);
            register_code16(KC_K);
    }
}

void dance_mack_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP:
            unregister_code16(KC_K);
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_K));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_K);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_K);
            break;
    }
    dance_state[12].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------ENTER / SHIFT+ENTER-------------------------------
void on_dance_entr(qk_tap_dance_state_t *state, void *user_data);
void dance_entr_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_entr_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_entr(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if (state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_entr_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP:
            register_code16(KC_ENTER);
            break;
        case SINGLE_HOLD:
            register_code16(LSFT(KC_ENTER));
            break;
        case DOUBLE_TAP:
            register_code16(KC_ENTER);
            register_code16(KC_ENTER);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_ENTER);
            register_code16(KC_ENTER);
    }
}

void dance_entr_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP:
            unregister_code16(KC_ENTER);
            break;
        case SINGLE_HOLD:
            unregister_code16(LSFT(KC_ENTER));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_ENTER);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_ENTER);
            break;
    }
    dance_state[13].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------UP/ PGUP/ HOME------------------------------------
void on_dance_up(qk_tap_dance_state_t *state, void *user_data);
void dance_up_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_up_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_up(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_UP);
        tap_code16(KC_UP);
        tap_code16(KC_UP);
    }
    if (state->count > 3) {
        tap_code16(KC_UP);
    }
}

void dance_up_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
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

void dance_up_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
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
    dance_state[14].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------DOWN/ PGDN/ END-----------------------------------
void on_dance_dwn(qk_tap_dance_state_t *state, void *user_data);
void dance_dwn_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_dwn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_dwn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
    }
    if (state->count > 3) {
        tap_code16(KC_DOWN);
    }
}

void dance_dwn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
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

void dance_dwn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
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
    dance_state[15].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-B---------------------------------------------
void on_dance_winb(qk_tap_dance_state_t *state, void *user_data);
void dance_winb_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_winb_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_winb(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_B);
        tap_code16(KC_B);
        tap_code16(KC_B);
    }
    if (state->count > 3) {
        tap_code16(KC_B);
    }
}

void dance_winb_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP:
            register_code16(KC_B);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_B));
            break;
        case DOUBLE_TAP:
            register_code16(KC_B);
            register_code16(KC_B);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_B);
            register_code16(KC_B);
    }
}

void dance_winb_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP:
            unregister_code16(KC_B);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_B));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_B);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_B);
            break;
    }
    dance_state[17].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-S---------------------------------------------
void on_dance_wins(qk_tap_dance_state_t *state, void *user_data);
void dance_wins_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_wins_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_wins(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_S);
        tap_code16(KC_S);
        tap_code16(KC_S);
    }
    if (state->count > 3) {
        tap_code16(KC_S);
    }
}

void dance_wins_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP:
            register_code16(KC_S);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_S));
            break;
        case DOUBLE_TAP:
            register_code16(KC_S);
            register_code16(KC_S);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_S);
            register_code16(KC_S);
    }
}

void dance_wins_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP:
            unregister_code16(KC_S);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_S));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_S);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_S);
            break;
    }
    dance_state[18].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-Z---------------------------------------------
void on_dance_winz(qk_tap_dance_state_t *state, void *user_data);
void dance_winz_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_winz_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_winz(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if (state->count > 3) {
        tap_code16(KC_Z);
    }
}

void dance_winz_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP:
            register_code16(KC_Z);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_Z));
            break;
        case DOUBLE_TAP:
            register_code16(KC_Z);
            register_code16(KC_Z);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_Z);
            register_code16(KC_Z);
    }
}

void dance_winz_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP:
            unregister_code16(KC_Z);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_Z));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_Z);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_Z);
            break;
    }
    dance_state[19].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-X---------------------------------------------
void on_dance_winx(qk_tap_dance_state_t *state, void *user_data);
void dance_winx_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_winx_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_winx(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if (state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_winx_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            register_code16(KC_X);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_X));
            break;
        case DOUBLE_TAP:
            register_code16(KC_X);
            register_code16(KC_X);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_X);
            register_code16(KC_X);
    }
}

void dance_winx_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            unregister_code16(KC_X);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_X));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_X);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_X);
            break;
    }
    dance_state[20].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-C---------------------------------------------
void on_dance_winc(qk_tap_dance_state_t *state, void *user_data);
void dance_winc_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_winc_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_winc(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if (state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_winc_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP:
            register_code16(KC_C);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_C));
            break;
        case DOUBLE_TAP:
            register_code16(KC_C);
            register_code16(KC_C);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_C);
            register_code16(KC_C);
    }
}

void dance_winc_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP:
            unregister_code16(KC_C);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_C));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_C);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_C);
            break;
    }
    dance_state[21].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-V---------------------------------------------
void on_dance_winv(qk_tap_dance_state_t *state, void *user_data);
void dance_winv_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_winv_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_winv(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if (state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_winv_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP:
            register_code16(KC_V);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_V));
            break;
        case DOUBLE_TAP:
            register_code16(KC_V);
            register_code16(KC_V);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_V);
            register_code16(KC_V);
    }
}

void dance_winv_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP:
            unregister_code16(KC_V);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_V));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_V);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_V);
            break;
    }
    dance_state[22].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-F---------------------------------------------
void on_dance_winf(qk_tap_dance_state_t *state, void *user_data);
void dance_winf_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_winf_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_winf(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_F);
        tap_code16(KC_F);
        tap_code16(KC_F);
    }
    if (state->count > 3) {
        tap_code16(KC_F);
    }
}

void dance_winf_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP:
            register_code16(KC_F);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_F));
            break;
        case DOUBLE_TAP:
            register_code16(KC_F);
            register_code16(KC_F);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_F);
            register_code16(KC_F);
    }
}

void dance_winf_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP:
            unregister_code16(KC_F);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_F));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_F);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_F);
            break;
    }
    dance_state[23].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-U---------------------------------------------
void on_dance_winu(qk_tap_dance_state_t *state, void *user_data);
void dance_winu_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_winu_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_winu(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if (state->count > 3) {
        tap_code16(KC_U);
    }
}

void dance_winu_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP:
            register_code16(KC_U);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_U));
            break;
        case DOUBLE_TAP:
            register_code16(KC_U);
            register_code16(KC_U);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_U);
            register_code16(KC_U);
    }
}

void dance_winu_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP:
            unregister_code16(KC_U);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_U));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_U);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_U);
            break;
    }
    dance_state[24].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-P---------------------------------------------
void on_dance_winp(qk_tap_dance_state_t *state, void *user_data);
void dance_winp_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_winp_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_winp(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if (state->count > 3) {
        tap_code16(KC_P);
    }
}

void dance_winp_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP:
            register_code16(KC_P);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_P));
            break;
        case DOUBLE_TAP:
            register_code16(KC_P);
            register_code16(KC_P);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_P);
            register_code16(KC_P);
    } 
}

void dance_winp_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP:
            unregister_code16(KC_P);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_P));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_P);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_P);
            break;
    }
    dance_state[25].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-N---------------------------------------------
void on_dance_winn(qk_tap_dance_state_t *state, void *user_data);
void dance_winn_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_winn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_winn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if (state->count > 3) {
        tap_code16(KC_N);
    }
}

void dance_winn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP:
            register_code16(KC_N);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_N));
            break;
        case DOUBLE_TAP:
            register_code16(KC_N);
            register_code16(KC_N);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_N);
            register_code16(KC_N);
    }
}

void dance_winn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP:
            unregister_code16(KC_N);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_N));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_N);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_N);
            break;
    }
    dance_state[26].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-O---------------------------------------------
void on_dance_wino(qk_tap_dance_state_t *state, void *user_data);
void dance_wino_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_wino_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_wino(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if (state->count > 3) {
        tap_code16(KC_O);
    }
}

void dance_wino_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP:
            register_code16(KC_O);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_O));
            break;
        case DOUBLE_TAP:
            register_code16(KC_O);
            register_code16(KC_O);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_O);
            register_code16(KC_O);
    }
}

void dance_wino_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP:
            unregister_code16(KC_O);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_O));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_O);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_O);
            break;
    }
    dance_state[27].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-I---------------------------------------------
void on_dance_wini(qk_tap_dance_state_t *state, void *user_data);
void dance_wini_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_wini_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_wini(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if (state->count > 3) {
        tap_code16(KC_I);
    }
}

void dance_wini_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP:
            register_code16(KC_I);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_I));
            break;
        case DOUBLE_TAP:
            register_code16(KC_I);
            register_code16(KC_I);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_I);
            register_code16(KC_I);
    }
}

void dance_wini_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP:
            unregister_code16(KC_I);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_I));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_I);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_I);
            break;
    }
    dance_state[28].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------WIN-K---------------------------------------------
void on_dance_wink(qk_tap_dance_state_t *state, void *user_data);
void dance_wink_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_wink_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_wink(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if (state->count > 3) {
        tap_code16(KC_K);
    }
}

void dance_wink_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP:
            register_code16(KC_K);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_K));
            break;
        case DOUBLE_TAP:
            register_code16(KC_K);
            register_code16(KC_K);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_K);
            register_code16(KC_K);
    }
}

void dance_wink_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP:
            unregister_code16(KC_K);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_K));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_K);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_K);
            break;
    }
    dance_state[29].step = 0;
}




//-------------------------------------------------------------------------------
//-----------------------------LAYER->_WIN_WM + _FUNC----------------------------
// Tap to go to _WIN_WM, hold to go to _FUNC
void dance_to_winwm_func_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_to_winwm_func_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_to_winwm_func_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP:
            layer_move(_WIN_WM);
            break;
        case SINGLE_HOLD:
            layer_on(_FUNC);
            break;
            //    case DOUBLE_TAP: layer_move(_WIN_WM); break;
            //    case DOUBLE_SINGLE_TAP: layer_move(_WIN_WM); break;
    }
}
void dance_to_winwm_func_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_HOLD:
            layer_off(_FUNC);
            break;
    }
    dance_state[30].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_MAC_WM + _FUNC----------------------------
// Tap to go to _MAC_WM, hold to go to _FUNC
void dance_to_macwm_func_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_to_macwm_func_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_to_macwm_func_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP:
            layer_move(_MAC_WM);
            break;
        case SINGLE_HOLD:
            layer_on(_FUNC);
            break;
            //    case DOUBLE_TAP: layer_move(_MAC_WM); break;
            //    case DOUBLE_SINGLE_TAP: layer_move(_MAC_WM); break;
    }
}
void dance_to_macwm_func_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_HOLD:
            layer_off(_FUNC);
            break;
    }
    dance_state[31].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_WIN_WM + _NUMPAD--------------------------
// Tap to go to _WIN_WM, hold to go to _NUMPAD
void dance_to_winwm_num_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_to_winwm_num_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_to_winwm_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP:
            layer_move(_WIN_WM);
            break;
        case SINGLE_HOLD:
            layer_on(_NUMPAD);
            break;
            //  case DOUBLE_TAP: layer_move(_WIN_WM); break;
            //  case DOUBLE_SINGLE_TAP: layer_move(_WIN_WM); break;
    }
}
void dance_to_winwm_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_HOLD:
            layer_off(_NUMPAD);
            break;
    }
    dance_state[32].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_MAC_WM + _NUMPAD--------------------------
// Tap to go to _MAC_WM, hold to go to _NUMPAD
void dance_to_macwm_num_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_to_macwm_num_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_to_macwm_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP:
            layer_move(_MAC_WM);
            break;
        case SINGLE_HOLD:
            layer_on(_NUMPAD);
            break;
            //    case DOUBLE_TAP: layer_move(_MAC_WM); break;
            //    case DOUBLE_SINGLE_TAP: layer_move(_MAC_WM); break;
    }
}
void dance_to_macwm_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_HOLD:
            layer_off(_NUMPAD);
            break;
    }
    dance_state[33].step = 0;
}


//-------------------------------------------------------------------------------
//-----------------------------LAYER->_WIN_QWERTY + _FUNC------------------------
// Tap to go to _WIN_QWERTY, hold to go to _FUNC
void dance_to_winqt_func_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_to_winqt_func_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_to_winqt_func_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
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
void dance_to_winqt_func_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_HOLD:
            layer_off(_FUNC);
            break;
    }
    dance_state[34].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_MAC_QWERTY + _FUNC------------------------
// Tap to go to _MAC_QWERTY, hold to go to _FUNC
void dance_to_macqt_func_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_to_macqt_func_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_to_macqt_func_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[35].step = dance_step(state);
    switch (dance_state[35].step) {
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
void dance_to_macqt_func_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[35].step) {
        case SINGLE_HOLD:
            layer_off(_FUNC);
            break;
    }
    dance_state[35].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_WIN_QWERTY + _NUMPAD--------------------------
// Tap to go to _WIN_QWERTY, hold to go to _NUMPAD
void dance_to_winqt_num_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_to_winqt_num_reset(qk_tap_dance_state_t *state, void *user_data);
void dance_to_winqt_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[36].step = dance_step(state);
    switch (dance_state[36].step) {
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
void dance_to_winqt_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[36].step) {
        case SINGLE_HOLD:
            layer_off(_NUMPAD);
            break;
    }
    dance_state[36].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------LAYER->_MAC_QWERTY + _NUMPAD--------------------------
// Tap to go to _MAC_QWERTY, hold to go to _NUMPAD
void dance_to_macqt_num_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_to_macqt_num_reset(qk_tap_dance_state_t *state, void *user_data);

void dance_to_macqt_num_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[37].step = dance_step(state);
    switch (dance_state[37].step) {
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
void dance_to_macqt_num_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[37].step) {
        case SINGLE_HOLD:
            layer_off(_NUMPAD);
            break;
    }
    dance_state[37].step = 0;
}

//-------------------------------------------------------------------------------
//-----------------------------SFT_PRN---------------------------------------------
// Tap for (
// Hold for shift
// Double tap for CAPS
void on_dance_sft_prn(qk_tap_dance_state_t *state, void *user_data);
void dance_sft_prn_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_sft_prn_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_sft_prn(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_sft_prn_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[38].step = dance_step(state);
    switch (dance_state[38].step) {
        case SINGLE_TAP:
            SEND_STRING("()");
            // tap_code(KC_LEFT);
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

void dance_sft_prn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[38].step) {
        case SINGLE_TAP:
            tap_code(KC_LEFT);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_LSHIFT);
            break;
     /*   case DOUBLE_TAP:
            unregister_code16(KC_CAPS_LOCK);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_CAPS_LOCK);
            break;*/
    }
    dance_state[38].step = 0;
}
//-------------------------------------------------------------------------------
qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_MACB] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macb, dance_macb_finished, dance_macb_reset),
        [DANCE_MACS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macs, dance_macs_finished, dance_macs_reset),
        [DANCE_MACZ] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macz, dance_macz_finished, dance_macz_reset),
        [DANCE_MACX] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macx, dance_macx_finished, dance_macx_reset),
        [DANCE_MACC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macc, dance_macc_finished, dance_macc_reset),
        [DANCE_MACV] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macv, dance_macv_finished, dance_macv_reset),
        [DANCE_ENTR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_entr, dance_entr_finished, dance_entr_reset),
        [DANCE_MACF] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macf, dance_macf_finished, dance_macf_reset),
        [DANCE_MACU] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macu, dance_macu_finished, dance_macu_reset),
        [DANCE_MACP] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macp, dance_macp_finished, dance_macp_reset),
        [DANCE_MACN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_macn, dance_macn_finished, dance_macn_reset),
        [DANCE_MACO] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_maco, dance_maco_finished, dance_maco_reset),
        [DANCE_MACI] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_maci, dance_maci_finished, dance_maci_reset),
        [DANCE_MACK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_mack, dance_mack_finished, dance_mack_reset),
        [DANCE_UP]   = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_up, dance_up_finished, dance_up_reset),
        [DANCE_DWN]  = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_dwn, dance_dwn_finished, dance_dwn_reset),
        [DANCE_WINB] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_winb, dance_winb_finished, dance_winb_reset),
        [DANCE_WINS] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_wins, dance_wins_finished, dance_wins_reset),
        [DANCE_WINZ] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_winz, dance_winz_finished, dance_winz_reset),
        [DANCE_WINX] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_winx, dance_winx_finished, dance_winx_reset),
        [DANCE_WINC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_winc, dance_winc_finished, dance_winc_reset),
        [DANCE_WINV] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_winv, dance_winv_finished, dance_winv_reset),
        [DANCE_WINF] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_winf, dance_winf_finished, dance_winf_reset),
        [DANCE_WINU] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_winu, dance_winu_finished, dance_winu_reset),
        [DANCE_WINP] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_winp, dance_winp_finished, dance_winp_reset),
        [DANCE_WINN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_winn, dance_winn_finished, dance_winn_reset),
        [DANCE_WINO] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_wino, dance_wino_finished, dance_wino_reset),
        [DANCE_WINI] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_wini, dance_wini_finished, dance_wini_reset),
        [DANCE_WINK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_wink, dance_wink_finished, dance_wink_reset),

        [DANCE_TO_WINWM_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_to_winwm_func_finished, dance_to_winwm_func_reset),
        [DANCE_TO_MACWM_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_to_macwm_func_finished, dance_to_macwm_func_reset),
        [DANCE_TO_WINWM_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_to_winwm_num_finished, dance_to_winwm_num_reset),
        [DANCE_TO_MACWM_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_to_macwm_num_finished, dance_to_macwm_num_reset),
        [DANCE_TO_WINQT_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_to_winqt_func_finished, dance_to_winqt_func_reset),
        [DANCE_TO_MACQT_FUNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_to_macqt_func_finished, dance_to_macqt_func_reset),
        [DANCE_TO_WINQT_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_to_winqt_num_finished, dance_to_winqt_num_reset),
        [DANCE_TO_MACQT_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_to_macqt_num_finished, dance_to_macqt_num_reset),
        [DANCE_SFT_PRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_sft_prn, dance_sft_prn_finished, dance_sft_prn_reset),
};
