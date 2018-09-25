#include "LCD.h"
#include "AT89C51RC2.h"
#include "Util.h"

void LCD_Write_Command(uint8_t value)
{
	RS = 0;
	E = 1;
	P0 = value;
	E = 0;
	P0 = 0xFF;
}

void LCD_Write_Text(uint8_t value)
{
	RS = 1;
	E = 1;
	P0 = value;
	E = 0;
	P0 = 0xFF;
}

void LCD_Print(uint8_t* string)
{
	uint8_t i = 0;
	while(&(string + i))
	{
		LCD_Write_Text(&(string + i));
		i++;
	}
}

void LCD_Init(void) 
{
	delay_ms(30); //delay after power up 
	LCD_Write_Command(0x38);  // constant better than 0x3C
	delay_ms(5);    // greater than 4.1ms delay
	LCD_Write_Command(0x38);  // Function Set repeated 4 times
	delay_ms(1);    // greater than 100us delay
	LCD_Write_Command(0x38); 
	delay_ms(1);
	LCD_Write_Command(0x38);  
	delay_ms(1);
	LCD_Write_Command(0x0C);  // Display on, cursor off
	delay_ms(1);
	LCD_Write_Command(0x01);  // display clear
	delay_ms(3);    // wait until memory cleared
	LCD_Write_Command(0x06);  // Entry mode set, Increment
	delay_ms(1);
}