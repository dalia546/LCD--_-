

#ifndef GPIO_H
#define GPIO_H

#include "BIT_MATH.h"
#include "STD_Types.h"

/* Ports */
#define GPIO_PORTB 0
#define GPIO_PORTC 1
#define GPIO_PORTD 2

/* Pins */
#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7

/* Direction */
#define GPIO_INPUT  0
#define GPIO_OUTPUT 1

/* Value */
#define GPIO_LOW  0
#define GPIO_HIGH 1
#include "Config.h"
/* APIs */
void GPIO_SetPinDirection(u8 port, u8 pin, u8 direction);
void GPIO_SetPortDirection(u8 port, u8 direction);

void GPIO_SetPinValue(u8 port, u8 pin, u8 value);
void GPIO_TogglePin(u8 port, u8 pin);

void GPIO_SetPortValue(u8 port, u8 value);

u8 GPIO_GetPinValue(u8 port, u8 pin);
u8 GPIO_GetPortValue(u8 port);

#endif