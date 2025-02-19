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
#define SENSOR_LEFT 			&hadc1
#define SENSOR_RIGHT 			&hadc2

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
int sensor_read(int pin);

// 7oto sensor_trigger_left w sensor_trigger_right (output 1 lw only one pin et2ra) w sensor_triggered_both (lw 2 pins) 3shan mksl :)
//separate functions
//lw 2l 1000-> white  zad alf  1000->black &delay 1 milli


#endif /* INC_SENSOR_H_ */
