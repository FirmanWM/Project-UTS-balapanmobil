/*
 * hardwareinit.h
 *
 *  Created on: Nov 1, 2019
 *      Author: Sudjat
 */

#ifndef INC_HARDWAREINIT_H_
#define INC_HARDWAREINIT_H_


void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_TIM2_Init();
void MX_TIM3_Init();
void MX_USART1_UART_Init();


#define tekan_SS 			HAL_GPIO_ReadPin(Button_StartStop_GPIO_Port, Button_StartStop_Pin)==GPIO_PIN_RESET
#define tekan_Reset			HAL_GPIO_ReadPin(Button_RESET_GPIO_Port, Button_RESET_Pin)==GPIO_PIN_RESET


TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;
#endif /* INC_HARDWAREINIT_H_ */
