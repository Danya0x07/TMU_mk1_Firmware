/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

#include "stm32f1xx_ll_spi.h"
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_system.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_exti.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_cortex.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_pwr.h"
#include "stm32f1xx_ll_dma.h"

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
#define NRF_IRQ_Pin LL_GPIO_PIN_4
#define NRF_IRQ_GPIO_Port GPIOA
#define NRF_CSN_Pin LL_GPIO_PIN_0
#define NRF_CSN_GPIO_Port GPIOB
#define NRF_CE_Pin LL_GPIO_PIN_1
#define NRF_CE_GPIO_Port GPIOB
#define LEDMX_OE_Pin LL_GPIO_PIN_10
#define LEDMX_OE_GPIO_Port GPIOB
#define LEDMX_A_Pin LL_GPIO_PIN_11
#define LEDMX_A_GPIO_Port GPIOB
#define LEDMX_B_Pin LL_GPIO_PIN_12
#define LEDMX_B_GPIO_Port GPIOB
#define LEDMX_SCLK_Pin LL_GPIO_PIN_14
#define LEDMX_SCLK_GPIO_Port GPIOB
#define BTN_START_Pin LL_GPIO_PIN_8
#define BTN_START_GPIO_Port GPIOA
#define BTN_START_EXTI_IRQn EXTI9_5_IRQn
#define BTN_STOP_Pin LL_GPIO_PIN_9
#define BTN_STOP_GPIO_Port GPIOA
#define BTN_STOP_EXTI_IRQn EXTI9_5_IRQn
#define LED_LINKSTART_Pin LL_GPIO_PIN_6
#define LED_LINKSTART_GPIO_Port GPIOB
#define LED_LINKFINISH_Pin LL_GPIO_PIN_7
#define LED_LINKFINISH_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
