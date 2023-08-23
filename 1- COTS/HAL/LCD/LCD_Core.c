/*
 * LCD_Core.c
 *
 * Created: 8/23/2023 9:28:34 PM
 *  Author: Mina
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LCD_Core.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LCD_Core.h"
#define F_CPU 16000000U
#include <util/delay.h>

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
void LCD_Init(void)
{
	#if (lCD_MODS == LCD_4BIT_MODE)
	LCD_WriteCommand(0x33);   	 //DATASHEET
	LCD_WriteCommand(0x32);		 //DATASHEET
	LCD_WriteCommand(0x28);
	
	LCD_WriteCommand(0x0C);		 //DATASHEET
	LCD_WriteCommand(0x01);		 //DATASHEET
	LCD_WriteCommand(0x06);		 //DATASHEET
	LCD_WriteCommand(0x02); 	 //DATASHEET

    #endif
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

void LCD_WriteCommand(Uint_8 cmd)
{
	Uint_8 Old_Value = 0 ,New_Value = 0;
	DIO_WriteChannel(LCD_RS_PIN , PIN_LOW);
	DIO_WriteChannel(LCD_E_PIN ,  PIN_LOW);
	
	#if (lCD_MODS == LCD_4BIT_MODE)
	/***METHOD 1****/
	/*DIO_WriteChannel(LCD_D4_PIN,GET_BIT(cmd , 4));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(cmd , 5));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(cmd , 6));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(cmd , 7));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(cmd , 0));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(cmd , 1));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(cmd , 2));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(cmd , 3));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	_delay_ms(5);*/
	
	/****METHOD2(High Execution Time)****/	
	DIO_ReadOutputPort(LCD_D4_PIN, &Old_Value);
	New_Value= ((cmd >>1) & DATA_MASK) | (Old_Value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN , New_Value);
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_ReadOutputPort(LCD_D4_PIN, &Old_Value);
	New_Value= ((cmd <<3) & DATA_MASK) | (Old_Value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN , New_Value);
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	_delay_ms(5);
    #endif
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
void LCD_WriteChar(Uint_8 chr)
{
	Uint_8 Old_Value = 0 ,New_Value = 0;
	DIO_WriteChannel(LCD_RS_PIN , PIN_HIGH);
	DIO_WriteChannel(LCD_E_PIN ,  PIN_LOW);
	
	#if (lCD_MODS == LCD_4BIT_MODE)
	/***METHOD 1****/
	/*DIO_WriteChannel(LCD_D4_PIN,GET_BIT(chr , 4));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(chr , 5));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(chr , 6));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(chr , 7));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_WriteChannel(LCD_D4_PIN,GET_BIT(chr , 0));
	DIO_WriteChannel(LCD_D5_PIN,GET_BIT(chr , 1));
	DIO_WriteChannel(LCD_D6_PIN,GET_BIT(chr , 2));
	DIO_WriteChannel(LCD_D7_PIN,GET_BIT(chr , 3));
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	_delay_ms(5);*/
	
	/****METHOD2(High Execution Time)****/	
	DIO_ReadOutputPort(LCD_D4_PIN, &Old_Value);
	New_Value= ((chr >>1) & DATA_MASK) | (Old_Value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN , New_Value);
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	
	DIO_ReadOutputPort(LCD_D4_PIN, &Old_Value);
	New_Value= ((chr <<3) & DATA_MASK) | (Old_Value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN , New_Value);
	
	DIO_WriteChannel(LCD_E_PIN , PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChannel(LCD_E_PIN , PIN_LOW);
	_delay_ms(5);
    #endif
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

void LCD_WriteString(Uint_8* chr)
{
	Uint_8 cnt = 0;
	while(chr[cnt]!='\0')
	{
		LCD_WriteChar(chr[cnt]);
		cnt++;
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

void LCD_WriteInt(Uint_32 num)
{
	
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

void LCD_Clear(void)
{
	LCD_WriteCommand(0X01);
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
void LCD_GOTO(Uint_8 ROW , Uint_8 COLUMN)
{
	Uint_8 arr[2]= {0x80 , 0xc0};
		LCD_WriteCommand(arr[ROW]+COLUMN);
}

/**********************************************************************************************************************
 *  END OF FILE: LCD_Core.c
 *********************************************************************************************************************/
