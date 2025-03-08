#define Periph_base 		(0x40000000UL)


#define AHB1_PERIPH_OFFSET	(0x00020000UL)
#define AHB1_PERIPH_BASE	(Periph_base+AHB1_PERIPH_OFFSET)


#define GPIOA_OFFSET		(0x0UL)
#define GPIOA_BASE			(AHB1_PERIPH_BASE+GPIOA_OFFSET)


#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1_PERIPH_BASE+RCC_OFFSET)
#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int *)(RCC_BASE+AHB1EN_R_OFFSET))


#define GPIOAEN				(1U<<0)  //0b 0000 0000 0000 0000 0000 0000 0000 0001


#define OD_R_OFFSET			(0x14UL)
#define GPIO_OD_R			(*(volatile unsigned int *)(GPIOA_BASE+OD_R_OFFSET))


#define MODE_R_OFFSET		(0x00UL)
#define GPIO_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE+MODE_R_OFFSET))

#define PIN5				(1U<<5)
#define LED_PIN				PIN5


/*
 *  (1U<<10) // set bit 10 to 1
 *  &=~(1U<<11) // Set bit 11 to 0 */


int main (void)
{
	/*1.Enable clock access to GPIOA*/
	RCC_AHB1EN_R |= GPIOAEN;

	/*2.Set PA5 as output pin*/
	GPIO_MODE_R |= (1U<<10);
	GPIO_MODE_R &=~(1U<<11);

	while (1)
	{
		/*3.Set PA5 high*/
		GPIO_OD_R |= LED_PIN;

		/*4.toggle the LED*/
		//GPIO_OD_R ^= LED_PIN;
		//for(int i=0;i<100000;i++){}

	}
}
