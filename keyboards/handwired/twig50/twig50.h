#pragma once

#include "quantum.h"

#define ___ KC_NO

#define KEYMAP( \
	K00,      K02,      K04, K05, K06, \
	K10, K11, K12, K13, K14, K15, K16, \
	K20, K21, K22, K23, K24, K25, K26, \
	K30, K31, K32, K33, K34, K35, K36, \
	K40, K41, K42, K43, K44, K45, K46, \
	K50, K51, K52, K53, K54, K55,      \
	K60, K61, K62, K63, K64, K65,      \
	K70, K71, K72,      K74, K75  \
) { \
	{ K00,   KC_NO, K02,   KC_NO, K04,   K05,   K06 }, \
	{ K10,   K11,   K12,   K13,   K14,   K15,   K16 }, \
	{ K20,   K21,   K22,   K23,   K24,   K25,   K26 }, \
	{ K30,   K31,   K32,   K33,   K34,   K35,   K36 }, \
	{ K40,   K41,   K42,   K43,   K44,   K45,   K46 }, \
	{ K50,   K51,   K52,   K53,   K54,   K55,   KC_NO }, \
	{ K60,   K61,   K62,   K63,   K64,   K65,   KC_NO }, \
	{ K70,   K71,   K72,   KC_NO, K74,   K75,   KC_NO }  \
}
