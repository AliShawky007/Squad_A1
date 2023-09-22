/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LCD_Core.c
 *        \brief  LCD 
 *		Created: 8/23/2023 9:28:35 PM
 *		 Author: ahmed
 *      \details  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LCD_Core.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint8 Custom_char_[C_char_no][Bytes_no]={
	{0x0E,0x08,0x1E,0x00,0x04,0x04,0x04,0x04},
	{0x00,0x00,0x00,0x00,0x00,0x1C,0x02,0x1F},
	{0x00,0x00,0x00,0x00,0x00,0x0E,0x0A,0x1F},
	{0x00,0x00,0x00,0x00,0x04,0x02,0x02,0x0F},
	
	{0x00,0x00,0x0A,0x1F,0x1F,0x1F,0x0E,0x04},
	{0x0E,0x08,0x1E,0x00,0x04,0x04,0x04,0x04},
	{0x02,0x04,0x08,0x1F,0x02,0x04,0x08,0x00}
	
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
* \Syntax          : void LCD_Init(void)     
* \Description     : initialze the LCD                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void LCD_Init(void)
{
	#if (LCD_MODE==LCD_4BIT_MODE)
	LCD_WriteCommand(0X33);
	LCD_WriteCommand(0X32);
	LCD_WriteCommand(0X28);

	LCD_WriteCommand(0X0C);
	LCD_WriteCommand(0X01);
	
	LCD_WriteCommand(0X06);
	LCD_WriteCommand(0X02);
	
	
	#endif
}
/******************************************************************************
* \Syntax          : void LCD_WriteCommand(uint8 cmd)
* \Description     : WriteCommand
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteCommand(uint8 cmd)
{
	uint8 old_value = 0 , New_value = 0;
	DIO_WriteChennel(LCD_RS_PIN,PIN_LOW);
	DIO_WriteChennel(LCD_E_PIN,PIN_LOW);
	
	#if (LCD_MODE==LCD_4BIT_MODE)
	
	DIO_ReadOutPutPort(LCD_D4_PIN,&old_value);
	New_value = ((cmd>>1)&DATA_MASK) | (old_value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN,New_value);
	
	
// 	DIO_WriteChennel(LCD_D4_PIN,GET_BIT(cmd,4));
// 	DIO_WriteChennel(LCD_D5_PIN,GET_BIT(cmd,5));
// 	DIO_WriteChennel(LCD_D6_PIN,GET_BIT(cmd,6));
// 	DIO_WriteChennel(LCD_D7_PIN,GET_BIT(cmd,7));
	
	DIO_WriteChennel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChennel(LCD_E_PIN,PIN_LOW);
	
	DIO_ReadOutPutPort(LCD_D4_PIN,&old_value);
	New_value = ((cmd<<3)&DATA_MASK) | (old_value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN,New_value);
	
// 	DIO_WriteChennel(LCD_D4_PIN,GET_BIT(cmd,0));
// 	DIO_WriteChennel(LCD_D5_PIN,GET_BIT(cmd,1));
// 	DIO_WriteChennel(LCD_D6_PIN,GET_BIT(cmd,2));
// 	DIO_WriteChennel(LCD_D7_PIN,GET_BIT(cmd,3));
	
	DIO_WriteChennel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChennel(LCD_E_PIN,PIN_LOW);
	
	_delay_ms(5);
	
	#endif
	
}
/******************************************************************************
* \Syntax          : void LCD_WriteChar(uint8 chr)
* \Description     : WriteChar
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteChar(uint8 chr)
{
	uint8 old_value = 0 , New_value = 0;
	DIO_WriteChennel(LCD_RS_PIN,PIN_HIGH);
	DIO_WriteChennel(LCD_E_PIN,PIN_LOW);
	
	#if (LCD_MODE==LCD_4BIT_MODE)
	
	DIO_ReadOutPutPort(LCD_D4_PIN,&old_value);
	New_value= ((chr>>1)&DATA_MASK) | (old_value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN,New_value);
	
	
// 	DIO_WriteChennel(LCD_D4_PIN,GET_BIT(chr,4));
// 	DIO_WriteChennel(LCD_D5_PIN,GET_BIT(chr,5));
// 	DIO_WriteChennel(LCD_D6_PIN,GET_BIT(chr,6));
// 	DIO_WriteChennel(LCD_D7_PIN,GET_BIT(chr,7));
	
	DIO_WriteChennel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChennel(LCD_E_PIN,PIN_LOW);
	
	DIO_ReadOutPutPort(LCD_D4_PIN,&old_value);
	New_value =((chr<<3)&DATA_MASK) | (old_value & DATA_PORT_MASK);
	DIO_WritePort(LCD_D4_PIN,New_value);
	
// 	DIO_WriteChennel(LCD_D4_PIN,GET_BIT(chr,0));
// 	DIO_WriteChennel(LCD_D5_PIN,GET_BIT(chr,1));
// 	DIO_WriteChennel(LCD_D6_PIN,GET_BIT(chr,2));
// 	DIO_WriteChennel(LCD_D7_PIN,GET_BIT(chr,3));
	
	DIO_WriteChennel(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WriteChennel(LCD_E_PIN,PIN_LOW);
	
	_delay_ms(5);
	
	#endif
}
/******************************************************************************
* \Syntax          : void LCD_WriteString(uint8* chr)
* \Description     : WriteString
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteString(uint8* chr)
{
	uint8 cnt = 0;
	while (chr[cnt] != '\0')
	{
		LCD_WriteChar(chr[cnt]);
		cnt++;
	}
}

/******************************************************************************
* \Syntax          : void LCD_WriteInteger(sint32 num)
* \Description     : WriteInteger
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteInteger(sint32 num)
{	
	uint32 temp=1;
	if (num==0)
	{
		LCD_WriteChar(48);
	}
	else if (num <0 )
	{
		LCD_WriteChar(45);
		num*=-1;
	}
	

	while (num)
	{
		temp =(temp*10)+ num%10;
		num /=10;
	}

	
	while (temp!=1)
	{
		LCD_WriteChar((temp%10)+48);
		temp/=10;
	}
	
}
/******************************************************************************
* \Syntax          : void LCD_WriteClear(void)
* \Description     : clearLCD
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_WriteClear(void)
{
	LCD_WriteCommand(0X01);
	LCD_WriteCommand(0X06);
	LCD_WriteCommand(0X02);
}
/******************************************************************************
* \Syntax          : void LCD_GoTo(uint8 Row,uint8 Col)
* \Description     : go to custom location in lcd
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_GoTo(uint8 Row,uint8 Col)
{
	uint8 arr[2]={0X80,0XC0};
	LCD_WriteCommand(arr[Row]+Col);	
}
/******************************************************************************
* \Syntax          : void Custom_char(void)
* \Description     : display custom char
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void Custom_char(void)
{
	uint8 Cust_char_cnt = 0 , Bytes = 0 ;
	
	for (Cust_char_cnt = 0 ; Cust_char_cnt < C_char_no ; Cust_char_cnt++)
	{
		LCD_WriteCommand(0X40+(Cust_char_cnt*8));
		
		for(Bytes = 0; Bytes< Bytes_no ; Bytes++)
		{
			LCD_WriteChar(Custom_char_[Cust_char_cnt][Bytes]);
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: LCD_Core.c
 *********************************************************************************************************************/
