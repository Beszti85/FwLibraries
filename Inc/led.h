/*
 * led.h
 *
 *  Created on: March 16, 2026
 *      Author: Csaba Besztercei
 */

#ifndef LED_H_
#define LED_H_

#include <stdint.h>
#include <stdbool.h>
#include "main.h"

typedef enum
{
  RED = 0,
  YELLOW = 1,
  GREEN = 2,
  BLUE,
  WHITE
} LED_Color_e;

typedef struct
{
  TIM_HandleTypeDef* PtrTimHandle;
  GPIO_TypeDef*      PtrGpioPort;
  uint16_t           GpioPin;
  bool               ActiveState;
  bool               PwmCtrl;      // Enable/Disable PWM ctrl
  uint8_t            DutyCycle;    // Percentage in one decimal point
  LED_Color_e        Color;
} LED_Handler_s;

void LED_Toggle( LED_Handler_s* ptrHandler );
uint8_t LED_GetPwmDuty( LED_Handler_s* ptrHandler );
void SetPwmDuty( LED_Handler_s* ptrHandler, uint8_t percentage );


#endif /* LED_H_ */