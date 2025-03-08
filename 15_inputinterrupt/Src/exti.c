#include "exti.h"


#define GPIOCEN		(1U<<2)
#define SYSCNFG_EN	(1U<<14)
#define EXTI_MR		(1U<<13)


void pc13_exti_init(void)
{
	/*Disable global interrupt*/
	__disable_irq();
	/*Enable clock access for GPIOC*/
	RCC->AHB1ENR |= GPIOCEN;
	/*Set PC13 as input*/
	GPIOC->MODER &=~ (1U<<26);
	GPIOC->MODER &=~ (1U<<27);
	/*Enable clock access to SYSCFG*/
	RCC->APB2ENR |= SYSCNFG_EN;
	/*Select PORTC for EXTI13*/
	SYSCFG->EXTICR[3] |= (1U<<5);
	/*Unmask EXTI13*/
	EXTI->IMR |= EXTI_MR;
	/*Select falling edge trigger*/
	EXTI->FTSR |= (1U<<13);
	/*Enable EXTI13 line in NVCI*/
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	/*Enable global Interrupt*/
	__enable_irq();
}
