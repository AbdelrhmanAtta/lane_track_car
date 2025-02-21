/*
 * sensor.c
 *
 *  Created on: Feb 19, 2025
 *      Author: Mariam Ramy , Nancy Ashraf
 */

#include "sensor.h"


/*
 * function to change the analog value to digital
 */
int sensor_read(ADC_HandleTypeDef *hadc)
{
    HAL_ADC_Start(hadc);
    HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY);  // Wait for conversion
    int value = HAL_ADC_GetValue(hadc);
    HAL_ADC_Stop(hadc);
    return value;
}



sensor_trigger_t sensor_trigger() {
    static int prev_reading_left = 1000;
    static int prev_reading_right = 1000;

    int current_reading_left = sensor_read(SENSOR_LEFT);
    int current_reading_right = sensor_read(SENSOR_RIGHT);

    if ((current_reading_left > (prev_reading_left + 1000)) && (current_reading_right > (prev_reading_right + 1000))) {
    	return R_BOTH_DETECTED;
    }
    else if (current_reading_left > (prev_reading_left + 1000)) {
    	return R_LEFT_DETECTED;
    }
    else if (current_reading_right > (prev_reading_right + 1000)) {
    	return R_RIGHT_DETECTED;
    }


    prev_reading_left = current_reading_left;
    prev_reading_right = current_reading_right;

    return R_NOT_ON_LINE;

}

