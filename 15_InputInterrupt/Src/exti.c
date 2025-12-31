#include "exti.h"

#define GPIOCEN 	(1U<<2)
#define SYSCFGEN	(1U<<14)


void pc13_exti_init(void)
{
	//Disable global interrupts (optional but recommended practice)
	__disable_irq(); //comes with cortexm.h files

	//Enable clock access for GPIOC
	RCC->AHB1ENR |= GPIOCEN;
	//Enable clock access to SYSCFG
	RCC->APB2ENR |= SYSCFGEN;

	//set pc13 as input
	GPIOC->MODER &=~ (1U<<26);
	GPIOC->MODER &=~ (1U<<27);

	//Select port c for EXTI13
	SYSCFG->EXTICR[3] |= (1U<<5); //shifting bit 5 to 1 on syscfg-exticr4 enables exti line 13 for port c
	//Unmask EXTI13
	EXTI->IMR |= (1U<<13);
	//Select falling edge trigger
	EXTI->FTSR |= (1U<<13);
	//Enable EXTI line in NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn); //comes with cortexm header files + you can look thru header file to find symbolic names for each interrupt
	//Enable global interrupts
	__enable_irq();

}
