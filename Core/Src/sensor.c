/*
 * sensor.c
 *
 *  Created on: Feb 19, 2025
 *      Author: Mariam
 */
#include "sensor.h"

void sensor_init(){
	/*Configuration for enabling continuous mode in both left and right sensors*/
	SENSOR_LEFT->Init.ContinuousConvMode = ENABLE;
	HAL_ADC_Init(SENSOR_LEFT);
	HAL_ADC_Start(SENSOR_LEFT);

	SENSOR_RIGHT->Init.ContinuousConvMode = ENABLE;
	HAL_ADC_Init(SENSOR_RIGHT);
	HAL_ADC_Start(SENSOR_RIGHT);

}

int sensor_read(int pin){
	long reading;
	HAL_ADC_PollForConversion(pin, HAL_MAX_DELAY);
	reading = HAL_ADC_GetValue(pin);
	return reading;
}


int sensor_trigger_left(){

}

int sensor_trigger_right(){

}
