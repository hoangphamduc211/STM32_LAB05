/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
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
#define button1_Pin GPIO_PIN_13
#define button1_GPIO_Port GPIOC
#define button2_Pin GPIO_PIN_1
#define button2_GPIO_Port GPIOA
#define button3_Pin GPIO_PIN_2
#define button3_GPIO_Port GPIOA
#define LED_RED1_Pin GPIO_PIN_3
#define LED_RED1_GPIO_Port GPIOA
#define LED_GREEN1_Pin GPIO_PIN_4
#define LED_GREEN1_GPIO_Port GPIOA
#define LED_YELLOW1_Pin GPIO_PIN_5
#define LED_YELLOW1_GPIO_Port GPIOA
#define LED_RED2_Pin GPIO_PIN_6
#define LED_RED2_GPIO_Port GPIOA
#define LED_GREEN2_Pin GPIO_PIN_7
#define LED_GREEN2_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_0
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_1
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_2
#define EN2_GPIO_Port GPIOB
#define LED_YELLOW2_Pin GPIO_PIN_8
#define LED_YELLOW2_GPIO_Port GPIOA
#define SEG_A_Pin GPIO_PIN_9
#define SEG_A_GPIO_Port GPIOA
#define SEG_B_Pin GPIO_PIN_10
#define SEG_B_GPIO_Port GPIOA
#define SEG_C_Pin GPIO_PIN_11
#define SEG_C_GPIO_Port GPIOA
#define SEG_D_Pin GPIO_PIN_12
#define SEG_D_GPIO_Port GPIOA
#define SEG_E_Pin GPIO_PIN_13
#define SEG_E_GPIO_Port GPIOA
#define SEG_F_Pin GPIO_PIN_14
#define SEG_F_GPIO_Port GPIOA
#define SEG_G_Pin GPIO_PIN_15
#define SEG_G_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_3
#define EN3_GPIO_Port GPIOB
#define EN0B4_Pin GPIO_PIN_4
#define EN0B4_GPIO_Port GPIOB
#define EN1B5_Pin GPIO_PIN_5
#define EN1B5_GPIO_Port GPIOB
#define EN2B6_Pin GPIO_PIN_6
#define EN2B6_GPIO_Port GPIOB
#define EN3B7_Pin GPIO_PIN_7
#define EN3B7_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
