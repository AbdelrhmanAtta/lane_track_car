/*
 * sensor.c
 *
 *  Created on: Feb 19, 2025
 *      Author: Mariam Ramy , Nancy Ashraf
 */
#include "sensor.h"


int sensor_read(ADC_HandleTypeDefhadc) {
    HAL_ADC_Start(hadc);
    HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY);  // Wait for conversion
    int value = HAL_ADC_GetValue(hadc);
    HAL_ADC_Stop(hadc);
    return value;
}


sensor_trigger_t sensor_trigger() {
    static int prev_reading_left = 500;   //Initialise readings
    static int prev_reading_right = 500;

    int current_reading_left = sensor_read(SENSOR_LEFT);  //Read values from sensors
    int current_reading_right = sensor_read(SENSOR_RIGHT);

    int threshold=1000;

    if ((current_reading_left > (prev_reading_left + threshold)) && (current_reading_right > (prev_reading_right + threshold))) {
    	prev_reading_left = current_reading_left;
    	prev_reading_right = current_reading_right;
    	return R_BOTH_DETECTED;
    }
    else if (current_reading_left > (prev_reading_left + threshold)) {
    	prev_reading_left = current_reading_left;
    	prev_reading_right = current_reading_right;
        return R_LEFT_DETECTED;
    }
    else if (current_reading_right > (prev_reading_right + threshold)) {
    	prev_reading_left = current_reading_left;
    	prev_reading_right = current_reading_right;
        return R_RIGHT_DETECTED;
    }
    else if (current_reading_right < (prev_reading_right - threshold)) {
    	prev_reading_left = current_reading_left;
    	prev_reading_right = current_reading_right;
    	return R_NOT_ON_LINE;
    }
    else if (current_reading_left < (prev_reading_left - threshold)) {
    	 prev_reading_left = current_reading_left;
    	 prev_reading_right = current_reading_right;
        return R_NOT_ON_LINE;
    }


    // Update previous readings
    prev_reading_left = current_reading_left;
    prev_reading_right = current_reading_right;
}
