/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ahmed Essam
 */ 

#include "BTN.h"
#include "PORT_Core.h"
#include "SevSeg_Core.h"
#include "Timer.h"
#include "BUZZER.h"

#define  F_CPU  16000000U
#include <util/delay.h>

/*project to take from user minutes and seconds to set timer*/
int main(void)
{
	/*initialize the used pins in project*/
	PORT_Init();
	
	uint8 BTN1 = 0 , BTN2 = 0 , BTN3 = 0 , BTN4 = 0;
	sint8 Sec=0 , Min=0;
	while (1)
	{
		while (1)
		{
			BTN1 = BTN_GetValue(Button_0);
			BTN2 = BTN_GetValue(Button_1);
			BTN3 = BTN_GetValue(Button_2);
			BTN4 = BTN_GetValue(Button_3);
			/*conditions check which button was pressed and btn1 increment the minutes , btn2 the seconds
			btn 3 starts the timer*/
			if ( BTN1 == pressed)
			{
				if (Min==9)/*return to 0 if exceeds 9*/
				{
					Min=0;
					continue;
				}
				Min++;
			}
		
			if (BTN2 == pressed)
			{
				if (Sec==6) /*return to 0 if exceeds 9*/
				{
					Min++;
					Sec=0;
					continue;
				}
				Sec++;
			}
		
			if (BTN3 == pressed)
			{
				if (Sec==0 && Min==0) continue; /*guard if no time is set dont do any thing*/
				break;
			}
			
			if (BTN4 == pressed) /*Restart and ask for new inputs if btn 4 is pressed*/
			{
				Min=0;
				Sec=0;
				continue;
			}
		
			/*display the minutes and seconds on left digit*/
			SevSeg_Display((Min*10)+Sec);
		}
		
		Timer(Min,Sec); /*Calling timer function*/
		
		/*buzzer loop to alerts after timer is off and restarts & ask for new inputs if btn 4 is pressed*/
		while(1)
		{	
			BTN4 = BTN_GetValue(Button_3);
			BUZZER_toggle();
			_delay_ms(200);
			if(BTN4 == pressed)
			{
				BUZZER_SET_VALUE(BUZZER_LOW);
				break;
			}
		}
	}		
}

