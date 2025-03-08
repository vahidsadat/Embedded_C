#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#define GPIOAEN		(1U<<0)
#define PIN5		(1U<<5)
#define LED_PIN		(PIN5)

int main(void)
{
	tim2_1hz_init();
	uart2_tx_init();
	RCC->AHB1ENR	|=GPIOAEN;

	GPIOA->MODER |=(1U<<10);
	GPIOA->MODER &=~(1U<<11);



	while(1)
	{
		/*whait for uif*/
		while(!(TIM2->SR & SR_UIF)){}

		/*clear UIF*/
		TIM2->SR &=~SR_UIF;
		printf("A second just passed !! \n\r");
		GPIOA->ODR ^=LED_PIN;
	}
}






