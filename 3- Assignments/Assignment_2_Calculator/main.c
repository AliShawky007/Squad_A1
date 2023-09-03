/*
 * Calculator.c
 *
 * Created: 8/29/2023 10:10:31 PM
 * Author : Mina
 */ 
#include <stdlib.h>
#include "PORT_CORE.h"
#include "LCD_Core.h"
#include "KeyPad_Core.h"
#include "Calculator.h"
#define F_CPU 16000000U
#include "util/delay.h"


int main(void)
{
	Uint_8 button = 0 ,i=0 ;
	
	Sint_32 result=0;
	PORT_Init();
	LCD_Init();
	KEYPAD_Init();
    
    while (1) 
    {
		button=KEYPAD_GetValue();
		if (button !=0)
		{
			Calculator_Display(button);		
        }
		button = 0;
	
}
}

