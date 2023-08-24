/*
 * PORT_CORE.c
 *
 * Created: 8/19/2023 3:55:47 PM
 *  Author: pc
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT_CORE.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : void PORT_INIT(void)
* \Description     : port init
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void PORT_INIT(void)
{
	uint8  cnt=0, port=0,pin=0,Dir=0;
	for(cnt=0;cnt<DEFINED_PINS;cnt++)
	{
		port=PORT_Initialization[cnt].PIN_NUM / NUMBER_OF_EACH_PORT_PINSS ;
		pin=PORT_Initialization[cnt].PIN_NUM % NUMBER_OF_EACH_PORT_PINSS ;
		Dir=PORT_Initialization[cnt].PIN_DIR;
		
		switch(Dir)
		{
			case PIN_OUTPUT:
			
			switch(port)
			{
				case 0:
				SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_DIRCETION_REGISTER_DDR),pin);
				
				break;
				
				case 1:
				SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_DIRCETION_REGISTER_DDR),pin);
				break;
				
				case 2:
				SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_DIRCETION_REGISTER_DDR),pin);
				break;
				
				case 3:
				SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_DIRCETION_REGISTER_DDR),pin);
				break;
			}
			break;
			
			case PIN_INPUT:
			
			switch(pin)
			{
				case 0:
				CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_DIRCETION_REGISTER_DDR),pin);
				
				break;
				
				case 1:
				CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_DIRCETION_REGISTER_DDR),pin);
				break;
				
				case 2:
				CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_DIRCETION_REGISTER_DDR),pin);
				break;
				
				case 3:
				CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_DIRCETION_REGISTER_DDR),pin);
				break;
			}
			
			break;
			
			default:
			
			break;
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/