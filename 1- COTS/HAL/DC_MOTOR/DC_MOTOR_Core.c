/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DC_MOTOR_Core.c
 *        \brief  control the direction and speed of DC motor
 * Created: 9/22/2023 5:14:19 PM
 *  Author: ahmed
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "DC_MOTOR_Core.h"

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
* \Syntax          : void DC_MOTOR_Init(void)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DC_MOTOR_Init(void)
{
	PWM_Init();
}
/******************************************************************************
* \Syntax          :void DC_MOTOR_Direction(DC_Motor_Drive Direction)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DC_MOTOR_Direction(DC_Motor_Drive Direction)
{
	if (Direction == Left)
	{
		DIO_WriteChennel(INT1 , HIGH);
		DIO_WriteChennel(INT2 , LOW);
	}
	else if (Direction == Right)
	{
		DIO_WriteChennel(INT1 , LOW);
		DIO_WriteChennel(INT2 , HIGH);
	}
}
/******************************************************************************
* \Syntax          : void DC_MOTOR_Speed(uint8 DutyCycle)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DC_MOTOR_Speed(uint8 DutyCycle)
{
	PWM0_Generate(DutyCycle);
}
/******************************************************************************
* \Syntax          : void DC_Motor_Stop(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DC_Motor_Stop(void)
{
	DIO_WriteChennel(INT1 , HIGH);
	DIO_WriteChennel(INT2 , HIGH);
}

/**********************************************************************************************************************
 *  END OF FILE: DC_MOTOR_Core.c
 *********************************************************************************************************************/