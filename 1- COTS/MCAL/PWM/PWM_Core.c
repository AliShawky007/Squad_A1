/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PWM_Core.c
 *        \brief  
 * Created: 9/22/2023 2:35:50 PM
 *  Author: ahmed
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PWM_Core.h"


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
* \Syntax          : void PWM_Init(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void PWM_Init(void)
{
	#if (PWM0_STATE == PWM_ENABLE)
	
	#if (PWM0_TYPE == PWM_FAST)
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	#elif (PWM0_TYPE == PWM_PHASE_CORRECT)
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	#endif //if (PWM0_TYPE)
	
	#if (PWM0_MDOE==PWM_NON_INVERTED)
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#elif (PWM0_MDOE==PWM_INVERTED)
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	#endif // (PWM0_MODE)
	
	#endif //if (PWM0_STATE)
	
	#if (PWM1_STATE==	PWM_ENABLE )
	#if (PWM1_TYPE == PWM_FAST)
	TCCR1A |= 0X02;
	TCCR1B |= 0X18;
	#elif (PWM1_TYPE == PWM_PHASE_CORRECT)
	TCCR1A |= 0X02;
	TCCR1B |= 0X10;
	#endif //if (PWM1_TYPE)
	
	#if (PWM1_MDOE==PWM_NON_INVERTED)
	TCCR1A |= 0X80;
	#elif (PWM1_MDOE==PWM_INVERTED)
	TCCR1A |= 0XC0;
	#endif // (PWM1_MODE)

	#endif //PWM1_STATE
	
}
/******************************************************************************
* \Syntax          : void PWM0_Generate(uint8 Duty_CY)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void PWM0_Generate(uint8 Duty_CY)
{
	#if (PWM0_STATE == PWM_ENABLE)
	#if (PWM0_TYPE == PWM_FAST)
	
	#if (PWM0_MDOE == PWM_NON_INVERTED)
	//OCR0 = (((TIMER0_DUTY_CYCLE*TIMER0_TOP)+TIMER0_DUTY_CYCLE)/100)-1;
	OCR0 = ((Duty_CY*256)/100)-1;
	#elif (PWM0_MDOE == PWM_INVERTED)
	//OCR0 = TIMER0_TOP-(TIMER0_DUTY_CYCLE*(TIMER0_TOP+1))/100;
	OCR0 = 255 - ((Duty_CY * 256 ) / 100 );
	#endif //PWM0_MDOE
	
	#elif (PWM0_TYPE == PWM_PHASE_CORRECT)
	#if (PWM0_MDOE == PWM_NON_INVERTED)
	OCR0 = ((Duty_CY*255)/100)-1;
	#elif (PWM0_MDOE == PWM_INVERTED)
	OCR0 = 255 - ((Duty_CY * 255 ) / 100 );
	#endif //PWM0_MDOE
	
	#endif //PWM0_TYPE
	
	#if   (PWM0_PRESCALER == PWM_PRESC8		)
	TCCR0 |= 0X02;
	#elif (TIMER0_PRESCALER == PWM_PRESC64	)
	TCCR0 |= 0X03;
	#elif (TIMER0_PRESCALER == PWM_PRESC256 )
	TCCR0 |= 0X04;
	#elif (TIMER0_PRESCALER == PWM_PRESC1024)
	TCCR0 |= 0X05;
	#endif //if (PWM0_PRESCALER)
	
	#endif //PWM0_STATE
}
/******************************************************************************
* \Syntax          : void PWM1_Generate(uint8 Duty_CY ,uint16 Frequency)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void PWM1_Generate(uint8 Duty_CY ,uint16 Frequency)
{
	#if (PWM1_STATE == PWM_ENABLE)
	#if (PWM1_TYPE == PWM_FAST)
	ICR1_16bit_access = (16000000/(PWM1_PRESCALER*Frequency));
	#if (PWM1_MDOE == PWM_NON_INVERTED)
	OCR1_16bit_access = ((Duty_CY*ICR1_16bit_access+1)/100)-1;
	#elif (PWM1_MDOE == PWM_INVERTED)
	OCR1_16bit_access = ICR1_16bit_access -((Duty_CY * ICR1_16bit_access+1 )/100);
	#endif //PWM1_MDOE
	#elif (PWM1_TYPE == PWM_PHASE_CORRECT)
	ICR1_16bit_access = (16000000/(2*PWM1_PRESCALER*Frequency));
	#if (PWM1_MDOE == PWM_NON_INVERTED)
	OCR1_16bit_access = ((Duty_CY*ICR1_16bit_access)/100)-1;
	#elif (PWM1_MDOE == PWM_INVERTED)
	OCR1_16bit_access = ICR1_16bit_access -((Duty_CY * ICR1_16bit_access )/100);
	#endif //PWM1_MDOE
	#endif //PWM1_TYPE
	
	
	#if   (PWM1_PRESCALER == PWM_PRESC8		)
	TCCR1B |= 0X02;
	#elif (PWM1_PRESCALER == PWM_PRESC64	)
	TCCR1B |= 0X03;
	#elif (PWM1_PRESCALER == PWM_PRESC256 )
	TCCR1B |= 0X04;
	#elif (PWM1_PRESCALER == PWM_PRESC1024)
	TCCR1B |= 0X05;
	#endif //if (PWM1_PRESCALER)
	
	#endif //PWM1_STATE
}

/**********************************************************************************************************************
 *  END OF FILE: PWM_Core.c
 *********************************************************************************************************************/
