/*
 * sensor.c
 *
 *  Created on: Nov 1, 2019
 *      Author: Sudjat
 */

#include "main.h"
#include "task.h"
#include "stopwatch.h"
#include "LCD_display2.h"
#include "stm32f1xx_hal.h"
#include "hardwareinit.h"

#define n 5
uint8_t lap_1, lap_2, lap_3, lap_4;
uint16_t milisecondA[6], milisecondB[6], milisecondC[6];
uint8_t secondA[6], secondB[6], secondC[6];
uint8_t minuteA[6], minuteB[6], minuteC[6];
uint16_t timeout1, timeout2, timeout3, timeout4, timeout5, timeoutVal = 700;
uint16_t resetDisplay;

unsigned char bouncing1=0xFF;
unsigned char bouncing2=0xFF;
unsigned char bouncing3=0xFF;
unsigned char bouncing4=0xFF;
unsigned char bouncing5=0xFF;

void task_init(void){
	miliSecond=0;
	second=0;
	minute=0;
	LCD_init();
	Stopwatch_init();
}

void task_mulai(void){
	if (tekan_SS){
		if(timeout1++ > timeoutVal){
			stopwatchEna = 0;
			task_errordis(1, "Button START/STOP Error");
		}
		else
			bouncing1 = (bouncing1<<1)|1;
	}
	else{
		timeout1 = 0;
		bouncing1 = bouncing1<<1;
	}
	if (bouncing1==3){
		stopwatchEna = !(stopwatchEna);
		task_display(stopwatchEna);
	}
	if (tekan_Reset){
		if(timeout2++ > timeoutVal){
			stopwatchEna = 0;
			task_errordis(1, "Button Reset Error");
		}
		else
			bouncing2 = (bouncing2<<1)|1;
	}
	else{
		timeout2 = 0;
		bouncing2 = bouncing2<<1;
	}
	if (bouncing2==3){
		Stopwatch_Reset();
	}

	//sensor aktif saat stopwatch aktif

	if (stopwatchEna){
		//sensor 1
		if (HAL_GPIO_ReadPin(sens1_GPIO_Port, sens1_Pin)==GPIO_PIN_RESET){
			if (timeout3++ > timeoutVal){
				stopwatchEna = 0;
				LCD_clear(0, 0);
				task_errordis(1, "Sens 1 Error");
			}
			else
				bouncing3 = (bouncing3<<1)|1;
		}
		else {
			timeout3=0;
			bouncing3 = bouncing3<<1;
		}
		if (bouncing3==3){
			lap_1++;
			if (lap_1 > n) lap_1 = n;
			milisecondA[lap_1] = miliSecond;
			secondA[lap_1] = second;
			minuteA[lap_1] = minute;
			task_display(1);
			LCD_SetCursor(4, 1);
			LCD_printnum(milisecondA[lap_1]); LCD_print(" :");
			LCD_printnum(secondA[lap_1]);
			for(uint8_t i=1; i<=4 ; i++){
				task_LED(i, 1);
			}
		}
		///sensor2
		if (HAL_GPIO_ReadPin(sens2_GPIO_Port, sens2_Pin)==GPIO_PIN_RESET){
			if(timeout4++ > timeoutVal){
				stopwatchEna=0;
				LCD_clear(0, 0);
				task_errordis(1, "Sensor 2 Error");
			}
			else
				bouncing4 = (bouncing4<<1)|1;
		}
		else {
			timeout4=0;
			bouncing4 = bouncing4<<1;
		}

		if (bouncing4==3){
			lap_2++;
			if(lap_2 > n) lap_2=n;
			milisecondB[lap_2] = miliSecond;
			secondB[lap_2] = second;
			minuteB[lap_2] = minute;
			task_display(stopwatchEna);
			for(uint8_t i=1;i<=4;i++){
				task_LED(i, 2);
			}
		}
		//sensor3
		if (HAL_GPIO_ReadPin(sens3_GPIO_Port, sens3_Pin)==GPIO_PIN_RESET){
			if(timeout5++ > timeoutVal){
				stopwatchEna=0;
				LCD_clear(0, 0);
				task_errordis(1, "Seomsor 3 Error");
			}
			else
				bouncing5 = (bouncing5<<1)|1;
		}
		else {
			timeout5=0;
			bouncing5 = bouncing5<<1;
		}

		if (bouncing5==3){
			lap_3++;
			if(lap_3 > n) lap_3=n;
			milisecondC[lap_3] = miliSecond;
			secondC[lap_3] = second;
			minuteC[lap_3] = minute;
			task_display(stopwatchEna);
			for(uint8_t i=1;i<=4;i++){
				task_LED(i, 3);
			}
		}
	}
}

void task_errordis(_Bool state, char *msg){
	LCD_SetCursor(0, 0); LCD_print(msg);
	task_displayreset();
}

void task_displayreset(void){
	if(resetDisplay++ > 20){
		resetDisplay = 0;
		LCD_clear(0, 0);
	}
}

void task_display(uint8_t sesi){
	switch (sesi) {
		case 1:
			//format LCD1
			LCD_clear(0, 0);
			LCD_SetCursor(0,1);
			LCD_print("A");
			LCD_SetCursor(0,2);
			LCD_print("B");
			LCD_SetCursor(0,3);
			LCD_print("C");
			LCD_SetCursor(4,0);
			LCD_print("LAP 1");
			break;
		default:
			break;
	}
}

void task_LED(uint8_t Dled, uint8_t slot){

	switch (Dled) {
	case 0:
		HAL_GPIO_WritePin(D0_LAP_GPIO_Port, D0_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D1_LAP_GPIO_Port, D1_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D2_LAP_GPIO_Port, D2_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(D0_LAP_GPIO_Port, D0_LAP_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D1_LAP_GPIO_Port, D1_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D2_LAP_GPIO_Port, D2_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(D0_LAP_GPIO_Port, D0_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D1_LAP_GPIO_Port, D1_LAP_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(D2_LAP_GPIO_Port, D2_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(D0_LAP_GPIO_Port, D0_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D1_LAP_GPIO_Port, D1_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D2_LAP_GPIO_Port, D2_LAP_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(D0_LAP_GPIO_Port, D0_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D1_LAP_GPIO_Port, D1_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(D2_LAP_GPIO_Port, D2_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
		break;
	}
	switch (slot) {
	case 1 :
		HAL_GPIO_WritePin(ENA1_LAP_GPIO_Port, ENA1_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENA2_LAP_GPIO_Port, ENA2_LAP_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENA3_LAP_GPIO_Port, ENA3_LAP_Pin, GPIO_PIN_RESET);
		break;
	case 2 :
		HAL_GPIO_WritePin(ENA1_LAP_GPIO_Port, ENA1_LAP_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENA2_LAP_GPIO_Port, ENA2_LAP_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENA3_LAP_GPIO_Port, ENA3_LAP_Pin, GPIO_PIN_RESET);
		break;
	case 3 :
		HAL_GPIO_WritePin(ENA1_LAP_GPIO_Port, ENA1_LAP_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENA2_LAP_GPIO_Port, ENA2_LAP_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENA3_LAP_GPIO_Port, ENA3_LAP_Pin, GPIO_PIN_SET);
		break;
	}
}
