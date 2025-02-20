/*
 * sensor.c
 *
 *  Created on: Feb 19, 2025
 *      Author: Mariam , Nancy Ashraf
 */
#include "sensor.h"


int sensor_read(ADC_HandleTypeDef *hadc){
    HAL_ADC_Start(hadc);
    if (HAL_ADC_PollForConversion(hadc, 10) == HAL_OK) {
        return HAL_ADC_GetValue(hadc);
    }
}


sensor_trigger_t sensor_trigger() {
    static int prev_reading_left = 1000;
    static int prev_reading_right = 1000;

    int current_reading_left = sensor_read(SENSOR_LEFT);
    int current_reading_right = sensor_read(SENSOR_RIGHT);

    static sensor_trigger_t sensor_trigger = R_NOT_ON_LINE;

    if ((current_reading_left > (prev_reading_left + 1000)) && (current_reading_right > (prev_reading_right + 1000))) {
        sensor_trigger = R_BOTH_DETECTED;
    }
    else if (current_reading_left > (prev_reading_left + 1000)) {
        sensor_trigger = R_LEFT_DETECTED;
    }
    else if (current_reading_right > (prev_reading_right + 1000)) {
        sensor_trigger = R_RIGHT_DETECTED;
    }
    else if (current_reading_right < (prev_reading_right - 1000)) {
        sensor_trigger = R_NOT_ON_LINE;
    }
    else if (current_reading_left < (prev_reading_left - 1000)) {
        sensor_trigger = R_NOT_ON_LINE;
    }


    // Update previous readings
    prev_reading_left = current_reading_left;
    prev_reading_right = current_reading_right;


    return sensor_trigger;
}
