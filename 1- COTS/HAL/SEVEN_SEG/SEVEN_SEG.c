/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SEVEN_SEG.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SEVEN_SEG.h"
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
uint8 seven_seg[10]={0X7E,0X0C,0XB6,0X9E,0XCC,0XDA,0XF8,0X0E,0XFE,0XCE};
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
* \Syntax          : void SEVEN_SEG_OUT(uint8)
* \Description     : display 7-SEG
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void SEVEN_SEG_OUT(uint8 num)
{
	DIO_WriteChannel(SEV_SEG_1,PIN_HIGH);
	DIO_WriteChannel(SEV_SEG_2,PIN_LOW);
	DIO_WritePort(SEV_SEG_PORT,seven_seg[num%10]);
	_delay_ms(10);
	DIO_WriteChannel(SEV_SEG_1,PIN_LOW);
	DIO_WriteChannel(SEV_SEG_2,PIN_HIGH);
	DIO_WritePort(SEV_SEG_PORT,seven_seg[num/10]);
	_delay_ms(10);
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/