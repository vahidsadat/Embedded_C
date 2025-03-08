
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "cmsis_os.h"
#include "uart.h"
#include "adc.h"
#include "exti.h"
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void USART2_UART_TX_Init(void);
int __io_putchar(int ch);
void polledUARTReceiver(void *pvParameters);

void HandlerTask(void *pvParameters);
uint8_t btn_state;
uint32_t sensor_value;

const int STACK_SIZE=128;
static QueueHandle_t uart2_BytesReceived=NULL;


BaseType_t status1,status2;
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();


 xTaskCreate(polledUARTReceiver, "pollling UART", STACK_SIZE, NULL, tskIDLE_PRIORITY+2, NULL);
  xTaskCreate(HandlerTask, "UART print task", STACK_SIZE, NULL, tskIDLE_PRIORITY+3, NULL);

  uart2_BytesReceived=xQueueCreate(10,sizeof(char));
  vTaskStartScheduler();

  while (1)
  {
	  btn_state = read_digital_sensor();
	  sensor_value = read_analog_sensor();
  }
}

void polledUARTReceiver(void *pvParameters)
	{
	uint8_t nexByte;
	USART2_UART_RX_Init();
	while(1)
		{
		nexByte=USART2_read();
		xQueueSend(uart2_BytesReceived,&nexByte,0);
		}

	}


char rcByte;
void HandlerTask(void *pvParameters)
	{



	while(1)
		{
		xQueueReceive(uart2_BytesReceived, &rcByte, portMAX_DELAY);

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
