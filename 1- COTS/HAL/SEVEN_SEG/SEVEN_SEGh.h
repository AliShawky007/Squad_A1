/*
 * SEVEN_SEGh.h
 *
 * Created: 8/18/2023 4:08:20 PM
 *  Author: pc
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
#ifndef SEVEN_SEGH_H_
#define SEVEN_SEGH_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO_CORE.h"
#include "SEVEN_SEG_CFG.h"
#include "BUZ_CFG.h"
#define  F_CPU  16000000U
#include <util/delay.h>

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
typedef enum
{
	SEG_LOW=0,
	SEG_HIGH
}SEG_VALUE_T;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SEG_SETVALUE(uint8 NUM);


#endif /* SEVEN_SEGH_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

