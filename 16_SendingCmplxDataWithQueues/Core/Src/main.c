
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

typedef enum
{
	humidity_sensor,
	pressure_sensore
}DataSource_t;

//Define structure type to be passed to the queue
typedef struct
{
	uint8_t ucValue;
	DataSource_t sDataSource;
}Data_t;

static const Data_t xStructsToSend[ 2 ] =
{
		{77, humidity_sensor}, // Used by humidity sensor
		{63, pressure_sensore} // Used by pressure sensor
};
TaskHandle_t hum_task_handle,press_task_handle, receiver_handle;
QueueHandle_t xQueue;
void ReceiverTask(void *pvParameters);
void SenderTask(void *pvParameters);
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();


  xQueue = xQueueCreate(3,sizeof(Data_t));
  //Create a receiver task with a priority of 1
  xTaskCreate(ReceiverTask,"Receiver Task",100,NULL,1,&receiver_handle);
  //Create task to send humidity data with a priority of 2
  xTaskCreate(SenderTask,"Humidity Sender Task",100,(void *)&(xStructsToSend[0]),2,&hum_task_handle);
  //Create task to send pressure data with a priority of 2
  xTaskCreate(SenderTask,"Pressure Sender Task",100,(void *)&(xStructsToSend[1]),2,&press_task_handle);

  vTaskStartScheduler();
  while (1)
  {
  }
}

void SenderTask(void *pvParameters)
{
	BaseType_t qStatus;

	//Enter the blocked state for 200ms for space to become available in the queue each
	//time the queue is full

	const TickType_t wait_time = pdMS_TO_TICKS(200);

	while(1)
	{
		qStatus = xQueueSend(xQueue,pvParameters,wait_time);
		if(qStatus != pdPASS)
		{
			//Do Sth
		}
		for(int i = 0;i<100000;i++){}
	}
}
void ReceiverTask(void *pvParameters)
{
	Data_t xReceivedStructure;

	BaseType_t qStatus;

	while(1)
	{
		qStatus = xQueueReceive(xQueue,&xReceivedStructure,0);
		if(qStatus == pdPASS)
		{
			if(xReceivedStructure.sDataSource == humidity_sensor)
			{
				printf("Humidity sensor value = %d \n\r",xReceivedStructure.ucValue);
			}
			else
			{
				printf("Pressure sensor value = %d \n\r",xReceivedStructure.ucValue);
			}
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
