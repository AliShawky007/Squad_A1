/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <LCD_Core.h>
 *       Module:  1.0.0
 * Created: 8/23/2023 9:28:46 PM
 *  Author: ahmed
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef LCD_CORE_H_
#define LCD_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO_Core.h"
#include "LCD_Cfg.h"
#define  F_CPU  16000000U
#include <util/delay.h>
#include "STD.h"

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
void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_WriteChar(uint8 chr);

void LCD_WriteString(uint8* chr); 

void LCD_WriteInteger(sint32 num);

void LCD_WriteClear(void);

void LCD_GoTo(uint8 Row,uint8 Col);

void Custom_char(void);

#endif  /* LCD_CORE_H_ */

/**************************************************************************************************************
 *  END OF FILE: LCD_Core.h
********/
