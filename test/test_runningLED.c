#include "unity.h"
#include "mock_LED.h"
#include "mock_Times.h"
#include "runningLED.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_blinkLED__blink1time_should_turnOn_turnOff()
{
	int Time_LED6 = 500 ;

	TaskBlock tb ;
	initTaskBlock(&tb);
	
	/*turn on LED6*/
	checkTime_ExpectAndReturn(500,LED6,1);
	turnOnLED_Expect(LED6);
	blinkLED(&tb,Time_LED6,LED6);
	
	/*turn off LED6*/
	checkTime_ExpectAndReturn(500,LED6,1);
	turnOffLED_Expect(LED6);
	blinkLED(&tb,Time_LED6,LED6);
}

void test_inverseBlinkLED__blink1time_should_turnOff_turnOn()
{
	int Time_LED6 = 500 ;

	TaskBlock tb ;
	initTaskBlock(&tb);
	
	/*turn off LED6*/
	checkTime_ExpectAndReturn(500,LED6,1);
	turnOffLED_Expect(LED6);
	inverseBlinkLED(&tb,Time_LED6,LED6);
	
	/*turn on LED6*/
	checkTime_ExpectAndReturn(500,LED6,1);
	turnOnLED_Expect(LED6);
	inverseBlinkLED(&tb,Time_LED6,LED6);
}

void test_blinkLED_blink2times()
{
	int Time_LED6 = 500 ;

	TaskBlock tb ;
	initTaskBlock(&tb);
	
	/*turn on LED6*/
	checkTime_ExpectAndReturn(500,LED6,1);
	turnOnLED_Expect(LED6);
	blinkLED(&tb,Time_LED6,LED6);
	
	/*turn off LED6*/
	checkTime_ExpectAndReturn(500,LED6,1);
	turnOffLED_Expect(LED6);
	blinkLED(&tb,Time_LED6,LED6);

	/*turn on LED6*/
	checkTime_ExpectAndReturn(500,LED6,1);
	turnOnLED_Expect(LED6);
	blinkLED(&tb,Time_LED6,LED6);
	
	/*turn off LED6*/
	checkTime_ExpectAndReturn(500,LED6,1);
	turnOffLED_Expect(LED6);
	blinkLED(&tb,Time_LED6,LED6);
}

void test_runningLED()
{
	int Time_LED = 100 ;
	TaskBlock tb ;
	
	initTaskBlock(&tb);
	
	/*turn on LED3*/
	checkTime_ExpectAndReturn(100,LED3,1);
	turnOnLED_Expect(LED3);
	runningLED(&tb,Time_LED);
	
	/*turn off LED3*/
	checkTime_ExpectAndReturn(100,LED3,1);
	turnOffLED_Expect(LED3);
	runningLED(&tb,Time_LED);
	
	/*turn on LED4*/
	checkTime_ExpectAndReturn(100,LED3,1);
	turnOnLED_Expect(LED4);
	runningLED(&tb,Time_LED);
	
	/*turn off LED4*/
	checkTime_ExpectAndReturn(100,LED3,1);
	turnOffLED_Expect(LED4);
	runningLED(&tb,Time_LED);
	
	/*turn on LED5*/
	checkTime_ExpectAndReturn(100,LED3,1);
	turnOnLED_Expect(LED5);
	runningLED(&tb,Time_LED);
	
	/*turn off LED5*/
	checkTime_ExpectAndReturn(100,LED3,1);
	turnOffLED_Expect(LED5);
	runningLED(&tb,Time_LED);
	
	/*turn on LED6*/
	checkTime_ExpectAndReturn(100,LED3,1);
	turnOnLED_Expect(LED6);
	runningLED(&tb,Time_LED);
	
	/*turn off LED6*/
	checkTime_ExpectAndReturn(100,LED3,1);
	turnOffLED_Expect(LED6);
	runningLED(&tb,Time_LED);

}
