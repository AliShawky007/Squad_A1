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
Uint_8 Custom_Char_Arr[C_CHAR_NO][BYTES_NO]={
	/*************Heart Custom1*************/
{ 0x00,0x1B,0x15,0x11,0x0A,0x04,0x00,0x00},
   /*************? Custom2*************/
{ 0x00,0x00,0x06,0x1E,0x00,0x00,0x00,0x00},
/*************? Custom2*************/
{ 0x00,0x01,0x01,0x1F,0x00,0x06,0x00,0x00},
/*************? Custom2*************/
{ 0x04,
	0x01,
	0x01,
	0x1F,
	0x00,
	0x00,
	0x00,
	0x00},
/*************? Custom2*************/
{0x04,
	0x04,
	0x04,
	0x07,
	0x00,
	0x00,
	0x00,
	0x00}
	
	
	
	
	
	
};
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

void LCD_WriteInt(Sint_32 num)
{
Uint_32 temp=1;
if(num==0)
{
	LCD_WriteChar('0');
}
if (num<0)
{
	LCD_WriteChar('-');
	num*=-1;
}
while (num!=0)
{
	temp =(temp *10)+(num%10);
	num/=10;
}
while(temp!=1)
{
	LCD_WriteChar((temp%10)+48);
	temp/=10;
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
void Custom_Char (void)
{
	Uint_8 Custom_Char_Count = 0 , Bytes = 0;
	for (Custom_Char_Count = 0 ; Custom_Char_Count < C_CHAR_NO ; Custom_Char_Count++)
	{
	       LCD_WriteCommand(0X40+(Custom_Char_Count*8));
		   for(Bytes = 0 ; Bytes < BYTES_NO ; Bytes++)
		   {
			   LCD_WriteChar(Custom_Char_Arr[Custom_Char_Count][Bytes]);
		   }
	}
}

/**********************************************************************************************************************
 *  END OF FILE: LCD_Core.c
 *********************************************************************************************************************/
