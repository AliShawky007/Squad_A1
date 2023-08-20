/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ali
 */ 

#include "LED.h"
#include "BTN.h"
#include "PORT_Core.h"

#define  F_CPU  16000000U
#include <util/delay.h>


int main(void)
{
  uint8 val = 0;
  
  PORT_Init();

    while (1) 
    {
		val = BTN_GetValue(Button_0);
		
		if(val == 0)
		{
			LED_Toggle(LED_GREEN);
		}


    }
}

