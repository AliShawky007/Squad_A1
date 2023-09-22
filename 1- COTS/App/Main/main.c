/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ahmed Essam
 */ 

#include "PORT_Core.h"
#include "DC_MOTOR_Core.h"
#include "SERVO_MOTOR_Core.h"




#define F_CPU 16000000U
#include <util/delay.h>

int main(void)
{
	PORT_Init();
	
	DC_MOTOR_Init();
	
	Servo_Init();
	
	Servo_Generate(3,50);
	_delay_ms(500);
	Servo_Generate(4,50);
	_delay_ms(200);
// 	while (1)
// 	{
// 		DC_MOTOR_Direction(Left);
//		DC_MOTOR_Speed(60);
// 		_delay_ms(2000);
// 		DC_MOTOR_Direction(Right);
//		DC_MOTOR_Speed(60);
// 		_delay_ms(2000);
// 		DC_Motor_Stop();
// 		_delay_ms(2000);
// 	
//	}
	


}
