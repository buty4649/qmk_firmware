#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xE53C
#define DEVICE_VER      0x0001
#define MANUFACTURER    buty4649
#define PRODUCT         USB-ESC key
#define DESCRIPTION     USB ESC KEY

#define MATRIX_ROWS 1
#define MATRIX_COLS 1

#define MATRIX_COL_PINS { B5 }
#define MATRIX_ROW_PINS { B4 }
#define UNUSED_PINS

#define USE_I2C

#endif
