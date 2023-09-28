/*
 * ICU_CORE.c
 *
 * Created: 9/23/2023 4:45:26 PM
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
#include "ICU_CORE.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
volatile Uint_32 Captured_Readings_1 = 0;

volatile Uint_32 Captured_Readings_2 = 0;

volatile Uint_32 Captured_Readings_3 = 0;

volatile Uint_32 Capture_Flag = 0;
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
void ICU_Init(void)
{
	GPT_Init();
	ICR1 = 0X0000;
	
	SET_BIT(TCCR1B,6);
	
	
	SET_BIT(TIMSK,5);
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
Uint_32 ICU_CaptureTime(void)
{

static Uint_32 time =0;
if(Capture_Flag == 2U)
{
	/*the total number of ticks * the time of each tick*/
	time = (Captured_Readings_2 - Captured_Readings_1) * 64U ;
	Capture_Flag = 0;
	/*Enable ICU Interrupt*/
	SET_BIT(TIMSK,5);
}
return time;
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
void Pulse_Meter(void)
{
	static Uint_32 Duty_Cycle =0;
	static Uint_32 Frequency = 0;
	if(Capture_Flag == 3U)
	{
	 	Duty_Cycle = ((Captured_Readings_2 - Captured_Readings_1 )*100) / (Captured_Readings_3 - Captured_Readings_1);
		 Frequency = F_CPU / ((Captured_Readings_3 - Captured_Readings_1)*8);
		 LCD_GOTO(0,0);
		 LCD_WriteString("Duty Cycle:");
		 LCD_WriteInt( Duty_Cycle);
		 LCD_WriteString("%");
		 
		 LCD_GOTO(1,0);
		 LCD_WriteString("Freq:");
		 LCD_WriteInt(Frequency);
		 LCD_WriteString("Hz");
		 Capture_Flag = 0;
		 SET_BIT(TIMSK , 5) ;		 
    }
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
