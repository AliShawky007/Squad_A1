/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:01 PM
 * Author : Moamen
 */ 
#include "LED.h"
#include "BTN.h"
#include "PORT_Core.h"
#include "DIO_Core.h"

#define F_CPU 16000000U
#include <util/delay.h>
uint8 val1=1, val2=1,f=0;
uint8 j=0,sec=0;
uint16 i=0;

int main(void)
{	

	PORT_Init();
    while (1) 
    {
		Seven_Seg_display(sec);
		val1=BTN_GetValue(Button_0);
		if(val1 == 0)
		{
			sec++;
			Seven_Seg_display(sec);
		}
		val2=BTN_GetValue(Button_1);
		if (val2 == 0 && val1==1)
		{
			//Seven_Seg_display(sec);

			for(j=sec;j>=0;j--)
			{
				for(i=0;i<=500;i++)
				{
					Seven_Seg_display(j);
				}

				if(j==0)
				{
					Buzzer_on();
					_delay_ms(1000);
					sec=0;
					break;
				}
			}
							

		}		
	}
}

