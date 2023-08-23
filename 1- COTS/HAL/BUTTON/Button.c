/*
 * Button.c
 *
 * Created: 8/16/2023 9:46:41 PM
 *  Author: Mina
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Button.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "button.h"



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
* \Syntax          : Uint_8 Button_GetValue(Uint_8 button_num)
* \Description     : Button GetValue
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
Uint_8 Button_GetValue(Uint_8 button_num)
{
	Uint_8 button =1,temp=0;
	DIO_ReadChannel(button_num,&button);
	while(temp==0)
	{
    DIO_ReadChannel(button_num,&temp);
	}
	_delay_ms(10);
	return button;
}


/**********************************************************************************************************************
 *  END OF FILE: Button.c
 *********************************************************************************************************************/