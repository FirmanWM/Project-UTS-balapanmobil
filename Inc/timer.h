/*
 * timer.h
 *
 *  Created on: Nov 1, 2019
 *      Author: Sudjat
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_


void MX_TIM2_Init(void);
void MX_TIM3_Init(void);

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

#endif /* INC_TIMER_H_ */
