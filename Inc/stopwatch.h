/*
 * stopwatch.h
 *
 *  Created on: Nov 2, 2019
 *      Author: Sudjat
 */

#ifndef INC_STOPWATCH_H_
#define INC_STOPWATCH_H_


void Stopwatch(void);
void Stopwatch_Reset(void);
void Stopwatch_init(void);
uint16_t miliSecond;
uint8_t second;
uint8_t minute;
uint8_t lap_1, lap_2, lap_3, lap_4;
_Bool stopwatchEna;

#endif /* INC_STOPWATCH_H_ */
