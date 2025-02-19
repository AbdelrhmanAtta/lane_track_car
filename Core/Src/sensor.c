/*
 * sensor.c
 *
 *  Created on: Feb 19, 2025
 *      Author: Mariam
 */
#include "sensor.h"

int sensor_read(int pin){
	long reading;
	HAL_ADC_PollForConversion(pin, HAL_MAX_DELAY);
	reading = HAL_ADC_GetValue(pin);
	return reading;
}
