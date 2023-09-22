/*
 * PWM_CORE.h
 *
 * Created: 9/22/2023 2:35:59 PM
 *  Author: Mina
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
#ifndef PWM_CORE_H_
#define PWM_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PWM_CFG.h"
#include "BIT_MATH.h"
#include "MCU.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PWM_ENABLE 1
#define PWM_DISABLE 0

#define PWM_FAST 0
#define PWM_PHASE_CORRECT 1

#define PWM_INVERTED    0
#define PWM_NONINVERTED 1

#define PWM_PRESC8      8
#define PWM_PRESC32     32
#define PWM_PRESC64     64
#define PWM_PRESC128    128
#define PWM_PRESC256    256
#define PWM_PRESC1024   1024

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
void PWM_Init(void);

void PWM0_Generate(Uint_8 Duty_Cycle);

void PWM1_Generate(Uint_8 Duty_Cycle , Uint_16 Frequency);
 
#endif /* PWM_CORE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/



