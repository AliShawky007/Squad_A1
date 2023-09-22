/*
 * DC MOTOR.c
 *
 * Created: 9/23/2023 12:56:39 AM
 * Author : Mina
 */ 

#include "PORT_CORE.h"
#include "PWM_CORE.h"
#include "DC_MOTOR_CORE.h"
#define F_CPU 16000000U
#include <util/delay.h>


int main(void)
{
    PORT_Init();
	DCMOTOR_Init();
	DCMOTOR_ForSpeed(60);
	DCMOTOR_ForDirection(RIGHT);
	_delay_ms(1000);
	DCMOTOR_Stop();
    while (1) 
    {
    }
}

