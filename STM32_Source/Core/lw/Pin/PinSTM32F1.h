#pragma once
#include "stm32f1xx_hal.h"

#define LW_PIN_FIELDS \
GPIO_TypeDef* port; \
uint16_t pin; \
bool isReversed = false; \

#define LW_PIN_CONSTRUCTOR \
Pin(GPIO_TypeDef* port, uint16_t pin, bool isHighMeanSet = true) : port(port), pin(pin), isReversed(!isHighMeanSet)	{} \

#define LW_PIN_IS_SET (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET) ? !isReversed : isReversed;

#define LW_PIN_WRITE \
if(isReversed) \
	HAL_GPIO_WritePin(port, pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET); \
else \
	HAL_GPIO_WritePin(port, pin, state ? GPIO_PIN_SET : GPIO_PIN_RESET); \

#define LW_PIN_TOOGLE HAL_GPIO_TogglePin(port, pin);
