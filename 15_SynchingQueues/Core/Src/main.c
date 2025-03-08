
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "cmsis_os.h"

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void *argument);
int __io_putchar(int ch);
int uart2_write(int ch);
void SenderTask1(void *pvParameter);
void SenderTask2(void *pvParameter);
void ReceiverTask(void *pvParameter);

TaskHandle_t sender_handler, receiver_handler;

QueueHandle_t yearQueue;
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  yearQueue = xQueueCreate(5,sizeof(int32_t));

  //Create a receiver task of a higher priority
  xTaskCreate(ReceiverTask,"Receiver Task",100,NULL,1,&sender_handler);
  //Create two sender tasks of the same priority
  //lower than the receiver task priority
  xTaskCreate(SenderTask1,"Sender Task1",100,NULL,2,&receiver_handler);
  xTaskCreate(SenderTask2,"Sender Task2",100,NULL,2,&receiver_handler);
  vTaskStartScheduler();
  while (1)
  {
  }
}

void SenderTask1(void *pvParameter)
{
	int32_t value_to_send = 2050;
	BaseType_t qStatus;
	while(1)
	{
		qStatus = xQueueSend(yearQueue,&value_to_send,0);
		if(qStatus != pdPASS)
		{
			printf("Error : Data couldn't be sent....\n\r");
		}
		for(int i = 0;i<100000;i++){}
	}
}
void SenderTask2(void *pvParameter)
{
	int32_t value_to_send = 5050;
	BaseType_t qStatus;
	while(1)
	{
		qStatus = xQueueSend(yearQueue,&value_to_send,0);
		if(qStatus != pdPASS)
		{
			printf("Error : Data couldn't be sent....\n\r");
		}
		for(int i = 0;i<100000;i++){}
	}
}
void ReceiverTask(void *pvParameter)
{
	int32_t value_received;
	BaseType_t qStatus;
	const TickType_t wait_time = pdMS_TO_TICKS(100);
	while(1)
	{
		qStatus = xQueueReceive(yearQueue,&value_received,wait_time);
		if(qStatus == pdPASS)
		{
			printf("The value received id : %ld....\n\r",value_received);
		}
		else
		{
			printf("Error : Data couldn't receive....\n\r");
		}
	}
}

int uart2_write(int ch)
{
	while (!(USART2->SR &0x0080)){}
	USART2->DR = (ch & 0xFF);

	return ch;
}

int __io_putchar(int ch)
	{
	uart2_write(ch);
	return ch;
	}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }

}

static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
}

void Error_Handler(void)
{

}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{ 

}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
