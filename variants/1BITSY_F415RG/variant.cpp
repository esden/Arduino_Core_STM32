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

#include "variant.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
const PinName digitalPin[] = {
// Regular Pins Left side
  PC_10, //D0
  PC_11, //D1
  PC_12, //D2
  PD_2,  //D3
  PB_4,  //D4
  PB_5,  //D5
  PB_6,  //D6
  PB_7,  //D7
  PB_8,  //D8
  PB_9,  //D9
  PC_2,  //D10
  PC_3,  //D11
// Regular Pins Right side
  PB_0,  //D12
  PB_1,  //D13
  PB_10, //D14
  PB_11, //D15
  PB_12, //D16
  PB_13, //D17
  PB_14, //D18
  PB_15, //D19
  PC_6,  //D20
  PC_7,  //D21
  PC_8,  //D22
  PC_9,  //D23
// Regular Pins Bottom side
  PA_0,  //D24
  PA_1,  //D25
  PA_2,  //D26
  PA_3,  //D27
  PA_4,  //D28
  PA_5,  //D29
  PA_6,  //D30
  PA_7,  //D31
  PC_4,  //D32
  PC_5,  //D33
// Regular Pins Extra
  PC_13, //D34
  PC_0,  //D35
  PB_2,  //D36
// Functional Pins
  PA_8,  //D37 - Orange LED
  PC_1,  //D38 - User Button
  PC_15, //D39 - RTC XTal Out
  PC_14, //D40 - RTC XTal In
  PA_10, //D41 - USB ID
  PA_12, //D42 - USB D+
  PA_11, //D43 - USB D-
  PA_9,  //D44 - USB V+
  PB_3,  //D45 - JTDO/TRACESWO
  PA_13, //D46 - JTMS/SWDIO
  PA_14, //D47 - JTCK/SWCLK
  PA_15, //D48 - JTDI
//Duplicated to have A0-A9 as F407 do not have Uno like connector
// and to be aligned with PinMap_ADC
  PC_2,//D49/A0 = D10
  PC_3,//D50/A1 = D11
  PA_0,//D51/A2 = D24
  PA_1,//D52/A3 = D25
  PA_2,//D53/A4 = D26
  PA_3,//D54/A5 = D27
  PC_4,//D55/A6 = D32
  PC_5,//D56/A7 = D33
  PB_0,//D57/A8 = D12
  PB_1,//D58/A9 = D13
};

#ifdef __cplusplus
}
#endif

/*
 * UART objects
 */

HardwareSerial  Serial(PA_3, PA_2); // Could be connected to ST-Link

void serialEvent() __attribute__((weak));
void serialEvent() { }

void serialEventRun(void)
{
  if (Serial.available()) serialEvent();
}

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                                  RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  /* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
  if (HAL_GetREVID() == 0x1001)
  {
    /* Enable the Flash prefetch */
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
  }
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

#ifdef __cplusplus
}
#endif
