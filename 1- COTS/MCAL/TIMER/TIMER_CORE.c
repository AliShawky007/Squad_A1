/*
 * TIMER_CORE.c
 *
 * Created: 9/15/2023 3:44:03 PM
 *  Author: Mina
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
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
Uint_32 TIMER0_Number_OVRflows_g =0;
Uint_32 TIMER0_Init_Value_g =0;
Uint_32 TIMER1_Init_Value_g=0;

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
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void GPT_Init(void)
{
     #if (Timer0_State == TIMER_ENABLE)
     /** Timer0 Operation Mode **/
	  #if (TIMER0_MODE == NORMAL_MODE)
      CLR_BIT(TCCR0,6);
      CLR_BIT(TCCR0,3);
	    #if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED)
	    SET_BIT(TIMSK,0);
	    #elif (TIMER0_INTERRUPT_STATE == INTERRUPT_DISABLED)
        CLR_BIT(TIMSK,0);
        #endif /*(TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED)*/
      #elif (TIMER0_MODE == CTC_MODE)
	  CLR_BIT(TCCR0,6);
	  SET_BIT(TCCR0,3);
      #endif /*(TIMER0_MODE == NORMAL_MODE)*/
     	#if (TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING)
     	TCCR0 |= 0X01;
     	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_8)
     	TCCR0 |= 0X02;
     	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_64)
     	TCCR0 |= 0X03;
     	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_256)
        TCCR0 |= 0X04;
     	#elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_1024)
     	TCCR0 |= 0X05;
      #endif /*(TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING)*/
     #endif /*(Timer0_State == TIMER_ENABLE)*/
	 
	 #if (Timer1_State == TIMER_ENABLE)
	 /** Timer1 Operation Mode **/
	 #if (TIMER1_MODE == CTC_MODE)
	 CLR_BIT(TCCR1A,0);
	 CLR_BIT(TCCR1A,1);
	 SET_BIT(TCCR1B,3);
	 CLR_BIT(TCCR1B,4);
	 #if (TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED)
	 SET_BIT(TIMSK,4);
	 #elif (TIMER1_INTERRUPT_STATE == INTERRUPT_DISABLED)
	 CLR_BIT(TIMSK,4);
	 #endif /*(TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED)*/
	 #elif (TIMER1_MODE == NORMAL_MODE)
	 CLR_BIT(TCCR1A,0);
	 CLR_BIT(TCCR1A,1);
	 CLR_BIT(TCCR1B,3);
	 CLR_BIT(TCCR1B,4);
	 #if (TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED)
	 SET_BIT(TIMSK,2);
	 #elif (TIMER1_INTERRUPT_STATE == INTERRUPT_DISABLED)
	 CLR_BIT(TIMSK,2);
	 #endif /*(TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED)*/
	 #endif /*(TIMER1_MODE == CTC_MODE)*/
	 
	 #if (TIMER1_PRESCALER == CLK_SRC_WITH_NO_PRESCALING)
	 TCCR1B |= 0X01;
	 #elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_8)
	 TCCR1B |= 0X02;
	 #elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_64)
	 TCCR1B |= 0X03;
	 #elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_256)
	 TCCR1B |= 0X04;
	 #elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_1024)
	 TCCR1B |= 0X05;
	 #endif /*(TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING)*/
	 #endif /*(Timer1_State == TIMER_ENABLE)*/
	 
	 
}


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void GPT_SetTime(void)
{
	Uint_8 MCU_CLK_us = MCU_CLK / 1000000 ;
	#if (Timer0_State == TIMER_ENABLE)
	Uint_8 Timer0Tick_Time_us = TIMER0_PRESCALER / MCU_CLK_us;
    #if (TIMER0_MODE == NORMAL_MODE)
    Uint_32 Time = TIMER0_COUNTED_MS;
	Uint_32 Timer0Total_Ticks = (Time*1000) /Timer0Tick_Time_us;
	TIMER0_Number_OVRflows_g = Timer0Total_Ticks /256;
	TIMER0_Init_Value_g = 256 - (Timer0Total_Ticks % 256);
	
	TCNT0 = TIMER0_Init_Value_g;
	if((Timer0Total_Ticks % 256) !=0)
	{
		TIMER0_Number_OVRflows_g++;
	}
	
	#elif (TIMER0_MODE == CTC_MODE)
	
	
    #endif /*(TIMER0_MODE == NORMAL_MODE)*/
    #endif /*(Timer0_State == TIMER_ENABLE)*/
	
	#if (Timer1_State == TIMER_ENABLE)
	Uint_8 Timer1Tick_Time_us = TIMER1_PRESCALER / MCU_CLK_us;
	#if (TIMER1_MODE == CTC_MODE)
	Uint_32 Time1 = TIMER1_COUNTED_MS;
	Uint_32 Timer1Total_Ticks = (Time1*1000) /Timer1Tick_Time_us;
	TIMER1_Init_Value_g = Timer1Total_Ticks - 1 ;
	OCRA1 = TIMER1_Init_Value_g;
	#endif /*(TIMER1_MODE == CTC_MODE)*/
	#endif /*(Timer1_State == TIMER_ENABLE)*/
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
