/*
 * LCD_display2.h
 *
 *  Created on: 31 Okt 2019
 *      Author: Sudjat
 */

#ifndef INC_LCD_DISPLAY2_H_
#define INC_LCD_DISPLAY2_H_

#include "main.h"
#include "stm32f1xx_hal.h"

#define E_LCD() 		{   HAL_GPIO_WritePin(E_LCD_GPIO_Port,E_LCD_Pin,GPIO_PIN_SET);\
							for(uint16_t i=0; i<1750; i++);\
							HAL_GPIO_WritePin(E_LCD_GPIO_Port,E_LCD_Pin,GPIO_PIN_RESET);\
							for(uint16_t i=0; i<1750; i++);}
#define RS_LCD(state) {HAL_GPIO_WritePin(RS_LCD_GPIO_Port,RS_LCD_Pin, (state) ? GPIO_PIN_SET : GPIO_PIN_RESET);}
#define LCD_Commend(data) {LCD_send (0, data);}
#define LCD_Data(data) {LCD_send (1, data);}

void LCD_Write4Bit(uint8_t);
void LCD_send(_Bool , uint8_t);
void LCD_init(void);
void LCD_print(char *);
void LCD_SetCursor(uint8_t, uint8_t);
void LCD_clear(void);
void LCD_printnum(uint16_t);


#endif /* INC_LCD_DISPLAY2_H_ */
