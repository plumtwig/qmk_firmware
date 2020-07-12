#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Twig
#define PRODUCT         Handwired50Keys Rev2
#define DESCRIPTION     4 rows 50 keys

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 14

// #define MATRIX_ROW_PINS { A2, A1, A0, B8 }
// #define MATRIX_COL_PINS { B13, B14, B15, B9, B7, B6, B5, B4, B3, B2, B1, B0, B10, B11 }
#define MATRIX_ROW_PINS { B7, B6, B5, B4 }
#define MATRIX_COL_PINS { A2, A1, A0, B8 , B13, B14, B15, B9, B10, B11, B3, B2, B1, B0}

#define DEBOUNCE 8
#define TAPPING_TERM 150

#define FORCE_NKRO

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(STARTUP_SOUND)
#endif
