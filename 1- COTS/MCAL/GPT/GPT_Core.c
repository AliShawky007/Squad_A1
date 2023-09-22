/*
 * GPT_Core.c
 *
 * Created: 9/15/2023 5:03:21 PM
 *  Author: Ali
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
#include "GPT_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 TIMER0_Number_OVRflows_g = 0;
uint32 TIMER0_Init_Value_g = 0;
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
		#if(Timer0_State == TIMER_ENABLE)
		/** Timer0 Operation Mode **/
		   #if (TIMER0_MODE == NORMAL_MODE)
	         CLR_BIT(TCCR0 , 3);
	         CLR_BIT(TCCR0 , 6);
			  #if (TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED)
			   SET_BIT(TIMSK,0);
			  #elif (TIMER0_INTERRUPT_STATE == INTERRUPT_DISABLED)	
			   CLR_BIT(TIMSK,0);
			  #endif	/*(TIMER0_INTERRUPT_STATE == INTERRUPT_ENABLED)*/
		   #elif (TIMER0_MODE == CTC_MODE)
		   
		   #endif /*if(TIMER0_MODE == NORMAL_MODE)*/
		   
		   #if (TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	 )
		    TCCR0 |= 0X01;
		   #elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_8		 )
		    TCCR0 |= 0X02;
		   #elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_64		 )
		    TCCR0 |= 0X03;
		   #elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_256		 )
		    TCCR0 |= 0X04;
		   #elif (TIMER0_PRESCALER == CLK_SRC_PRESCALING_1024		 )
		    TCCR0 |= 0X05;
		   #endif /*if(TIMER0_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	 )*/
		#endif /*if(Timer0_State == TIMER_ENABLE)*/
		#if (Timer1_State == TIMER_ENABLE)
		#if (TIMER1_MODE == NORMAL_MODE)
		
		#elif (TIMER1_MODE == CTC_MODE)
		CLR_BIT(TCCR1A , 0);
		CLR_BIT(TCCR1A , 1);
		SET_BIT(TCCR1B , 3);
		CLR_BIT(TCCR1B , 4);
		#if (TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED)
		SET_BIT(TIMSK,4);
		#elif (TIMER1_INTERRUPT_STATE == INTERRUPT_DISABLED)
		CLR_BIT(TIMSK,4);
		#endif /*end #if(TIMER1_INTERRUPT_STATE == INTERRUPT_ENABLED) */
		#endif /*end #if (TIMER0_MODE == NORMAL_MODE)*/
		/** Timer1 Prescaler value **/
		#if (TIMER1_PRESCALER == CLK_SRC_WITH_NO_PRESCALING	 )
		TCCR1B |= 0X01;
		#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_8		 )
		TCCR1B |= 0X02;
		#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_64		 )
		TCCR1B |= 0X03;
		#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_256	 )
		TCCR1B |= 0X04;
		#elif (TIMER1_PRESCALER == CLK_SRC_PRESCALING_1024	 )
		TCCR1B |= 0X05;
		#endif /*end #if(TIMER1_PRESCALER == CLK_SRC_WITH_NO_PRESCALING) */
		#endif /*if (Timer1_State == TIMER_ENABLE)*/
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
	uint8 MCU_CLK_us = 16000000 / 1000000 ;
	
	#if (Timer0_State == TIMER_ENABLE)
	uint8 Timer0Tick_Time_us = TIMER0_PRESCALER / MCU_CLK_us ; 
	 #if (TIMER0_MODE == NORMAL_MODE)
	 uint32 Time_ms = TIMER0_COUNTED_MS;
	 uint32 Timer0Total_Ticks = (Time_ms*1000) / Timer0Tick_Time_us;
	 TIMER0_Number_OVRflows_g = Timer0Total_Ticks / 256 ;
	 TIMER0_Init_Value_g = 256 -( Timer0Total_Ticks % 256) ;
	 
	  TCNT0 = TIMER0_Init_Value_g ;
	  if( Timer0Total_Ticks % 256 != 0)
	  {
		 TIMER0_Number_OVRflows_g++; 
	  }
	  
	 #elif(TIMER0_MODE == CTC_MODE)
	 
	 #endif /*if  (TIMER0_MODE == NORMAL_MODE)*/
	#endif /*if (Timer0_State == TIMER_ENABLE)*/
	
	#if (Timer1_State == TIMER_ENABLE)
	uint8 Timer1Tick_Time_us_l = (TIMER1_PRESCALER / MCU_CLK_us) ;
	
	#if (TIMER1_MODE == NORMAL_MODE)
	
	#elif (TIMER1_MODE == CTC_MODE)
	uint32 Time_1_ms = TIMER1_COUNTED_MS;
	 uint32 Timer1Total_Ticks = (Time_1_ms*1000) / Timer1Tick_Time_us_l;
	 OCR1A_16BIT_ACCESS = Timer1Total_Ticks - 1;
	#endif /*if (TIMER1_MODE == NORMAL_MODE)*/
	#endif /*if (Timer1_State == TIMER_ENABLE)*/

}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/

