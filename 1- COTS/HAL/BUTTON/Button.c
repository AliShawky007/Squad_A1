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
* \Syntax          : Uint_8 Button_GetValue(void)
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


/******************************************************************************
* \Syntax          : Uint_8 Button1_GetValue(void)
* \Description     : Button1 GetValue
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
Uint_8 Button1_GetValue(Uint_8 button_num1)
{
	Uint_8 button1 =1,temp1=0;
	DIO_ReadChannel(button_num1,&button1);
	while(temp1==0)
	{
		DIO_ReadChannel(button_num1,&temp1);
	}
	_delay_ms(10);
	return button1;
}




/******************************************************************************
* \Syntax          : Uint_8 Button2_GetValue(void)
* \Description     : Button2 GetValue
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
Uint_8 Button2_GetValue(Uint_8 button_num2)
{
	Uint_8 button2 =1,temp2=0;
	DIO_ReadChannel(button_num2,&button2);
	while(temp2==0)
	{
		DIO_ReadChannel(button_num2,&temp2);
	}
	_delay_ms(10);
	return button2;
}



/******************************************************************************
* \Syntax          : Uint_8 Button3_GetValue(void)
* \Description     : Button3 GetValue
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
Uint_8 Button3_GetValue(Uint_8 button_num3)
{
	Uint_8 button3 =1,temp3=0;
	DIO_ReadChannel(button_num3 ,&button3);
	while(temp3==0)
	{
		DIO_ReadChannel(button_num3,&temp3);
	}
	_delay_ms(10);
	return button3;
}
/**********************************************************************************************************************
 *  END OF FILE: Button.c
 *********************************************************************************************************************/
