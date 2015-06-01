#include "runningLED.h"
#include "Times.h"


int blinkLED(TaskBlock *tb ,int Time_LED, int LED_no)
{
	if ((!checkTime(Time_LED,LED_no)))
		return 0;

	startTask(tb);
	turnOnLED(LED_no);
	yield(tb);
	turnOffLED(LED_no);
	tb->state = 0 ; //restart
	endTask(tb);

	return 1;
}

int inverseBlinkLED(TaskBlock *tb ,int Time_LED, int LED_no)
{
	if (!(checkTime(Time_LED,LED_no)))
	return 0;

	startTask(tb);
	turnOffLED(LED_no);
	yield(tb);
	turnOnLED(LED_no);
	tb->state = 0 ; //restart
	endTask(tb);

	return 1 ;
}

int runningLED(TaskBlock *tb,int Time_LED)
{
	if ((!checkTime(Time_LED,LED3)))
		return 0 ;
	
	startTask(tb);
	
	turnOnLED(LED3);
	yield(tb);
	turnOffLED(LED3);
	yield(tb);
	
	turnOnLED(LED4);
	yield(tb);
	turnOffLED(LED4);
	yield(tb);
	
	turnOnLED(LED5);
	yield(tb);
	turnOffLED(LED5);
	yield(tb);
	
	turnOnLED(LED6);
	yield(tb);
	turnOffLED(LED6);
	
	tb->state = 0 ; //restart
	endTask(tb);

	return 1 ;
}

int runningLED2(TaskBlock tb[4],int Time_LED)
{
	static int counter = 0 , LED_no = LED3 ;
	
	if(blinkLED(&tb[LED_no],Time_LED,LED_no))
		counter ++ ;
	
	if (counter != 0 && counter % 2 == 0 )
		LED_no ++ ;
		
	if (counter == 8 && LED_no == LED6)
	{
		LED_no = LED3 ;
		counter = 0 ;
	}

}



