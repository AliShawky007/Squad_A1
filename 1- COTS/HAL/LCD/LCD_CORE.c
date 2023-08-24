/*
 * LCD_CORE.c
 *
 * Created: 8/23/2023 9:28:54 PM
 *  Author: pc
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
#include "LCD_CORE.h"

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
* \Syntax          : void LED_Toggle(void)
* \Description     : Led Toggle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void LCD_INIT(void)
{
	#if (LCD_MODE == LCD_4BIT_MODE)
	
	LCD_write_command(0x33);
	LCD_write_command(0x32);
	LCD_write_command(0x28);
	
	LCD_write_command(0x0C);
	LCD_write_command(0x01);
	LCD_write_command(0x06);
	LCD_write_command(0x02);
	
	#endif
}


/******************************************************************************
* \Syntax          : void LED_Toggle(void)
* \Description     : Led Toggle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/


void LCD_write_command(uint8 cmd)
{
	uint8 old_val=0 ,new_val=0;
	DIO_WRITECHANNEL(LCD_RS_PIN,PIN_LOW);
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_LOW);
	#if (LCD_MODE==LCD_4BIT_MODE)

   DIO_ReadOUTPUTPort(PORT_A,&old_val);

	new_val=((cmd>>1)&DATA_MASK)|(old_val&DATA_PORT_MASK);
	DIO_WRITEPORT(PORT_A,new_val);
	
	
	/*DIO_WRITECHANNEL(LCD_D4_PIN,GET_BIT(cmd,4));
	DIO_WRITECHANNEL(LCD_D5_PIN,GET_BIT(cmd,5));
	DIO_WRITECHANNEL(LCD_D6_PIN,GET_BIT(cmd,6));
	DIO_WRITECHANNEL(LCD_D7_PIN,GET_BIT(cmd,7));*/
	
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_LOW);
	
	DIO_ReadOUTPUTPort(LCD_D4_PIN,&old_val);

	new_val=((cmd<<3)&DATA_MASK)|(old_val&DATA_PORT_MASK);
	DIO_WRITEPORT(PORT_A,new_val);
	
	/*DIO_WRITECHANNEL(LCD_D4_PIN,GET_BIT(cmd,0));
	DIO_WRITECHANNEL(LCD_D5_PIN,GET_BIT(cmd,1));
	DIO_WRITECHANNEL(LCD_D6_PIN,GET_BIT(cmd,2));
	DIO_WRITECHANNEL(LCD_D7_PIN,GET_BIT(cmd,3));*/
	
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_LOW);
	
	_delay_ms(5);
	#endif
}

/******************************************************************************
* \Syntax          : void LED_Toggle(void)
* \Description     : Led Toggle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/



void LCD_write_char(uint8 chr)
{
	uint8 old_val=0 ,new_val=0;
	DIO_WRITECHANNEL(LCD_RS_PIN,PIN_HIGH);
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_LOW);
	
	#if (LCD_MODE==LCD_4BIT_MODE)

    DIO_ReadOUTPUTPort(PORT_A,&old_val);

	new_val=((chr>>1)&DATA_MASK)|(old_val&DATA_PORT_MASK);
	DIO_WRITEPORT(LCD_D4_PIN,new_val);
	
	
	/*DIO_WRITECHANNEL(LCD_D4_PIN,GET_BIT(chr,4));
	DIO_WRITECHANNEL(LCD_D5_PIN,GET_BIT(chr,5));
	DIO_WRITECHANNEL(LCD_D6_PIN,GET_BIT(chr,6));
	DIO_WRITECHANNEL(LCD_D7_PIN,GET_BIT(chr,7));*/
	
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_LOW);
	
	DIO_ReadOUTPUTPort(PORT_A,&old_val);

	new_val=((chr<<3)&DATA_MASK)|(old_val&DATA_PORT_MASK);
	DIO_WRITEPORT(PORT_A,new_val);
	
	/*DIO_WRITECHANNEL(LCD_D4_PIN,GET_BIT(chr,0));
	DIO_WRITECHANNEL(LCD_D5_PIN,GET_BIT(chr,1));
	DIO_WRITECHANNEL(LCD_D6_PIN,GET_BIT(chr,2));
	DIO_WRITECHANNEL(LCD_D7_PIN,GET_BIT(chr,3));*/
	
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_HIGH);
	_delay_ms(1);
	DIO_WRITECHANNEL(LCD_E_PIN,PIN_LOW);
	
	_delay_ms(5);
	#endif

}

/******************************************************************************
* \Syntax          : void LED_Toggle(void)
* \Description     : Led Toggle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_write_STRING(uint8 *chr)
{
	uint8 cnt=0;
	while(chr[cnt]!='\0')
	{
		LCD_write_char(chr[cnt]);
		cnt++;
	}
}

/******************************************************************************
* \Syntax          : void LED_Toggle(void)
* \Description     : Led Toggle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void LCD_CLR(void)
{
	LCD_write_command(0x01);
}
/******************************************************************************
* \Syntax          : void LED_Toggle(void)
* \Description     : Led Toggle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void LCD_GOTO(uint8 ROW,uint8 col)
{
	uint8 arr[2]={0x80,0x0c};
		LCD_write_command(arr[ROW]+col);
		
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
