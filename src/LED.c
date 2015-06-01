#include "LED.h"
#include "Times.h"

void turnOffLED(int LED)
{
	if (LED == LED3)
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
	else if (LED == LED4)
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
	else if (LED == LED5)
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
}

void turnOnLED(int LED)
{
	if (LED == LED3)
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
	else if (LED == LED4)
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
	else if (LED == LED5)
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET); //LED6 active low
}

void SM_LED(State *state,int LED,int *Time)
{
	static int currentTime[4] = {} ;
	static int counter = 0, triggered = 0 ;
	GPIO_PinState UserInput = 0;

	switch(*state)
	{
			case START :
							turnOffLED(LED);
							*state = CHECK_BUTTON ;
							break ;

			case CHECK_BUTTON :
							UserInput = readUserInput();
							if(UserInput == 1)
							{
								triggered = 1 ; //remembered that the user had already pressed the button
								if(LED == LED4 || LED == LED5)
									*state = BUTTON_PRESSED ; // for LED4 and LED5 only
								else
									*state = LED_OFF ;

							}
							else
								*state = BUTTON_NOT_PRESSED ;
							break ;

			case LED_ON :
							turnOnLED(LED);
							if (getCurrentTime() - currentTime[LED] >= *Time)
							{
								currentTime[LED] = getCurrentTime();
								turnOffLED(LED);
								*state = CHECK_BUTTON ;

								if (LED == LED5)
									counter ++ ;
							}

							break ;

			case LED_OFF:
							turnOffLED(LED);
							if (getCurrentTime() - currentTime[LED] >= *Time)
							{
								currentTime[LED] = getCurrentTime();
								turnOnLED(LED);
								*state = LED_ON ;
							}

							break ;

			case BUTTON_PRESSED:
							if (LED == LED4)
								*Time = 50;
							else if (LED == LED5)
							{
								if (counter == 5) // LED5 blinked 5 times
								{
									*state = START ;
									break ;
								}
							}
							*state = LED_OFF ;
							break ;
			case BUTTON_NOT_PRESSED :

							if (LED == LED4) //restore LED4 to original blinking rate
								*Time = 500 ;
							else if (LED == LED5)
								{
									if (triggered) // button was pressed
									{
										if (counter == 5 )
										{
											triggered  = 0 ;
											counter = 0 ;
										}
										else //force LED5 to blink till 5 times
										{
											*state = LED_OFF ;
											break;
										}

									}

									*state = CHECK_BUTTON ;
									break ;
								}

							*state = LED_OFF ;
							break ;
	}
}
