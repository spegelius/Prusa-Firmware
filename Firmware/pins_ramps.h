/*****************************************************************
* RAMPS 1.3 Pin Assignments
******************************************************************/

#define ELECTRONICS "RAMPS"

#define KNOWN_BOARD
#ifndef __AVR_ATmega2560__
  #error Oops!  Make sure you have 'Arduino Mega 2560 or Rambo' selected from the 'Tools -> Boards' menu.
#endif

#define PINDA_THERMISTOR

#define LARGE_FLASH true

#define SWI2C_SDA      2 // x max
#define SWI2C_SCL      15 // y max

//
// Servos
//
#ifdef IS_RAMPS_13
  #define SERVO0_PIN        7 // RAMPS_13 // Will conflict with BTN_EN2 on LCD_I2C_VIKI
#else
  #define SERVO0_PIN       11
#endif
#define SERVO1_PIN          6
#define SERVO2_PIN          5
#define SERVO3_PIN          4

//
// Limit Switches
//
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  32
#endif

#define SLED_PIN           -1

//
// Steppers
//
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53
#define X_MS1_PIN          -1
#define X_MS2_PIN          -1

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_CS_PIN           49
#define Y_MS1_PIN          -1
#define Y_MS2_PIN          -1

//#define Z_STEP_PIN         46
//#define Z_DIR_PIN          48
//#define Z_ENABLE_PIN       62
//#define Z_CS_PIN           40
//#define Z_MS1_PIN          -1
//#define Z_MS2_PIN          -1

#define E1_STEP_PIN         46
#define E1_DIR_PIN          48
#define E1_ENABLE_PIN       62
#define E1_CS_PIN           40
#define E1_MS1_PIN          -1
#define E1_MS2_PIN          -1

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24
#define E0_CS_PIN          42
#define E0_MS1_PIN         -1
#define E0_MS2_PIN         -1

//#define E1_STEP_PIN        36
//#define E1_DIR_PIN         34
//#define E1_ENABLE_PIN      30
//#define E1_CS_PIN          44
//#define E1_MS1_PIN         -1
//#define E1_MS2_PIN         -1

#define Z_STEP_PIN        36
#define Z_DIR_PIN         34
#define Z_ENABLE_PIN      30
#define Z_CS_PIN          44
#define Z_MS1_PIN         -1
#define Z_MS2_PIN         -1

#define EXTRUDER_0_AUTO_FAN_PIN 6
#define CONTROLLERFAN_PIN      7  //Pin used for the fan to cool controller (-1 to disable)
//
// Temperature Sensors
//
#define TEMP_0_PIN         13   // Analog Input
#define TEMP_1_PIN         15   // Analog Input
#define TEMP_BED_PIN       14   // Analog Input

#define TEMP_AMBIENT_PIN        -1
#define TEMP_PINDA_PIN          -1

// SPI for Max6675 or Max31855 Thermocouple
#if !defined(SDSUPPORT)
  #define MAX6675_SS       66 // Do not use pin 53 if there is even the remote possibility of using Display/SD card
#else
  #define MAX6675_SS       66 // Do not use pin 49 as this is tied to the switch inside the SD card socket to detect if there is an SD card present
#endif

//
// Augmentation for auto-assigning RAMPS plugs
//
#define PIN_EXISTS(PN) (defined(PN ##_PIN) && PN ##_PIN >= 0)
#if !defined(IS_RAMPS_EEB) && !defined(IS_RAMPS_EEF) && !defined(IS_RAMPS_EFB) && !defined(IS_RAMPS_EFF) && !defined(IS_RAMPS_SF) && !PIN_EXISTS(MOSFET_D)
  #if HOTENDS > 1
    #if TEMP_SENSOR_BED
      #define IS_RAMPS_EEB
    #else
      #define IS_RAMPS_EEF
    #endif
  #elif TEMP_SENSOR_BED
    #define IS_RAMPS_EFB
  #else
    #define IS_RAMPS_EFF
  #endif
#endif

//#define MOTOR_CURRENT_PWM_XY_PIN -1
//#define MOTOR_CURRENT_PWM_Z_PIN  -1
//#define MOTOR_CURRENT_PWM_E_PIN  -1

//
// Heaters / Fans
//
#ifndef MOSFET_D_PIN
  #define MOSFET_D_PIN  -1
#endif
#ifndef RAMPS_D8_PIN
  #define RAMPS_D8_PIN   8
#endif
#ifndef RAMPS_D9_PIN
  #define RAMPS_D9_PIN   9
#endif
#ifndef RAMPS_D10_PIN
  #define RAMPS_D10_PIN 10
#endif

#define HEATER_0_PIN     RAMPS_D10_PIN

#if defined(IS_RAMPS_EFB)                      // Hotend, Fan, Bed
  #define FAN_PIN        RAMPS_D9_PIN
  #define HEATER_BED_PIN RAMPS_D8_PIN
#elif defined(IS_RAMPS_EEF)                    // Hotend, Hotend, Fan
  #define HEATER_1_PIN   RAMPS_D9_PIN
  #define FAN_PIN        RAMPS_D8_PIN
#elif defined(IS_RAMPS_EEB)                    // Hotend, Hotend, Bed
  #define HEATER_1_PIN   RAMPS_D9_PIN
  #define HEATER_BED_PIN RAMPS_D8_PIN
#elif defined(IS_RAMPS_EFF)                    // Hotend, Fan, Fan
  #define FAN_PIN        RAMPS_D9_PIN
  #define FAN1_PIN       RAMPS_D8_PIN
#elif defined(IS_RAMPS_SF)                     // Spindle, Fan
  #define FAN_PIN        RAMPS_D8_PIN
#else                                          // Non-specific are "EFB" (i.e., "EFBF" or "EFBE")
  #define FAN_PIN        RAMPS_D9_PIN
  #define HEATER_BED_PIN RAMPS_D8_PIN
  #if HOTENDS == 1
    #define FAN1_PIN     MOSFET_D_PIN
  #else
    #define HEATER_1_PIN MOSFET_D_PIN
  #endif
#endif

#define FAN_1_PIN           -1
#define TACH_0              -1

#ifndef FAN_PIN
  #define FAN_PIN 4      // IO pin. Buffer needed
#endif

//
// Misc. Functions
//
#define SDSS               53
#define LED_PIN            13

// Use the RAMPS 1.4 Analog input 5 on the AUX2 connector
#define FILWIDTH_PIN        -1 //5   // Analog Input

// define digital pin 4 for the filament runout sensor. Use the RAMPS 1.4 digital input 4 on the servos connector
#define FIL_RUNOUT_PIN      4

#define PS_ON_PIN          12
#define SUICIDE_PIN        -1
#define IR_SENSOR_PIN      19 // z max
//
// LCD / Controller
//

#if defined(REPRAPWORLD_GRAPHICAL_LCD)
  #define LCD_PINS_RS     49 // CS chip select /SS chip slave select
  #define LCD_PINS_ENABLE 51 // SID (MOSI)
  #define LCD_PINS_D4     52 // SCK (CLK) clock
#elif defined(PANEL_ONE)
  #define LCD_PINS_RS 40
  #define LCD_PINS_ENABLE 42
  #define LCD_PINS_D4 65
  #define LCD_PINS_D5 66
  #define LCD_PINS_D6 44
  #define LCD_PINS_D7 64
#else
  #define LCD_PINS_RS 16
  #define LCD_PINS_ENABLE 17
  #define LCD_PINS_D4 23
  #define LCD_PINS_D5 25
  #define LCD_PINS_D6 27
  #define LCD_PINS_D7 29
#endif

#if defined(REPRAP_DISCOUNT_SMART_CONTROLLER)
  #define BEEPER_PIN 37

  #define BTN_EN1 33
  #define BTN_EN2 31
  #define BTN_ENC 35

  #define SDCARDDETECT 49
  #define KILL_PIN 41

  #if defined(BQ_LCD_SMART_CONTROLLER)
    #define LCD_BACKLIGHT_PIN 39
  #endif

#elif defined(REPRAPWORLD_GRAPHICAL_LCD)
  #define BTN_EN1 64
  #define BTN_EN2 59
  #define BTN_ENC 63
  #define SDCARDDETECT 42
#elif defined(LCD_I2C_PANELOLU2)
  #define BTN_EN1 47  // reverse if the encoder turns the wrong way.
  #define BTN_EN2 43
  #define BTN_ENC 32
  #define LCD_SDSS 53
  #define SDCARDDETECT -1
  #define KILL_PIN 41
#elif defined(LCD_I2C_VIKI)
  #define BTN_EN1 22  // reverse if the encoder turns the wrong way.
  #define BTN_EN2 7   // http://files.panucatt.com/datasheets/viki_wiring_diagram.pdf
                      // tells about 40/42.
                      // 22/7 are unused on RAMPS_14. 22 is unused and 7 the SERVO0_PIN on RAMPS_13.
  #define BTN_ENC -1
  #define LCD_SDSS 53
  #define SDCARDDETECT 49
#elif defined(VIKI2) || defined(miniVIKI)
  #define BEEPER_PIN       33

  // Pins for DOGM SPI LCD Support
  #define DOGLCD_A0        44
  #define DOGLCD_CS        45
  #define LCD_SCREEN_ROT_180

  #define BTN_EN1          22
  #define BTN_EN2           7
  #define BTN_ENC          39

  #define SDSS             53
  #define SDCARDDETECT    -1  // Pin 49 for display sd interface, 72 for easy adapter board

  #define KILL_PIN         31

  #define STAT_LED_RED_PIN 32
  #define STAT_LED_BLUE_PIN 35

#elif defined(ELB_FULL_GRAPHIC_CONTROLLER)
  #define BTN_EN1 35  // reverse if the encoder turns the wrong way.
  #define BTN_EN2 37
  #define BTN_ENC 31
  #define SDCARDDETECT 49
  #define LCD_SDSS 53
  #define KILL_PIN 41
  #define BEEPER_PIN 23
  #define DOGLCD_CS 29
  #define DOGLCD_A0 27
  #define LCD_BACKLIGHT_PIN 33
#elif defined(MINIPANEL)
  #define BEEPER_PIN 42
  // Pins for DOGM SPI LCD Support
  #define DOGLCD_A0  44
  #define DOGLCD_CS  66
  #define LCD_BACKLIGHT_PIN 65 // backlight LED on A11/D65
  #define SDSS   53

  #define KILL_PIN 64
  // GLCD features
  //#define LCD_CONTRAST 190
  // Uncomment screen orientation
  //#define LCD_SCREEN_ROT_90
  //#define LCD_SCREEN_ROT_180
  //#define LCD_SCREEN_ROT_270
  // The encoder and click button
  #define BTN_EN1 40
  #define BTN_EN2 63
  #define BTN_ENC 59
  // not connected to a pin
  #define SDCARDDETECT 49

#else

  // Beeper on AUX-4
  #define BEEPER_PIN 33

  // buttons are directly attached using AUX-2
  #if defined(REPRAPWORLD_KEYPAD)
    #define BTN_EN1 64 // encoder
    #define BTN_EN2 59 // encoder
    #define BTN_ENC 63 // enter button
    #define SHIFT_OUT 40 // shift register
    #define SHIFT_CLK 44 // shift register
    #define SHIFT_LD 42 // shift register
  #elif defined(PANEL_ONE)
    #define BTN_EN1 59 // AUX2 PIN 3
    #define BTN_EN2 63 // AUX2 PIN 4
    #define BTN_ENC 49 // AUX3 PIN 7
  #else
    #define BTN_EN1 37
    #define BTN_EN2 35
    #define BTN_ENC 31 // the click
  #endif

  #if defined(G3D_PANEL)
    #define SDCARDDETECT 49
    #define KILL_PIN 41
  #else
    //#define SDCARDDETECT -1 // Ramps doesn't use this
  #endif
#endif

#define SDPOWER -1
#define BEEPER BEEPER_PIN
#define TEMP_2_PIN TEMP_BED_PIN

// The Z2 axis, if any, should be the next open extruder port
#define __EPIN(p,q) E##p##_##q##_PIN
#define _EPIN(p,q) __EPIN(p,q)
#if defined(Z_DUAL_STEPPER_DRIVERS)
  #ifndef Z2_STEP_PIN
    #define Z2_STEP_PIN   E1_STEP_PIN
    #define Z2_DIR_PIN    E1_DIR_PIN
    #define Z2_ENABLE_PIN E1_ENABLE_PIN
    #define Z2_CS_PIN     E1_CS_PIN
  #endif
  #undef _Z2_PINS
  #define _Z2_PINS Z2_STEP_PIN, Z2_DIR_PIN, Z2_ENABLE_PIN,
#endif


