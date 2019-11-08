/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "hardwareinit.h"
#include "usart.h"
#include "timer.h"
#include "LCD_display2.h"
#include "task.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint16_t ms;
uint8_t s;
uint8_t m;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */


	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();


	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_TIM2_Init();
	MX_TIM3_Init();
	MX_USART1_UART_Init();
	/* USER CODE BEGIN 2 */

	task_init();
	//
	//		LCD_init();
	//		LCD_clear(0, 0);
	//		LCD_SetCursor(3,1);
	//		LCD_print("BALAPAN MOBIL");
	//		LCD_SetCursor(3,2);
	//		LCD_print("by : FIRMANWM");
	//	HAL_Delay(3000);
	//	//Format Tampilan LCD 1
	//	LCD_clear(0,0);
	//	LCD_SetCursor(2,0);
	//	LCD_print("LAP1");
	//	LCD_SetCursor(8,0);
	//	LCD_print("LAP2");
	//	LCD_SetCursor(14,0);
	//	LCD_print("LAP3");
	//	LCD_SetCursor(0,1);
	//	LCD_print("A");
	//	LCD_SetCursor(0,2);
	//	LCD_print("B");
	//	LCD_SetCursor(0,3);
	//	LCD_print("C");
	//	HAL_Delay(3000);
	//	//Format Tampilan LCD 2
	//	LCD_clear(0,0);
	//	LCD_SetCursor(2,0);
	//	LCD_print("LAP4");
	//	LCD_SetCursor(8,0);
	//	LCD_print("JUARA");
	//	LCD_SetCursor(0,1);
	//	LCD_print("A");
	//	LCD_SetCursor(0,2);
	//	LCD_print("B");
	//	LCD_SetCursor(0,3);
	//	LCD_print("C");
	//	HAL_Delay(3000);
	//
	//	LCD_clear(0, 0);
	//	LCD_SetCursor(3,1);
	//	LCD_print("BALAPAN MOBIL");
	//	LCD_SetCursor(3,2);
	//	LCD_print("by : FIRMANWM")

	HAL_TIM_Base_Start_IT(&htim2);
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		//task_mulai();
		if (HAL_GPIO_ReadPin(Button_StartStop_GPIO_Port, Button_StartStop_Pin)==GPIO_PIN_SET){
			LCD_SetCursor(0, 0);
			LCD_print("button bisa");
		}
		else {
			LCD_SetCursor(0, 3);
			LCD_print("button tidak bisa");
		}
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{ 
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
