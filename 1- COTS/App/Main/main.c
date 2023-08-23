/*
 * COTS.c
 *
 * Created: 8/12/2023 3:32:34 PM
 * Author : Mina
 */ 
#include "LED.h"
#include "Button.h"
#include "Relay.h"
#include "Buzzer.h"
#include "Seven_Seg.h"
#include "PORT_CORE.h"
#include "LCD_Core.h"
#define F_CPU 16000000U
#include <util/delay.h>






int main(void)
{
    /* Replace with your application code */
	//PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_DIRECTION_REGISTER_DDR) = 0x02; //bit //0b00000010
	//PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_OUTPUT_REGISTER_PORT)=0x02; //pin
	//SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_DIRECTION_REGISTER_DDR) , 1);
	//SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_OUTPUT_REGISTER_PORT) , 1);
	//SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_DIRECTION_REGISTER_DDR) , 2);
	//SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_OUTPUT_REGISTER_PORT) , 2);
	
	//Uint_8 button =1, button1 =1, button2 =1 , button3 =1 ;
	//Uint_8 seven_seg[10]={0X7E,0X0C,0XB6,0X9E,0XCC,0XDA,0XFA,0X0E,0XFE,0XCE};
	//	SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_DIRECTION_REGISTER_DDR) , 6);
	//	SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_DIRECTION_REGISTER_DDR) , 7);
	//	PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRESS + GPIO_DIRECTION_REGISTER_DDR) = 0xFF;
		
	
	//LED_Init();
	//Button_Init();
	//Button1_Init();
	//Button2_Init();
	//Button3_Init();
	//Buzzer_Init();
	//Relay1_Init();
	//Relay2_Init();
	//Seven_Seg_Init();
	//LED_On();
	
	//Uint_8 val=0,va=0,b3=0,b4=0;
	PORT_Init();
	LCD_Init();
	LCD_WriteString("Mina");
	
	
	
    while (1) 
    {
		//button=Button_GetValue();
		//
		//if(button==0)
		//{
		//	LED_Toggle();
		//}
		//
		//button1=Button1_GetValue();
		//
		//if(button1==0)
		//{
		//	Buzzer_Toggle();
		//}
		//button2=Button2_GetValue();
		//if(button2==0)
		//{
		//	Relay1_Toggle();
		//}
		//button3=Button3_GetValue();
		//if(button3==0)
		//{
		//	Relay2_Toggle();
		//}
		
		//_delay_ms(1000);
		//SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_OUTPUT_REGISTER_PORT) , 6);
		//SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_OUTPUT_REGISTER_PORT) , 7);
		//PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRESS+GPIO_OUTPUT_REGISTER_PORT)=seven_seg[8];
		
		//SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_OUTPUT_REGISTER_PORT) , 6);
		//CLR_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_OUTPUT_REGISTER_PORT) , 7);
		//PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRESS+GPIO_OUTPUT_REGISTER_PORT)=seven_seg[93%10];
		//_delay_ms(1);
		//CLR_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_OUTPUT_REGISTER_PORT) , 6);
		//SET_BIT( PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRESS + GPIO_OUTPUT_REGISTER_PORT) , 7);
		//PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRESS+GPIO_OUTPUT_REGISTER_PORT)=seven_seg[93/10];
		//_delay_ms(1);
		//Seven_Seg_Display(45);
		//Seven_Seg_increment_Counter();
		//Seven_Seg_Decrement_Counter();
	    //Seven_Seg_increment_Counter_Start_End(12,20);
		//Seven_Seg_Decrement_Counter_Start_End(10,00);
		//val=Button_GetValue(Button_0);
		//if (val==0)
		//{
		//	
		//}
		//va=Button1_GetValue(Button_1);
		//if (va==0)
		//{
		//	LED_Toggle(LED_GREEN);
		//}
		//b3=Button2_GetValue(Button_2);
		//if (b3==0)
		//{
		//	Relay_Toggle(Relay1);
		//}
		//b4=Button3_GetValue(Button_3);
		//if (b4==0)
		//{
		//	Relay_Toggle(Relay2);
		//}
		
		
		
    }
	
}

