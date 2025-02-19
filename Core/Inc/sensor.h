/*
 * sensor.h
 *
 *  Created on: Feb 19, 2025
 *      Author: Mariam Ramy & Nancy Ashraf
 *      Sub-Author: A.Atta
 */

#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

#include "main.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;


/*//////
 * Defines for sensors channels
 */
#define SENSOR_LEFT 			&hadc2
#define SENSOR_RIGHT 			&hadc1

/*
 * Enum with return codes for trigger
 */
typedef enum{
	R_NOT_ON_LINE = 0,
	R_LEFT_DETECTED,
	R_RIGHT_DETECTED,
	R_BOTH_DETECTED
}sensor_trigger_t;

/*
 * @brief: Continous Analog init to save space in code.
 * @param: none
 * @return: void
 */
void sensor_init();

/*
 * @brief: Reads analog data
 * @param: Sensor pin
 * @return: Analog reading as int
 */
int sensor_read(ADC_HandleTypeDef *hadc);

// 7oto sensor_trigger_left w sensor_trigger_right (output 1 lw only one pin et2ra) w sensor_triggered_both (lw 2 pins) 3shan mksl :)
//separate functions
//lw 2l 1000-> white  zad alf  1000->black &delay 1 milli

sensor_trigger_t sensor_trigger_left();

sensor_trigger_t sensor_trigger_right();

#endif /* INC_SENSOR_H_ */
