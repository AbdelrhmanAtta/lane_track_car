/*
 * motor.c
 *
 *  Created on: Feb 19, 2025
 *      Author: A.Atta & Beshoy Maher
 */
#include "motor.h"
#include "main.h"

/*
 * @brief: Normal PWM init to save space in code.
 * @param: none
 * @return: void
 */
void motor_init(void)
{
	  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
}


/*
 * @brief: Controls both motors.
 * @param: speed as PWM signal (from 0 to 1023).
 * @return: void (change if needed later)
 */
void motor_forward_speed(uint16_t speed) 
{
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, speed);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, speed);
}

/*
 * @brief: Controls each motor separately, almost like motor_forward_speed but takes angle not PWM, change to PWM if more readable.
 * @param: Left and Right angle to steer with (from 0 to 90).
 * @return: void (change if needed later)
 */
void motors_steer(uint16_t steer_left_angle, uint16_t steer_right_angle)
{
	uint16_t steer_right = (steer_right_angle * 1023) / 90;
	uint16_t steer_left = (steer_left_angle * 1023) / 90;

	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, steer_right);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, steer_left);
}

