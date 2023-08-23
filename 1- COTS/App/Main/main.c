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
uint8 i=0,j=0,sec=0;

int main(void)
{	

PORT_Init();





    while (1) 
    {
	
		/*val1 = BTN_GetValue(Button_0);
		if(val1==0)
		{
			uint8 i=0,j=0;
			for(i=0;i<99;i++)
			{
				Seven_Seg_display(i);
				_delay_ms(1000);
				val2=BTN_GetValue(Button_1);
				if(Button_1==0)
				{
					for(j=i;i>=0;j--)
					{
						Seven_Seg_display(j);
					}
					Buzzer_on();
				}
				
			}
		}*/
		SevSeg_Display(sec);
		val1=BTN_GetValue(Button_0);
	
		if(val1 == 0)
		{
			SevSeg_Display(++sec);
		}
		
		val2=BTN_GetValue(Button_1);
		if (val2 == 0)
		{

					for(j=sec;j>=0;j--)
					{
						
					   
						SevSeg_Display(j);
						_delay_ms(1000);
					}
		}

		
	}

}

