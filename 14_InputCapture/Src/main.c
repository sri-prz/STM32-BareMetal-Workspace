#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

#define GPIOAEN		(1U<<0)
#define PIN5 		(1U<<5)

#define LED_PIN		PIN5

int timestamp = 0;
int main(void)
{
	tim2_pa5_output_compare();
	tim3_pa6_input_capture();

	while(1)
	{
		//Wait until edge is captured
		while((TIM3->SR & SR_CC1IF)){}
		//Read captured counter value
		timestamp = TIM3->CCR1;

	}

}


//connect jumper wire from pa5 to pa6




