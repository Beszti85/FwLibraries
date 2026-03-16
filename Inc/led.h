/*
 * led.h
 *
 *  Created on: March 16, 2026
 *      Author: Csaba Besztercei
 */

#ifndef LED_H_
#define LED_H_

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
  GPIO_TypeDef* PtrGpioPort;
  bool          ActiveState;
  bool          PwmCtrl;      // Enable/Disable PWM ctrl
  uint8_t       DutyCycle;    // Percentage
  LED_Color_e   Color;
} LED_Handler_s;




#endif /* LED_H_ */