/*
 * PWM_CORE.c
 *
 * Created: 9/22/2023 2:35:36 PM
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
#include "PWM_CORE.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
void PWM_Init(void)
{
	#if (PWM0_STATE == PWM_ENABLE)
	#if (PWM0_TYPE == PWM_FAST)
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	#elif (PWM0_TYPE == PWM_PHASE_CORRECT)
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
    #endif /*(PWM0_TYPE == PWM_FAST)*/
	
	#if (PWM0_MODE == PWM_INVERTED)
	SET_BIT(TCCR0,5);
	SET_BIT(TCCR0,4);
	#elif (PWM0_MODE == PWM_NONINVERTED)
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);
	#endif /*(PWM0_MODE == PWM_INVERTED)*/
	
    #endif /*(PWM0_STATE == PWM_ENABLE)*/
	
	#if (PWM1_STATE == PWM_ENABLE)
	 	#if (PWM1_TYPE == PWM_FAST)
	 	TCCR1A |= 0x02;
		TCCR1B |= 0x18;
	 	#elif (PWM1_TYPE == PWM_PHASE_CORRECT)
	 	TCCR1A |= 0x02;
	 	TCCR1B |= 0x10;
	 	#endif /*(PWM1_TYPE == PWM_FAST)*/
	 	
	 	#if (PWM1_MODE == PWM_INVERTED)
	 	TCCR1A |= 0xc0;
	 	#elif (PWM1_MODE == PWM_NONINVERTED)
	 	TCCR1A |= 0x80;
	 	#endif /*(PWM1_MODE == PWM_INVERTED)*/

	#endif /*(PWM1_STATE == PWM_ENABLE)*/
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
void PWM0_Generate(Uint_8 Duty_Cycle)
{
	#if (PWM0_STATE == PWM_ENABLE)
	  #if (PWM0_TYPE == PWM_FAST)
	    #if (PWM0_MODE == PWM_INVERTED)
	    OCR0 = 255 - ((Duty_Cycle *256)/100);
	    #elif (PWM0_MODE == PWM_NONINVERTED)
        OCR0 = ((Duty_Cycle *256)/100)-1;
        #endif /*(PWM0_MODE == PWM_INVERTED)*/
	
	  #elif (PWM0_TYPE == PWM_PHASE_CORRECT)
	    #if (PWM0_MODE == PWM_INVERTED)
	    OCR0 = 255 - ((Duty_Cycle *255)/100) ;
	    #elif (PWM0_MODE == PWM_NONINVERTED)
        OCR0 = ((Duty_Cycle *255)/100)-1;
	    #endif /*(PWM0_MODE == PWM_INVERTED)*/
	#endif /*(PWM0_TYPE == PWM_FAST)*/
	#if (PWM0_PRESC == PWM_PRESC8)
	TCCR0 |=0X02;
	#elif (PWM0_PRESC == PWM_PRESC64)
	TCCR0 |=0X03;
	#elif (PWM0_PRESC == PWM_PRESC256)
	TCCR0 |=0X04;
	#elif (PWM0_PRESC == PWM_PRESC1024)
	TCCR0 |=0X05;
    #endif /*(PWM0_PRESC == PWM_PRESC8)*/
    #endif /*(PWM0_STATE == PWM_ENABLE)*/
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
void PWM1_Generate(Uint_8 Duty_Cycle , Uint_16 Frequency)
{
	#if (PWM1_STATE == PWM_ENABLE)
	 #if (PWM1_TYPE == PWM_FAST)   
	  /*TIMER NO. OF COUNTS*/
	  ICR1=(16000000U / (Frequency * PWM1_PRESC));
	  /************************************/
	   #if (PWM1_MODE == PWM_INVERTED)
	   OCRA1= ICR1 -((Duty_Cycle * (ICR1+1))/100); 
	   #elif (PWM1_MODE == PWM_NONINVERTED)
	   OCRA1= ((Duty_Cycle * (ICR1+1))/100) - 1;
       #endif /*(PWM1_MODE == PWM_INVERTED)*/
      
	  
	  #elif (PWM1_TYPE == PWM_PHASE_CORRECT) 
	  	 /*****TIMER TOP NUMBER OF COUNTS*********/
		    ICR1=(16000000U / (2*(Frequency * PWM1_PRESC)));
/************************************************************/
	   #if (PWM1_MODE == PWM_INVERTED)
	   OCRA1= ICR1 -((Duty_Cycle * (ICR1))/100);
	   #elif (PWM1_MODE == PWM_NONINVERTED)
	   OCRA1= ((Duty_Cycle * (ICR1))/100);
	   #endif /*(PWM1_MODE == PWM_INVERTED)*/
	   	   
     #endif /*(PWM1_TYPE == PWM_FAST)*/
	 
	 	  #if (PWM1_PRESC == PWM_PRESC8)
	 	  TCCR1B |=0X02;
	 	  #elif (PWM1_PRESC == PWM_PRESC64)
	 	  TCCR1B |=0X03;
	 	  #elif (PWM1_PRESC == PWM_PRESC256)
	 	  TCCR1B |=0X04;
	 	  #elif (PWM1_PRESC == PWM_PRESC1024)
	 	  TCCR1B |=0X05;
	 	  #endif /*(PWM0_PRESC == PWM_PRESC8)*/
   
   #endif /*(PWM1_STATE == PWM_ENABLE)*/
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
