/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Mohamed Osama
 */ 

#include "App.h"	
sint8 Stop_watch_val=0;

int main(void)
{
	PORT_Init();
    while (1) 
    {
	if(BTN_GetValue(BUTTON_0)==BUTTON_PRESSED){
		Choose_Timer_Min();
	}
	else if(BTN_GetValue(BUTTON_1)==BUTTON_PRESSED){
		Choose_Timer_10Secs();
	}
	else if (BTN_GetValue(BUTTON_2)==BUTTON_PRESSED){
		Timer_On();
	}
	else SEVEN_SEG_DISPLAY(Stop_watch_val);
	}
}
/******************************************************************************
* \Syntax          : void Choose_Timer_Min(void)
* \Description     : choose the timer minutes from 0 to 9 min
*******************************************************************************/
void Choose_Timer_Min(void){
	if(Stop_watch_val/10==max_min)Stop_watch_val-=Zero_min;
	SEVEN_SEG_DISPLAY(Stop_watch_val+=increment_min);
}
/******************************************************************************
* \Syntax          : void Choose_Timer_10Sec(void)
* \Description     : choose the timer 10seconds from 0 to 5  10secs
*******************************************************************************/
void Choose_Timer_10Secs(void){
	if(Stop_watch_val%10==max_10sec)Stop_watch_val-=Zero_10sec;
	SEVEN_SEG_DISPLAY(Stop_watch_val+=increment_10sec);
}
/******************************************************************************
* \Syntax          : void Timer_On(void)
* \Description     : start the timer counter
*******************************************************************************/
void Timer_On(void){
		uint16 ten_seconds_counter=0;
	while(1){
		if (Stop_watch_val%10==PASSED_MINUTE)
		{
				Stop_watch_val-=decrement_min;
				Stop_watch_val+=Count_NEW_60_SEC;
			if(Stop_watch_val==Timer_Finished){
				Stop_watch_val=0;
				SEVEN_SEG_DISPLAY(Stop_watch_val);
				BUZZ_ON();
				_delay_ms(5000);
				BUZZ_OFF();
				break;
			}
		}
		else {
			SEVEN_SEG_DISPLAY(Stop_watch_val);
			ten_seconds_counter++;
			if(ten_seconds_counter==PASSED_TEN_SECONDS)
			{
				Stop_watch_val-=decrement_10sec;
				ten_seconds_counter=0;
			}
		}
	}
}
