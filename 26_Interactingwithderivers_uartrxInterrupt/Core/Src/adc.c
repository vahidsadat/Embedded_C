#include "stm32f4xx_hal.h"

#define APB2_CLK_EN		(1U<<8)
#define AHB1_CLK_EN 	(1U<<0)


void adc_init(void){
	(RCC->AHB1ENR) |= AHB1_CLK_EN;
	(RCC->APB2ENR) |= APB2_CLK_EN;
	(GPIOA->MODER) |= (1U<<2);
	(GPIOA->MODER) |= (1U<<3);

	(ADC1->CR2)    = 0;				// SW trigger
	(ADC1->SQR3)   |= (1U<<0); 		// Conversion sequence starts at ch1
	(ADC1->SQR1)   &= ~(1U<<0);		// conversion sequence length 1
	(ADC1->CR2)    |= (1<<0);		// enable ADC1

}

uint32_t read_analog_sensor(void)
{
	ADC1->CR2 |= (1U<<30);	//Start conversion

	while(!(ADC1->SR & 2)){} // wait for conversion to complete

	return ADC1->DR;  //return result

}
