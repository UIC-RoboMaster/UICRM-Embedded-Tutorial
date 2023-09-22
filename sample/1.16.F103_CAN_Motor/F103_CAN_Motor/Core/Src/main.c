/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "can.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
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
// this function is for can callback
uint16_t ecd;
uint16_t last_ecd;
uint16_t speed_rpm;
uint16_t given_current;
uint16_t temperate;
void RxFIFO0MessagePendingCallback(CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8];

    HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data);

    switch (rx_header.StdId)
    {
        case 0x201:
        {
            last_ecd = ecd;
            ecd = (uint16_t)rx_data[0]<<8|rx_data[1];
            speed_rpm = (uint16_t)rx_data[2]<<8|rx_data[3];
            given_current = (uint16_t)rx_data[4]<<8|rx_data[5];
            temperate = (uint16_t)rx_data[6];

            break;
        }
        default:
        {
            break;
        }
    }
}
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
  MX_CAN_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  CAN_FilterTypeDef filter;
  filter.FilterIdHigh = 0x0000;
  filter.FilterIdLow = 0x0000;
  filter.FilterMaskIdHigh = 0x0000;
  filter.FilterMaskIdLow = 0x0000;
  filter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
  filter.FilterMode = CAN_FILTERMODE_IDMASK;
  filter.FilterScale = CAN_FILTERSCALE_32BIT;
  filter.FilterActivation = ENABLE;
  filter.SlaveStartFilterBank = 14;  // CAN1 and CAN2 split all 28 filters
  filter.FilterBank = 0;  // Master CAN get filter 0-13
  HAL_CAN_ConfigFilter(&hcan,&filter);
  // Configure the filter.
  HAL_CAN_RegisterCallback(&hcan, HAL_CAN_RX_FIFO0_MSG_PENDING_CB_ID,RxFIFO0MessagePendingCallback);
    HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
  // Register the callback.
  HAL_CAN_Start(&hcan);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_Delay(1000);
  char print_buffer[100];
  while (1)
  {
      uint32_t can_id = 0x200;
      CAN_TxHeaderTypeDef header = {
              .StdId = can_id,
              .ExtId = 0x0,  // don't care since we use standard id mode
              .IDE = CAN_ID_STD,
              .RTR = CAN_RTR_DATA,
              .DLC = 8, // the length of data
              .TransmitGlobalTime = DISABLE,
      };
      uint8_t can_data[8] = {0x10, 0x02, 0x00,0x00,0x00,0x00,0x00,0x00};
      // check the status of the key
      if (HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin) == GPIO_PIN_RESET) {
          can_data[0]=0x08;
          can_data[1]=0x02;
      }
      else{
          can_data[0]=0x00;
          can_data[1]=0x00;
      }
      // the can data refer to the manual of the motor
      uint32_t mailbox;
      // the mailbox that is used to send the message, it is not important, just a number
      // it can be used to check if the message is sent successfully
      HAL_CAN_AddTxMessage(&hcan, &header, (uint8_t*)can_data, &mailbox);
      // send the message
      // while(HAL_CAN_IsTxMessagePending(&hcan, mailbox));
      // check if the message is sent successfully
      sniprintf(print_buffer,99,"ECD: %d RPM: %d CUR: %d TEMP:%d \r\n",ecd,speed_rpm,given_current,temperate);
      HAL_UART_Transmit(&huart1,print_buffer,strlen(print_buffer),50);
      HAL_Delay(20);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
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
