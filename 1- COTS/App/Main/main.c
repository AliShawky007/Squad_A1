/*
 * Stop Watch.c
 *
 * Created: 8/20/2023 7:03:02 PM
 * Author : Mina
 */ 

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Stop Watch.c
 *        
 *           \brief A stopwatch is a handheld timepiece used to measure the amount of time elapsed
 *            from a particular time when it is started, to the time when the piece is stopped. 
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Buzzer.h"
#include "Button.h"
#include "Seven_Seg.h"
#include "PORT_CORE.h"
#define F_CPU 16000000U
#include <util/delay.h>

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

int main(void)
{
	/* Replace with your application code */
	PORT_Init();
	Uint_8 b1 = 0 , b2 = 0 , b3 = 0 , minute = 0 , second = 0 ;
	while (1)
	{
		b1=Button_GetValue(Button_0);
		if (b1==0)
		{
			minute++;
			if(minute == 10)
			{
				minute = 0;
			}
		}
		Seven_Seg_Display_minute(minute);
		b2=Button_GetValue(Button_1);
		if (b2==0)
		{
			second++;
			if(second == 10)
			{
				second = 0;
			}
		}
		Seven_Seg_Display_second(second);
		b3=Button_GetValue(Button_2);
		if (b3==0)
		{
		Seven_Seg_Decrement_Counter_Start_End(minute,second);
		minute = 0 , second = 0 ;
		Buzzer_Toggle();		
		}	
		}
		
	
	
	
}

/**********************************************************************************************************************
 *  END OF FILE: Stop Watch.c
 *********************************************************************************************************************/
