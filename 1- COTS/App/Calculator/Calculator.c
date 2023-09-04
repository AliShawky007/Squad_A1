/*
 * Calculator.c
 *
 * Created: 8/26/2023 5:53:59 PM
 *  Author: mk591
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
* \Syntax          : uint8 Start_Calculate(void)   
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
sint32 Start_Calculate(void)
{
	sint8 cnt=0,temp=0;
	uint8 val=0,weight=0,flag=0;
	uint8 num[5]={0};
		sint32 res=0,num1=0;
	while(cnt<5)
	{
		if (cnt==5)
		{
			cnt=0;
		}
		val=KeyPad_GetValue();
	    if(val!=0)
	    {
			switch (val)
			{
				case '-':
				if (cnt==0)
				{
					flag=1;
				}
				
				else
				{
					LCD_WriteChar(val);
					temp=cnt-1;
					cnt=cnt-1;
					while(cnt>=0)
					{
						weight=power(10,temp-cnt);
						num1=num1+(num[cnt]*weight);
						cnt--;
					}
					if (flag==1)
					{
						num1=num1*-1;
					}
					res=Subtract_num(num1);
					return res;
				}
				break;
				case '+':
				temp=cnt-1;
				cnt=cnt-1;
				while(cnt>=0)
				{
					weight=power(10,temp-cnt);
					num1=num1+(num[cnt]*weight);
					cnt--;
				}
				if (flag==1)
				{
					num1=num1*-1;
				}
				LCD_WriteChar(val);
				res=Add_Num(num1);
				return res;
				break;
				case '*':
				temp=cnt-1;
				cnt=cnt-1;
				while(cnt>=0)
				{
					weight=power(10,temp-cnt);
					num1=num1+(num[cnt]*weight);
					cnt--;
				}
				if (flag==1)
				{
					num1=num1*-1;
				}
				LCD_WriteChar(val);
				res=multiply_Num(num1);
				return res;
				break;
					case '/':
					temp=cnt-1;
					cnt=cnt-1;
					while(cnt>=0)
					{
						weight=power(10,temp-cnt);
						num1=num1+(num[cnt]*weight);
						cnt--;
					}
					if (flag==1)
					{
						num1=num1*-1;
					}
					LCD_WriteChar(val);
					res=Divide_Num(num1);
					return res;
					break;
			}
	    	LCD_WriteChar(val);
			if ((val>=48)&&(val<=57))
			{
				num[cnt]=val-48;
	    	    cnt++;
			}
			
	    }
	}
}

/******************************************************************************
* \Syntax          : uint8 Add_Num(uint8)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
sint32 Add_Num(sint32 num1)
{
	uint8 val=0,weight=0;
	sint8 cnt=0,temp=0;
	uint8 num[5]={0};
		sint32 num2=0;
	while(1)
	{
		if (cnt==5)
		{
			cnt=0;
		}
		val=KeyPad_GetValue();
		if (val!=0)
		{
			if (val=='=')
			{
				temp=cnt-1;
				cnt=cnt-1;
				LCD_WriteChar('=');
				while(cnt>=0)
				{
					weight=power(10,temp-cnt);
					num2=num2+(num[cnt]*weight);
					cnt--;
				}
				num2=num1+num2;
				return num2;
			}
			LCD_WriteChar(val);
			num[cnt]=val-48;
			cnt++;
		}
	}
}
/******************************************************************************
* \Syntax          : uint8 Subtract_num(uint8)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
sint32 Subtract_num(sint32 num1)
{
	uint8 val=0,weight=0;
	sint8 cnt=0,temp=0;
	uint8 num[5]={0};
		sint32 num2=0;
	while(1)
	{
		if (cnt==5)
		{
			cnt=0;
		}
		val=KeyPad_GetValue();
		if (val!=0)
		{
			if (val=='=')
			{
				temp=cnt-1;
				cnt=cnt-1;
				LCD_WriteChar('=');
				while(cnt>=0)
				{
					weight=power(10,temp-cnt);
					num2=num2+(num[cnt]*weight);
					cnt--;
				}
				num2=num1-num2;
				return num2;
			}
			LCD_WriteChar(val);
			num[cnt]=val-48;
			cnt++;
		}
	}
}
/******************************************************************************
* \Syntax          : uint8 multiply_Num(uint8)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
sint32 multiply_Num(sint32 num1)
{
	uint8 val=0,weight=0;
	sint8 cnt=0,temp=0;
	uint8 num[5]={0};
		sint32 num2=0;
	while(1)
	{
		if (cnt==5)
		{
			cnt=0;
		}
		val=KeyPad_GetValue();
		if (val!=0)
		{
			if (val=='=')
			{
				temp=cnt-1;
				cnt=cnt-1;
				LCD_WriteChar('=');
				while(cnt>=0)
				{
					weight=power(10,temp-cnt);
					num2=num2+(num[cnt]*weight);
					cnt--;
				}
				num2=num1*num2;
				return num2;
			}
			LCD_WriteChar(val);
			num[cnt]=val-48;
			cnt++;
		}
	}
}
sint32 Divide_Num(sint32 num1)
{
	uint8 val=0,weight=0;
	sint8 cnt=0,temp=0;
	uint8 num[5]={0};
		sint32 num2=0;
	while(1)
	{
		if (cnt==5)
		{
			cnt=0;
		}
		val=KeyPad_GetValue();
		if (val!=0)
		{
			if (val=='=')
			{
				temp=cnt-1;
				cnt=cnt-1;
				LCD_WriteChar('=');
				while(cnt>=0)
				{
					weight=power(10,temp-cnt);
					num2=num2+(num[cnt]*weight);
					cnt--;
				}
				num2=num1/num2;
				return num2;
			}
			LCD_WriteChar(val);
			num[cnt]=val-48;
			cnt++;
		}
	}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/