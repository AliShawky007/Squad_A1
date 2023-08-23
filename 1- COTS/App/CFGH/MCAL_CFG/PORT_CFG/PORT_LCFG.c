/*
 * PORT_LCFG.c
 *
 * Created: 8/19/2023 3:48:02 PM
 *  Author: Mina
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT_LCFG.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT_LCFG.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const PIN_PARAMETERS PORT_Initialization[DEFINED_PINS]={
	/*****GREEN LED***
	{ PORTC_PIN1, PIN_OUTPUT  },*/
		/*****PUSH BUTTON 1***
	{ PORTD_PIN2, PIN_INPUT  },*/
		/*****BLUE LED***
	{ PORTC_PIN2, PIN_OUTPUT  },*/
	/*****PUSH BUTTON 2***
	{ PORTD_PIN3, PIN_INPUT  },*/
		/*****PUSH BUTTON 3***
	{ PORTD_PIN4, PIN_INPUT  },*/
	/*****PUSH BUTTON 4***
	{ PORTD_PIN5, PIN_INPUT  },*/
	/*****Relay 1***
	{ PORTC_PIN4, PIN_OUTPUT  },*/
	/*****Buzzer***
	{ PORTC_PIN3, PIN_OUTPUT  },*/
	/*****Enable Right 7-Segment***
	{ PORTC_PIN6, PIN_OUTPUT  },*/
	/*****Enable Left 7-Segment***
	{ PORTC_PIN7, PIN_OUTPUT  },*/
	/*****Enable PORTA_PIN0 7-Segment**
	{ PORTA_PIN1, PIN_OUTPUT  },*/
	/*****Enable B 7-Segment***
	{ PORTA_PIN2, PIN_OUTPUT  },
	/*****Enable C 7-Segment***
	{ PORTA_PIN3, PIN_OUTPUT  },*/
	/*****Enable D 7-Segment***
	{ PORTA_PIN4, PIN_OUTPUT  },*/
	/*****Enable E 7-Segment***
	{ PORTA_PIN5, PIN_OUTPUT  },*/
	/*****Enable F 7-Segment***
	{ PORTA_PIN6, PIN_OUTPUT  },*/
	/*****Enable G 7-Segment***
	{ PORTA_PIN7, PIN_OUTPUT  },*/
	/*****Enable DOT 7-Segment***
	{ PORTB_PIN0, PIN_OUTPUT  },*/
	/*****LCD E PIN******/
	{ PORTA_PIN2, PIN_OUTPUT  },
	/*****LCD RS PIN******/
	{ PORTA_PIN1, PIN_OUTPUT  },
	/*****LCD D4 PIN******/
	{ PORTA_PIN3, PIN_OUTPUT  },
	/*****LCD D5 PIN******/
	{ PORTA_PIN4, PIN_OUTPUT  },
	/*****LCD D6 PIN******/
	{ PORTA_PIN5, PIN_OUTPUT  },
	/*****LCD D7 PIN******/
	{ PORTA_PIN6, PIN_OUTPUT  }	
		
		
};
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
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: PORT_LCFG.c
 *********************************************************************************************************************/
