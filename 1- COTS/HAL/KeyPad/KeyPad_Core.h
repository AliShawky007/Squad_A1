/*
 * KeyPad.h
 *
 * Created: 4/28/2021 10:02:24 PM
 *  Author: Ali
 */ 

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef KEYPAD_H_
#define KEYPAD_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "KeyPad_Cfg.h"
#include "DIO_Core.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	KEYPAD_PRESSED = 0,
	KEYPAD_NOT_PRESSED,
	KEYPAD_NA
}BUTTON_STATUS;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
STD_RETURN KeyPad_Init(void);

uint8 KeyPad_GetValue(void);
 
#endif /* KEYPAD_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

