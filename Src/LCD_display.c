/*
 * LCD_display.c
 *
 *  Created on: Oct 31, 2019
 *      Author: Sudjat
 */

#include "main.h"
#include "LCD_display2.h"
#include <stdio.h>

void LCD_Write4Bit(uint8_t data){
	HAL_GPIO_WritePin(D4_LCD_GPIO_Port, D4_LCD_Pin, ((data>>0)&1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D5_LCD_GPIO_Port, D5_LCD_Pin, ((data>>1)&1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D6_LCD_GPIO_Port, D6_LCD_Pin, ((data>>2)&1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(D7_LCD_GPIO_Port, D7_LCD_Pin, ((data>>3)&1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}
void LCD_send(_Bool mode, uint8_t data){
	if (mode) {RS_LCD(1);}
	else { RS_LCD(0);}

	LCD_Write4Bit(data>>4);
	E_LCD();
	LCD_Write4Bit(data);
	E_LCD();

}
void LCD_clear(uint8_t x, uint8_t y){
	LCD_Commend(0x01);
}
void LCD_init(void){
	LCD_Commend(0x33);
	LCD_Commend(0x32);
	LCD_Commend(0x28);
	LCD_Commend(0x0c);
	LCD_Commend(0x06);
}
void LCD_print(char *pData){
	while(*pData){
		LCD_Data(*pData++);
	}
}
void LCD_SetCursor(uint8_t x, uint8_t y){
	if (y == 0) LCD_Commend( 0x80 + x);
	if (y == 1) LCD_Commend( 0xc0 + x);
	if (y == 2) LCD_Commend( 0x94 + x);
	if (y == 3) LCD_Commend( 0xd4 + x);
}

void LCD_printnum(uint16_t num){
	char isi[20];
	sprintf(isi, "%d", num);
	LCD_print(isi);
}
