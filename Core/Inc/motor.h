/*
 * motor.h
 *
 *  Created on: Feb 19, 2025
 *      Author: A.Atta
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"


extern TIM_HandleTypeDef htim2;


/*
 * @brief: Normal PWM init to save space in code.
 * @param: none
 * @return: void
 */
void motor_init();

/*
 * @brief: Controls both motors.
 * @param: speed as PWM signal (from 0 to 1023).
 * @return: void (change if needed later)
 */
void motor_forward_speed(uint16_t speed) ;

/*
 * @brief: Controls each motor separately, almost like motor_forward_speed but takes angle not PWM, change to PWM if more readable.
 * @param: Left and Right angle to steer with (from 0 to 90).
 * @return: void (change if needed later)
 */
void motors_steer(uint16_t steer_left_angle, uint16_t steer_right_angle);



#endif /* INC_MOTOR_H_ */
