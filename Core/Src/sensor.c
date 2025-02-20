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


sensor_trigger_t sensor_trigger(){
	static int prev_reading_left=0;
	static int prev_reading_right=0;

	prev_reading_left=sensor_read(SENSOR_LEFT);
	prev_reading_right=sensor_read(SENSOR_RIGHT);

	sensor_trigger_t res;

	if((SENSOR_LEFT>(prev_reading_left+1000))&&(SENSOR_RIGHT>(prev_reading_right+1000))){  /*Left sensor and Right sensor
																							detected dark material(line)*/
		prev_reading_left=sensor_read(SENSOR_LEFT);
		prev_reading_right=sensor_read(SENSOR_RIGHT);
		res= R_BOTH_DETECTED;
	}
	else if((SENSOR_LEFT>(prev_reading_left+1000))&&(SENSOR_RIGHT<(prev_reading_right+1000))){/*Left sensor ONLY
																							detected dark material(line)*/
		prev_reading_left=sensor_read(SENSOR_LEFT);
		prev_reading_right=sensor_read(SENSOR_RIGHT);
		res= R_LEFT_DETECTED;
	}
	else if((SENSOR_LEFT<(prev_reading_left+1000))&&(SENSOR_RIGHT>(prev_reading_right+1000))){/*Right sensor ONLY
																								detected dark material(line)*/
			prev_reading_left=sensor_read(SENSOR_LEFT);
			prev_reading_right=sensor_read(SENSOR_RIGHT);
			res= R_RIGHT_DETECTED;
		}
	else{
		prev_reading_left=sensor_read(SENSOR_LEFT);
		prev_reading_right=sensor_read(SENSOR_RIGHT);
		res= R_NOT_ON_LINE;
	}
	return res;
}

