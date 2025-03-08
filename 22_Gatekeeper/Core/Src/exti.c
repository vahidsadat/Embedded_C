#include "stm32f4xx_hal.h"

void p13_interrupt_init(void)
{
	RCC->AHB1ENR |= (1U<<2);


	RCC->APB2ENR |= (1U<<14);  //System configuration controller

	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);

	//Clear port selection for EXTI13
	SYSCFG->EXTICR[3] &= ~(1U<<4);
	SYSCFG->EXTICR[3] &= ~(1U<<5);
	SYSCFG->EXTICR[3] &= ~(1U<<6);
	SYSCFG->EXTICR[3] &= ~(1U<<7);

	// select port c for EXTI13
	SYSCFG->EXTICR[3] &= ~(1U<<4);
	SYSCFG->EXTICR[3] |= (1U<<5);
	SYSCFG->EXTICR[3] &= ~(1U<<6);
	SYSCFG->EXTICR[3] &= ~(1U<<7);

	// unmask EXTI13
	EXTI->IMR		  |= (1U<<13);

	//select falling edge trigger
	EXTI->FTSR		|= (1U<<13);


	NVIC_SetPriority(EXTI15_10_IRQn, 6);

	NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void gpio_init(void)
{
	RCC->AHB1ENR |= (1U<<2);

	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);
}

uint8_t read_digital_sensor(void)
{
	if( GPIOC->IDR & 0x2000)
	{
		return 1;
	}
	else
	{
		return 0;

	}
}
