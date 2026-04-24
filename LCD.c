#include "LCD.h"
#include "GPIO.h"

#define F_CPU 16000000UL
#include <util/delay.h>

static void LCD_EnablePulse(void)
{
    GPIO_SetPinValue(GPIO_PORTC, LCD_EN, GPIO_HIGH);
    _delay_us(2);
    GPIO_SetPinValue(GPIO_PORTC, LCD_EN, GPIO_LOW);
    _delay_us(20);
}

void LCD_Command(u8 cmd)
{
    GPIO_SetPinValue(GPIO_PORTC, LCD_RS, GPIO_LOW);

    // ?? RW ????? ?????????:
    GPIO_SetPinValue(GPIO_PORTC, LCD_RW, GPIO_LOW);

    GPIO_SetPortValue(GPIO_PORTB, cmd);
    LCD_EnablePulse();
}

void LCD_Char(u8 data)
{
    GPIO_SetPinValue(GPIO_PORTC, LCD_RS, GPIO_HIGH);

    GPIO_SetPinValue(GPIO_PORTC, LCD_RW, GPIO_LOW);

    GPIO_SetPortValue(GPIO_PORTB, data);
    LCD_EnablePulse();
}

void LCD_Init(void)
{
    GPIO_SetPortDirection(GPIO_PORTB, GPIO_OUTPUT);

    GPIO_SetPinDirection(GPIO_PORTC, LCD_RS, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, LCD_EN, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, LCD_RW, GPIO_OUTPUT);

    _delay_ms(40);

    LCD_Command(0x38);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
    _delay_ms(2);
}

void LCD_String(u8 *str)
{
    while(*str)
    {
        LCD_Char(*str++);
    }
}

void LCD_Clear(void)
{
    LCD_Command(0x01);
    _delay_ms(2);
}

