
#include "GPIO.h"
#include "BIT_MATH.h"
#include <avr/io.h>
//#include "Config.h"
/* Registers */
#define DDRB  *((volatile u8*)0x24)
#define PINB  *((volatile u8*)0x23)
#define PORTB *((volatile u8*)0x25)
//
#define DDRC  *((volatile u8*)0x27)
#define PINC  *((volatile u8*)0x26)
#define PORTC *((volatile u8*)0x28)
//
#define DDRD  *((volatile u8*)0x2A)
#define PIND  *((volatile u8*)0x29)
#define PORTD *((volatile u8*)0x2B)

/* Set Pin Direction */
void GPIO_SetPinDirection(u8 port, u8 pin, u8 direction)
{
    if(direction == GPIO_OUTPUT)
    {
        switch(port)
        {
            case GPIO_PORTB: SET_BIT(DDRB, pin); break;
            case GPIO_PORTC: SET_BIT(DDRC, pin); break;
            case GPIO_PORTD: SET_BIT(DDRD, pin); break;
        }
    }
    else
    {
        switch(port)
        {
            case GPIO_PORTB: CLR_BIT(DDRB, pin); break;
            case GPIO_PORTC: CLR_BIT(DDRC, pin); break;
            case GPIO_PORTD: CLR_BIT(DDRD, pin); break;
        }
    }
}

/* Set Pin Value */
void GPIO_SetPinValue(u8 port, u8 pin, u8 value)
{
    if(value == GPIO_HIGH)
    {
        switch(port)
        {
            case GPIO_PORTB: SET_BIT(PORTB, pin); break;
            case GPIO_PORTC: SET_BIT(PORTC, pin); break;
            case GPIO_PORTD: SET_BIT(PORTD, pin); break;
        }
    }
    else
    {
        switch(port)
        {
            case GPIO_PORTB: CLR_BIT(PORTB, pin); break;
            case GPIO_PORTC: CLR_BIT(PORTC, pin); break;
            case GPIO_PORTD: CLR_BIT(PORTD, pin); break;
        }
    }
}

/* Toggle */
void GPIO_TogglePin(u8 port, u8 pin)
{
    switch(port)
    {
        case GPIO_PORTB: TOGGLE_BIT(PORTB, pin); break;
        case GPIO_PORTC: TOGGLE_BIT(PORTC, pin); break;
        case GPIO_PORTD: TOGGLE_BIT(PORTD, pin); break;
    }
}

/* Get Pin */
u8 GPIO_GetPinValue(u8 port, u8 pin)
{
    switch(port)
    {
        case GPIO_PORTB: return GET_BIT(PINB, pin);
        case GPIO_PORTC: return GET_BIT(PINC, pin);
        case GPIO_PORTD: return GET_BIT(PIND, pin);
    }
    return 0;
}

/* Set Port Direction */
void GPIO_SetPortDirection(u8 port, u8 direction)
{
    switch(port)
    {
        case GPIO_PORTB: DDRB = direction; break;
        case GPIO_PORTC: DDRC = direction; break;
        case GPIO_PORTD: DDRD = direction; break;
    }
}

/* Set Port Value */
void GPIO_SetPortValue(u8 port, u8 value)
{
    switch(port)
    {
        case GPIO_PORTB: PORTB = value; break;
        case GPIO_PORTC: PORTC = value; break;
        case GPIO_PORTD: PORTD = value; break;
    }
}

/* Get Port Value */
u8 GPIO_GetPortValue(u8 port)
{
    switch(port)
    {
        case GPIO_PORTB: return PINB;
        case GPIO_PORTC: return PINC;
        case GPIO_PORTD: return PIND;
    }

    return 0;
}