
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
uint32_t start_rx_interrupt(uint8_t * Buffer, uint_fast16_t len);
void HandlerTask(void *pvParameters);
volatile int rxInProgress=0;
static uint16_t rxLen=0;
static uint8_t *rxBuff=NULL;
static uint16_t rxItr=0;
#define EXPECTED_LENGTH		5


uint8_t btn_state;
uint32_t sensor_value;

const int STACK_SIZE=128;
static QueueHandle_t uart2_BytesReceived=NULL;
static SemaphoreHandle_t rxDone=NULL;


BaseType_t status1,status2;
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  rxDone=xSemaphoreCreateBinary();


  xTaskCreate(HandlerTask, "UART print task", STACK_SIZE, NULL, tskIDLE_PRIORITY+3, NULL);

  uart2_BytesReceived=xQueueCreate(10,sizeof(char));
  vTaskStartScheduler();

  while (1)
  {
  }
}



uint32_t start_rx_interrupt(uint8_t * Buffer, uint_fast16_t len)
	{

	if(!rxInProgress&& (NULL!=Buffer)){
	rxInProgress=1;
	rxLen=len;
	rxBuff=Buffer;
	rxItr=0;
	USART2->CR1|=USART_CR1_RXNEIE;
	NVIC_SetPriority(USART2_IRQn,6);
	NVIC_EnableIRQ(USART2_IRQn);
	return 0;
	}
return -1;
	}

uint8_t rxData[EXPECTED_LENGTH];
char rxCode[50]={0};
void HandlerTask(void *pvParameters)
	{


	for (int i=0;i<sizeof(rxData);i++)
		{
		rxData[i]=0;
		}

	const TickType_t timeout = pdMS_TO_TICKS(8000);

	USART2_UART_RX_Init();


	while(1)
		{
		start_rx_interrupt(rxData,EXPECTED_LENGTH);
		if(xSemaphoreTake(rxDone,timeout)==pdPASS)
			{
				if(EXPECTED_LENGTH==rxItr)
					{
					sprintf(rxCode,"received");
					}
				else
					{
					sprintf(rxCode,"Length mismatch");
					}
			}
		else {
	sprintf(rxCode,"Timeout" );
		}


		}
	}
void USART2_IRQHandler(void)
	{
	portBASE_TYPE xHigherPriorityTaskWoken=pdFALSE;
		if(USART2->SR & USART_SR_RXNE)
			{
			uint8_t tempVal=(uint8_t)USART2->DR;
			if(rxInProgress)
				{
					rxBuff[rxItr++]=tempVal;
					if(rxLen==rxItr)
						{
						rxInProgress=0;
						xSemaphoreGiveFromISR(rxDone,&xHigherPriorityTaskWoken);
						}
				}
			}
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
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
