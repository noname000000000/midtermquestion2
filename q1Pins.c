#include "stm32f4xx.h"
void SystemInit()
{
	(*((int*)0xE000ED88))|=0x0F00000;  			// Floating Point activation. 0-red,1-blue,2-orange,3-green.
	
	RCC->AHB1ENR |= 0x00000008;        			// Pin D clock signal activated for LED activation
	GPIOD->MODER = 0x05000000;         			// Pin 113, 12 are set as output for Port D 
	GPIOD->OSPEEDR= 0xFFFFFFFF;        			// GPIOD all I/O pins are set to maximum speed. 
	
} 
void delayy(){ 							//User Created Function for blink Delay
	int delay0 = 0x000FFFFF;
	while (delay0--){   					//Until count down reaches zero will wait here
		}
}

int main()
{
	while(1){						//Our code will continue as long as there is power.
		
		GPIOD->ODR= 0x00003000;     			//Leds on for Name=MuhamedALi ascii value= 983 modulo 4 is 3 for greenLED and surname=AlAmin ascii=562 modulo 4 is 2 for orangeLED 
		delayy();
		GPIOD->ODR= 0x00000000;    			// Leds off
		delayy();
	}
} 