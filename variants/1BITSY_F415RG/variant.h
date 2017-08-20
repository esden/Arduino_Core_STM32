/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "Arduino.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
#include "PeripheralPins.h"

extern const PinName digitalPin[];

enum {
// Regular Pins Left side
  PC10, //D0
  PC11, //D1
  PC12, //D2
  PD2,  //D3
  PB4,  //D4
  PB5,  //D5
  PB6,  //D6
  PB7,  //D7
  PB8,  //D8
  PB9,  //D9
  PC2,  //D10
  PC3,  //D11
// Regular Pins Right side
  PB0,  //D12
  PB1,  //D13
  PB10, //D14
  PB11, //D15
  PB12, //D16
  PB13, //D17
  PB14, //D18
  PB15, //D19
  PC6,  //D20
  PC7,  //D21
  PC8,  //D22
  PC9,  //D23
// Regular Pins Bottom side
  PA0,  //D24
  PA1,  //D25
  PA2,  //D26
  PA3,  //D27
  PA4,  //D28
  PA5,  //D29
  PA6,  //D30
  PA7,  //D31
  PC4,  //D32
  PC5,  //D33
// Regular Pins Extra
  PC13, //D34
  PC0,  //D35
  PB2,  //D36
// Functional Pins
  PA8,  //D37 - Orange LED
  PC1,  //D38 - User Button
  PC15, //D39 - RTC XTal Out
  PC14, //D40 - RTC XTal In
  PA10, //D41 - USB ID
  PA12, //D42 - USB D+
  PA11, //D43 - USB D-
  PA9,  //D44 - USB V+
  PB3,  //D45 - JTDO/TRACESWO
  PA13, //D46 - JTMS/SWDIO
  PA14, //D47 - JTCK/SWCLK
  PA15, //D48 - JTDI
//Duplicated to have A0-A9 as F407 do not have Uno like connector
// and to be aligned with PinMap_ADC
  PC2_2,//D49/A0 = D10
  PC3_2,//D50/A1 = D11
  PA0_2,//D51/A2 = D24
  PA1_2,//D52/A3 = D25
  PA2_2,//D53/A4 = D26
  PA3_2,//D54/A5 = D27
  PC4_2,//D55/A6 = D32
  PC5_2,//D56/A7 = D33
  PB0_2,//D57/A8 = D12
  PB1_2,//D58/A9 = D13
  PEND
};

enum {
  A_START_AFTER = D48,
  A0,  A1,  A2,  A3,  A4,  A5,  A6, A7, A8, A9,
  AEND
};

//ADC resolution is 12bits
#define ADC_RESOLUTION          12
#define DACC_RESOLUTION         12

//PWR resolution
#define PWM_RESOLUTION          8
#define PWM_FREQUENCY           1000
#define PWM_MAX_DUTY_CYCLE      255

//On-board LED pin number
#define LED_BUILTIN             37
#define LED_ORANGE              LED_BUILTIN

//On-board user button
#define USER_BTN                38


//SPI definitions
//define 16 channels. As many channel as digital IOs
#define SPI_CHANNELS_NUM        16

//default chip salect pin
#define BOARD_SPI_DEFAULT_SS    10

//In case SPI CS channel is not used we define a default one
#define BOARD_SPI_OWN_SS        SPI_CHANNELS_NUM

#define SS                      BOARD_SPI_DEFAULT_SS
#define SS1                     4
#define SS2                     14
#define MOSI                    44
#define MISO                    5
#define SCLK                    43
#define SCK                     SCLK

//I2C Definitions
#define SDA                     66
#define SCL                     26

//Timer Definitions
//Do not use timer used by PWM pin. See PinMap_PWM.
#define TIMER_TONE              TIM6
#define TIMER_SERVO             TIM7
#define TIMER_UART_EMULATED     TIM6

#define DEBUG_UART              ((USART_TypeDef *) USART2)

// UART Emulation
#define UART_EMUL_RX            PE_9
#define UART_EMUL_TX            PE_11

// Serial Pin Firmata
#define PIN_SERIAL_RX           42
#define PIN_SERIAL_TX           3

#ifdef __cplusplus
} // extern "C"
#endif
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern HardwareSerial Serial;

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR Serial // Require connections for ST-LINK VCP on U2 pin 12 and 13.
                                   // See UM §6.1.3 ST-LINK/V2-A VCP configuration)
#define SERIAL_PORT_HARDWARE_OPEN  Serial
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
