/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IRQH_Core.c
 *        \brief  LCD 
 *		Created: 8/23/2023 9:28:35 PM
 *		 Author: Ahmed Essam
 *      \details  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IRQH_CORE.h"
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
extern uint32 ADC_Vin_Value ;
extern uint32 Timer0_Number_OVRflows_g;
extern uint32 Timer0_Init_Value_g;
extern uint32 Timer1_Number_OVRflows_g;
extern uint32 Timer1_Init_Value_g;
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
* \Syntax          : void IRQH_SetGloabINT(uint8 Global_INT_Status)  
* \Description     : set gloabl interrupts                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void IRQH_SetGloabINT(uint8 Global_INT_Status)
{
	switch (Global_INT_Status)
	{
		case INT_ENABLE:
		SET_BIT(SREG,7);
		break;
		
		case INT_DISABLE:
		CLR_BIT(SREG,7);
		break;
		
		default:
		break;
	}
}
/******************************************************************************
* \Syntax          : void IRQH_SetExternalINT(void)
* \Description     : set the external interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void IRQH_SetExternalINT(void)
{
	#if (EXT_INT_0 == INT_ENABLE)
	SET_BIT(GICR,6);
	#if (EXT_INT0_TRIGGER == EXT_INT_TRIGGER_LOW_LEVEL )
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#elif (EXT_INT0_TRIGGER == EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE )
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#elif (EXT_INT0_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE)
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#elif (EXT_INT0_TRIGGER == EXT_INT_TRIGGER_RISING_EDGE  )
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#endif /*EXT_INT0_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE*/
	#endif /*EXT_INT_0 == INT_ENABLE*/
	
	#if (EXT_INT_1 == INT_ENABLE)
	SET_BIT(GICR,7);
	
	#if (EXT_INT1_TRIGGER == EXT_INT_TRIGGER_LOW_LEVEL )
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#elif (EXT_INT1_TRIGGER == EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE )
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
	#elif (EXT_INT1_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE)
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#elif (EXT_INT1_TRIGGER == EXT_INT_TRIGGER_RISING_EDGE  )
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	#endif /*EXT_INT1_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE*/
	#endif /*EXT_INT_1 == INT_ENABLE*/
	
	#if (EXT_INT_2 == INT_ENABLE)
	SET_BIT(GICR,5);
	#if (EXT_INT2_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE)
	CLR_BIT(MCUCSR,6);
	#elif (EXT_INT2_TRIGGER == EXT_INT_TRIGGER_RISING_EDGE  )
	SET_BIT(MCUCSR,6);
	#endif /*EXT_INT2_TRIGGER == EXT_INT_TRIGGER_FALLING_EDGE*/
	#endif /*EXT_INT_2 == INT_ENABLE*/
}

/******************************************************************************
* \Syntax          : void IRQH_SetCallBack(uint8 Interrupt_Vector_Index , void(*p)(void))
* \Description     : 
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void IRQH_SetCallBack(uint8 Interrupt_Vector_Index , void(*p)(void))
{
	CallBack_PtrFunc[Interrupt_Vector_Index] = p ; 
}


ISR(INT0_vect)
{
	if (CallBack_PtrFunc[External_Interrupt_Request_0_VECTOR_INDEX] != Null);
	{
		CallBack_PtrFunc[External_Interrupt_Request_0_VECTOR_INDEX]();
	}
}
ISR(ADC_vect)
{
	uint32 ADC_Digital_Value = ADC_input_16bit_access;
	ADC_Vin_Value= (ADC_Digital_Value *5000)/1023;
	if (CallBack_PtrFunc[ADC_Conversion_Complete_VECTOR_INDEX]!=Null)	{		(*CallBack_PtrFunc[ADC_Conversion_Complete_VECTOR_INDEX])();	}
}



ISR(TIMER0_OVF_vect)
{
	static uint8 INT_CNT_1 = 0;
	INT_CNT_1++;
	if (INT_CNT_1 == Timer0_Number_OVRflows_g)
	{
		CallBack_PtrFunc[Timer_Counter0_Overflow_VECTOR_INDEX]();
		INT_CNT_1 = 0;
		TCNT0 = Timer0_Init_Value_g ;
	}
}

ISR(TIMER0_COMP_vect)
{
	static uint8 INT_CNT_1 = 0;
	INT_CNT_1++;
	OCR0 = 255 ;
	if (INT_CNT_1 == Timer0_Number_OVRflows_g)
	{
		CallBack_PtrFunc[Timer_Counter0_Compare_Match_VECTOR_INDEX]();
		INT_CNT_1 = 0;
		OCR0 = Timer0_Init_Value_g ;
	}
}

ISR(TIMER1_OVF_vect)
{
	static uint8 INT_CNT_1 = 0;
	INT_CNT_1++;
	if (INT_CNT_1 == Timer1_Number_OVRflows_g)
	{
		CallBack_PtrFunc[Timer_Counter1_Overflow_VECTOR_INDEX]();
		INT_CNT_1 = 0;
		TCNT1_16bit_access = Timer1_Init_Value_g ;
	}
}
ISR(TIMER1_COMPA_vect)
{
	static uint8 INT_CNT_1 = 0;
	INT_CNT_1++;
	if (INT_CNT_1 == 1)
	{
		(*CallBack_PtrFunc[Timer_Counter1_Compare_Match_A_VECTOR_INDEX])();
		INT_CNT_1 = 0;
	}
}


// ISR(ADC_vect)
// {
// 	uint32 ADC_Digital_Value = ADC_input_16bit_access;
// 	ADC_Vin_Value_mV= (ADC_Digital_Value *5000)/1023;
// 
// 	if (CallBack_PtrFunc[ADC_Conversion_Complete_VECTOR_INDEX]!=Null)
// 	{
// 		(*CallBack_PtrFunc[ADC_Conversion_Complete_VECTOR_INDEX])();
// 	}
// 	
// }

/**********************************************************************************************************************
 *  END OF FILE: IRQH_Core.c
 *********************************************************************************************************************/


