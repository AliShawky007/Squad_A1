/*
 * KeyPad_Core.h
 *
 * Created: 8/26/2023 2:34:58 PM
 *  Author: Mina
 */ 
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <KeyPad_Core.h>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef KEYPAD_CORE_H_
#define KEYPAD_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO_CORE.h"
#include "KeyPad_CFG.h"
#define F_CPU 16000000U
#include "util/delay.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void KEYPAD_Init(void);
Uint_8 KEYPAD_GetValue(void);

 
#endif /* KEYPAD_CORE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: KeyPad_Core.h
 *********************************************************************************************************************/



