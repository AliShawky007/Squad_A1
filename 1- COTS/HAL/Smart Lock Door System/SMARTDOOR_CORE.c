/*
 * SMARTDOOR_CORE.c
 *
 * Created: 9/25/2023 7:45:06 PM
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
#include "SMARTDOOR_CORE.h"
#define F_CPU 16000000U
#include "util/delay.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define In_Pass 4
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Uint_8 Input_Password[In_Pass] = {1997 , 1998 , 1999 , 2001};
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
void Smart_Door_Init(Uint_8 button)
{
	DIO_WriteChannel(LED_RED,led_high);
	static Uint_8 NUM =0;
	static Uint_8 num =0;
	static Uint_8 cnt =0;
	static Uint_8 cnt1 =0;
	static Uint_8 i =0;
	switch (button)
	{
		case '1':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case '2':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case '3':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case '4':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case '5':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case '6':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case '7':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case '8':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case '9':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case '0':
		NUM = button-0X30;
		LCD_WriteChar('*');
		break;
		case 'c':
		NUM =0,num=0,cnt=0,cnt1=0;
		DIO_WriteChannel(LED_GREEN,led_low);
		DIO_WriteChannel(PORTC_PIN5,PIN_LOW);
		LCD_Clear();
		LCD_WriteString("Code:");
		break;
		case '=':
		LCD_Clear();
		break;
		default:
		break;
	}
	if (button>='0'&&button<='9')
	{
		num = num*10+NUM;
	}
	
	if (button == '=')
	{
		for (i=0;i<In_Pass;i++)
		{
			if (num == Input_Password[i])
			{
				cnt++;
			}
			if (num != Input_Password[i])
			{
				cnt1++;
			}
		}
		if (cnt!=0)
		{
		  LCD_GOTO(0,1);
		  LCD_WriteString("Door Unlocked");
		  DIO_WriteChannel(LED_GREEN,led_high);
		  DIO_WriteChannel(LED_RED,led_low);
		  SERVO_SetDegree(115);
		  num=0,NUM=0,cnt=0,cnt1=0;
		  _delay_ms(5000);
		  SERVO_SetDegree(0);
		  DIO_WriteChannel(LED_RED,led_high);
		  DIO_WriteChannel(LED_GREEN,led_low);
		  LCD_Clear();
		  LCD_GOTO(0,2);
		  LCD_WriteString("Door Locked");
		  _delay_ms(2000);
		  LCD_Clear();
		  LCD_WriteString("Code:");
		}
		else
		{
			LCD_GOTO(0,2);
			LCD_WriteString("Door Locked");
			num=0,NUM=0,cnt=0;
			SERVO_SetDegree(0);
			_delay_ms(2000);
			LCD_Clear();
			LCD_WriteString("Code:");
		}
		if (cnt1 == (In_Pass*5))
		{
			LCD_Clear();
			DIO_WriteChannel(PORTC_PIN5,PIN_HIGH);
			LCD_GOTO(0,1);
			LCD_WriteString("!!!!ALERT!!!!");
			LCD_GOTO(1,2);
			LCD_WriteString("Door Locked");
			num=0,NUM=0,cnt=0;
			SERVO_SetDegree(0);
			
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
