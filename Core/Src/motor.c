/*
 * motor.c
 *
 *  Created on: Feb 19, 2025
 *      Author: Beshoy Maher										lw esht8lt ektb esmk hna
 *      Sub-Author: A.Atta
 */
#include 'motor.h'

/*
 * @brief: Normal PWM init to save space in code.
 * @param: none
 * @return: void
 */
void motor_init()
{
   
        __HAL_RCC_TIM2_CLK_ENABLE();  

        TIM_HandleTypeDef pwm_timer2; 
        TIM_OC_InitTypeDef my_pwm = { 0 }; 

        pwm_timer2.Instance = TIM2; // Change TIM L enta 3ayzo

        pwm_timer2.Init.Prescaler = 39;  // Change bardo Lw ento 3ayz bs an searched W L2et L range Kws  
        pwm_timer2.Init.CounterMode = TIM_COUNTERMODE_UP;
        pwm_timer2.Init.Period = 1000; // as above 
        pwm_timer2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

        HAL_TIM_PWM_Init(&pwm_timer2); 

        my_pwm.OCMode = TIM_OCMODE_PWM1;  
        my_pwm.Pulse = 0 ; 
        my_pwm.OCPolarity = TIM_OCPOLARITY_HIGH;   

        HAL_TIM_PWM_ConfigChannel(&pwm_timer2, &my_pwm, TIM_CHANNEL_3); // M4 3aref anhy TIM_channel 
        HAL_TIM_PWM_Start(&pwm_timer2, TIM_CHANNEL_3);  //as above



}


/*
 * @brief: Controls both motors.
 * @param: speed as PWM signal (from 0 to 1023).
 * @return: void (change if needed later)
 */
void motor_forward_speed(uint16_t speed);

/*
 * @brief: Controls each motor separately, almost like motor_forward_speed but takes angle not PWM, change to PWM if more readable.
 * @param: Left and Right angle to steer with (from 0 to 90).
 * @return: void (change if needed later)
 */
void motors_steer(uint16_t, uint16_t);



#endif /* INC_MOTOR_H_ */
