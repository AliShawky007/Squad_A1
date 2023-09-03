/*
 * Calculator.c
 *
 * Created: 8/26/2023 5:40:39 PM
 *  Author: Mina
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Calculator.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Calculator.h"

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
 void Calculator_Display(Uint_8 button)
{

static	Sint_32 arr[32]={0};
static	Sint_8 cnt =0;
static	Sint_32 num = 0 ;
static	Sint_32 NUM = 0;
static	Sint_32 res = 0;
Uint_8 z=0 ,i =0;
switch (button)
{
	case '1':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case '2':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case '3':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case '4':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case '5':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case '6':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case '7':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case '8':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case '9':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case '0':
	NUM = button-0X30;
	LCD_WriteInt(NUM);
	break;
	case 'c':
	NUM =0,num = 0,res= 0,i=0,cnt = 0,z=0;
	for (i=0;i<32;i++)
	{
		arr[i]=0;	
	}
	LCD_WriteCommand(0x01);
	break;
	case '+':
	LCD_WriteChar(button);
	break;
	case '-':
	LCD_WriteChar(button);
	break;
	case '*':
	LCD_WriteChar(button);
	break;
	case '/':
	LCD_WriteChar(button);
	break;
	case '=':
	LCD_WriteChar(button);
	LCD_WriteCommand(0x01);
	break;
}
if (button>='0'&&button<='9')
{
		num = num*10+NUM;	
		arr[cnt] = num;
}


 else if (button == '+' || button == '-' || button == '*' || button == '/' )
{
	cnt++;
	arr[cnt]= button;
	cnt++;
	num = 0;
}



else if (button == '=')
{	
   for ( i =0 ; i < cnt+1 ; i++)
{
		if (arr[i] == '*')
		{
			arr[i-1] = arr[i-1] * arr [i+1];

			for ( z = i ; z < cnt+1 ; z+=2)
			{
				arr[z] = arr[z+2];
				arr[z+1]=arr[z+3];
			}
			cnt-=2;
			i=0;
		}
		if (arr[i] == '/')
		{
			if (arr[i+1]==0)
			{
				LCD_WriteCommand(0x01);
				LCD_GOTO(0,0);
				LCD_WriteString("Divided By Zero!");
				LCD_GOTO(1,4);
				LCD_WriteString("Undefined         ");
				
				break;
			}
			arr[i-1] = (arr[i-1] / arr [ i+1]);

			for ( z = i ; z < cnt+1 ; z+=2)
			{
				arr[z] = arr[z+2];
				arr[z+1]=arr[z+3];
			}
			cnt-=2;
			i=0;
		}
}


for ( i =0 ; i < cnt +1 ; i++)
{
	if (arr[i] == '+')
	{
		arr[i-1] = arr[i-1] + arr [ i+1];

		for ( z = i ; z < cnt+1 ; z+=2)
		{
			arr[z] = arr[z+2];
			arr[z+1]=arr[z+3];
		}
		cnt-=2;
		i=0;
	}
	if (arr[i] == '-')
	{
		arr[i-1] = arr[i-1] - arr [i+1];

		for ( z = i ; z < cnt+1 ; z+=2)
		{
			arr[z] = arr[z+2];
			arr[z+1]=arr[z+3];
		}
		cnt-=2;
		i=0;
	}
}


for (i = 0 ; i <cnt+1 ; i++)
{
	res= res + arr[i];
	
}
num =res;
LCD_WriteInt(res);
cnt=0;
for (i = 0 ; i <32 ; i++)
{
	arr[i]=0;
}



}

}




/**********************************************************************************************************************
 *  END OF FILE: Calculator.c
 *********************************************************************************************************************/
