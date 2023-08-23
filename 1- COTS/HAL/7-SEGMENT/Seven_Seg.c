/*
 * Seven_Seg.c
 *
 * Created: 8/18/2023 4:11:17 PM
 *  Author: Mina
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Seven_Seg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Seven_Seg.h"
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
Uint_8 seven_seg[10]={0X7E,0X0C,0XB6,0X9E,0XCC,0XDA,0XFA,0X0E,0XFE,0XCE};
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
* \Syntax          : void Seven_Seg_Display(Uint_8 value)
* \Description     : Display 7-Segment
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Seven_Seg_Display(Uint_8 value)
{
	
		DIO_WriteChannel(COMMON1,seven_high);
		DIO_WriteChannel(COMMON2,seven_low );
		DIO_WritePort(A , seven_seg[value%10]);
		_delay_ms(1);
		
	    DIO_WriteChannel(COMMON1,seven_low );
	    DIO_WriteChannel(COMMON2,seven_high);
	    DIO_WritePort(A,seven_seg[value/10]);
	   _delay_ms(1);
}
/******************************************************************************
* \Syntax          : void Seven_Seg_increment_Counter(void)
* \Description     : INCREMENT COUNTER 7-Segment
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Seven_Seg_increment_Counter(void)
{
	Uint_8 i = 0, j = 0, z = 0;
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			for(z=0;z<=254;z++)
			{
					DIO_WriteChannel(COMMON1,seven_high);
					DIO_WriteChannel(COMMON2,seven_low );
					DIO_WritePort(A , seven_seg[j]);
					_delay_ms(1);
					
					DIO_WriteChannel(COMMON1,seven_low );
					DIO_WriteChannel(COMMON2,seven_high);
					DIO_WritePort(A,seven_seg[i]);
					_delay_ms(1);
			}
		}
	}
}

/******************************************************************************
* \Syntax          : void Seven_Seg_Decrement_Counter(void)
* \Description     : DECREMENT COUNTER 7-Segment
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Seven_Seg_Decrement_Counter(void)
{
	Sint_8 i = 0, j = 0;
	Uint_8 z = 0;
	for (i=9;i>-1;i--)
	{
		for (j=9;j>-1;j--)
		{
			for(z=0;z<=254;z++)
			{
				
				
				DIO_WriteChannel(COMMON1,seven_low );
				DIO_WriteChannel(COMMON2,seven_high);
				DIO_WritePort(A,seven_seg[i]);
				_delay_ms(1);
				
				DIO_WriteChannel(COMMON1,seven_high);
				DIO_WriteChannel(COMMON2,seven_low );
				DIO_WritePort(A , seven_seg[j]);
				_delay_ms(1);

			}
		}
	}
}

/******************************************************************************
* \Syntax          : void Seven_Seg_increment_Counter_Start_End(void)
* \Description     : INCREMENT COUNTER 7-Segment
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Seven_Seg_increment_Counter_Start_End(Uint_8 start,Uint_8 end)
{
	Uint_8 i = 0, j = 0, z = 0,COUNT=0,LOOP=end-start;
	for (i=start/10;i<=end/10;i++)
	{
		for (j=start%10;j<10;j++)
		{
			for(z=0;z<=254;z++)
			{
				DIO_WriteChannel(COMMON1,seven_high);
				DIO_WriteChannel(COMMON2,seven_low );
				DIO_WritePort(A , seven_seg[j]);
				_delay_ms(1);
				
				DIO_WriteChannel(COMMON1,seven_low );
				DIO_WriteChannel(COMMON2,seven_high);
				DIO_WritePort(A,seven_seg[i]);
				_delay_ms(1);
			
			}
			if(COUNT==LOOP)
			{
				break;
			}
			COUNT++;
			start=0;
			
		}
	
	}
}

/******************************************************************************
* \Syntax          : void Seven_Seg_Decrement_Counter_Start_End(void)
* \Description     : INCREMENT COUNTER 7-Segment
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Seven_Seg_Decrement_Counter_Start_End(Uint_8 start,Uint_8 end)
{
	Sint_8 i = 0, j = 0;
	Uint_8 z = 0,COUNT=0,LOOP=start-end;
	for (i=start/10;i>=end/10;i--)
	{
		for (j=start%10;j>-1;j--)
		{
			for(z=0;z<=254;z++)
			{
				
				DIO_WriteChannel(COMMON1,seven_low);
				DIO_WriteChannel(COMMON2,seven_high);
				DIO_WritePort(A,seven_seg[i]);
				_delay_ms(1);
				
				
				DIO_WriteChannel(COMMON1,seven_high);
				DIO_WriteChannel(COMMON2,seven_low);
				DIO_WritePort(A , seven_seg[j]);
				_delay_ms(1);
		
				
			}
			if(COUNT==LOOP)
			{
				break;
			}
			COUNT++;
			start=9;
			
		}
		
	}
}
/**********************************************************************************************************************
 *  END OF FILE: Seven_Seg.c
 *********************************************************************************************************************/
