#ifndef runningLED_H
#define runningLED_H

#include "LED.h"

#define initTaskBlock(x) 	(x)->state = 0 ;
#define yield(x) 			(x)->state = __LINE__ ; break ; case __LINE__ : ;
#define startTask(x)  		switch((x)->state) {case 0:
#define endTask(x)   		break; }

typedef struct
{
	State state ;
}TaskBlock ;

int blinkLED(TaskBlock *tb ,int Time_LED6, int LED_no);
int inverseBlinkLED(TaskBlock *tb ,int Time_LED, int LED_no);
int runningLED(TaskBlock *tb,int Time_LED);
int runningLED2(TaskBlock tb[4],int Time_LED);
#endif // runningLED_H
