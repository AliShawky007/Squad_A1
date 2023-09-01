/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ali
 */ 

#include "LED.h"
#include "BTN.h"
#include "PORT_Core.h"
#include "IRQH_Core.h"

#define  F_CPU  16000000U
#include <util/delay.h>


int main(void)
{
  PORT_Init();
  IRQH_SetGlobalINT(INT_ENABLE);
  IRQH_SetExternalINT();

    while (1) 
    {
		

    }
}

ISR(INT0_vect)
{
	LED_Toggle(LED_GREEN);
}