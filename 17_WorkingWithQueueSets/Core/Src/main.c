
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
int uart2_write(int ch);
int __io_putchar(int ch);

static QueueHandle_t xQueue1 = NULL, xQueue2 = NULL;

//Declare a queue set
static QueueSetHandle_t xQueueSet = NULL;


void vSenderTask1(void *pvParameters);
void vSenderTask2(void *pvParameters);
void vReceiverTask(void *pvParameters);
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  xQueue1 = xQueueCreate( 1, sizeof(char *));
  xQueue2 = xQueueCreate( 1, sizeof(char *));
  //Create queue set
  xQueueSet=xQueueCreateSet(1*2);
  //Add two queues to queue set
  xQueueAddToSet (xQueue1,xQueueSet);
  xQueueAddToSet (xQueue2,xQueueSet);
  /*Create the sender tasks*/
  xTaskCreate(vSenderTask1, "sender1",100,NULL,1,NULL);
  xTaskCreate(vSenderTask2, "sender2",100,NULL,1,NULL);

  /*Create the receiver task*/
  xTaskCreate(vReceiverTask, "Receiver",100,NULL,2,NULL);

  vTaskStartScheduler();


  while (1)
  {
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

void vSenderTask1(void *pvParameters)
{
	const TickType_t xBlcokTime = pdMS_TO_TICKS(100);
	const char *const msg ="Message from vSenderTask1\r\n";
	while(1)
	{
		vTaskDelay(xBlcokTime);
		xQueueSend(xQueue1,&msg,0);
	}

}
void vSenderTask2(void *pvParameters)
{
	const TickType_t xBlcokTime = pdMS_TO_TICKS(200);
	const char *const msg ="Message from vSenderTask2\r\n";
	while(1)
	{
		vTaskDelay(xBlcokTime);
		xQueueSend(xQueue2,&msg,0);

	}

}
void vReceiverTask(void *pvParameters)
{
	QueueHandle_t xQueueThatContainsData;
	char *pcReceivedString;
	while(1)
	{
		xQueueThatContainsData=(QueueHandle_t )xQueueSelectFromSet(xQueueSet,portMAX_DELAY);
		xQueueReceive(xQueueThatContainsData,&pcReceivedString,0);
		printf(pcReceivedString);
	}

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
