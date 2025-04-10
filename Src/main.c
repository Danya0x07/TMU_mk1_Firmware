/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "p10txt.h"
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
const uint8_t symbol[6 * 1] = {
    0b00110000,
    0b01111000,
    0b11111100,
    0b11111100,
    0b01111000,
    0b00110000,
};

const struct P10_Image image = {.n = 6, .m = 6, .data = &symbol[0]};

const uint8_t symbol2[6 * 2] = {
    0b11111111,0b11111110,
    0b10000011,0b11110010,
    0b10000100,0b00000010,
    0b10101000,0b00000010,
    0b10010000,0b00000010,
    0b11111111,0b11111110,
};

const struct P10_Image image2 = {.n = 15, .m = 6, .data = &symbol2[0]};
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
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  LL_SPI_Enable(SPI1);
  LL_SPI_Enable(SPI2);

  // Таймер динамической индикации
  LL_TIM_EnableIT_UPDATE(TIM1);
  LL_TIM_EnableCounter(TIM1);

  // Таймер для яркости панели
  LL_TIM_CC_EnableChannel(TIM2, LL_TIM_CHANNEL_CH3);
  LL_TIM_EnableCounter(TIM2);

  // Таймеры для отсчёта миллисекунд и микросекунд;
  LL_TIM_EnableCounter(TIM3);
  LL_TIM_EnableCounter(TIM4);

  P10_Clear();
  Millis_Wait(1000);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    LL_GPIO_SetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin);
    HAL_Delay(500);
    LL_GPIO_ResetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin);
    HAL_Delay(500);

    for (int j = 0; j <= 10; j++) {
        for (int i = 0; i <= 10; i++) {
            P10_Clear();
            P10_DrawImage(&image, j, i);
            Millis_Wait(100);
        }
    }

    LL_GPIO_SetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin);
    HAL_Delay(500);
    LL_GPIO_ResetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin);
    HAL_Delay(500);

    for (int j = 0; j <= 10; j++) {
        for (int i = 0; i <= 10; i++) {
            P10_Clear();
            P10_DrawImage(&image2, j, i);
            Millis_Wait(100);
        }
    }

    LL_GPIO_SetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin);
    HAL_Delay(500);
    LL_GPIO_ResetOutputPin(LED_LINKSTART_GPIO_Port, LED_LINKSTART_Pin);
    HAL_Delay(500);

    P10_Clear();
    P10_SetCursor(0, 0);
    P10_PrintString_5x7("Hi");
    P10_SetCursor(1, 0);
    P10_PrintString_5x7("123");
    Millis_Wait(3000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
