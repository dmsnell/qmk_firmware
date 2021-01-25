#include QMK_KEYBOARD_H
#include "version.h"

#define ____ KC_TRANSPARENT
#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

#define ___ {0,0,0}       // Clear
#define _RED {0,194,237}   // Red
#define _GRN {86,244,174}  // Green
#define _LGR {109,51,209}  // Light Green
#define _BLU {141,255,233} // Blue
#define _YLW {41, 179, 222} // Yellow

enum layer_names {
  _L_BASE = 0,
  _L_SYMBOLS,
  _L_MOUSE,
  _L_MOUSE_SCROLL,
  _L_COMMAND,
  _L_ERLANG,
};

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  _M_EXPOSE,                  // macOS Exposé
  _M_TAB_CHAR,                // for entering tab characters in browsers which otherwise move to the next input field
  _M_UNICODE,                 // macOS Unicode Picker panel
  _M_CURLIES,                 // {}
  _M_PARENS,                  // ()
  _M_SQUARES,                 // []
  _M_ERL_EXPORT,              // -export([]).
  _M_ERL_MAP,                 // #{}
  _M_ERL_BIN,                 // <<"">>
  _M_ERL_C1,                  // % - one level of Erlang commenting (line)
  _M_ERL_C2,                  // %% - two levels of Erlang commenting (function)
  _M_ERL_C3,                  // %%% - three levels of Erlang commenting (module)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_L_BASE] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_ESCAPE,                            _M_TAB_CHAR,    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    LT(_L_ERLANG,KC_DELETE),KC_Q,   KC_W,           KC_E,           KC_R,           KC_T,           _M_EXPOSE,                            KC_TAB,         KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    LT(_L_SYMBOLS,KC_TAB),KC_A,     KC_S,           KC_D,           KC_F,           KC_G,                                                                 KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      LT(_L_MOUSE,KC_QUOTE),
    KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           LT(_L_COMMAND, KC_ENTER),             KC_ENTER,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),KC_RSPC,
    KC_LCTRL,       WEBUSB_PAIR,    LALT(KC_LSHIFT),KC_LEFT,        KC_RIGHT,                                                                                             KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    _M_UNICODE,
                                                                                                    KC_LALT,        KC_HOME,        KC_PGUP,        KC_RALT,
                                                                                                                    KC_END,         KC_PGDOWN,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_LGUI,        KC_RGUI,        KC_BSPACE,      KC_SPACE
  ),
  [_L_SYMBOLS] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ____,                                 KC_HASH,        KC_F6,          KC_F7,          KC_F8,          KC_F9,           KC_F10,         KC_F11,
    ____,           KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        ____,                                 ____,           KC_UP,          KC_P7,          KC_P8,          KC_P9,           KC_PAST,        KC_F12,
    ____,           KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                                                             KC_DOWN,        KC_P4,          KC_P5,          KC_P6,           KC_PPLS,        ____,
    ____,           KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        ____,                                 ____,           KC_PMNS,        KC_P1,          KC_P2,          KC_P3,           KC_BSLASH,      ____,
    ____,           KC_EQUAL,       ____,           ____,           ____,                                                                                                 KC_P0,          KC_P0,          KC_PDOT,         KC_EQUAL,       ____,
                                                                                                    RGB_MOD,        _M_CURLIES,     RGB_TOG,        RGB_SLD,
                                                                                                                    _M_PARENS,      ____,
                                                                                    RGB_VAD,        RGB_VAI,        _M_SQUARES,     ____,           ____,           ____
  ),
  [_L_MOUSE] = LAYOUT_ergodox_pretty(
    ____,           ____,           ____,           ____,           ____,           ____,           ____,                                 ____,           ____,           ____,           ____,           ____,           ____,           RESET,
    ____,           ____,           ____,           KC_MS_UP,       ____,           ____,           ____,                                 KC_BRIGHTNESS_UP,____,          ____,           ____,           ____,           ____,           ____,
    LT(_L_MOUSE_SCROLL,KC_NO),____, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    ____,                                                                 ____,           ____,           ____,           ____,           ____,           ____,
    ____,           ____,           ____,           ____,           ____,           ____,           ____,                                 KC_BRIGHTNESS_DOWN,KC_MEDIA_STOP,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,____,____,
    ____,           WEBUSB_PAIR,    ____,           KC_MS_BTN2,     KC_MS_BTN1,                                                                                           KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,____,           ____,
                                                                                                    ____,           ____,           ____,           ____,
                                                                                                                    ____,           ____,
                                                                                    ____,           ____,           ____,           ____,           ____,           KC_WWW_BACK
  ),
  [_L_MOUSE_SCROLL] = LAYOUT_ergodox_pretty(
    ____,           ____,           ____,           ____,           ____,           ____,           ____,                                 ____,           ____,           ____,           ____,           ____,           ____,           ____,
    ____,           ____,           ____,           KC_MS_WH_UP,    ____,           ____,           ____,                                 ____,           ____,           ____,           ____,           ____,           ____,           ____,
    ____,           ____,           KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_RIGHT, ____,                                                                 ____,           ____,           ____,           ____,           ____,           ____,
    ____,           ____,           ____,           ____,           ____,           ____,           ____,                                 ____,           ____,           ____,           ____,           ____,           ____,           ____,
    ____,           ____,           ____,           ____,           ____,                                                                                                 ____,           ____,           ____,           ____,           ____,
                                                                                                    DYN_MACRO_PLAY1,DYN_REC_START1, ____,           ____,
                                                                                                                    DYN_REC_STOP,   ____,
                                                                                    ____,           ____,           ____,           ____,           ____,           ____
  ),
  [_L_COMMAND] = LAYOUT_ergodox_pretty(
    MAGIC_TOGGLE_NKRO,TO(_L_BASE),  TO(_L_SYMBOLS), TO(_L_MOUSE),   TO(_L_MOUSE_SCROLL),TO(_L_COMMAND),TO(_L_ERLANG),                     ____,           ____,           ____,           ____,           ____,           WEBUSB_PAIR,    ____,
    ____,           ____,           ____,           ____,           ____,           ____,           ____,                                 ____,           ____,           ____,           KC_UP,          ____,           ____,           ____,
    ____,           ____,           ____,           ____,           ____,           ____,                                                                 ____,           KC_LEFT,        KC_DOWN,        KC_RIGHT,       ____,           ____,
    ____,           ____,           ____,           ____,           ____,           ____,           ____,                                 ____,           ____,           ____,           ____,           ____,           ____,           ____,
    ____,           ____,           ____,           ____,           ____,                                                                                                 ____,           ____,           ____,           ____,           ____,
                                                                                                    ____,           ____,           ____,           ____,
                                                                                                                    ____,           ____,
                                                                                    ____,           ____,           ____,           ____,           ____,           ____
  ),
  [_L_ERLANG] = LAYOUT_ergodox_pretty(
    ____,           ____,           ____,           ____,           ____,           ____,           ____,                                 ____,           _M_ERL_C1,      _M_ERL_C2,      _M_ERL_C3,      ____,           ____,           ____,
    ____,           ____,           ____,           _M_ERL_EXPORT,  ____,           ____,           ____,                                 _M_ERL_MAP,     ____,           ____,           ____,           ____,           ____,           ____,
    ____,           ____,           ____,           ____,           ____,           ____,                                                                 ____,           ____,           ____,           ____,           ____,           ____,
    ____,           ____,           ____,           ____,           ____,           ____,           ____,                                 _M_ERL_BIN,     ____,           ____,           ____,           ____,           ____,           ____,
    ____,           ____,           ____,           ____,           ____,                                                                                                 ____,           ____,           ____,           ____,           ____,
                                                                                                    ____,           ____,           ____,           ____,
                                                                                                                    ____,           ____,
                                                                                    ____,           ____,           ____,           ____,           ____,           ____
  ),
};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][5] = {
    // [_L_LAYER] = LED_LAYOUT_ergodox_pretty(
    //   ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
    //   ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
    //   ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
    //   ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
    //   ___,  ___,  ___,  ___,                    ___,  ___,  ___,  ___
    // ),
    [_L_SYMBOLS] = LED_LAYOUT_ergodox_pretty(
      ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  _BLU, _RED, _RED, ___,        _RED, _BLU, _BLU, _BLU, _YLW,
      _BLU, ___,  _YLW, _YLW, ___,        _RED, _BLU, _BLU, _BLU, _YLW,
      _BLU, ___,  _GRN, _GRN, ___,        _YLW, _BLU, _BLU, _BLU, _YLW,
      ___,  ___,  ___,  ___,                    _BLU, _BLU, _YLW, _YLW
    ),

    [_L_MOUSE] = LED_LAYOUT_ergodox_pretty(
      ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  _BLU, ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  _BLU, _BLU, _BLU, ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  _BLU, _BLU,                   ___,  ___,  ___,  ___
    ),

    [_L_MOUSE_SCROLL] = LED_LAYOUT_ergodox_pretty(
      ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  _YLW, ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  _YLW, _YLW, _YLW, ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,                    ___,  ___,  ___,  ___
    ),

    [_L_COMMAND] = LED_LAYOUT_ergodox_pretty(
      _BLU, _BLU, _BLU, _BLU, _BLU,       ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,  ___,        ___,  ___,  _GRN, ___,  ___,
      ___,  ___,  ___,  ___,  ___,        ___,  _GRN, _GRN, _GRN, ___,
      ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,                    ___,  ___,  ___,  ___
    ),

    [_L_ERLANG] = LED_LAYOUT_ergodox_pretty(
      ___,  ___,  ___,  ___,  ___,        _LGR, _LGR, _LGR, ___,  ___,
      ___,  ___,  _RED, ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,  ___,        ___,  ___,  ___,  ___,  ___,
      ___,  ___,  ___,  ___,                    ___,  ___,  ___,  ___
    ),
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
    if (g_suspend_state || keyboard_config.disable_layer_led) {
      return;
    }

    uint8_t layer = biton32(layer_state);
    switch (layer) {
    case _L_SYMBOLS:
    case _L_MOUSE:
    case _L_MOUSE_SCROLL:
    case _L_COMMAND:
    case _L_ERLANG:
        set_layer_color(layer);
        break;

    default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
            rgb_matrix_set_color_all(0, 0, 0);
        }
        break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _M_EXPOSE:
        if (record->event.pressed) {
          SEND_STRING(SS_RCTL(SS_TAP(X_UP)));
        }
        break;

    case _M_TAB_CHAR:
        if (record->event.pressed) {
          SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_TAB))));
        }
        break;

    case _M_UNICODE:
        if (record->event.pressed) {
          SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_SPACE))));
        }
        break;

    case _M_CURLIES:
        if (record->event.pressed) {
          SEND_STRING("{}");
        }
        break;

    case _M_PARENS:
        if (record->event.pressed) {
          SEND_STRING("()");
        }
        break;

    case _M_SQUARES:
        if (record->event.pressed) {
            SEND_STRING("[]");
        }
        break;

    case _M_ERL_EXPORT:
        if (record->event.pressed) {
            SEND_STRING("-EXPORT([])." SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        break;

    case _M_ERL_MAP:
        if (record->event.pressed) {
            SEND_STRING("#{}" SS_TAP(X_LEFT));
        }
        break;

    case _M_ERL_BIN:
        if (record->event.pressed) {
            SEND_STRING("<<\"\">>" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        break;

    case _M_ERL_C1:
        if (record->event.pressed) {
            SEND_STRING("% ");
        }
        break;

    case _M_ERL_C2:
        if (record->event.pressed) {
            SEND_STRING("%% ");
        }
        break;

    case _M_ERL_C3:
        if (record->event.pressed) {
            SEND_STRING("%%% ");
        }
        break;

    case RGB_SLD:
        if (record->event.pressed) {
          rgblight_mode(1);
        }
        return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
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
