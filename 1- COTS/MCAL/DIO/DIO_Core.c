/*
 * DIO_CORE.c
 *
 * Created: 8/19/2023 5:45:34 PM
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
#include "DIO_CORE.h"

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
* \Syntax          : void DIO_WRITECHANNEL(uint8 pin_NUM,PIN_VALUE_T pin_value)
* \Description     : DIO_WRITECHANNEL
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_WRITECHANNEL(uint8 pin_NUM,PIN_VALUE_T pin_value)
{
	uint8 port=0, pin=0 ;
	port=pin_NUM / NUMBER_OF_EACH_PORT_PINSS;
	 pin =pin_NUM % NUMBER_OF_EACH_PORT_PINSS;
	switch(pin_value){
		case PIN_HIGH :
		switch(port){
			case 0:
			SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 1:
			SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 2:
			SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 3:
			SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			default:
			break;
		}
		break;
		case PIN_LOW :
		switch(port){
			case 0:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 1:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 2:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			case 3:
			CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

/******************************************************************************
* \Syntax          : void DIO_READCHANNEL(uint8 pin_NUM,uint8 *pin_value)
* \Description     : DIO_READCHANNEL
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_READCHANNEL(uint8 pin_NUM,uint8 *pin_value)
{
	uint8 Port=0 ,Pin=0;
	Port=pin_NUM/(NUMBER_OF_EACH_PORT_PINSS);
	Pin=pin_NUM % (NUMBER_OF_EACH_PORT_PINSS);
	switch(Port){
		case 0:
		*pin_value=GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN),Pin);
		break;
		case 1:
		*pin_value=GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN),Pin);
		break;
		case 2:
		*pin_value=GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN),Pin);
		break;
		case 3:
		*pin_value=GET_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_INPUT_REGISTER_PIN),Pin);
		break;
		default:
		break;
	}
}

/******************************************************************************
* \Syntax          : void DIO_FLIPCHANNEL(uint8 pin_NUM)
* \Description     : Led Toggle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_FLIPCHANNEL(uint8 pin_NUM)
{
	uint8 Port=0 ,Pin=0;
	Port=pin_NUM/(NUMBER_OF_EACH_PORT_PINSS);
	Pin=pin_NUM % (NUMBER_OF_EACH_PORT_PINSS);
	switch(Port){
		case 0:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),Pin);
		break;
		case 1:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),Pin);
		break;
		case 2:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),Pin);
		break;
		case 3:
		Toggle_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT),Pin);
		break;
		default:
		break;
	}
}

/******************************************************************************
* \Syntax          : void DIO_WRITEPORT(uint8 pin_NUM,uint8 PORT_value)
* \Description     : DIO_WRITEPORT
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_WRITEPORT(PORT_NUM_T PORT,uint8 PORT_value)
{
	
	//Port=pin_NUM/(NUMBER_OF_EACH_PORT_PINSS);
	switch(PORT){
		case 0:
		PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT)=PORT_value;
		break;
		case 1:
		PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT)=PORT_value;
		break;
		case 2:
		PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT)=PORT_value;
		break;
		case 3:
		PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT)=PORT_value;
		break;
		default:
		break;
	}
	
}

/******************************************************************************
* \Syntax          : void LED_Toggle(void)
* \Description     : Led Toggle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_READPORT(uint8 pin_NUM,uint8 *PORT_value)
{
	uint8 Port=0 ;
	Port=pin_NUM/(NUMBER_OF_EACH_PORT_PINSS);
	switch(Port){
		case 0:
	    *PORT_value=PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		case 1:
		*PORT_value=PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		case 2:
		*PORT_value=PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		case 3:
		*PORT_value=PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		default:
		break;
	}
}
/******************************************************************************
* \Syntax          : void LED_Toggle(void)
* \Description     : Led Toggle
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void DIO_ReadOUTPUTPort(PORT_NUM_T PORT,uint8 *PORT_value)
{
	switch(PORT){
		case 0:
		*PORT_value=PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		case 1:
		*PORT_value=PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		case 2:
		*PORT_value=PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		case 3:
		*PORT_value=PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS+GPIO_OUTPUT_REGISTER_PORT);
		break;
		default:
		break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/