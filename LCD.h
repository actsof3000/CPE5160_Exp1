#ifndef LCD_H
#define LCD_H

#include "Main.h"

sbit RS = P1^0;
sbit E = P1^1;

void LCD_Init(void);

void LCD_Print(uint8_t* string);

#endif