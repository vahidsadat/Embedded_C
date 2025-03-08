#include "stm32f4xx.h"

#define SYSTICK_LOAD_VAL	16000
#define CTRL_EN				(1U<<0)
#define	CTRL_CLKSRC			(1U<<2)
#define CTRL_COUNTFLAG		(1U<<16)
#define CTRL_TICKINT		(1U<<1)
#define ONE_SEC_LOAD		(16000000)
void systickDelayMs(int delay)
{
	/*configure systick*/
	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD = SYSTICK_LOAD_VAL;

	/*Clear syslick current value register*/
	SysTick->VAL =0;
	/*Enable syslick and select internal clk src*/
	SysTick->CTRL = CTRL_EN|CTRL_CLKSRC;

	for(int i=0;i<delay;i++){
		/*Wait until the COUNTFLAG is set*/

		while((SysTick->CTRL & CTRL_COUNTFLAG) == 0){}
	}
	SysTick->CTRL = 0;
}


void systick_1hz_interrupt(void)
{
	/*Reload with nimber of clock per second*/
	SysTick->LOAD = ONE_SEC_LOAD - 1;
	/*Clear syslick current value register*/
	SysTick->VAL =0;
	/*Enable syslick and select internal clk src*/
	SysTick->CTRL = CTRL_EN|CTRL_CLKSRC;
	/*Enable systick interrupt*/
	SysTick->CTRL |= CTRL_TICKINT;

}
