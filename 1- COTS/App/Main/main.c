/*
 * Smart Lock Door System.c
 *
 * Created: 9/25/2023 7:20:18 PM
 * Author : Mina
 */ 

#include "PORT_CORE.h"
#include "KeyPad_Core.h"
#include "LCD_Core.h"
#include "SMARTDOOR_CORE.h"

int main(void)
{
    Uint_8 button = 0;
	PORT_Init();
	LCD_Init();
	KEYPAD_Init();
	SERVO_Init();
	DIO_WriteChannel(LED_RED,led_high);
	LCD_WriteString("Code:");
    while (1) 
    {
		
		button = KEYPAD_GetValue();
		if (button!=0)
		{
			Smart_Door_Init(button);
		}
		button = 0;
    }
}

