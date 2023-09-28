/*
 * KeyPad_CFG.h
 *
 * Created: 8/26/2023 2:38:29 PM
 *  Author: Mina
 */ 



/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <KeyPad_CFG.h>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define ROWS_NUMBERS 4
#define COLUMNS_NUMBERS 4

#define ROW_INIT PORTB_PIN4
#define ROW_FINAL PORTB_PIN7

#define COLUMN_INIT  PORTD_PIN2
#define COLUMN_FINAL PORTD_PIN4


#define KEYPAD_ROW0 PORTB_PIN4
#define KEYPAD_ROW1 PORTB_PIN5
#define KEYPAD_ROW2 PORTB_PIN6
#define KEYPAD_ROW3 PORTB_PIN7


#define KEYPAD_COLUMN0 PORTD_PIN2
#define KEYPAD_COLUMN1 PORTD_PIN3
#define KEYPAD_COLUMN2 PORTD_PIN4


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern Uint_8 KEYPAD_VALUE[ROWS_NUMBERS][COLUMNS_NUMBERS];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /* KEYPAD_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: KeyPad_CFG.h
 *********************************************************************************************************************/





