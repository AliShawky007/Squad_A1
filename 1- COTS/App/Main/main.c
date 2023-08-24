/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ali
 */ 

#include "LED.h"
#include "Button.h"
#include "Relay.h"
#include "BUZ.h"
#include "LCD_CORE.h"
#include "SEVEN_SEGh.h"
#include "PORT_CORE.h"
#define  F_CPU  16000000U
#include <util/delay.h>

int main(void)
{
   /*LCD_CLR();  
   PORT_INIT();
   LCD_INIT();
   LCD_write_char('A');*/
	uint8 val=0;
	uint8 R=0;
   PORT_INIT();
   uint8 VAL=0;
   uint8 CNT=0;
   
    while (1) 
    {
	   SEG_SETVALUE(VAL);
		val=BTN_GET(Button_0);
		if(val==0)
		{
			_delay_ms(10000);
			
			SEG_SETVALUE(VAL++);
			
		}
		R=BTN_GET(Button_1);
		if(R==0)
		{
			if(VAL==6)
			{
				SEG_SETVALUE(VAL+=10);
				_delay_ms(1000);
				SEG_SETVALUE(VAL-=6);
			}
			

		}
	    int n=BTN_GET(Button_2);
		if(n==0)
		{
			
			for(CNT=VAL-1;CNT>=0;CNT--)
			{
				_delay_ms(10000);
				SEG_SETVALUE(CNT);
				_delay_ms(1000);
				if(CNT>10)
				{
					_delay_ms(10000);
					SEG_SETVALUE(CNT-=5);
					_delay_ms(1000);
					
				}
				
				if(CNT==0)
				{
					BUZ_SETVALUE(BUZZER_0,1);
					_delay_ms(500);
					BUZ_SETVALUE(BUZZER_0,0);
					break;
				}
				
			}
			
			
		}
			}  
	}
		
	
  
	

