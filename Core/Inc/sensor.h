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

/*
 * use the defined handler in main
 */

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;


/*//////
 * Defines for sensors channels
 */

#define SENSOR_LEFT 			&hadc2
#define SENSOR_RIGHT 			&hadc1
#define factor                  1.2
/*
 * Enum with return codes for trigger
 */
typedef enum
{
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


int sensor_read(ADC_HandleTypeDef *hadc);

/*
 * @brief: Detects if car is on line
 * @param: none
 * @return: Car touching line status
 */

sensor_trigger_t sensor_trigger();



#endif /* INC_SENSOR_H_ */
