/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Button_RESET_Pin GPIO_PIN_14
#define Button_RESET_GPIO_Port GPIOC
#define Button_StartStop_Pin GPIO_PIN_15
#define Button_StartStop_GPIO_Port GPIOC
#define sens1_Pin GPIO_PIN_0
#define sens1_GPIO_Port GPIOA
#define sens2_Pin GPIO_PIN_1
#define sens2_GPIO_Port GPIOA
#define sens3_Pin GPIO_PIN_2
#define sens3_GPIO_Port GPIOA
#define ENA1_LAP_Pin GPIO_PIN_4
#define ENA1_LAP_GPIO_Port GPIOA
#define ENA2_LAP_Pin GPIO_PIN_5
#define ENA2_LAP_GPIO_Port GPIOA
#define ENA3_LAP_Pin GPIO_PIN_6
#define ENA3_LAP_GPIO_Port GPIOA
#define D0_LAP_Pin GPIO_PIN_7
#define D0_LAP_GPIO_Port GPIOA
#define D1_LAP_Pin GPIO_PIN_0
#define D1_LAP_GPIO_Port GPIOB
#define D2_LAP_Pin GPIO_PIN_1
#define D2_LAP_GPIO_Port GPIOB
#define D3_LAP_Pin GPIO_PIN_2
#define D3_LAP_GPIO_Port GPIOB
#define buzzer_Pin GPIO_PIN_10
#define buzzer_GPIO_Port GPIOB
#define RS_LCD_Pin GPIO_PIN_13
#define RS_LCD_GPIO_Port GPIOB
#define E_LCD_Pin GPIO_PIN_15
#define E_LCD_GPIO_Port GPIOB
#define D4_LCD_Pin GPIO_PIN_12
#define D4_LCD_GPIO_Port GPIOA
#define D5_LCD_Pin GPIO_PIN_15
#define D5_LCD_GPIO_Port GPIOA
#define D6_LCD_Pin GPIO_PIN_3
#define D6_LCD_GPIO_Port GPIOB
#define D7_LCD_Pin GPIO_PIN_4
#define D7_LCD_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
