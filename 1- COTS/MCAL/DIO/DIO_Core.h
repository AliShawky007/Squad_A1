/*
 * DIO_CORE.h
 *
 * Created: 8/19/2023 5:45:08 PM
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
#ifndef DIO_CORE_H_
#define DIO_CORE_H_
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  CPU.h
 *       Module:  1.0.0
 *
 *  Description:  CPU Driver    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************
PORTA_PIN0 ---> #0    PORTB _PIN0 ---> #8         PORTC_PIN0 ---> #16       PORTD_PIN0 ---> #24  
PORTA_PIN1 ---> #1    PORTB _PIN1 ---> #9         PORTC_PIN1 ---> #17       PORTD_PIN1 ---> #25
PORTA_PIN2 ---> #2    PORTB _PIN2 ---> #10        PORTC_PIN2 ---> #18       PORTD_PIN2 ---> #26
PORTA_PIN3 ---> #3    PORTB _PIN3 ---> #11        PORTC_PIN3 ---> #19       PORTD_PIN3 ---> #27
PORTA_PIN4 ---> #4    PORTB _PIN4 ---> #12        PORTC_PIN4 ---> #20       PORTD_PIN4 ---> #28
PORTA_PIN5 ---> #5    PORTB _PIN5 ---> #13        PORTC_PIN5 ---> #21       PORTD_PIN5 ---> #29
PORTA_PIN6 ---> #6    PORTB _PIN6 ---> #14        PORTC_PIN6 ---> #22       PORTD_PIN6 ---> #30
PORTA_PIN7 ---> #7    PORTB _PIN7 ---> #15        PORTC_PIN7 ---> #23       PORTD_PIN7 ---> #31
**********************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "MCU.h"
#include "STD.h"
#include "BIT_Math.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define  NUMBER_OF_EACH_PORT_PINSS    8


#define PORTA_PIN0  0
#define PORTA_PIN1  1
#define PORTA_PIN2  2
#define PORTA_PIN3  3
#define PORTA_PIN4  4
#define PORTA_PIN5  5
#define PORTA_PIN6  6
#define PORTA_PIN7  7


#define PORTB_PIN0  8
#define PORTB_PIN1  9
#define PORTB_PIN2  10
#define PORTB_PIN3  11
#define PORTB_PIN4  12
#define PORTB_PIN5  13
#define PORTB_PIN6  14
#define PORTB_PIN7  15

#define PORTC_PIN0  16
#define PORTC_PIN1  17
#define PORTC_PIN2  18
#define PORTC_PIN3  19
#define PORTC_PIN4  20
#define PORTC_PIN5  21
#define PORTC_PIN6  22
#define PORTC_PIN7  23

#define PORTD_PIN0  24
#define PORTD_PIN1  25
#define PORTD_PIN2  26
#define PORTD_PIN3  27
#define PORTD_PIN4  28
#define PORTD_PIN5  29
#define PORTD_PIN6  30
#define PORTD_PIN7  31

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
	PIN_LOW = 0,
	PIN_HIGH
}PIN_VALUE_T;

typedef enum
{
	PORT_A = 0,
	PORT_B,
	PORT_C,
	PORT_D
}PORT_NUM_T;




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void DIO_WRITECHANNEL(uint8 pin_NUM,PIN_VALUE_T pin_value);
void DIO_READCHANNEL(uint8 pin_NUM,PIN_VALUE_T *pin_value);
void DIO_FLIPCHANNEL(uint8 pin_NUM);
void DIO_WRITEPORT(uint8 pin_NUM,uint8 PORT_value);
void DIO_READPORT(uint8 pin_NUM,uint8 *PORT_value);
void DIO_ReadOUTPUTPort(PORT_NUM_T PORT,uint8 *PORT_value);




 

#endif /* DIO_CORE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
