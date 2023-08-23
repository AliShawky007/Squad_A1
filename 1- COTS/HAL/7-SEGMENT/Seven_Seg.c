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
void Seven_Seg_Display_second(Uint_8 second)
{
	
		DIO_WriteChannel(COMMON1,seven_high);
		DIO_WriteChannel(COMMON2,seven_low );
		DIO_WritePort(A , seven_seg[second]);
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
void Seven_Seg_Display_minute(Uint_8 minute)
{
	DIO_WriteChannel(COMMON1,seven_low );
	DIO_WriteChannel(COMMON2,seven_high);
	DIO_WritePort(A,seven_seg[minute]);
	_delay_ms(1);
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
void Seven_Seg_Decrement_Counter_Start_End(Sint_8 minute,Sint_8 second)
{
	
	Sint_8 i = 0, j = 0;
	Uint_16 z = 0;
	for (i=minute;i>-1;i--)
	{
		for (j=second;j>-1;j--)
		{	
		     for(z=0;z<=5000;z++)
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
			second=9;
		}	

	}
}
/**********************************************************************************************************************
 *  END OF FILE: Seven_Seg.c
 *********************************************************************************************************************/
