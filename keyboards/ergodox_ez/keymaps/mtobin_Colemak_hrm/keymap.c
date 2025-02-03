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
  TAB_ESC, // Tab on tap, Esc on hold
  SFTPRN, // Left parenthesis on tap, Left shift on hold, Caps lock on double tap
  UP, // Up arrow on tap, PgUp on double tap, Home on hold
  DWN, // Down arrow on tap, PgDn on double tap, End on hold
  ENTER, // Enter on tap, Shift+Enter on hold
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
   /* _MACOS:  Colemak DH Layer (Blue LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab/Esc|   Q  |   W  |   F  |   P  |   B  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | ALFRED |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   O  |   I  |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      | Left | Right|                                       |  Up  | Down |      |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |       |      |         |      |      |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
  [_MACOS] = LAYOUT_ergodox_pretty(
    KC_NO,         KC_NO, KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,            KC_NO, KC_NO,        KC_NO,        KC_NO,            KC_NO,  KC_NO,     KC_NO,
    TD(TAB_ESC),   KC_Q,  KC_W,  KC_F,         KC_P,         KC_B,         KC_NO,            KC_NO, KC_J,         KC_L,         KC_U,             KC_Y,   KC_SCOLON, KC_BSLASH,
    MEH(KC_SPACE), KC_A,  KC_R,  KC_S,         KC_T,         KC_G,                           KC_M,  KC_N,         KC_E,         KC_O,             KC_I,   KC_QUOTE,
    TD(SFTPRN),    KC_Z,  KC_X,  LCTL_T(KC_C), LOPT_T(KC_D), LCMD_T(KC_V), KC_NO,            KC_NO, RCMD_T(KC_K), ROPT_T(KC_H), RCTL_T(KC_COMMA), KC_DOT, KC_SLASH,  KC_RSPC,
    KC_NO,         KC_NO, KC_NO, KC_LEFT,      KC_RIGHT,                                                          TD(UP),       TD(DWN),          KC_NO,  KC_NO,     KC_NO,
                                                                    KC_NO, KC_NO,            KC_NO, KC_NO,
                                                                           KC_NO,            KC_NO,
                                             LT(_NUM,KC_SPACE), KC_BSPACE, KC_NO,            KC_NO, LT(_FUNC,KC_DELETE),TD(ENTER)
  ),


   /* _WINDOWS:  Windows Colemak DH Layer (Blue LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Tab/Esc|   Q  |   W  |   F  |   P  |   B  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Search |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   O  |   I  |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      | Left | Right|                                       |  Up  | Down |      |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |       |      |         |      |      |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
  [_WINDOWS] = LAYOUT_ergodox_pretty(
    KC_NO,       KC_NO, KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,          KC_NO, KC_NO,        KC_NO,        KC_NO,            KC_NO,  KC_NO,     KC_NO,
    TD(TAB_ESC), KC_Q,  KC_W,  KC_F,         KC_P,         KC_B,         KC_NO,          KC_NO, KC_J,         KC_L,         KC_U,             KC_Y,   KC_SCOLON, KC_BSLASH,
    LGUI(KC_S),  KC_A,  KC_R,  KC_S,         KC_T,         KC_G,                         KC_M,  KC_N,         KC_E,         KC_O,             KC_I,   KC_QUOTE,
    TD(SFTPRN),  KC_Z,  KC_X,  LWIN_T(KC_C), LALT_T(KC_D), LCTL_T(KC_V), KC_NO,          KC_NO, RCTL_T(KC_K), RALT_T(KC_H), RWIN_T(KC_COMMA), KC_DOT, KC_SLASH,  KC_RSPC,
    KC_NO,       KC_NO, KC_NO, KC_LEFT,      KC_RIGHT,                                                        TD(UP),       TD(DWN),          KC_NO,  KC_NO,     KC_NO,
                                                                  KC_NO, KC_NO,          KC_NO, KC_NO,
                                                                         KC_NO,          KC_NO,
                                           LT(_NUM,KC_SPACE), KC_BSPACE, KC_NO,          KC_NO, LT(_FUNC,KC_DELETE), TD(ENTER)  
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
        KC_NO,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_0,  KC_DOT,  KC_NO, KC_NO,   KC_NO,
                                
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

static tap dance_state[5];

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
void on_tab_esc(qk_tap_dance_state_t *state, void *user_data);
void tab_esc_finished(qk_tap_dance_state_t *state, void *user_data);
void tab_esc_reset(qk_tap_dance_state_t *state, void *user_data);

void on_tab_esc(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void tab_esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void tab_esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[0].step = 0;
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
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: register_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void sftprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[1].step = 0;
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
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_UP); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UP); register_code16(KC_UP);
    }
}

void up_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_UP); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UP); break;
    }
    dance_state[2].step = 0;
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
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_DOWN); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOWN); register_code16(KC_DOWN);
    }
}

void dwn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_DOWN); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOWN); break;
    }
    dance_state[3].step = 0;
}


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
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: register_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void enter_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[4].step = 0;
}




qk_tap_dance_action_t tap_dance_actions[] = {
        [TAB_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(on_tab_esc, tab_esc_finished, tab_esc_reset),
        [SFTPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_sftprn, sftprn_finished, sftprn_reset),
        [UP] = ACTION_TAP_DANCE_FN_ADVANCED(on_up, up_finished, up_reset),
        [DWN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dwn, dwn_finished, dwn_reset),
        [ENTER] = ACTION_TAP_DANCE_FN_ADVANCED(on_enter, enter_finished, enter_reset),

};
