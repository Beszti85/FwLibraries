/*
 * led.c
 *
 *  Created on: March 16, 2026
 *      Author: Csaba Besztercei
 */

#include "led.h"
#include <stdint.h>

void LED_Toggle( LED_IO_Handler_s* ptrHandler )
{
    HAL_GPIO_TogglePin( ptrHandler->PtrGpioPort, ptrHandler->GpioPin );
}

uint8_t LED_GetPwmDuty( LED_PWM_Handler_s* ptrHandler )
{
  uint8_t retval = 0u;
  uint32_t tempU32 = 0u;

  if( ptrHandler->PwmCtrl == true)
  {
    // CCR register: 16 bit, maximum is 65535
    tempU32 = __HAL_TIM_GET_COMPARE( ptrHandler->PtrTimHandle, ptrHandler->Channel );
    retval = (uint8_t)(tempU32 * 100u / 65535u);
  }
  else
  {
    retval = 100u;
  }  

  return retval;
}

void LED_SetPwmDuty( LED_PWM_Handler_s* ptrHandler, uint8_t percentage )
{
  // Calculate CCR value from the given percentage
  __HAL_TIM_SET_COMPARE( ptrHandler->PtrTimHandle, ptrHandler->Channel, (uint16_t)((uint32_t)percentage * 65535u / 100u) );
}