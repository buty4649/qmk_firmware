#include <print.h>
#include "usb_esc.h"
#include "pointing_device.h"
#include "i2c.h"

#define TB_ADDR 0x4A

enum MOTION_REG_ADDR
{
  MOTION_REG_UP = 0X00,
  MOTION_REG_DOWN,
  MOTION_REG_LEFT,
  MOTION_REG_RIGHT,
  MOTION_REG_CONFIRM,
  MOTION_REG_NUM
};

enum CONFIG_REG_ADDR
{
  CONFIG_REG_VALID = MOTION_REG_NUM,
  CONFIG_REG_I2C_ADDR = CONFIG_REG_VALID + 4,
  CONFIG_REG_I2C_SPEED,
  CONFIG_REG_LED_MODE = CONFIG_REG_I2C_SPEED + 2,
  CONFIG_REG_LED_FLASH_TIME,
  CONFIG_REG_DATA_CLEAR_TIME = CONFIG_REG_LED_FLASH_TIME + 2,  //CONFIG_REG_LED_FLASH_TIME has 2bytes
  CONFIG_REG_DATA_READ_TIME = CONFIG_REG_DATA_CLEAR_TIME + 2,
  CONFIG_REG_NUM = CONFIG_REG_DATA_READ_TIME + 2
};

enum LED_MODE
{
  LED_FLASH_1 = 0X00,
  LED_FLASH_2,
  LED_FLASH_TOGGLE,
  LED_FLASH_ALL,
  LED_ALWAYS_ON_1,
  LED_ALWAYS_ON_2, 
  LED_ALWAYS_ON_ALL,
  LED_ALWAYS_OFF,
  LED_BREATHING_1,
  LED_BREATHING_2,
  LED_BREATHING_ALL,
  LED_MOVE_FLASH,
  LED_MODE_NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KEYMAP( KC_ESC )
};

void startup_user() {
    debug_enable = true;
}

void pointing_device_init(void) {
    i2c_master_init();

    // Set Default Value
    i2c_start_write(TB_ADDR);
    i2c_master_write(0x01);     // WriteMode
    i2c_master_write(CONFIG_REG_VALID);
    i2c_master_write(0);
    i2c_master_write(0);
    i2c_master_write(0);
    i2c_master_write(0);
    i2c_master_stop();
}

uint8_t trackball_read(uint8_t reg) {
    if(i2c_start_write(TB_ADDR)) {
        print("i2c_start_write(TB_ADDR): ");
        goto i2c_error;
    }
    if(i2c_master_write(0x00)){
        print("i2c_master_write(0x00): ");
        goto i2c_error;     // ReadMode
    }
    if(i2c_master_write(reg)) {
        print("i2c_master_write(MOTION_REG_UP): ");
        goto i2c_error;
    }
    if(i2c_master_write(0x01)){
        print("i2c_master_write(0x00): ");
        goto i2c_error;     // ReadMode
    }
    //i2c_master_stop();

    if(i2c_start_read(TB_ADDR)) {
        print("i2c_start_read(TB_ADDR): ");
        goto i2c_error;
    }
    uint8_t trackdata = i2c_master_read(I2C_ACK);
    i2c_master_read(I2C_NACK);
    i2c_master_stop();

    return trackdata;

i2c_error:
    println("i2c_error");
    i2c_reset_state();
    return 0;
}

void pointing_device_task() {
    uint8_t up = trackball_read(MOTION_REG_UP);
    uint8_t down = trackball_read(MOTION_REG_DOWN);
    uint8_t left = trackball_read(MOTION_REG_LEFT);
    uint8_t right = trackball_read(MOTION_REG_RIGHT);

    print_hex4(up);   print("-");
    print_hex4(down); print("-");
    print_hex4(left); print("-");
    print_hex4(right); print("-");
    println();

    report_mouse_t currentReport = pointing_device_get_report();
    currentReport.x = (left-right) * 50;
    currentReport.y = (up-down) * 50;
    pointing_device_set_report(currentReport);

    pointing_device_send();

    return;

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    static uint8_t led_mode = 0;

    if (record->event.pressed) {
        i2c_start_write(TB_ADDR);
        i2c_master_write(0x01);     // WriteMode
        i2c_master_write(CONFIG_REG_LED_MODE);
        i2c_master_write(led_mode);
        i2c_master_stop();

        print("led_mode:"); print_hex4(led_mode); println();

        led_mode++;
        if(led_mode >= LED_MODE_NUM) {
            led_mode = 0;
        }
    }
    return true;
}
