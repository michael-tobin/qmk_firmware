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
  CMD_F,
  CMD_P,
  CMD_B,
  TAB_ESC, // Tab on tap, Esc on hold
  CMD_S,
  CMD_T,
  SFTPRN, // Left parenthesis on tap, Left shift on hold, Caps lock on double tap
  CMD_Z,
  CMD_X,
  CMD_C,
  CMD_V,
  CMD_U,
  CMD_N,
  CMD_I,
  CMD_O,
  CMD_K,
  UP, // Up arrow on tap, PgUp on double tap, Home on hold
  DWN, // Down arrow on tap, PgDn on double tap, End on hold
  ENTER, // Enter on tap, Shift+Enter on hold
  CTL_F,
  CTL_P,
  CTL_B,
  CTL_S,
  CTL_T,
  CTL_Z,
  CTL_X,
  CTL_C,
  CTL_V,
  CTL_U,
  CTL_N,
  CTL_I,
  CTL_O,
  CTL_K,
};

// ---- Combo definitions ----
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

// -- end of combo definitions --

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* _MACOS:  Colemak DH Layer (Blue LED)
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
  [_MACOS] = LAYOUT_ergodox_pretty(
    KC_NO,         KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,            KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,      KC_NO,     KC_NO,
    MEH(KC_SPACE), KC_Q,      KC_W,      TD(CMD_F), TD(CMD_P), TD(CMD_B), KC_NO,            KC_NO, KC_J,      KC_L,      TD(CMD_U), KC_Y,       KC_SCOLON, KC_BSLASH,
    TD(TAB_ESC),   KC_A,      KC_R,      TD(CMD_S), TD(CMD_T), KC_G,                               KC_M,      TD(CMD_N), KC_E,      TD(CMD_I),  TD(CMD_O), KC_QUOTE,
    TD(SFTPRN),    TD(CMD_Z), TD(CMD_X), TD(CMD_C), KC_D,      TD(CMD_V), KC_NO,            KC_NO, TD(CMD_K), KC_H,      KC_COMMA,  KC_DOT,     KC_SLASH,  KC_RSPC,
    KC_NO,         KC_LALT,   KC_LGUI,   KC_LEFT,   KC_RIGHT,                                                 TD(UP),    TD(DWN),   KC_LBRC,    KC_RBRC,   KC_NO,
                                                           LGUI(KC_LALT), KC_NO,            KC_EQUAL, KC_MINUS,
                                                                          KC_NO,            KC_NO,
                                            LT(_NUM,KC_SPACE), KC_BSPACE, KC_NO,            KC_NO, LT(_FUNC,KC_DELETE),TD(ENTER)
  ),


   /* _WINDOWS:  Windows Colemak DH Layer (Blue LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | Search |   Q  |   W  |   F  |   P  |   B  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Tab/Esc|   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |(/Shift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      | Ctrl | Alt  | Left | Right|                                       |  Up  | Down |   [  |   ]  |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                      ,--------------.         ,-------------.
    *                                      |  Win  |      |         |  =   |  -   |
    *                               ,------|-------|------|         |------+--------+------.
    *                               |      |       |      |         |      |        |      |
    *                               | Space| Bkspc |------|         |------|  Del   |Enter |
    *                               |      |       |      |         |      |        |      |
    *                               `---------------------'         `----------------------'
    */
  [_WINDOWS] = LAYOUT_ergodox_pretty(
    KC_NO,       KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,          KC_NO, KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
    LGUI(KC_S),  KC_Q,      KC_W,      TD(CTL_F), TD(CTL_P), TD(CTL_B), KC_NO,          KC_NO, KC_J,      KC_L,      TD(CTL_U), KC_Y,      KC_SCOLON, KC_BSLASH,
    TD(TAB_ESC), KC_A,      KC_R,      TD(CTL_S), TD(CTL_T), KC_G,                             KC_M,      TD(CTL_N), KC_E,      TD(CTL_I), TD(CTL_O), KC_QUOTE,
    TD(SFTPRN),  TD(CTL_Z), TD(CTL_X), TD(CTL_C), KC_D,      TD(CTL_V), KC_NO,          KC_NO, TD(CTL_K), KC_H,      KC_COMMA,  KC_DOT,    KC_SLASH,  KC_RSPC,
    KC_NO,       KC_LCTRL,  KC_LALT,   KC_LEFT,   KC_RIGHT,                                               TD(UP),    TD(DWN),   KC_LBRC,   KC_RBRC,   KC_NO,
                                                               KC_LGUI, KC_NO,          KC_EQUAL, KC_MINUS,
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
    *   |      | Ctrl | Meta |      |      |                                       |      |      |      |      |      |
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
    KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5,  KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
    KC_NO, KC_F6,   KC_F7,   KC_F8, KC_F9, KC_F10,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F11,  KC_F12,  KC_NO, KC_NO, KC_NO,  KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_LCTL, KC_LGUI, KC_NO, KC_NO,                                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_NO, KC_NO,         KC_NO, KC_NO,
                                                   KC_NO,         KC_NO,
                                     KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO
  ),


      /* _NUM: Number pad Layer (Yellow LED)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * | ALFRED |   1! |  2@  |  3#  | 4$   |  5%  |      |           |      |  6^  |  7&  |  8*  |  9(  |  0)  |   \    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Tab/Esc|      |      |      |      |      |------|           |------|      |  4$  |  5%  |  6^  |      |   '    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |(/Shift |      |      |      |      |      |      |           |      |      |  1!  |  2@  |  3#  |   /  | (/Shift|
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      | Ctrl | Meta | Left | Right|                                       |  0)  |   .  |   [  |      |      |
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
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_NO,        KC_NO, KC_6,  KC_7,  KC_8,   KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,                        KC_NO, KC_4,  KC_5,   KC_6,    KC_NO,   KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,        KC_NO, KC_NO, KC_1,  KC_2,   KC_3,    KC_NO,   KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_0,  KC_DOT, KC_TRNS, KC_TRNS, KC_NO,
                                
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
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

static tap dance_state[33];

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
void on_cmd_f(qk_tap_dance_state_t *state, void *user_data);
void cmd_f_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_f_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_f(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F);
        tap_code16(KC_F);
        tap_code16(KC_F);
    }
    if(state->count > 3) {
        tap_code16(KC_F);
    }
}

void cmd_f_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_F); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_F)); break;
        case DOUBLE_TAP: register_code16(KC_F); register_code16(KC_F); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F); register_code16(KC_F);
    }
}

void cmd_f_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_F); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_F)); break;
        case DOUBLE_TAP: unregister_code16(KC_F); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F); break;
    }
    dance_state[0].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_p(qk_tap_dance_state_t *state, void *user_data);
void cmd_p_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_p_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_p(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if(state->count > 3) {
        tap_code16(KC_P);
    }
}

void cmd_p_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_P); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_P)); break;
        case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
    }
}

void cmd_p_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_P); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_P)); break;
        case DOUBLE_TAP: unregister_code16(KC_P); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_P); break;
    }
    dance_state[1].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_b(qk_tap_dance_state_t *state, void *user_data);
void cmd_b_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_b_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_b(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_B);
        tap_code16(KC_B);
        tap_code16(KC_B);
    }
    if(state->count > 3) {
        tap_code16(KC_B);
    }
}

void cmd_b_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_B); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_B)); break;
        case DOUBLE_TAP: register_code16(KC_B); register_code16(KC_B); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_B); register_code16(KC_B);
    }
}

void cmd_b_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_B); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_B)); break;
        case DOUBLE_TAP: unregister_code16(KC_B); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_B); break;
    }
    dance_state[2].step = 0;
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
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void tab_esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[3].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_s(qk_tap_dance_state_t *state, void *user_data);
void cmd_s_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_s_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_s(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_S);
        tap_code16(KC_S);
        tap_code16(KC_S);
    }
    if(state->count > 3) {
        tap_code16(KC_S);
    }
}

void cmd_s_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_S); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_S)); break;
        case DOUBLE_TAP: register_code16(KC_S); register_code16(KC_S); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_S); register_code16(KC_S);
    }
}

void cmd_s_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_S); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_S)); break;
        case DOUBLE_TAP: unregister_code16(KC_S); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_S); break;
    }
    dance_state[4].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_t(qk_tap_dance_state_t *state, void *user_data);
void cmd_t_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_t_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_t(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_T);
        tap_code16(KC_T);
        tap_code16(KC_T);
    }
    if(state->count > 3) {
        tap_code16(KC_T);
    }
}

void cmd_t_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_T); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_T)); break;
        case DOUBLE_TAP: register_code16(KC_T); register_code16(KC_T); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_T); register_code16(KC_T);
    }
}

void cmd_t_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_T); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_T)); break;
        case DOUBLE_TAP: unregister_code16(KC_T); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_T); break;
    }
    dance_state[5].step = 0;
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
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: register_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void sftprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_CAPSLOCK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[6].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_z(qk_tap_dance_state_t *state, void *user_data);
void cmd_z_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_z_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_z(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if(state->count > 3) {
        tap_code16(KC_Z);
    }
}

void cmd_z_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_Z); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_Z)); break;
        case DOUBLE_TAP: register_code16(KC_Z); register_code16(KC_Z); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Z); register_code16(KC_Z);
    }
}

void cmd_z_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_Z); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_Z)); break;
        case DOUBLE_TAP: unregister_code16(KC_Z); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Z); break;
    }
    dance_state[7].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_x(qk_tap_dance_state_t *state, void *user_data);
void cmd_x_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_x_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_x(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

void cmd_x_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_X)); break;
        case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void cmd_x_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_X)); break;
        case DOUBLE_TAP: unregister_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state[8].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_c(qk_tap_dance_state_t *state, void *user_data);
void cmd_c_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_c_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_c(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if(state->count > 3) {
        tap_code16(KC_C);
    }
}

void cmd_c_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_C)); break;
        case DOUBLE_TAP: register_code16(KC_C); register_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void cmd_c_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_C)); break;
        case DOUBLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state[9].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_v(qk_tap_dance_state_t *state, void *user_data);
void cmd_v_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_v_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_v(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void cmd_v_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void cmd_v_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[10].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_u(qk_tap_dance_state_t *state, void *user_data);
void cmd_u_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_u_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_u(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

void cmd_u_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_U)); break;
        case DOUBLE_TAP: register_code16(KC_U); register_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void cmd_u_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_U); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_U)); break;
        case DOUBLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_U); break;
    }
    dance_state[11].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_n(qk_tap_dance_state_t *state, void *user_data);
void cmd_n_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_n_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_n(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if(state->count > 3) {
        tap_code16(KC_N);
    }
}

void cmd_n_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_N); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_N)); break;
        case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
    }
}

void cmd_n_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_N); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_N)); break;
        case DOUBLE_TAP: unregister_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
    }
    dance_state[12].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_i(qk_tap_dance_state_t *state, void *user_data);
void cmd_i_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_i_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_i(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if(state->count > 3) {
        tap_code16(KC_I);
    }
}

void cmd_i_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_I); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_I)); break;
        case DOUBLE_TAP: register_code16(KC_I); register_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_I); register_code16(KC_I);
    }
}

void cmd_i_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_I); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_I)); break;
        case DOUBLE_TAP: unregister_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_I); break;
    }
    dance_state[13].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_o(qk_tap_dance_state_t *state, void *user_data);
void cmd_o_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_o_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_o(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

void cmd_o_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_O)); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void cmd_o_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_O); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_O)); break;
        case DOUBLE_TAP: unregister_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
    }
    dance_state[14].step = 0;
}


//-------------------------------------------------------------------------------
void on_cmd_k(qk_tap_dance_state_t *state, void *user_data);
void cmd_k_finished(qk_tap_dance_state_t *state, void *user_data);
void cmd_k_reset(qk_tap_dance_state_t *state, void *user_data);

void on_cmd_k(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void cmd_k_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_K)); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void cmd_k_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[15].step = 0;
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
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_UP); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UP); register_code16(KC_UP);
    }
}

void up_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_UP); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UP); break;
    }
    dance_state[16].step = 0;
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
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_DOWN); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOWN); register_code16(KC_DOWN);
    }
}

void dwn_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_DOWN); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOWN); break;
    }
    dance_state[17].step = 0;
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
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: register_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void enter_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_ENTER)); break;
        case DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[18].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_f(qk_tap_dance_state_t *state, void *user_data);
void ctl_f_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_f_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_f(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F);
        tap_code16(KC_F);
        tap_code16(KC_F);
    }
    if(state->count > 3) {
        tap_code16(KC_F);
    }
}

void ctl_f_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(KC_F); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_F)); break;
        case DOUBLE_TAP: register_code16(KC_F); register_code16(KC_F); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F); register_code16(KC_F);
    }
}

void ctl_f_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(KC_F); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_F)); break;
        case DOUBLE_TAP: unregister_code16(KC_F); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F); break;
    }
    dance_state[19].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_p(qk_tap_dance_state_t *state, void *user_data);
void ctl_p_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_p_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_p(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_P);
        tap_code16(KC_P);
        tap_code16(KC_P);
    }
    if(state->count > 3) {
        tap_code16(KC_P);
    }
}

void ctl_p_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(KC_P); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_P)); break;
        case DOUBLE_TAP: register_code16(KC_P); register_code16(KC_P); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_P); register_code16(KC_P);
    }
}

void ctl_p_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(KC_P); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_P)); break;
        case DOUBLE_TAP: unregister_code16(KC_P); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_P); break;
    }
    dance_state[20].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_b(qk_tap_dance_state_t *state, void *user_data);
void ctl_b_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_b_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_b(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_B);
        tap_code16(KC_B);
        tap_code16(KC_B);
    }
    if(state->count > 3) {
        tap_code16(KC_B);
    }
}

void ctl_b_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP: register_code16(KC_B); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_B)); break;
        case DOUBLE_TAP: register_code16(KC_B); register_code16(KC_B); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_B); register_code16(KC_B);
    }
}

void ctl_b_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP: unregister_code16(KC_B); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_B)); break;
        case DOUBLE_TAP: unregister_code16(KC_B); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_B); break;
    }
    dance_state[21].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_s(qk_tap_dance_state_t *state, void *user_data);
void ctl_s_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_s_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_s(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_S);
        tap_code16(KC_S);
        tap_code16(KC_S);
    }
    if(state->count > 3) {
        tap_code16(KC_S);
    }
}

void ctl_s_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(KC_S); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_S)); break;
        case DOUBLE_TAP: register_code16(KC_S); register_code16(KC_S); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_S); register_code16(KC_S);
    }
}

void ctl_s_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(KC_S); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_S)); break;
        case DOUBLE_TAP: unregister_code16(KC_S); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_S); break;
    }
    dance_state[22].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_t(qk_tap_dance_state_t *state, void *user_data);
void ctl_t_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_t_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_t(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_T);
        tap_code16(KC_T);
        tap_code16(KC_T);
    }
    if(state->count > 3) {
        tap_code16(KC_T);
    }
}

void ctl_t_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(KC_T); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_T)); break;
        case DOUBLE_TAP: register_code16(KC_T); register_code16(KC_T); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_T); register_code16(KC_T);
    }
}

void ctl_t_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(KC_T); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_T)); break;
        case DOUBLE_TAP: unregister_code16(KC_T); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_T); break;
    }
    dance_state[23].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_z(qk_tap_dance_state_t *state, void *user_data);
void ctl_z_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_z_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_z(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if(state->count > 3) {
        tap_code16(KC_Z);
    }
}

void ctl_z_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP: register_code16(KC_Z); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_Z)); break;
        case DOUBLE_TAP: register_code16(KC_Z); register_code16(KC_Z); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Z); register_code16(KC_Z);
    }
}

void ctl_z_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP: unregister_code16(KC_Z); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_Z)); break;
        case DOUBLE_TAP: unregister_code16(KC_Z); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Z); break;
    }
    dance_state[24].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_x(qk_tap_dance_state_t *state, void *user_data);
void ctl_x_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_x_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_x(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_X);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

void ctl_x_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_X)); break;
        case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void ctl_x_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_X)); break;
        case DOUBLE_TAP: unregister_code16(KC_X); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state[25].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_c(qk_tap_dance_state_t *state, void *user_data);
void ctl_c_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_c_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_c(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if(state->count > 3) {
        tap_code16(KC_C);
    }
}

void ctl_c_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_C)); break;
        case DOUBLE_TAP: register_code16(KC_C); register_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void ctl_c_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_C)); break;
        case DOUBLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state[26].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_v(qk_tap_dance_state_t *state, void *user_data);
void ctl_v_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_v_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_v(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void ctl_v_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_V)); break;
        case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void ctl_v_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[27].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_u(qk_tap_dance_state_t *state, void *user_data);
void ctl_u_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_u_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_u(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

void ctl_u_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_U)); break;
        case DOUBLE_TAP: register_code16(KC_U); register_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void ctl_u_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP: unregister_code16(KC_U); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_U)); break;
        case DOUBLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_U); break;
    }
    dance_state[28].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_n(qk_tap_dance_state_t *state, void *user_data);
void ctl_n_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_n_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_n(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if(state->count > 3) {
        tap_code16(KC_N);
    }
}

void ctl_n_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP: register_code16(KC_N); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_N)); break;
        case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
    }
}

void ctl_n_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP: unregister_code16(KC_N); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_N)); break;
        case DOUBLE_TAP: unregister_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
    }
    dance_state[29].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_i(qk_tap_dance_state_t *state, void *user_data);
void ctl_i_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_i_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_i(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if(state->count > 3) {
        tap_code16(KC_I);
    }
}

void ctl_i_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP: register_code16(KC_I); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_I)); break;
        case DOUBLE_TAP: register_code16(KC_I); register_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_I); register_code16(KC_I);
    }
}

void ctl_i_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP: unregister_code16(KC_I); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_I)); break;
        case DOUBLE_TAP: unregister_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_I); break;
    }
    dance_state[30].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_o(qk_tap_dance_state_t *state, void *user_data);
void ctl_o_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_o_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_o(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

void ctl_o_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_O)); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void ctl_o_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP: unregister_code16(KC_O); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_O)); break;
        case DOUBLE_TAP: unregister_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
    }
    dance_state[31].step = 0;
}


//-------------------------------------------------------------------------------
void on_ctl_k(qk_tap_dance_state_t *state, void *user_data);
void ctl_k_finished(qk_tap_dance_state_t *state, void *user_data);
void ctl_k_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctl_k(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void ctl_k_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_K)); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void ctl_k_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[32].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [CMD_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_f, cmd_f_finished, cmd_f_reset),
        [CMD_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_p, cmd_p_finished, cmd_p_reset),
        [CMD_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_b, cmd_b_finished, cmd_b_reset),
        [TAB_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(on_tab_esc, tab_esc_finished, tab_esc_reset),
        [CMD_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_s, cmd_s_finished, cmd_s_reset),
        [CMD_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_t, cmd_t_finished, cmd_t_reset),
        [SFTPRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_sftprn, sftprn_finished, sftprn_reset),
        [CMD_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_z, cmd_z_finished, cmd_z_reset),
        [CMD_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_x, cmd_x_finished, cmd_x_reset),
        [CMD_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_c, cmd_c_finished, cmd_c_reset),
        [CMD_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_v, cmd_v_finished, cmd_v_reset),
        [CMD_U] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_u, cmd_u_finished, cmd_u_reset),
        [CMD_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_n, cmd_n_finished, cmd_n_reset),
        [CMD_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_i, cmd_i_finished, cmd_i_reset),
        [CMD_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_o, cmd_o_finished, cmd_o_reset),
        [CMD_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_cmd_k, cmd_k_finished, cmd_k_reset),
        [UP] = ACTION_TAP_DANCE_FN_ADVANCED(on_up, up_finished, up_reset),
        [DWN] = ACTION_TAP_DANCE_FN_ADVANCED(on_dwn, dwn_finished, dwn_reset),
        [ENTER] = ACTION_TAP_DANCE_FN_ADVANCED(on_enter, enter_finished, enter_reset),
        [CTL_F] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_f, ctl_f_finished, ctl_f_reset),
        [CTL_P] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_p, ctl_p_finished, ctl_p_reset),
        [CTL_B] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_b, ctl_b_finished, ctl_b_reset),
        [CTL_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_s, ctl_s_finished, ctl_s_reset),
        [CTL_T] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_t, ctl_t_finished, ctl_t_reset),
        [CTL_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_z, ctl_z_finished, ctl_z_reset),
        [CTL_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_x, ctl_x_finished, ctl_x_reset),
        [CTL_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_c, ctl_c_finished, ctl_c_reset),
        [CTL_V] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_v, ctl_v_finished, ctl_v_reset),
        [CTL_U] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_u, ctl_u_finished, ctl_u_reset),
        [CTL_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_n, ctl_n_finished, ctl_n_reset),
        [CTL_I] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_i, ctl_i_finished, ctl_i_reset),
        [CTL_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_o, ctl_o_finished, ctl_o_reset),
        [CTL_K] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctl_k, ctl_k_finished, ctl_k_reset),
};
