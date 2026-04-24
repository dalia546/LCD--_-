/* 
 * File:   LCD.h
 * Author: Owner
 *
 * Created on April 18, 2026, 12:36 PM
 */
//
//#ifndef LCD_H
//#define	LCD_H
//
//
//
//#include "STD_Types.h"
//#include "Config.h"
///* LCD APIs */
//#define LCD_RS 0
//#define LCD_EN 1
//#define LCD_RW 2
//
//void LCD_Init(void);
//void LCD_Command(u8 cmd);
//void LCD_Char(u8 data);
//void LCD_String(u8 *str);
//void LCD_Clear(void);
//
//#endif



#ifndef LCD_H
#define LCD_H

#include "STD_Types.h"

void LCD_Init(void);
void LCD_Command(u8 cmd);
void LCD_Char(u8 data);
void LCD_String(u8 *str);
void LCD_Clear(void);

#endif



