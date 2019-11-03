/*
 * hardwareinit.c
 *
 *  Created on: Nov 1, 2019
 *      Author: Sudjat
 */
#include "stm32f1xx_it.h"
#include "main.h"
#include "hardwareinit.h"

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENA1_LAP_Pin|ENA2_LAP_Pin|ENA3_LAP_Pin|D0_LAP_Pin
                          |D4_LCD_Pin|D5_LCD_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, D1_LAP_Pin|D2_LAP_Pin|D3_LAP_Pin|buzzer_Pin
                          |RS_LCD_Pin|E_LCD_Pin|D6_LCD_Pin|D7_LCD_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Button_RESET_Pin Button_StartStop_Pin */
  GPIO_InitStruct.Pin = Button_RESET_Pin|Button_StartStop_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : sens1_Pin sens2_Pin sens3_Pin */
  GPIO_InitStruct.Pin = sens1_Pin|sens2_Pin|sens3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : ENA1_LAP_Pin ENA2_LAP_Pin ENA3_LAP_Pin D0_LAP_Pin
                           D4_LCD_Pin D5_LCD_Pin */
  GPIO_InitStruct.Pin = ENA1_LAP_Pin|ENA2_LAP_Pin|ENA3_LAP_Pin|D0_LAP_Pin
                          |D4_LCD_Pin|D5_LCD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : D1_LAP_Pin D2_LAP_Pin D3_LAP_Pin buzzer_Pin
                           RS_LCD_Pin E_LCD_Pin D6_LCD_Pin D7_LCD_Pin */
  GPIO_InitStruct.Pin = D1_LAP_Pin|D2_LAP_Pin|D3_LAP_Pin|buzzer_Pin
                          |RS_LCD_Pin|E_LCD_Pin|D6_LCD_Pin|D7_LCD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

