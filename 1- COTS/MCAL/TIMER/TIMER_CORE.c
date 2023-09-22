/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  TIMER_CORE.c
 *        \brief  
 * Created: 9/15/2023 3:25:02 PM
 *  Author: ahmed
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TIMER_CORE.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 Timer0_Number_OVRflows_g = 0;
uint32 Timer0_Init_Value_g = 0;
uint32 Timer1_Number_OVRflows_g = 0;
uint32 Timer1_Init_Value_g = 0;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void GPT_Init(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void GPT_Init(void)
{
	#if (Timer0_State == TIMER_ENABLE)
	#if (TIMER0_MODE == NORMAL_MODE )
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	#if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED) //overflow int
	SET_BIT(TIMSK,0);
	#elif (#if (TIMER0_INTERRUPT_STATE == INTERRUPT_DISABLED)
	CLR_BIT(TIMSK,0);
	#endif //if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED)
	#elif (TIMER0_MODE == CTC_MODE )
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	#if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED) //COMPMATCH int
	SET_BIT(TIMSK,1);
	#elif (#if (TIMER0_INTERRUPT_STATE == INTERRUPT_DISABLED)
	CLR_BIT(TIMSK,1);
	#endif //if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED)
	
	#endif //if (TIMER0_MODE)
	
	#if   (TIMER0_PRESCALER == NO_CLK_SRC					)
	TCCR0 |= 0X00;
	#elif (TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	)
	TCCR0 |= 0X01;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_8			)
	TCCR0 |= 0X02;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_64 		)
	TCCR0 |= 0X03;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_256 		)
	TCCR0 |= 0X04;
	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_1024)
	TCCR0 |= 0X05;
	#endif //if (TIMER0_PRESCALER)
	#endif //if (Timer0_State)

	#if (Timer1_State == TIMER_ENABLE)
	#if (TIMER1_MODE == NORMAL_MODE )
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#if (TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED) //overflow int
	SET_BIT(TIMSK,2);
	#elif (TIMER1_INTERRUPT_STATE == INTERRUPT_DISABLED)
	CLR_BIT(TIMSK,2);
	#endif //if (TIMER1_INTERRUPT_STATE)
	#elif (TIMER1_MODE == CTC_MODE )
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#if (TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED) //compare_match int
	SET_BIT(TIMSK,4);
	#elif (TIMER1_INTERRUPT_STATE == INTERRUPT_DISABLED)
	CLR_BIT(TIMSK,4);
	#endif //if (TIMER1_INTERRUPT_STATE)

	#endif //if (TIMER1_MODE)
	
	#if   (TIMER1_PRESCALER == NO_CLK_SRC					)
	TCCR1B |= 0X00;
	#elif (TIMER1_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	)
	TCCR1B |= 0X01;
	#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_8			)
	TCCR1B |= 0X02;
	#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_64 		)
	TCCR1B |= 0X03;
	#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_256 		)
	TCCR1B |= 0X04;
	#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_1024		)
	TCCR1B |= 0X05;
	#endif //if (TIMER1_PRESCALER)
	#endif //if (Timer1_State)
	
	
	
}
/******************************************************************************
* \Syntax          : void GPT_SetTime(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void GPT_SetTime(void)
{
	uint32 MCU_CLK_us = F_CPU / 1000000 ;
	
	#if (Timer0_State == TIMER_ENABLE)
	uint8 Timer0_Tick_Time_us = TIMER0_PRESCALER / MCU_CLK_us ;
	#if (TIMER0_MODE == NORMAL_MODE )
	uint32 Time0_ms = TIMER0_COUNTED_MS;
	uint32 Timer0_Total_Ticks = (Time0_ms * 1000) / Timer0_Tick_Time_us;
	Timer0_Number_OVRflows_g = Timer0_Total_Ticks / 256 ;
	Timer0_Init_Value_g = 256 - (Timer0_Total_Ticks % 256);
	TCNT0 = Timer0_Init_Value_g ;
	if (Timer0_Total_Ticks % 256 != 0)
	{
		Timer0_Number_OVRflows_g++;
	}
	#elif (TIMER0_MODE == CTC_MODE )
	uint32 Time0_ms = TIMER1_COUNTED_MS;
	uint32 Timer0_Total_Ticks = (Time0_ms * 1000) / Timer0_Tick_Time_us;
	Timer0_Number_OVRflows_g = Timer0_Total_Ticks / 256 ;
	Timer0_Init_Value_g = 256 - (Timer0_Total_Ticks % 256);
	OCR0 = Timer0_Init_Value_g ;
	
	#endif //if (TIMER0_MODE)
	#endif //if (Timer0_State)
	
	
	
	#if (Timer1_State == TIMER_ENABLE)
	uint8 Timer1_Tick_Time_us = TIMER1_PRESCALER / MCU_CLK_us ;
	#if (TIMER1_MODE == NORMAL_MODE )
	uint32 Time1_ms = TIMER0_COUNTED_MS;
	uint32 Timer1_Total_Ticks = (Time1_ms * 1000) / Timer1_Tick_Time_us;
	Timer1_Number_OVRflows_g = Timer1_Total_Ticks / 65535 ;
	Timer1_Init_Value_g = 65535 - (Timer1_Total_Ticks % 65535);
	TCNT1_16bit_access = Timer1_Init_Value_g ;
	if (Timer1_Total_Ticks % 65535 != 0)
	{
		Timer1_Number_OVRflows_g++;
	}
	#elif (TIMER1_MODE == CTC_MODE  )
	uint32 Time1_ms = TIMER1_COUNTED_MS;
	uint32 Timer1_Total_Ticks = (Time1_ms * 1000) / Timer1_Tick_Time_us;
	OCR1_16bit_access = Timer1_Total_Ticks -1 ;
	#endif //if (TIMER1_MODE)
	#endif //if (Timer1_State)
}

/**********************************************************************************************************************
 *  END OF FILE: TIMER_CORE.c
 *********************************************************************************************************************/
