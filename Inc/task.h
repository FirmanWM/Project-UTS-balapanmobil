/*
 * task.h
 *
 *  Created on: Nov 3, 2019
 *      Author: Sudjat
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_

void task_init(void);
void task_mulai(void);
void task_errordis(_Bool state, char *msg);
void task_display(_Bool state);
void task_displayreset(void);
void task_LED(uint8_t Dled, uint8_t slot);
void Stopwatch(void);
void Stopwatch_Reset(void);
void Stopwatch_init(void);
uint16_t miliSecond;
uint8_t second;
uint8_t minute;
uint8_t lap_1, lap_2, lap_3, lap_4;
_Bool stopwatchEna;

#endif /* INC_TASK_H_ */
