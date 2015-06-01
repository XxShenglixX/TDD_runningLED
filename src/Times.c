#include "Times.h"

uint32 currentTime = 0 ;

void updateCurrentTime()
{
	static uint32_t counter = 0 ;

	if (counter++ >= 100)
	{
		counter = 0 ;
		currentTime ++ ;
	}
}

int checkTime(int Time_LED)
{
	static int previousTime = 0 ;

	if(currentTime - previousTime >= Time_LED)
		return 1;
	else
	{
		previousTime = currentTime ;
		return 0 ;
	}

}
