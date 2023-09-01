/*
 * IRQH_Core.h
 *
 * Created: 9/1/2023 5:47:44 PM
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

#ifndef IRQH_CORE_H_
#define IRQH_CORE_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MCU.h"
#include "BIT_Math.h"
#include "IRQH_Cfg.h"
#include <avr/interrupt.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define  INT_ENABLE       1
#define  INT_DISABLE      0

#define  EXT_INT_TRIGGER_FALLING_EDGE          0
#define  EXT_INT_TRIGGER_RISING_EDGE           1
#define  EXT_INT_TRIGGER_LOW_LEVEL             2
#define  EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE    3

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
void IRQH_SetGlobalINT(uint8 );

void IRQH_SetExternalINT(void);

void IRQH_Set_CallBack(uint8 Interrupt_Vector_Index , void(*p)(void));
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /* IRQH_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/


