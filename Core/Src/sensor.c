/*
 * sensor.c
 *
 *  Created on: Feb 19, 2025
 *      Author: Mariam
 */
#include "sensor.h"


int sensor_read(ADC_HandleTypeDef *hadc){
    HAL_ADC_Start(hadc);
    if (HAL_ADC_PollForConversion(hadc, 10) == HAL_OK) {
        return HAL_ADC_GetValue(hadc);
    }
}


int sensor_trigger_left(){

}

int sensor_trigger_right(){

}
