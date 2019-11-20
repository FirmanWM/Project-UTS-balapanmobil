/*
 * uart.c
 *
 *  Created on: Nov 4, 2019
 *      Author: Sudjat
 */

#include "main.h"
#include "hardwareinit.h"
#include "uart.h"
#include "stm32f1xx_it.h"
#include "string.h"
#include "stdio.h"


void uart_printdata(char *pdata){
	HAL_UART_Transmit(&huart1, (uint8_t *)pdata, strlen(pdata), 10);}
void uart_println(char *pdata){
	HAL_UART_Transmit(&huart1, (uint8_t *)pdata, strlen(pdata), 10);
	char barisbaru[2] = "\r\n";
	HAL_UART_Transmit(&huart1, (uint8_t *)barisbaru, 2, 10);

}
void uart_printangka(uint8_t angka){
	char buff[50];
	sprintf(buff,"%d", angka);
	HAL_UART_Transmit(&huart1, (uint8_t *)buff, strlen(buff), 10);
}
