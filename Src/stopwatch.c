/*
 * stopwatch.c
 *
 *  Created on: Nov 2, 2019
 *      Author: Sudjat
 */

#include "main.h"
#include "stopwatch.h"

uint16_t milisecondA[6], milisecondB[6], milisecondC[6];
uint8_t secondA[6], secondB[6], secondC[6];
uint8_t minuteA[6], minuteB[6], minuteC[6];

_Bool stopwatchEna;

void Stopwatch_init(void){
miliSecond=0;
second=0;
minute=0;
}

void Stopwatch(void){
	if(1){
		miliSecond++;
		if(miliSecond>99){
			miliSecond=0;
			second++;
			if(second>59){
				second=0;
				minute++;
			}
		}
	}
}
void Stopwatch_Reset(void){
	miliSecond=0; second=0; minute=0;

	lap_1=0;	lap_2=0;	lap_3=0;
		for(uint8_t i=0; i<5; i++){
			milisecondA[i]=0;	milisecondB[i]=0;	milisecondC[i]=0;
			secondA[i]=0;	secondB[i]=0;	secondC[i]=0;
			minuteA[i]=0;	minuteB[i]=0;	minuteC[i]=0;
		}
}
