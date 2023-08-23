
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer.c
 *        \brief  display numbers on the 7seg digits
 *		  \Created: 8/17/2023 4:41:52 PM
 *		  \Author: Ali
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Timer.h"
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
* \Syntax          : void Timer(uint8 Min, sint8 Sec)
* \Description     : takes min and sec and set timer 
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void Timer(uint8 Min, sint8 Sec)
{
	sint16 i; //var to loop through seconds and minutes counter and delay them
	/*timer for minutes*/

	while (1)
	{
		for ( ; Sec>0 ; Sec-- )
		{
			for (i = (10*500) ; i>=0 ; i--) /*loop for delaying the counter by 1 second and display it on both digits*/
			{				
				SevSeg_Display((Min*10)+Sec);
			}
		}
		if (Min==0) break; /*when minutes counter ends exit the while loop else decrement and count another 60seconds */
		else
		{
			Min--;
			Sec=6;
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Timer.c
 *********************************************************************************************************************/