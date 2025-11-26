/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 Gilgamesh @gilgamesh_one@mastodon.world

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_japanese.h"
#include "sendstring_japanese.h"
#include "features/select_word.h"



enum crkbd_layers {
    _MAGICSTURDY,
    _QWERTY,
    _TRON_BASE,
    _TRON_RED,
    _TRON_BLUE,
    _TRON_PURPLE,
    _TRON_NUM,
    _TRON_SYM,
    _NUM,
    _NAV,
    _SYM,
    _FUN,
    _NUM_W,
    _SORCERY,
    _WIN,
};

#define NUM LT(_NUM,KC_BSPC)
#define SYM LT(_SYM,KC_SPC)
#define OSS TD(OSS_NAV) // not used in this branch
#define SS OSM(MOD_LSFT)

#define FUN MO(_FUN)

#define PASTE G(KC_V)
#define COPY G(KC_C)
#define CUT G(KC_X)
#define PASTEW S(LAG(KC_V))
#define UNDO  G(KC_Z) 
#define REDO  S(G(KC_Z)) 

#define PRINTSCR  S(G(KC_3))
#define PRINTSEL  S(G(KC_4))
#define PRINTALT  S(G(KC_5))

#define HIRAGANA  C(KC_J)
#define KATAKANA  C(KC_K)

#define SAVE G(KC_S)

#define WINMIN G(KC_H)
#define WINMAX MEH(KC_SPC)
#define WINLEFT MEH(KC_S) 
#define WINRIGHT MEH(KC_D)

#define TRON_NUM LT(_TRON_NUM,KC_BSPC)
#define TRON_NAV MO(_NAV)

#define COMBO_REF_DEFAULT _MAGICSTURDY

// magic sturdy Left-hand home row mods
#define HSCTL_D LCTL_T(KC_D)
#define HSCMD_R LGUI_T(KC_R)
#define HSOPT_T LALT_T(KC_T)
#define HSSFT_S LSFT_T(KC_S)
#define HSHYP_G HYPR_T(KC_G)
#define HS_J LT(_FUN,KC_J)      

// magic sturdy Right-hand home row mods
#define HSCTL_N RCTL_T(KC_N)
#define HSCMD_E RGUI_T(KC_E)
#define HSOPT_A RALT_T(KC_A)
#define HSSFT_I RSFT_T(KC_I)
#define HSHYP_H HYPR_T(KC_H)
#define HS_COMM LT(_WIN,JP_COMM)

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
//     D * -> DY     O * -OA      U * -> UE
//     E * -> EU     P * -> PY      V * -> VS      
//     G * -> GY     R * -> RL      X * -> XT
//     Y * -> YP             
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
        case KC_Y: return KC_P;
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
    TJS_QMARK,
    TJS_SLASH,
    TJS_SEMI,
    TJS_COLN,
    TJS_N1,
    TJS_N2,
    TJS_N3,
    TJS_N4,
    TJS_N5,
    TJS_N6,
    TJS_N7,
    TJS_N8,
    TJS_N9,
    TJS_N0,
    TJS_AT,
    TJS_LBKT,
    TJS_RBKT,
    TJS_MINUS,
    TJS_CARET,
    TJS_YEN,
    TJS_EXL,
    TJS_DQT,
    TJS_HASH,
    TJS_DLLR,
    TJS_PRNT,
    TJS_AMPS,
    TJS_SQT,
    TJS_LPAR,
    TJS_RPAR,
    TJS_GRAVE,
    TJS_LBRC,
    TJS_RBRC,
    TJS_EQL,
    TJS_TILDE,
    TJS_PIPE,
    TJS_UNDER,
    TJS_ASTRK,
    TJS_PLUS,
    TJS_DOT,
    TJS_MT,
    TJS_LT,
    _KANA,
    _EISU,
    _NW_SPC,
    _NW_RET,
    SELWORD,
    _PANIC,
    _INAUD,
    _JPAUD,
    _UNISP,
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
    OSS_NAV, // One shot shift on press - nav layer access on hold
};

// Declare the functions to be used with the tap dance key OSS_NAV

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void sn_finished(tap_dance_state_t *state, void *user_data);
void sn_reset(tap_dance_state_t *state, void *user_data);

void ef_finished(tap_dance_state_t *state, void *user_data);
void ef_reset(tap_dance_state_t *state, void *user_data);

void kw_finished(tap_dance_state_t *state, void *user_data);
void kw_reset(tap_dance_state_t *state, void *user_data);


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


    // TJS_QMARK
  case TJS_QMARK:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_SLASH)
                  SS_UP(X_LSFT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
        // TJS_SLASH,
  case TJS_SLASH:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
        // TJS_SEMI
  case TJS_SEMI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SCLN));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
            // TJS_COLN
  case TJS_COLN:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;

                // TJS_N1
  case TJS_N1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_1));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_N2
  case TJS_N2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_2));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_N3
  case TJS_N3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_3));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_N4
  case TJS_N4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_4));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_N5
  case TJS_N5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_5));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_N6
  case TJS_N6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_6));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_N7
  case TJS_N7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_7));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_N8
  case TJS_N8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_8));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_N9
  case TJS_N9:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_9));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_N0
  case TJS_N0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_0));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_AT
  case TJS_AT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;    
        // TJS_LBKT
  case TJS_LBKT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRC));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
        return false;
                // TJS_RBKT
  case TJS_RBKT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_BSLS));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
        return false;
    // TJS_MINUS
  case TJS_MINUS:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINS));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
    // TJS_CARET
  case TJS_CARET:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQL));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
        // TJS_YEN
  case TJS_YEN:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_INT3));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
        // TJS_EXL
  case TJS_EXL:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_1)
                  SS_UP(X_LSFT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
        // TJS_DQT
  case TJS_DQT:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_2)
                  SS_UP(X_LSFT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
            // TJS_HASH
  case TJS_HASH:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_3)
                  SS_UP(X_LSFT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
            // TJS_DLLR
  case TJS_DLLR:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_4)
                  SS_UP(X_LSFT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
            // TJS_PRNT
  case TJS_PRNT:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_5)
                  SS_UP(X_LSFT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
            // TJS_AMPS
  case TJS_AMPS:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_6)
                  SS_UP(X_LSFT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
            // TJS_SQT
  case TJS_SQT:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_7)
                  SS_UP(X_LSFT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
            // TJS_LPAR
  case TJS_LPAR:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_8)
                  SS_UP(X_LSFT)); // shifted
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
                // TJS_RPAR
  case TJS_RPAR:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_9)
                  SS_UP(X_LSFT));
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;

  // TJS_GRAVE
  case TJS_GRAVE:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_LBRC)
                  SS_UP(X_LSFT)); // shifted   
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;    
        // TJS_LBRC
  case TJS_LBRC:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_RBRC)
                  SS_UP(X_LSFT)); // shifted 
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
        return false;
                // TJS_RBRC
  case TJS_RBRC:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_BSLS)
                  SS_UP(X_LSFT)); // shifted   
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
        return false;
        // TJS_EQL
  case TJS_EQL:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_MINS)
                  SS_UP(X_LSFT)); // shifted   
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
    // TJS_TILDE
  case TJS_TILDE:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_EQL)
                  SS_UP(X_LSFT)); // shifted  
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
        // TJS_PIPE
  case TJS_PIPE:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_INT3)
                  SS_UP(X_LSFT)); // shifted   
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
     // TJS_UNDER
  case TJS_UNDER:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_INT1)
                  SS_UP(X_LSFT)); // shifted   
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
   // TJS_ASRTK
  case TJS_ASTRK:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_QUOT)
                  SS_UP(X_LSFT)); // shifted   
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
   // TJS_PLUS
  case TJS_PLUS:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_SCLN)
                  SS_UP(X_LSFT)); // shifted   
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
       // TJS_DOT
  case TJS_DOT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DOT));    
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
   // TJS_MT
  case TJS_MT:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_DOT)
                  SS_UP(X_LSFT)); // shifted   
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
    } else {
      //
    }
    return false;
   // TJS_LT
  case TJS_LT:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_COMM)
                  SS_UP(X_LSFT)); // shifted   
      SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_L)
                  SS_UP(X_LCTL)); // convert to romaji
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
  case _NW_SPC: // to leave toggled layer
    if (record->event.pressed) {
      tap_code(KC_SPC);
    }
    else {
      layer_move(_MAGICSTURDY);
    }
    return false;
    case _PANIC: // to leave toggled layer
    if (record->event.pressed) {
      layer_move(_MAGICSTURDY);
    }
    else {
       // do nothing 
    }
    return false;
  case _INAUD:
    if (record->event.pressed) {
      // when keycode DFINE is pressed
      SEND_STRING("[inaudible []]"); //[inaudible )
      SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT));  // []] and center cursor
    } else {
      // when keycode DFINE is released
    }
   return false;
  case _JPAUD:
    if (record->event.pressed) {
      // when keycode DFINE is pressed
      SEND_STRING("[Japanese []]"); //[inaudible )
      SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT));  // []] and center cursor
    } else {
      // when keycode DFINE is released
    }
   return false;
   case _UNISP:
    if (record->event.pressed) {
      // when keycode DFINE is pressed
      SEND_STRING("Unidentified speaker: "); //[inaudible )
    } else {
      // when keycode DFINE is released
    }
     return false;
  case _NW_RET: // to leave toggled layer
    if (record->event.pressed) {
      tap_code(KC_ENT);
    }
    else {
      layer_move(_MAGICSTURDY);
    }
    return false;
  }
  if (!process_select_word(keycode, record, SELWORD)) { return false; } // for select word function
  return true;
}



// combos mappings

// system
const uint16_t PROGMEM combo_qkboot[] = {KC_X, HSSFT_S, KC_V, COMBO_END};
const uint16_t PROGMEM combo_qkreboot[] = {KC_P, KC_Y, KC_W, COMBO_END};
const uint16_t PROGMEM combo_qkeeprom[] = {KC_C, HSCTL_D, KC_G, COMBO_END};

// layers
const uint16_t PROGMEM combo_numword[] = {NUM, OSS, COMBO_END};
const uint16_t PROGMEM combo_os_num[] = {HSCMD_R, NUM, COMBO_END};
const uint16_t PROGMEM combo_os_nav[] = {HSOPT_T, NUM, COMBO_END};
const uint16_t PROGMEM combo_os_sym[] = {HSCTL_D, NUM, COMBO_END};

// English 
const uint16_t PROGMEM combo_sorcery[] = {KC_C, QK_AREP, COMBO_END};
const uint16_t PROGMEM combo_capsword[] = {SYM, QK_REP, COMBO_END};

// numword
const uint16_t PROGMEM combo_nwret[] = {KC_6, KC_3, COMBO_END};
const uint16_t PROGMEM combo_panic[] = {JP_AMPR, JP_EXLM, COMBO_END};

// movement 
const uint16_t PROGMEM combo_back_char[] = {HSCMD_R, HS_J, COMBO_END};
const uint16_t PROGMEM combo_for_char[] = {HS_COMM, HSCMD_E, COMBO_END};
const uint16_t PROGMEM combo_back_sent[] = {KC_Y, KC_W, COMBO_END};
const uint16_t PROGMEM combo_for_sent[] = {KC_Z, KC_F, COMBO_END};
const uint16_t PROGMEM combo_scroll_down[] = {HSCTL_N, KC_Z, COMBO_END};
const uint16_t PROGMEM combo_scroll_up [] = {HSCTL_D,  KC_W, COMBO_END};
const uint16_t PROGMEM combo_page_down[] = {HSOPT_A, HS_COMM, COMBO_END};
const uint16_t PROGMEM combo_page_up [] = {HSOPT_T,  HS_J, COMBO_END};
const uint16_t PROGMEM combo_down[] = {HSCTL_N, HSHYP_H, COMBO_END};
const uint16_t PROGMEM combo_up[] = {HSCTL_D, HSHYP_G, COMBO_END};

// j movement
const uint16_t PROGMEM combo_jback_char[] = {TJ_KA, TJ_NI, COMBO_END};
const uint16_t PROGMEM combo_jfor_char[] = {TJ_DOUTEN, TJ_U, COMBO_END};
const uint16_t PROGMEM combo_jback_sent[] = {TJ_MO, TJ_NA, COMBO_END};
const uint16_t PROGMEM combo_jfor_sent[] = {TJ_WO, TJ_SU, COMBO_END};
const uint16_t PROGMEM combo_jscroll_down[] = {TJ_I, TJ_SU, COMBO_END};
const uint16_t PROGMEM combo_jscroll_up [] = {TJ_TE,  TJ_NA, COMBO_END};
const uint16_t PROGMEM combo_jpage_down[] = {TJ_SHI, TJ_DOUTEN, COMBO_END};
const uint16_t PROGMEM combo_jpage_up [] = {TJ_TO,  TJ_NI, COMBO_END};
const uint16_t PROGMEM combo_jdown[] = {TJ_I, TJ_TSU, COMBO_END};
const uint16_t PROGMEM combo_jup[] = {TJ_TE, TJ_SA, COMBO_END};


// controls
const uint16_t PROGMEM combo_delw[] = {KC_Y, HSCTL_D, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {HSSFT_S, KC_V, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_X, HSSFT_S, COMBO_END};
const uint16_t PROGMEM combo_bkspw[] = {KC_F, HSCTL_N, COMBO_END};
const uint16_t PROGMEM combo_ret[] = {JP_DOT, HSOPT_A, COMBO_END};
// j controls

const uint16_t PROGMEM combo_jdel[] = {TJ_MO, TJ_TE, COMBO_END};
const uint16_t PROGMEM combo_jtab[] = {TJ_MA, TJ_TA, COMBO_END};
const uint16_t PROGMEM combo_jesc[] = {TJ_RA, TJ_TA, COMBO_END};
const uint16_t PROGMEM combo_jret[] = {TJ_KUTEN, TJ_SHI, COMBO_END};
const uint16_t PROGMEM combo_jbkspw[] = {TJ_WO, TJ_I, COMBO_END};



// Japanese language
const uint16_t PROGMEM combo_hiragana[] = {TJ_MO, TJ_XYO, COMBO_END};
const uint16_t PROGMEM combo_katakana[] = {TJ_KI, TJ_WO, COMBO_END};
const uint16_t PROGMEM combo_spc[] = {TJ_TO, TJ_RI, COMBO_END};
const uint16_t PROGMEM combo_eisu[] = {HSCTL_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo_jeisu[] = {TJ_HA, TJ_TE, COMBO_END};
const uint16_t PROGMEM combo_kana[] = {QK_AREP, HSCTL_N, COMBO_END};
const uint16_t PROGMEM combo_jkana[] = {TJ_NO, TJ_I, COMBO_END};

// copy paste & shortcuts
const uint16_t PROGMEM combo_undo[] = {KC_C, KC_P, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_M, HSOPT_T, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_L, HSCMD_R, COMBO_END};
const uint16_t PROGMEM combo_save[] = {KC_O, HSOPT_A, COMBO_END};
// j copy paste & shortcuts
const uint16_t PROGMEM combo_jundo[] = {TJ_HA, TJ_XYO, COMBO_END};
const uint16_t PROGMEM combo_jcopy[] = {TJ_RU, TJ_TO, COMBO_END};
const uint16_t PROGMEM combo_jpaste[] = {TJ_KO, TJ_KA, COMBO_END};
const uint16_t PROGMEM combo_jsave[] = {TJ_A, TJ_SHI, COMBO_END};
// misc
const uint16_t PROGMEM combo_selword[] = {HSCTL_D, HSCTL_N, COMBO_END};
const uint16_t PROGMEM combo_select_all[] = {HSSFT_I, JP_MINS, COMBO_END};
const uint16_t PROGMEM combo_squot[] = {HSCMD_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_dquot[] = {HSSFT_I, KC_Q, COMBO_END};




// combo effects

combo_t key_combos[] = {
  // system

  COMBO(combo_qkboot, QK_BOOT),
  COMBO(combo_qkeeprom, EE_CLR),
  COMBO(combo_qkreboot, QK_RBT),
  // layers
  COMBO(combo_numword, TO(_NUM_W)),
  COMBO(combo_os_num, OSL(_NUM)),
  COMBO(combo_os_nav, OSL(_NAV)),
  COMBO(combo_os_sym, OSL(_SYM)),
  // English
  COMBO(combo_sorcery, OSL(_SORCERY)),
  COMBO(combo_capsword, CW_TOGG),
  COMBO(combo_eisu, _EISU),
  COMBO(combo_kana, _KANA),
  // numword
  COMBO(combo_panic, _PANIC),
  COMBO(combo_nwret, _NW_RET),
  // movement
  COMBO(combo_back_char, KC_LEFT),
  COMBO(combo_for_char, KC_RGHT),

  COMBO(combo_back_sent, KC_HOME),
  COMBO(combo_for_sent, KC_END),
  COMBO(combo_scroll_up, MS_WHLU),
  COMBO(combo_scroll_down, MS_WHLD),
  COMBO(combo_page_up, KC_PGUP),
  COMBO(combo_page_down, KC_PGDN),
  COMBO(combo_up, KC_UP),
  COMBO(combo_down, KC_DOWN),

  // j movement
  COMBO(combo_jback_char, KC_LEFT),
  COMBO(combo_jfor_char, KC_RGHT),

  COMBO(combo_jback_sent, KC_HOME),
  COMBO(combo_jfor_sent, KC_END),
  COMBO(combo_jscroll_up, MS_WHLU),
  COMBO(combo_jscroll_down, MS_WHLD),
  COMBO(combo_jpage_up, KC_PGUP),
  COMBO(combo_jpage_down, KC_PGDN),
  COMBO(combo_jup, KC_UP),
  COMBO(combo_jdown, KC_DOWN),
  // control
  
  COMBO(combo_delw, A(KC_DEL)),
  COMBO(combo_tab, KC_TAB),
  COMBO(combo_esc, KC_ESC),
  COMBO(combo_bkspw, A(KC_BSPC)),
  COMBO(combo_ret, KC_ENT),
  // j controls
  
  COMBO(combo_jdel, KC_DEL),
  COMBO(combo_jtab, KC_TAB),
  COMBO(combo_jesc, KC_ESC),
  COMBO(combo_jbkspw, A(KC_BSPC)),
  COMBO(combo_jret, KC_ENT),
  // Japanese language
  COMBO(combo_hiragana, C(KC_J)),
  COMBO(combo_katakana, C(KC_K)),
  COMBO(combo_spc, KC_SPC),
  COMBO(combo_jeisu, _EISU),
  COMBO(combo_jkana, _KANA),
  // copy paste & shortcuts
  COMBO(combo_undo, UNDO),
  COMBO(combo_copy, COPY),
  COMBO(combo_paste, PASTE),
  COMBO(combo_save, G(KC_S)),
  // j copy paste & shortcuts
  COMBO(combo_jundo, UNDO),
  COMBO(combo_jcopy, COPY),
  COMBO(combo_jpaste, PASTE),
  COMBO(combo_jsave, G(KC_S)),
  // misc
  COMBO(combo_selword, SELWORD),
  COMBO(combo_select_all, G(KC_A)),
  COMBO(combo_squot, S(KC_7)),
  COMBO(combo_dquot, S(KC_2)),
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
const key_override_t comm_quo_override = ko_make_basic(MOD_MASK_SHIFT, HS_COMM, JP_QUOT);
const key_override_t dot_dquo_override = ko_make_basic(MOD_MASK_SHIFT, JP_DOT, JP_DQUO);
const key_override_t min_ques_override = ko_make_basic(MOD_MASK_SHIFT, JP_MINS, JP_QUES);
const key_override_t paste_pastewithout_override = ko_make_basic(MOD_MASK_SHIFT, PASTE, PASTEW);
const key_override_t undo_redo_override = ko_make_basic(MOD_MASK_SHIFT, UNDO, REDO);
const key_override_t copy_cut_override = ko_make_basic(MOD_MASK_SHIFT, COPY, CUT);
const key_override_t printscr_override = ko_make_basic(MOD_MASK_SHIFT, PRINTSEL, PRINTSCR);
const key_override_t printalt_override = ko_make_basic(MOD_MASK_ALT, PRINTSEL, PRINTALT);


const key_override_t *key_overrides[] = {
    &comm_quo_override,
    &dot_dquo_override,
    &min_ques_override,
    &paste_pastewithout_override,
    &undo_redo_override,
    &copy_cut_override,
    &printscr_override,
    &printalt_override,
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_3(
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 
                  '*', '*', '*',  '*', '*', '*'
    );

// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAGICSTURDY] = LAYOUT_split_3x5_3(
           KC_X,     KC_M,    KC_L,    KC_C, KC_P,              KC_B,  QK_AREP,    KC_U,    KC_O,    KC_Q,
        HSSFT_S,  HSOPT_T, HSCMD_R, HSCTL_D, KC_Y,              KC_F,  HSCTL_N, HSCMD_E, HSOPT_A, HSSFT_I,
           KC_V,     KC_K,  HS_J,   HSHYP_G, KC_W,              KC_Z,  HSHYP_H, HS_COMM, JP_DOT,  JP_MINS,
           _______,     NUM,  SYM,                              QK_REP,  SS, _______
  ),
  [_QWERTY] = LAYOUT_split_3x5_3(
           KC_Q,     KC_W,    KC_E,    KC_R,  KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
           KC_A,     KC_S,    KC_D,    KC_F,  KC_G,            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
           KC_Z,     KC_X,    KC_C,    KC_V,  KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                           _______,    NUM,    SYM,            QK_REP,  OSS, _______
  ),
  [_TRON_BASE] = LAYOUT_split_3x5_3(
        TJ_RA,   TJ_RU,   TJ_KO,   TJ_HA,  TJ_XYO,            TJ_KI,   TJ_NO,   TJ_KU,    TJ_A,   TJ_RE,
        TJ_TA,   TJ_TO,   TJ_KA,   TJ_TE,   TJ_MO,            TJ_WO,    TJ_I,    TJ_U,  TJ_SHI,   TJ_NN,
        TJ_MA,   TJ_RI,   TJ_NI,   TJ_SA,   TJ_NA,            TJ_SU,  TJ_TSU,TJ_DOUTEN,TJ_KUTEN,TJ_XTSU,
        _______,   TRON_NUM,  OSL(_TRON_RED),                 OSL(_TRON_BLUE), TRON_NAV,  _______
                         ),
  [_TRON_BLUE] = LAYOUT_split_3x5_3(
        TJ_BI,   TJ_ZO,   TJ_GO,  TJ_BA,    TJ_BO,            TJ_E,   TJ_KE,   TJ_ME,   TJ_MU,  TJ_RO,
        TJ_DA,   TJ_DO,   TJ_GA,  TJ_DE,    TJ_BU,            TJ_O,  TJ_CHI,TJ_CHOUONNPU,TJ_MI,  TJ_YA,
        TJ_XE,   TJ_XO,    TJ_ZE,  TJ_ZA,   TJ_BE,            TJ_WA,   TJ_XI,   TJ_XA, _______,   TJ_XU,
              _______,  OSL(_TRON_NUM), OSL(_TRON_PURPLE),             _______, _______, _______
                                    ),
  [_TRON_RED] = LAYOUT_split_3x5_3(
        TJ_HI,   TJ_SO,TJ_NAKAGURO,TJ_XYA,  TJ_HO,             TJ_GI,   TJ_GE,  TJ_GU,  _______, _______,
        TJ_NU,   TJ_NE,  TJ_XYU,   TJ_YO,   TJ_FU,             TJ_O,  TJ_DZI,  TJ_VU,    TJ_JI, _______,
        TJ_XE,   TJ_XO,   TJ_SE,   TJ_YU,   TJ_HE,             TJ_ZU,  TJ_DZU,TJ_LKAGIKAKO,TJ_RKAGIKAKO, TJ_XU,
                       _______,  _______, OSL(_TRON_SYM),             OSL(_TRON_PURPLE), _______, _______
                                    ),
  [_TRON_PURPLE] = LAYOUT_split_3x5_3(
        TJ_PI, _______, _______,   TJ_PA,   TJ_PO,            _______, _______, _______, _______, _______,
      KC_LNG5, _______, _______, _______,   TJ_PU,            _______, HIRAGANA, KATAKANA, _______, _______,
      _______, _______, _______, _______,   TJ_PE,            _______, _______, _______, _______, _______,
                        _______, KC_INT5, _______,            _______, KC_INT4, _______
                                    ),
  [_TRON_NUM] = LAYOUT_split_3x5_3(
     TJS_EXL, TJS_LBKT, TJS_RBKT,  TJS_COLN,  KC_INT1,        TJS_PLUS, TJS_N7, TJS_N8, TJS_N9, TJS_ASTRK,
     TJS_AMPS, TJS_LPAR, TJS_RPAR, TJS_SEMI,   TJS_AT,          TJS_MINUS, TJS_N4, TJS_N5, TJS_N6, TJS_SLASH,
     TJS_QMARK, TJS_UNDER, TJS_DQT, TJS_SQT,   TJS_PIPE,        TJS_EQL, TJS_N1, TJS_N2, TJS_N3, TJS_DOT,
     _______, _______, MO(_TRON_SYM),                           KC_ENT, TJS_N0, _______
                                    ),
  [_TRON_SYM] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______,  _______,            _______, TJS_DQT, TJS_LT, TJS_MT, TJS_CARET,
      _______, _______, _______, _______,  _______,            TJS_TILDE, TJS_SQT, TJS_LBRC, TJS_RBRC, TJS_GRAVE,
      _______, _______, _______, _______,  _______,            _______, TJS_YEN, TJS_DLLR, _______, _______,
                        _______, _______, _______,            _______, _______, _______
                                    ),
  [_NUM] = LAYOUT_split_3x5_3(
      JP_EXLM, JP_LBRC, JP_RBRC, JP_COLN, KC_INT1,           JP_PLUS,  KC_7, KC_8, KC_9, JP_ASTR,
      JP_AMPR, JP_LPRN, JP_RPRN, JP_SCLN, JP_HASH,            JP_MINS,  KC_4, KC_5, KC_6, JP_SLSH,
      TJS_QMARK, JP_UNDS, JP_PERC, JP_AT, JP_PIPE,            JP_EQL,   KC_1, KC_2, KC_3,  KC_DOT,
                        _______,     NUM,  _______,           _______,  KC_0, _______
                              ),
  [_NAV] = LAYOUT_split_3x5_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    PRINTSEL, OSM(MOD_RCTL), OSM(MOD_RGUI), OSM(MOD_RALT), OSM(MOD_RSFT),
      KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,      XXXXXXX,       KC_RCTL,       KC_RGUI,       KC_RALT,       KC_RSFT,
      KC_HOME, KC_PGUP, KC_PGDN, KC_END,   XXXXXXX,   HYPR(KC_B),       KC_MPLY,       KC_VOLD,       KC_VOLU,       KC_MUTE,
      _______, KC_ESC,    KC_TAB,      _______, _______, _______
                              ),
  [_SYM] = LAYOUT_split_3x5_3(
       XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,        KC_APP,         LSA(JP_8),  JP_HASH, JP_LABK, JP_RABK,   JP_CIRC,
       _______, A(KC_DEL), KC_PENT,   KC_DEL,    HYPR(KC_Y),           JP_TILD,  JP_PERC, JP_LCBR, JP_RCBR,    JP_GRV,
       JP_CAPS,     DFINE,   GTRNS,    GOOGL,       KC_LPAD,           KC_NUBS,   JP_YEN,  JP_DLR, A(JP_3), LSA(JP_2),
                                XXXXXXX, XXXXXXX,    XXXXXXX,           _______,  _______, _______
                              ),
  [_FUN] = LAYOUT_split_3x5_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_NUM,      KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_INS,      KC_SCRL,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
      XXXXXXX, XXXXXXX, XXXXXXX, DF(_MAGICSTURDY), KC_APP,      KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
                                 _______, XXXXXXX, XXXXXXX,       KC_NUM,  KC_INS,  _______
                              ),
  [_NUM_W] = LAYOUT_split_3x5_3(
      JP_EXLM, JP_LBRC, JP_RBRC, JP_COLN, KC_INT1,           JP_PLUS,  KC_7, KC_8, KC_9, JP_ASTR,
      JP_AMPR, JP_LPRN, JP_RPRN, JP_SCLN, TJS_HASH,           JP_MINS,  KC_4, KC_5, KC_6, JP_SLSH,
      JP_QUES, JP_UNDS, JP_PERC, JP_AT,    JP_PIPE,            JP_EQL,  KC_1, KC_2, KC_3,  KC_DOT,
                        _______, _______,  _NW_SPC,           _______,  KC_0, _______
                              ),
    [_SORCERY] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______, _______,     _______, _______,  _UNISP, _______, _______,
      _______, _______, _______, _______, _______,     _______, _______, _______, _______,  _INAUD,
      _______, _______, _JPAUD,  _______, _______,     _______, _______, _______, _______, _______,
      _______, _______, _______,     _______, _______, _______
                              ),
  [_WIN] = LAYOUT_split_3x5_3(
      MEH(KC_X), MEH(KC_M), KC_MCTL,  MEH(KC_C),  MEH(KC_P),           KC_EJCT, KC_F21, KC_F22, KC_F23, KC_F24,
      WINLEFT, MEH(KC_Z), MEH(KC_B),  MEH(KC_D),  C(KC_F2),           KC_CPNL, KC_F17, KC_F18, KC_F19, KC_F20,
      MEH(KC_V), MEH(KC_K), MEH(KC_J),  MEH(KC_G),  MEH(KC_W),           KC_LPAD, KC_F13, KC_F14, KC_F15, KC_F16, 
                               MEH(KC_Z),   WINMIN,  WINMAX,         XXXXXXX, XXXXXXX, _______
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
static td_tap_t sn_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void sn_finished(tap_dance_state_t *state, void *user_data) {
    sn_tap_state.state = cur_dance(state);
    switch (sn_tap_state.state) {
        case TD_SINGLE_TAP:            
            if ( is_caps_word_on() ) { caps_word_off(); }
            else { set_oneshot_mods(MOD_BIT(KC_LSFT)); }
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NAV);
            break;      
        default:
            break;
    }
}

void sn_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (sn_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_NAV);
    }
    sn_tap_state.state = TD_NONE;
}



// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
  [OSS_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sn_finished, sn_reset)
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM:
            return 300;
        case SYM:
            return 300;
        case OSS_NAV:
            return 300;
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 300;       
        default:
            return TAPPING_TERM;
    }
}


uint8_t combo_ref_from_layer(uint8_t layer){
    switch (get_highest_layer(layer_state)){
        case _TRON_BASE: return _TRON_BASE;
        case _TRON_RED: return _TRON_BASE;
        case _TRON_BLUE: return _TRON_BASE;
        case _TRON_PURPLE: return _TRON_BASE;
        case _NUM_W: return _NUM_W;
        default: return _MAGICSTURDY;
    }
    return layer;  // important if default is not in case.
}

