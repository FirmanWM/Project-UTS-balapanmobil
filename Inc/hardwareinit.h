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

#define tekan_SS 			HAL_GPIO_ReadPin(Button_StartStop_GPIO_Port, Button_StartStop_Pin)==GPIO_PIN_RESET
#define tekan_Reset			HAL_GPIO_ReadPin(Button_RESET_GPIO_Port, Button_RESET_Pin)==GPIO_PIN_RESET
#endif /* INC_HARDWAREINIT_H_ */
