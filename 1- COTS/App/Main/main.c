/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Mostafa
 */ 

#include "Buzzer.h"
#include "Button.h"
#include "SEVEN_SEG.h"
#include "PORT_CORE.h"

#define F_CPU 16000000U
#include <util/delay.h>


int main(void)
{
	uint8 VAL=0,BUT0,BUT1,BUT2,i=0;
	PORT_INIT();
	while (1)
	{
		SEVEN_SEG_OUT(VAL);
		BUT0=GET_BUTTON(Button_0);
		if(BUT0==0)
		{
			if((VAL%10)<5)
			{
				VAL++;
			}
		}
		BUT1=GET_BUTTON(Button_1);
		if(BUT1==0)
		{
			if((VAL)/10<9)
			{
				VAL=VAL+10;
			}
		}
		BUT2=GET_BUTTON(Button_2);
		if(BUT2==0)
		{
			while(VAL!=0)
			{
				for (i=0;i<500;i++)
				{
					SEVEN_SEG_OUT(VAL);
				}
				if(((VAL%10)==0)&&(VAL>=10))
				{
					VAL=VAL-5;
				}
				else{VAL--;}
			}
			BUZ_SetValue(PIN_HIGH);
			_delay_ms(1000);
			BUZ_SetValue(PIN_LOW);
		}
	}
}