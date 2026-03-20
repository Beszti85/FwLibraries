/*
 * led.c
 *
 *  Created on: March 16, 2026
 *      Author: Csaba Besztercei
 */

#include "led.h"
#include <stdint.h>

void LED_Toggle( LED_Handler_s* ptrHandler )
{
    HAL_GPIO_TogglePin( ptrHandler->PtrGpioPort, ptrHandler->GpioPin );
}

uint8_t LED_GetPwmDuty( LED_Handler_s* ptrHandler )
{
  uint8_t retval = 0u;
  uint32_t tempU32 = 0u;

  if( ptrHandler->PwmCtrl == true)
  {
    // CCR register: 16 bit, maximum is 65535
    tempU32 = (uint32_t)ptrHandler->PtrTimHandle->Instance->CCR1;
    retval = (uint8_t)(tempU32 * 100u / 65535u);
  }
  else
  {
    retval = 100u;
  }  

  return retval;
}

void SetPwmDuty( LED_Handler_s* ptrHandler, uint8_t percentage )
{
  // Calculate CCR value from the given percentage
  ptrHandler->PtrTimHandle->Instance->CCR1 = (uint16_t)((uint32_t)percentage * 65535u / 100u);
}