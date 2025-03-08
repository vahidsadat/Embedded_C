#include "stm32f4xx.h"

#define TIM2EN			(1U<<0)
#define TIM3EN			(1U<<1)
#define CR1_CEN			(1U<<0)
#define CCMR1_OCM1	    ((1U<<4)|(1U<<5))
#define CCER_EN			(1U<<0)
#define RCC_EN			(1U<<0)


void tim2_1hz_init(void)
{
	/*Enable clock access to Timer 2*/
	RCC->APB1ENR |= TIM2EN;
	/*Set prescaler value*/
	TIM2->PSC = 1600 - 1; // 16 000 000 / 1 600 = 10 000
	/*Set auto-reload register*/
	TIM2->ARR = 10000-1; // 100 000 / 10 000 = 1
	/*Clear counter*/
	TIM2->CNT = 0;
	/*Enable Timer*/
	TIM2->CR1 =  CR1_CEN;

}


void tim2_PA5_output_compare(void)
{
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_EN;
	/*Set PA5 mode to alternate function*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);
	/*Enable PA5 alternate function type to TIM2_CH1*/
	GPIOA->AFR[0] = (1U<<20);

	/*Enable clock access to Timer 2*/
	RCC->APB1ENR |= TIM2EN;
	/*Set prescaler value*/
	TIM2->PSC = 1600 - 1; // 16 000 000 / 1 600 = 10 000
	/*Set auto-reload register*/
	TIM2->ARR = 10000-1; // 100 000 / 10 000 = 1

	/*Set output compare toggle mode*/
	TIM2->CCMR1 = CCMR1_OCM1;
	/*Enable tim2 ch1 in compare mode*/
	TIM2->CCER |= CCER_EN;




	/*Clear counter*/
	TIM2->CNT = 0;
	/*Enable Timer*/
	TIM2->CR1 =  CR1_CEN;

}



