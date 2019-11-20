/*
 * sensor.c
 *
 *  Created on: Nov 1, 2019
 *      Author: Sudjat
 */

#include "main.h"
#include "task.h"
#include "LCD_display2.h"
#include "stm32f1xx_hal.h"
#include "hardwareinit.h"
#include "uart.h"

#define n 5
uint8_t lap_1, lap_2, lap_3, lap_4;
uint16_t miliSecond, milisecondA[6], milisecondB[6], milisecondC[6];
uint8_t second, secondA[6], secondB[6], secondC[6];
uint8_t minute, minuteA[6], minuteB[6], minuteC[6];
uint16_t timeout1 = 0, timeout2 = 0, timeout3 = 0, timeout4 = 0, timeout5 = 0;
//uint16_t timeoutVal1 = 500, timeoutVal2 = 500, timeoutVal3 = 500, timeoutVal4 = 500, timeoutVal5 = 500;
uint16_t timeoutVal = 50;
uint16_t resetDisplay;
uint8_t i;

unsigned char bouncing1=0xFF;
unsigned char bouncing2=0xFF;
unsigned char bouncing3=0xFF;
unsigned char bouncing4=0xFF;
unsigned char bouncing5=0xFF;

_Bool stopwatchEna;

void task_init(void){
	miliSecond=0;
	second=0;
	minute=0;
	LCD_init();
	LCD_clear();
	LCD_SetCursor(3,1);
	LCD_print("BALAPAN MOBIL");
	LCD_SetCursor(3,2);
	LCD_print("by : FIRMANWM");
}

void Stopwatch(void){
	if(stopwatchEna){
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

void task_mulai(void){
	if (HAL_GPIO_ReadPin(Button_StartStop_GPIO_Port, Button_StartStop_Pin)==GPIO_PIN_RESET){
		if(timeout1++ > timeoutVal){
			stopwatchEna = 1;
			LCD_clear();
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
	if (HAL_GPIO_ReadPin(Button_RESET_GPIO_Port, Button_RESET_Pin)==GPIO_PIN_RESET){
		if(timeout2++ > timeoutVal){
			stopwatchEna = 1;
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
		LCD_clear();
		task_displayreset();
		Stopwatch_Reset();
	}

	//sensor aktif saat stopwatch aktif

	if (stopwatchEna){
		//sensor 1
		if (HAL_GPIO_ReadPin(sens1_GPIO_Port, sens1_Pin)==GPIO_PIN_RESET){
			if (timeout3++ >= timeoutVal){
				stopwatchEna = 0;
				LCD_clear();
				task_errordis(1, "Sensor 1 Error");
				uart_println("Sensor 1 ERROR");
				//LCD_SetCursor(1, 4); LCD_print("sensor 1 Error");
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
			task_display(stopwatchEna);
			task_LED(lap_1, 1);
			//task_LED(lap_2, 2);
			//task_LED(lap_3, 3);
		}
		///sensor2
		if (HAL_GPIO_ReadPin(sens2_GPIO_Port, sens2_Pin)==GPIO_PIN_RESET){
			if(timeout4++ >= timeoutVal){
				stopwatchEna=0;
				LCD_clear();
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
			//task_LED(lap_1, 1);
			task_LED(lap_2, 2);
			//task_LED(lap_3, 3);
		}
		//sensor3
		if (HAL_GPIO_ReadPin(sens3_GPIO_Port, sens3_Pin)==GPIO_PIN_RESET){
			if(timeout5++ > timeoutVal){
				stopwatchEna=0;
				LCD_clear();
				task_errordis(1, "Sensor 3 Error");
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
			//task_LED(lap_1, 1);
			//task_LED(lap_2, 2);
			task_LED(lap_3, 3);
		}
	}
}

void task_errordis(_Bool state, char *msg){
	LCD_clear(); LCD_SetCursor(0, 0);LCD_SetCursor(1, 4); LCD_print(msg);
	uart_printdata(msg); uart_println(msg);
	//task_displayreset();
}

void task_displayreset(void){
	LCD_clear();
	LCD_SetCursor(3,1);
	LCD_print("BALAPAN MOBIL");
	LCD_SetCursor(3,2);
	LCD_print("by : FIRMANWM");
	if(resetDisplay++ > 20){
		resetDisplay = 0;
		LCD_clear();
	}
}

void task_display(_Bool state){
	if (state){
		//lcd
		LCD_clear();
		LCD_SetCursor(0,0); LCD_print("LAP :"); LCD_SetCursor(8, 0); LCD_print("TIME :");
		LCD_SetCursor(0, 1); LCD_print("A :"); LCD_printnum(lap_1);
		LCD_SetCursor(0, 2); LCD_print("B :"); LCD_printnum(lap_2);
		LCD_SetCursor(0, 3); LCD_print("C :"); LCD_printnum(lap_3);
		LCD_SetCursor(8, 1); LCD_printnum(secondA[lap_1]); LCD_print(":"); LCD_printnum(milisecondA[lap_1]);
		LCD_SetCursor(8, 2); LCD_printnum(secondB[lap_2]); LCD_print(":"); LCD_printnum(milisecondB[lap_2]);
		LCD_SetCursor(8, 3); LCD_printnum(secondC[lap_3]); LCD_print(":"); LCD_printnum(milisecondC[lap_3]);

		//uart
		uart_println(" >>>>>>>>>>>>>>>>>> DATA LAPANGAN DAN TIMER <<<<<<<<<<<<<<<<<<<<<< ");
		uart_printdata("LAP A : "); uart_printangka(lap_1); uart_printdata(" >> "); uart_printangka(secondA[lap_1]); uart_printdata(":"); uart_printangka(milisecondA[lap_1]);
		uart_println("\n\r");
		uart_printdata("LAP B : "); uart_printangka(lap_2); uart_printdata(" >> "); uart_printangka(secondB[lap_2]); uart_printdata(":"); uart_printangka(milisecondB[lap_2]);
		uart_println("\n\r");
		uart_printdata("LAP C : "); uart_printangka(lap_3); uart_printdata(" >> "); uart_printangka(secondC[lap_3]); uart_printdata(":"); uart_printangka(milisecondC[lap_3]);
		uart_println("\n\r");
		uart_println("  ");

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
