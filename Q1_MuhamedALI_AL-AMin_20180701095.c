#include "STM32F4xx.h"
void SystemInit()
{
	(*((int*)0xE000ED88))|=0x0F00000;  			// Floating Point activation. 0-red,1-blue,2-orange,3-green.

	RCC->AHB1ENR |= (1<<3);          // Pin D clock signal activated for LED activation and shift 1 to pin 3
	RCC->AHB1ENR |= 0x1;
  RCC->AHB1ENR = 0x00000008;        	// Pin D clock signal activated for LED activation ,,1: IO port D clock enabled


  GPIOD->MODER = 0x01; 		         // SET port D as output for LED
	GPIOD->MODER &= ~(1<<27);
  GPIOD->MODER |= (1<<26);              	// shift 1 to pin 13 for port D
                                   	// shift 1 to pin 13 for port D
  GPIOD->MODER &= ~(1<<25);           // shift 1 to pin 12 are set as output for Port D
	GPIOD->MODER |= (1<<24);             // shift 1 to pin 12 are set as output for Port D



	GPIOD->OSPEEDR |= 0xFFFFFFFF;   // GPIOD all I/O pins are set to maximum speed.
	GPIOD->PUPDR |= 0x00000000;				// Push pull and drain registers set as no pull up or pull down.

}
void delayy(){ 							//User Created Function for blink Delay
	int delay0 = 0x000FFFFF;
	while (delay0--){   					//Until count down reaches zero will wait here
		}
}

int main()
{
	while(1){						//Our code will continue as long as there is power.

		GPIOD->ODR |= (1<<13);
    GPIOD->ODR |= (1<<12);                    		//Leds on for Name=MuhamedALi ascii value= 983 modulo 4 is 3 for greenLED and surname=AlAmin ascii=562 modulo 4 is 2 for orangeLED
		delayy(1000);
		GPIOD->ODR &= ~(1<<13);
    GPIOD->ODR &= ~(1<<12);                        		// Leds off
		delayy(1000);
	}

}
