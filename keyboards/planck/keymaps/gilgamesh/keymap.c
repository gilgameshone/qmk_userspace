/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "sendstring_japanese.h"

#ifdef AUDIO_ENABLE
#include "muse.h"
#endif

enum planck_layers {
    _MAGICSTURDY,
    _QWERTY,
    _TRON_BASE,
    _TRON_RED,
    _TRON_BLUE,
    _TRON_PURPLE,
    _NUM,
    _NAV,
    _EXT,
    _FUN,
    _WIN,
};

#define NUM LT(_NUM,KC_BSPC)
#define EXT LT(_EXT,KC_SPC)
#define FUN MO(_FUN)

#define PASTE G(KC_V)

#define TRON_NUM LT(_NUM,KC_BSPC)
#define TRON_NAV MO(_NAV)
#define TRON_SPC LT(_TRON_RED,KC_SPC)
#define TRON_RET LT(_TRON_BLUE,KC_ENT)


// magic sturdy Left-hand home row mods
#define HSCTL_D LCTL_T(KC_D)
#define HSCMD_R LGUI_T(KC_R)
#define HSOPT_T LALT_T(KC_T)
#define HSSFT_S LSFT_T(KC_S)
#define HSHYP_G HYPR_T(KC_G)

// magic sturdy Right-hand home row mods
#define HSCTL_N RCTL_T(KC_N)
#define HSCMD_E RGUI_T(KC_E)
#define HSOPT_A RALT_T(KC_A)
#define HSSFT_I RSFT_T(KC_I)
#define HSHYP_H HYPR_T(KC_H)


// TRON Left-hand home row mods // defunct
#define HCTL_TJ_TE TJ_TE
#define HCMD_TJ_KA TJ_KA
#define HOPT_TJ_TO TJ_TO
#define HSFT_TJ_TA TJ_TA


// TRON Right-hand home row mods // defunct
#define HCTL_TJ_I TJ_I
#define HCMD_TJ_U TJ_U
#define HOPT_TJ_SHI TJ_SHI
#define HSFT_TJ_NN TJ_NN



// This keymap uses Ikcelaks' Magic Sturdy layout for the base layer (see
// https://github.com/Ikcelaks/keyboard_layouts). Getreuer also made some twists of
// his own, along with myself. The "magic" is a key whose function depends on the last pressed key,
// implemented using the Alternate Repeat Key. This key is used to remove the
// top SFBs and type common n-grams.
//
// The following describes the functionality, where * is the magic key and @ the
// repeat key. For example, tapping A and then the magic key types "ao".
//
// SFB removal and common n-grams:
//
//     A * -> AO     L * -> LR      
//     C * -> CY     M * -> MT      T * -> TM
//     D * -> DY     O * -> OA      U * -> UE
//     E * -> EU     P * -> PY      V * -> VS      
//     G * -> GY     R * -> RL      X * -> XT
//                   
//


uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_C: return KC_Y;
        case KC_P: return KC_Y;
        case HSCTL_D: return KC_Y;
        case HSHYP_G: return KC_Y;
        case HSCMD_R: return KC_L;
        case KC_L: return KC_R;
        case KC_U: return KC_E;
        case HSCMD_E: return KC_U;
        case KC_O: return KC_A;
        case HSOPT_A: return KC_O;
        case KC_X: return KC_T;
        case KC_M: return KC_T;
        case HSOPT_T: return KC_M;
        case KC_V: return KC_S;
    }
    return KC_TRNS; 
}


//tron japanese laid over JIS kana

#define TJ_RA JP_O
#define TJ_RU JP_DOT
#define TJ_KO JP_B
#define TJ_HA JP_F
#define TJ_XYO S(JP_9)
#define TJ_KI JP_G
#define TJ_NO JP_K
#define TJ_KU JP_H
#define TJ_A JP_3
#define TJ_RE JP_SCLN
#define TJ_TA JP_Q
#define TJ_TO JP_S
#define TJ_KA JP_T
#define TJ_TE JP_W
#define TJ_MO JP_M
#define TJ_WO S(JP_0)
#define TJ_I JP_E
#define TJ_U JP_4
#define TJ_SHI JP_D
#define TJ_NN JP_Y
#define TJ_MA JP_J
#define TJ_RI JP_L
#define TJ_NI JP_I
#define TJ_SA JP_X
#define TJ_NA JP_U
#define TJ_SU JP_R
#define TJ_TSU JP_Z
#define TJ_DOUTEN S(JP_COMM)
#define TJ_KUTEN S(JP_DOT)
#define TJ_XTSU S(JP_Z)
#define TJ_HI JP_V
#define TJ_SO JP_C
#define TJ_NAKAGURO S(JP_SLSH)
#define TJ_XYA S(JP_7)
#define TJ_HO JP_MINS
#define TJ_E JP_5
#define TJ_KE JP_COLN
#define TJ_ME JP_SLSH
#define TJ_MU JP_RBRC
#define TJ_RO JP_UNDS
#define TJ_NU JP_1
#define TJ_NE JP_COMM
#define TJ_XYU S(JP_8)
#define TJ_YO JP_9
#define TJ_FU JP_2
#define TJ_O JP_6
#define TJ_CHI JP_A
#define TJ_CHOUONNPU JP_YEN
#define TJ_MI JP_N
#define TJ_YA JP_7
#define TJ_XE S(JP_5)
#define TJ_XO S(JP_6)
#define TJ_SE JP_P
#define TJ_YU JP_8
#define TJ_HE JP_CIRC
#define TJ_WA JP_0
#define TJ_XI S(JP_E)
#define TJ_XA S(JP_3)
#define TJ_XU S(JP_4)




// magic sturdy

#define C_MAGIC QK_AREP


// super cmd tab
bool is_cmd_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t cmd_tab_timer = 0;     // we will be using them soon.

enum custom_keycodes {
    GOOGL = SAFE_RANGE,
    GTRNS,
    DFINE,
    TJ_GI,
    TJ_GE,
    TJ_GU,
    TJ_DI,
    TJ_DZI,
    TJ_VU,
    TJ_JI,
    TJ_ZU,
    TJ_DZU,
    TJ_BI,
    TJ_ZO,
    TJ_GO,
    TJ_BA,
    TJ_BO,
    TJ_DA,
    TJ_DO,
    TJ_GA,
    TJ_DE,
    TJ_BU,
    TJ_ZE,
    TJ_ZA,
    TJ_BE,
    TJ_PA,
    TJ_PI,
    TJ_PU,
    TJ_PE,
    TJ_PO,
    TJ_LKAGIKAKO,
    TJ_RKAGIKAKO,
    _KANA,
    _EISU,
};

// TAP DANCE
// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    OSS_NAV, // Our custom tap dance key; add any other tap dance keys to this enum 
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);

// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { 
    // lang switching
  case _EISU:
    if (record->event.pressed) {
      tap_code(KC_LNG2);
    }
    else {
      layer_move(_MAGICSTURDY);
    }
    return false;
  case _KANA:
    if (record->event.pressed) {
      tap_code(KC_LNG1);
    }
    else {
      layer_move(_TRON_BASE);
    }
    return false;
    // TJ_GI,
  case TJ_GI:
    if (record->event.pressed) {
      // when keycode TJ_GI is pressed
      SEND_STRING(SS_TAP(X_G));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_GE,
  case TJ_GE:
    if (record->event.pressed) {
      tap_code(KC_QUOT);
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_GU,
  case TJ_GU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_H));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DZI,
  case TJ_DZI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_A));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_VU,
  case TJ_VU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_4));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_JI,
  case TJ_JI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_D));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_ZU,
  case TJ_ZU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_R));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DZU,
  case TJ_DZU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Z));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_BI,
  case TJ_BI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_V));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_ZO,
  case TJ_ZO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_GO,
  case TJ_GO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_B));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_BA,
  case TJ_BA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_BO,
  case TJ_BO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINS));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DA,
  case TJ_DA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Q));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DO,
  case TJ_DO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_GA,
  case TJ_GA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DE,
  case TJ_DE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_W));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_BU,
  case TJ_BU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_2));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_ZE,
  case TJ_ZE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_P));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_ZA,
  case TJ_ZA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_X));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;

    // TJ_BE,
  case TJ_BE:
    if (record->event.pressed) {
      tap_code(KC_EQL);
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;

    // TJ_PA,
  case TJ_PA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F));
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_PI,
  case TJ_PI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_V));
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_PU,
  case TJ_PU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_2));
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_PE,
  case TJ_PE:
    if (record->event.pressed) {
      tap_code(KC_EQL);
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_PO,
  case TJ_PO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINS));
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_LKAGIKAKO,
  case TJ_LKAGIKAKO:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_RBRC) SS_UP(X_LSFT));
    } else {
      //
    }
    return false;
    // TJ_RKAGIKAKO,
  case  TJ_RKAGIKAKO:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_NUHS) SS_UP(X_LSFT));
    } else {
      //
    }
    return false;

    // other macros
  case GOOGL:
    if (record->event.pressed) {
      // when keycode GOOGL is pressed
      SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_C)
                  SS_UP(X_LCMD));  // command C
      SEND_STRING(SS_DOWN(X_LCMD)  SS_TAP(X_SPC) SS_UP(X_LCMD));  // open alfred
      wait_ms(50);
      SEND_STRING(SS_TAP(X_G) SS_TAP(X_SPC));  // tap G
      SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_V) SS_UP(X_LCMD)
                  SS_TAP(X_ENT));  // command V + enter
    } else {
      // when keycode GOOGL is released
    }
    return false;
  case GTRNS:
    if (record->event.pressed) {
      // when keycode GTRNS is pressed
      SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_C)
                  SS_UP(X_LCMD));  // command C
      SEND_STRING(SS_DOWN(X_LCMD)  SS_TAP(X_SPC) SS_UP(X_LCMD));  // open alfred
      wait_ms(50);
      SEND_STRING(SS_TAP(X_T) SS_TAP(X_SPC));  // tap T
      SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_V) SS_UP(X_LCMD)
                  SS_TAP(X_ENT));  // command V + enter
    } else {
      // when keycode GTRNS is released
    }
    return false;
  case DFINE:
    if (record->event.pressed) {
      // when keycode DFINE is pressed
      SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_C)
                  SS_UP(X_LCMD));  // command C
      SEND_STRING(SS_DOWN(X_LCMD)  SS_TAP(X_SPC) SS_UP(X_LCMD));  // open alfred
      wait_ms(200);
      SEND_STRING(SS_TAP(X_D) SS_TAP(X_SPC));  // tap D
      SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_V)
                  SS_UP(X_LCMD));  // command V
      wait_ms(200);                     // wait
      SEND_STRING(SS_TAP(X_ENT));      // enter
    } else {
      // when keycode DFINE is released
    }
     return false;
     
  }
  return true;
}






// combos

const uint16_t PROGMEM combo_capsword[] = {EXT, QK_REP, COMBO_END};
const uint16_t PROGMEM combo_qkboot[] = {KC_X, HSSFT_S, KC_V, COMBO_END};
const uint16_t PROGMEM combo_qkreboot[] = {KC_P, KC_Y, KC_W, COMBO_END};
const uint16_t PROGMEM combo_qkeeprom[] = {KC_C, HSCTL_D, KC_G, COMBO_END};
const uint16_t PROGMEM combo_fun[] = {EXT, NUM, COMBO_END};
const uint16_t PROGMEM combo_win[] = {QK_REP, TD(OSS_NAV), COMBO_END};
const uint16_t PROGMEM combo_sorcery[] = {KC_C, QK_AREP, COMBO_END};
const uint16_t PROGMEM combo_back_char[] = {HSHYP_G, KC_J, COMBO_END};
const uint16_t PROGMEM combo_for_char[] = {HSHYP_H, JP_COMM, COMBO_END};
const uint16_t PROGMEM combo_back_word[] = {KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM combo_for_word[] = {KC_COMM, JP_DOT, COMBO_END};
const uint16_t PROGMEM combo_back_sent[] = {KC_K, HSHYP_G, COMBO_END};
const uint16_t PROGMEM combo_for_sent[] = {HSHYP_H, JP_DOT, COMBO_END};
const uint16_t PROGMEM combo_pre_line[] = {HSCTL_D, KC_J, COMBO_END};
const uint16_t PROGMEM combo_next_line[] = {HSCTL_N, JP_COMM, COMBO_END};
const uint16_t PROGMEM combo_pre_para[] = {HSOPT_T,  KC_J, COMBO_END};
const uint16_t PROGMEM combo_next_para[] = {HSOPT_A, JP_COMM, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_capsword, CW_TOGG),
  COMBO(combo_qkboot, QK_BOOT),
  COMBO(combo_qkeeprom, EE_CLR),
  COMBO(combo_qkreboot, QK_RBT),
  COMBO(combo_fun, MO(_FUN)),
  COMBO(combo_win, MO(_WIN)),
  COMBO(combo_sorcery, S(KC_NUBS)),
  COMBO(combo_back_char, KC_LEFT),
  COMBO(combo_for_char, KC_RGHT),
  COMBO(combo_back_word, A(KC_LEFT)),
  COMBO(combo_for_word, A(KC_RGHT)),
  COMBO(combo_back_sent, KC_HOME),
  COMBO(combo_for_sent, KC_END),
  COMBO(combo_pre_line, KC_UP),
  COMBO(combo_next_line, KC_DOWN),
  COMBO(combo_pre_para, A(KC_UP)),
  COMBO(combo_next_para, A(KC_DOWN)),
};

// caps word

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case JP_UNDS:
        case JP_MINS:
        case JP_AMPR:
          return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}



// key overides
// SHIFT + ' = "
const key_override_t comm_quo_override = ko_make_basic(MOD_MASK_SHIFT, JP_COMM, JP_QUOT);
const key_override_t dot_dquo_override = ko_make_basic(MOD_MASK_SHIFT, JP_DOT, JP_DQUO);
const key_override_t min_ques_override = ko_make_basic(MOD_MASK_SHIFT, JP_MINS, JP_QUES);


const key_override_t **key_overrides = (const key_override_t *[]){
    &comm_quo_override,
    &dot_dquo_override,
    &min_ques_override,
    NULL
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAGICSTURDY] = LAYOUT_planck_grid(
           KC_X,     KC_M,    KC_L,    KC_C, KC_P,  RGB_TOG, RGB_MOD, KC_B,  QK_AREP,    KC_U,    KC_O,    KC_Q,
        HSSFT_S,  HSOPT_T, HSCMD_R, HSCTL_D, KC_Y,  RGB_HUI, RGB_HUD, KC_F,  HSCTL_N, HSCMD_E, HSOPT_A, HSSFT_I,
           KC_V,     KC_K,    KC_J, HSHYP_G, KC_W,  RGB_SAI, RGB_SAD, KC_Z,  HSHYP_H, JP_COMM, JP_DOT,  JP_MINS,
         XXXXXXX, XXXXXXX,  _______,     NUM,  EXT, XXXXXXX, XXXXXXX, QK_REP,  TD(OSS_NAV), _______, RGB_VAI, RGB_VAD
  ),
  [_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, JP_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    JP_COMM, JP_DOT,  JP_SLSH, KC_ENT ,
    QK_REP, KC_LCTL, KC_LALT, KC_LGUI, NUM,  EXT,  KC_SPC,  TD(OSS_NAV),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
                                   ),
  [_TRON_BASE] = LAYOUT_planck_grid(
        TJ_RA,   TJ_RU,   TJ_KO,   TJ_HA,  TJ_XYO, XXXXXXX,XXXXXXX,  TJ_KI,   TJ_NO,   TJ_KU,    TJ_A,   TJ_RE,
        TJ_TA,   TJ_TO,   TJ_KA,   TJ_TE,   TJ_MO, XXXXXXX,XXXXXXX,   TJ_WO,    TJ_I,    TJ_U,  TJ_SHI,   TJ_NN,
        TJ_MA,   TJ_RI,   TJ_NI,   TJ_SA,   TJ_NA, XXXXXXX,XXXXXXX,   TJ_SU,  TJ_TSU,TJ_DOUTEN,TJ_KUTEN,TJ_XTSU,
        XXXXXXX,XXXXXXX,  _______,  TRON_NUM, TRON_SPC, XXXXXXX,XXXXXXX, TRON_RET, TRON_NAV,  _______, XXXXXXX,XXXXXXX
                                    ),
  [_TRON_BLUE] = LAYOUT_planck_grid(
        TJ_BI,   TJ_ZO,   TJ_GO,  TJ_BA,    TJ_BO, XXXXXXX,XXXXXXX,    TJ_E,   TJ_KE,   TJ_ME,   TJ_MU,  TJ_RO,
        TJ_DA,   TJ_DO,   TJ_GA,  TJ_DE,    TJ_BU, XXXXXXX,XXXXXXX,     TJ_O,  TJ_CHI,TJ_CHOUONNPU,TJ_MI,  TJ_YA,
        TJ_XE,   TJ_XO,    TJ_ZE,  TJ_ZA,   TJ_BE, XXXXXXX,XXXXXXX,     TJ_WA,   TJ_XI,   TJ_XA, _______,   TJ_XU,
        XXXXXXX,XXXXXXX,   _______,  _______, MO(_TRON_PURPLE),XXXXXXX,XXXXXXX,       _______, _______, _______,XXXXXXX,XXXXXXX
                                    ),
  [_TRON_RED] = LAYOUT_planck_grid(
          TJ_HI,   TJ_SO,TJ_NAKAGURO,TJ_XYA,  TJ_HO,  XXXXXXX,XXXXXXX,     TJ_GI,   TJ_GE,  TJ_GU,  _______, _______,
        TJ_NU,   TJ_NE,  TJ_XYU,   TJ_YO,   TJ_FU,  XXXXXXX,XXXXXXX,     TJ_O,  TJ_DZI,  TJ_VU,    TJ_JI, _______,
        TJ_XE,   TJ_XO,   TJ_SE,   TJ_YU,   TJ_HE,  XXXXXXX,XXXXXXX,    TJ_ZU,  TJ_DZU,TJ_LKAGIKAKO,TJ_RKAGIKAKO, TJ_XU,
        XXXXXXX,XXXXXXX,   _______,  _______, _______,  XXXXXXX,XXXXXXX,     MO(_TRON_PURPLE), _______, _______,XXXXXXX,XXXXXXX
                                   ),
  [_TRON_PURPLE] = LAYOUT_planck_grid(
       TJ_PI, _______, _______,   TJ_PA,   TJ_PO,   XXXXXXX,XXXXXXX,    _______, _______, _______, _______,    _______,
      _______, _______, _______, _______,   TJ_PU,   XXXXXXX,XXXXXXX,   KC_SPC, C(JP_J), C(JP_K), C(JP_L), C(JP_SCLN),
      _______, _______, _______, _______,   TJ_PE,   XXXXXXX,XXXXXXX,   _______,  KC_ENT, _______, _______,    _______,
     XXXXXXX,XXXXXXX,     _______, _______, _______,   XXXXXXX,XXXXXXX,    _______, _______, _______,XXXXXXX,XXXXXXX
                                    ),

  [_NUM] = LAYOUT_planck_grid(
      JP_EXLM, JP_LBRC, JP_RBRC, JP_COLN, C(KC_F2), AU_PREV, AU_NEXT,   JP_PLUS,  KC_7, KC_8, KC_9, JP_ASTR,
      JP_AMPR, JP_LPRN, JP_RPRN, JP_SCLN, JP_AT,  MU_ON,   MU_OFF,  JP_MINS,  KC_4, KC_5, KC_6, JP_SLSH,
      JP_QUES, JP_UNDS, JP_DQUO, JP_QUOT, JP_PIPE, MI_ON,   MI_OFF,   JP_EQL,   KC_1, KC_2, KC_3,  KC_DOT,
      XXXXXXX,XXXXXXX,  _______,     NUM,  _______, XXXXXXX,XXXXXXX,  KC_ENT,  KC_0, _______, XXXXXXX,XXXXXXX
                              ), 
  [_NAV] = LAYOUT_planck_grid(
      G(KC_Z), G(KC_X), G(KC_C), PASTE,   LSG(KC_Z), AU_ON,   AU_OFF,     LSG(KC_5), KC_LNG2,   _EISU,   _KANA, KC_LNG1,
      KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT,   XXXXXXX,  AG_NORM, AG_SWAP,     _______, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
      KC_HOME, KC_PGUP, KC_PGDN, KC_END,    XXXXXXX,  MU_NEXT, XXXXXXX,    HYPR(KC_B), KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE,
      XXXXXXX, XXXXXXX,    _______, KC_ESC,     KC_TAB, XXXXXXX, XXXXXXX,   _______, _______, _______, XXXXXXX, XXXXXXX
                              ),
  [_EXT] = LAYOUT_planck_grid(
      _______,   _______, G(KC_C),    PASTE,  S(LAG(KC_V)), XXXXXXX,XXXXXXX,  LSA(JP_8),  JP_HASH, JP_LABK, JP_RABK,   JP_CIRC,
       _______, A(KC_DEL), _______,       KC_DEL, HYPR(KC_Y),XXXXXXX,XXXXXXX,  JP_TILD,  JP_PERC, JP_LCBR, JP_RCBR,    JP_GRV,
       JP_CAPS,     DFINE,   GTRNS,        GOOGL,    _______, XXXXXXX,XXXXXXX,  KC_NUBS,   JP_YEN,  JP_DLR, A(JP_3), LSA(JP_2),
      XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,XXXXXXX,   _______,  _______, _______, XXXXXXX,XXXXXXX
                              ),

  [_FUN] = LAYOUT_planck_grid(
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_NUM, XXXXXXX,XXXXXXX,  KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
      XXXXXXX, XXXXXXX, XXXXXXX, DF(_QWERTY),       KC_INS, XXXXXXX,XXXXXXX,  KC_SCRL,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
      XXXXXXX, XXXXXXX, XXXXXXX, DF(_MAGICSTURDY), XXXXXXX,XXXXXXX,XXXXXXX, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
     XXXXXXX,XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX
                              ),
  [_WIN] = LAYOUT_planck_grid(
      MEH(KC_X), MEH(KC_M), MEH(KC_L),  MEH(KC_C),  MEH(KC_P), XXXXXXX,XXXXXXX,  _______, _______, _______, _______, _______,
      MEH(KC_S), MEH(KC_T), MEH(KC_R),  MEH(KC_D),  MEH(KC_Y), XXXXXXX,XXXXXXX,  _______, _______, _______, _______, _______,
      MEH(KC_V), MEH(KC_K), MEH(KC_J),  MEH(KC_G),  MEH(KC_W), XXXXXXX,XXXXXXX,  _______, _______, _______, _______, _______, 
      XXXXXXX,XXXXXXX,  _______,   _______,  MEH(KC_SPC), XXXXXXX,XXXXXXX,  _______, _______, _______, XXXXXXX,XXXXXXX
                              )
};



// TAP DANCE 

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } 
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            set_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NAV);
            break;      
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_NAV);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [OSS_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM:
            return TAPPING_TERM - 80;
        case EXT:
            return TAPPING_TERM - 50;
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 200;       
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case NUM:
    // Immediately select the hold action when another key is tapped.
    return true;
  case EXT:
    return true;
  default :
    // Do not select the hold action when another key is tapped.
    return false;
  }
  return true;
}
