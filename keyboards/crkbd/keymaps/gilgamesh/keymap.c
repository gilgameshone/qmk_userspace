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
    _MAGICSTURDY2,
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
    _WIN,
};

#define NUM OSL(_MAGICSTURDY2)
#define SYM LT(_SYM,KC_SPC)
#define OSS TD(OSS_NAV)

#define FUN MO(_FUN)

#define PASTE G(KC_V)
#define UNDO G(KC_Z)
#define COPY G(KC_C)

#define TRON_NUM LT(_TRON_NUM,KC_BSPC)
#define TRON_NAV MO(_NAV)

#define COMBO_REF_DEFAULT _MAGICSTURDY

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

const uint16_t PROGMEM combo_capsword[] = {SYM, QK_REP, COMBO_END};
const uint16_t PROGMEM combo_qkboot[] = {KC_X, HSSFT_S, KC_V, COMBO_END};
const uint16_t PROGMEM combo_qkreboot[] = {KC_P, KC_Y, KC_W, COMBO_END};
const uint16_t PROGMEM combo_qkeeprom[] = {KC_C, HSCTL_D, KC_G, COMBO_END};
const uint16_t PROGMEM combo_fun[] = {SYM, NUM, COMBO_END};
const uint16_t PROGMEM combo_win[] = {QK_REP, OSS, COMBO_END};
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
const uint16_t PROGMEM combo_delw[] = {HSOPT_T, HSCTL_D, COMBO_END};
const uint16_t PROGMEM combo_del[] = {SYM, HSCTL_D, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {HSOPT_T, HSHYP_G, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_M, KC_C, COMBO_END};
const uint16_t PROGMEM combo_bkspw[] = {HSCTL_N, HSOPT_A, COMBO_END};
const uint16_t PROGMEM combo_bksp[] = {HSCTL_N, QK_REP, COMBO_END};
const uint16_t PROGMEM combo_ret[] = {HSCTL_N, HSCMD_E, HSOPT_A, COMBO_END};
const uint16_t PROGMEM combo_hiragana[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo_katakana[] = {KC_M, KC_O, COMBO_END};
const uint16_t PROGMEM combo_spc[] = {HSOPT_T, HSCMD_R, HSCTL_D, COMBO_END};
const uint16_t PROGMEM combo_eisu[] = {KC_M, KC_L, KC_C, COMBO_END};
const uint16_t PROGMEM combo_kana[] = {QK_AREP, KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo_numword[] = {NUM, OSS, COMBO_END};
const uint16_t PROGMEM combo_down[] = {HSCTL_N, HSCMD_E, COMBO_END};
const uint16_t PROGMEM combo_up[] = {HSCTL_D, HSCMD_R, COMBO_END};
const uint16_t PROGMEM combo_up_para[] = {HSOPT_T, HSCMD_R, COMBO_END};
const uint16_t PROGMEM combo_down_para[] = {HSOPT_A, HSCMD_E, COMBO_END};
const uint16_t PROGMEM combo_selword[] = {HSCTL_D, HSCTL_N, COMBO_END};
const uint16_t PROGMEM combo_os_num[] = {HSCMD_R, HSCMD_E, COMBO_END};
const uint16_t PROGMEM combo_os_nav[] = {HSOPT_T, HSOPT_A, COMBO_END};
const uint16_t PROGMEM combo_os_sym[] = {HSSFT_S, HSSFT_I, COMBO_END};
const uint16_t PROGMEM combo_undo[] = {SYM, KC_M, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_M, KC_L, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_L, KC_C, COMBO_END};
const uint16_t PROGMEM combo_save[] = {SYM, HSOPT_T, COMBO_END};
const uint16_t PROGMEM combo_page_up[] = {SYM, HSHYP_G, COMBO_END};
const uint16_t PROGMEM combo_page_down[] = {HSHYP_H, QK_REP, COMBO_END};
const uint16_t PROGMEM combo_select_all[] = {HSOPT_A, QK_REP, COMBO_END};

// combo effects

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
  COMBO(combo_del, KC_DEL),
  COMBO(combo_delw, A(KC_DEL)),
  COMBO(combo_tab, KC_TAB),
  COMBO(combo_esc, KC_ESC),
  COMBO(combo_bksp, KC_BSPC),
  COMBO(combo_bkspw, A(KC_BSPC)),
  COMBO(combo_ret, KC_ENT),
  COMBO(combo_hiragana, C(KC_J)),
  COMBO(combo_katakana, C(KC_K)),
  COMBO(combo_spc, KC_SPC),
  COMBO(combo_eisu, _EISU),
  COMBO(combo_kana, _KANA),
  COMBO(combo_numword, TO(_NUM_W)),
  COMBO(combo_up, KC_UP),
  COMBO(combo_down, KC_DOWN),
  COMBO(combo_up_para, A(KC_UP)),
  COMBO(combo_down_para, A(KC_DOWN)),
  COMBO(combo_selword, SELWORD),
  COMBO(combo_os_num, OSL(_NUM)),
  COMBO(combo_os_nav, OSL(_NAV)),
  COMBO(combo_os_sym, OSL(_SYM)),
  COMBO(combo_undo, UNDO),
  COMBO(combo_copy, COPY),
  COMBO(combo_paste, PASTE),
  COMBO(combo_save, G(KC_S)),
  COMBO(combo_page_up, KC_PGUP),
  COMBO(combo_page_down, KC_PGDN),
  COMBO(combo_select_all, G(KC_A)),
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
const key_override_t capsw_capsl_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);
const key_override_t paste_pastewithout_override = ko_make_basic(MOD_MASK_ALT, PASTE, S(LAG(KC_V)));
const key_override_t paste_yank_override = ko_make_basic(MOD_MASK_GUI, PASTE, S(LCAG(KC_Y))); //not working
const key_override_t undo_redo_override = ko_make_basic(MOD_MASK_CTRL, UNDO, S(G(KC_Z)));
const key_override_t copy_cut_override = ko_make_basic(MOD_MASK_CTRL, COPY, G(KC_X));




const key_override_t **key_overrides = (const key_override_t *[]){
    &comm_quo_override,
    &dot_dquo_override,
    &min_ques_override,
    &capsw_capsl_override,
    &paste_pastewithout_override,
    &undo_redo_override,
    &copy_cut_override,
    NULL
};



// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAGICSTURDY] = LAYOUT_split_3x5_3(
           XXXXXXX,     KC_M,    KC_L,    KC_C, XXXXXXX,              XXXXXXX,  QK_AREP,    KC_U,    KC_O,    XXXXXXX,
        HSSFT_S,  HSOPT_T, HSCMD_R, HSCTL_D, XXXXXXX,              XXXXXXX,  HSCTL_N, HSCMD_E, HSOPT_A, HSSFT_I,
           XXXXXXX,     KC_K,    KC_J, HSHYP_G, XXXXXXX,              XXXXXXX,  HSHYP_H, JP_COMM, JP_DOT,  XXXXXXX,
           _______,     NUM,  SYM,                              QK_REP,  OSS, TD(OSS_NAV)
  ),
  [_MAGICSTURDY2] = LAYOUT_split_3x5_3(
           XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_P, XXXXXXX,              XXXXXXX,  KC_B,    KC_U,    KC_O,  XXXXXXX,
           KC_X,     KC_V,     XXXXXXX,    KC_Y, XXXXXXX,              XXXXXXX,  KC_F, HSCMD_E, JP_MINS,  KC_Q,
           XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_W, XXXXXXX,              XXXXXXX,  KC_Z, XXXXXXX, XXXXXXX,  XXXXXXX,
           _______,     NUM,  SYM,                              QK_REP,  OSS, TD(OSS_NAV)
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
      _______, _______, _______, _______,   TJ_PU,            _______, C(JP_J), C(JP_K), C(JP_L), C(JP_SCLN),
      _______, _______, _______, _______,   TJ_PE,            _______, _______, _______, _______, _______,
                        _______, _______, _______,            _______, _______, _______
                                    ),
  [_TRON_NUM] = LAYOUT_split_3x5_3(
     TJS_EXL, TJS_LBKT, TJS_RBKT,  TJS_COLN,  C(KC_F2) ,        TJS_PLUS, TJS_N7, TJS_N8, TJS_N9, TJS_ASTRK,
     TJS_AMPS, TJS_LPAR, TJS_RPAR, TJS_SEMI,   TJS_AT,          TJS_MINUS, TJS_N4, TJS_N5, TJS_N6, TJS_SLASH,
     TJS_QMARK, TJS_UNDER, TJS_DQT, TJS_SQT,   TJS_PIPE,        TJS_EQL, TJS_N1, TJS_N2, TJS_N3, TJS_DOT,
     _______, _______, MO(_TRON_SYM),                           KC_ENT, TJS_N0, _______
                                    ),
  [_TRON_SYM] = LAYOUT_split_3x5_3(
      _______, _______, _______, _______,  _______,            _______, TJS_HASH, TJS_LT, TJS_MT, TJS_CARET,
      _______, _______, _______, _______,  _______,            TJS_TILDE, TJS_PRNT, TJS_LBRC, TJS_RBRC, TJS_GRAVE,
      _______, _______, _______, _______,  _______,            _______, TJS_YEN, TJS_DLLR, _______, _______,
                        _______, _______, _______,            _______, _______, _______
                                    ),
  [_NUM] = LAYOUT_split_3x5_3(
      JP_EXLM, JP_LBRC, JP_RBRC, JP_COLN, C(KC_F2),           JP_PLUS,  KC_7, KC_8, KC_9, JP_ASTR,
      JP_AMPR, JP_LPRN, JP_RPRN, JP_SCLN, JP_AT,              JP_MINS,  KC_4, KC_5, KC_6, JP_SLSH,
      TJS_QMARK, JP_UNDS, JP_DQUO, JP_QUOT, JP_PIPE,            JP_EQL,   KC_1, KC_2, KC_3,  KC_DOT,
                        _______,     NUM,  _______,           KC_ENT,  KC_0, _______
                              ),
  [_NAV] = LAYOUT_split_3x5_3(
      G(KC_Z), G(KC_X), G(KC_C), PASTE,   LSG(KC_Z),          LSG(KC_5), OSM(MOD_RCTL), OSM(MOD_RGUI), OSM(MOD_RALT), OSM(MOD_RSFT),
      KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT,   XXXXXXX,          _______, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
      KC_HOME, KC_PGUP, KC_PGDN, KC_END,    XXXXXXX,          HYPR(KC_B), KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE,
                        _______, KC_ESC,     KC_TAB,          _______, _______, _______
                              ),
  [_SYM] = LAYOUT_split_3x5_3(
       _______,   _______, G(KC_C),    PASTE,  S(LAG(KC_V)),         LSA(JP_8),  JP_HASH, JP_LABK, JP_RABK,   JP_CIRC,
       _______, A(KC_DEL), _______,   KC_DEL,    HYPR(KC_Y),           JP_TILD,  JP_PERC, JP_LCBR, JP_RCBR,    JP_GRV,
       JP_CAPS,     DFINE,   GTRNS,    GOOGL,       _______,           KC_NUBS,   JP_YEN,  JP_DLR, A(JP_3), LSA(JP_2),
                                XXXXXXX, XXXXXXX,    XXXXXXX,           _______,  _______, _______
                              ),
  [_FUN] = LAYOUT_split_3x5_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_NUM,             KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
      XXXXXXX, XXXXXXX, XXXXXXX, DF(_QWERTY),       KC_INS,             KC_SCRL,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
      XXXXXXX, XXXXXXX, XXXXXXX, DF(_MAGICSTURDY), XXXXXXX,             KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
                                 XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX
                              ),
  [_NUM_W] = LAYOUT_split_3x5_3(
      JP_EXLM, JP_LBRC, JP_RBRC, JP_COLN, C(KC_F2),           JP_PLUS,  KC_7, KC_8, KC_9, JP_ASTR,
      JP_AMPR, JP_LPRN, JP_RPRN, JP_SCLN, JP_AT,              JP_MINS,  KC_4, KC_5, KC_6, JP_SLSH,
      JP_QUES, JP_UNDS, JP_DQUO, JP_QUOT, JP_PIPE,            JP_EQL,   KC_1, KC_2, KC_3,  KC_DOT,
      _______,   TO(_MAGICSTURDY),  _NW_SPC,                 _NW_RET,  KC_0, _______
                              ),
  [_WIN] = LAYOUT_split_3x5_3(
      MEH(KC_X), MEH(KC_M), MEH(KC_L),  MEH(KC_C),  MEH(KC_P),           _______, _______, _______, _______, _______,
      MEH(KC_S), MEH(KC_T), MEH(KC_R),  MEH(KC_D),  MEH(KC_Y),           _______, _______, _______, _______, _______,
      MEH(KC_V), MEH(KC_K), MEH(KC_J),  MEH(KC_G),  MEH(KC_W),           _______, _______, _______, _______, _______, 
                               _______,   _______,  MEH(KC_SPC),         _______, _______, _______
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
            return 250;
        case SYM:
            return 250;
        case OSS_NAV:
            return 250;
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 250;       
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
