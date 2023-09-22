/*
 * TempSensor_Core.h
 *
 * Created: 9/9/2023 5:32:31 PM
 *  Author: Ali
 */ 


#ifndef TEMPSENSOR_CORE_H_
#define TEMPSENSOR_CORE_H_

#include "ADC_Core.h"

void TempSensor_Init(void);
uint16 TempSensor_Read(void);



#endif /* TEMPSENSOR_CORE_H_ */