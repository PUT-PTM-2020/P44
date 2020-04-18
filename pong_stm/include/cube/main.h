/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

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
#define Button_3_Pin GPIO_PIN_2
#define Button_3_GPIO_Port GPIOE
#define Button_3_EXTI_IRQn EXTI2_IRQn
#define Button_4_Pin GPIO_PIN_3
#define Button_4_GPIO_Port GPIOE
#define Button_4_EXTI_IRQn EXTI3_IRQn
#define Button_5_Pin GPIO_PIN_4
#define Button_5_GPIO_Port GPIOE
#define Button_5_EXTI_IRQn EXTI4_IRQn
#define Button_6_Pin GPIO_PIN_5
#define Button_6_GPIO_Port GPIOE
#define Button_6_EXTI_IRQn EXTI9_5_IRQn
#define Button_7_Pin GPIO_PIN_6
#define Button_7_GPIO_Port GPIOE
#define Button_7_EXTI_IRQn EXTI9_5_IRQn
#define Radio_SCK_Pin GPIO_PIN_5
#define Radio_SCK_GPIO_Port GPIOA
#define Radio_MISO_Pin GPIO_PIN_6
#define Radio_MISO_GPIO_Port GPIOA
#define Radio_MOSI_Pin GPIO_PIN_7
#define Radio_MOSI_GPIO_Port GPIOA
#define Radio_CSN_Pin GPIO_PIN_4
#define Radio_CSN_GPIO_Port GPIOC
#define Radio_CE_Pin GPIO_PIN_5
#define Radio_CE_GPIO_Port GPIOC
#define OLED_SCL_Pin GPIO_PIN_6
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_7
#define OLED_SDA_GPIO_Port GPIOB
#define Button_1_Pin GPIO_PIN_0
#define Button_1_GPIO_Port GPIOE
#define Button_1_EXTI_IRQn EXTI0_IRQn
#define Button_2_Pin GPIO_PIN_1
#define Button_2_GPIO_Port GPIOE
#define Button_2_EXTI_IRQn EXTI1_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
