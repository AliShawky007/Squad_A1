/*
 * IRQH_Core.c
 *
 * Created: 9/1/2023 5:47:29 PM
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
#include "IRQH_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
void(*CallBack_PtrFunc[20])(void) = {Null};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern uint32 TIMER0_Number_OVRflows_g ;
extern uint32 TIMER0_Init_Value_g ;
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
void IRQH_SetGlobalINT(uint8 Global_INT_Status)
{
	switch(Global_INT_Status)
	{
		case INT_ENABLE:
		SET_BIT(SREG , 7);
		break;
		
		case INT_DISABLE:
		CLR_BIT(SREG , 7);
		break;
		
		default:
		break;
	}
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
void IRQH_SetExternalINT(void)
{
	#if (EXT_INT_0 == INT_ENABLE)
	SET_BIT(GICR , 6);
	
	  #if (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_LOW_LEVEL)
	   CLR_BIT(MCUCR , 0);
	   CLR_BIT(MCUCR , 1);
	  #elif (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE)
	   SET_BIT(MCUCR , 0);
	   CLR_BIT(MCUCR , 1);	  
	  #elif (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)
	   CLR_BIT(MCUCR , 0);
	   SET_BIT(MCUCR , 1);	  
	  #elif (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_RISING_EDGE)
	   SET_BIT(MCUCR , 0);
	   SET_BIT(MCUCR , 1);	
	
	 #endif /*if (EXT_INT0_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)*/
	#endif /*if (EXT_INT_0 == INT_ENABLE)*/
	
	#if (EXT_INT_1 == INT_ENABLE)
	SET_BIT(GICR , 7);
	
	  #if (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_LOW_LEVEL)
	   CLR_BIT(MCUCR , 2);
	   CLR_BIT(MCUCR , 3);
	  #elif (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE)
	   SET_BIT(MCUCR , 2);
	   CLR_BIT(MCUCR , 3);
	  #elif (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)
	   CLR_BIT(MCUCR , 2);
	   SET_BIT(MCUCR , 3);
	  #elif (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_RISING_EDGE)
	   SET_BIT(MCUCR , 2);
	   SET_BIT(MCUCR , 3);	
	 #endif /*#if (EXT_INT1_TRIGGER   ==  EXT_INT_TRIGGER_LOW_LEVEL)*/
	#endif /*#if (EXT_INT_1 == INT_ENABLE)*/
		
	#if (EXT_INT_2 == INT_ENABLE)
	SET_BIT(GICR , 5);
	
	 #if (EXT_INT2_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)
	  CLR_BIT(MCUCSR , 6);
	 #elif (EXT_INT2_TRIGGER   ==  EXT_INT_TRIGGER_RISING_EDGE)
	  SET_BIT(MCUCSR , 6);
	 #endif /*#if (EXT_INT2_TRIGGER   ==  EXT_INT_TRIGGER_FALLING_EDGE)*/	
	#endif /*(EXT_INT_2 == INT_ENABLE)*/
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


void IRQH_Set_CallBack(uint8 Interrupt_Vector_Index , void(*p)(void))
{
	CallBack_PtrFunc[Interrupt_Vector_Index] = p;
}



ISR(INT0_vect)
{
	
	if(CallBack_PtrFunc[External_Interrupt_Request_0_VECTOR_INDEX] != Null)
	{
		(*CallBack_PtrFunc[External_Interrupt_Request_0_VECTOR_INDEX])();
	}
}

ISR(ADC_vect)
{
	
	if(CallBack_PtrFunc[ADC_Conversion_Complete_VECTOR_INDEX] != Null)
	{
		uint32 ADC_Digital_Value = ADC_INPUT_16BIT_ACCESS;
		ADC_Vin_Value_mv = (ADC_Digital_Value * 5000) / 1023;
		(*CallBack_PtrFunc[ADC_Conversion_Complete_VECTOR_INDEX])();
	}
}

ISR(TIMER0_OVF_vect)
{
	static uint8 INT_CNT_l = 0;
	
	INT_CNT_l++;
	
	if(INT_CNT_l == TIMER0_Number_OVRflows_g)
	{
		(*CallBack_PtrFunc[Timer_Counter0_Overflow_VECTOR_INDEX])();
		INT_CNT_l = 0;
		TCNT0 = TIMER0_Init_Value_g ;
	}
}

ISR(TIMER1_COMPA_vect)
{
	static uint8 INT_CNT_l = 0;
	INT_CNT_l++;
	if(INT_CNT_l == 1)
	{
		(*CallBack_PtrFunc[Timer_Counter1_Compare_Match_A_VECTOR_INDEX])();
		INT_CNT_l = 0;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/