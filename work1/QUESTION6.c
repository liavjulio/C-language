#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
	int firstSeconds, firstMinutes, firstHours, secondSeconds, secondMinutes, secondHours, thirdSeconds, thirdMinutes, thirdHours, finalHours, finalMinutes, finalSeconds;
	printf("Please enter time for first task (hours,minutes,seconds):\n");
	scanf_s("%d%d%d", &firstHours, &firstMinutes, &firstSeconds);
	printf("Please enter time for second task (hours,minutes,seconds):\n");
	scanf_s("%d%d%d", &secondHours, &secondMinutes, &secondSeconds);
	printf("Please enter time for third task (hours,minutes,seconds):\n");
	scanf_s("%d%d%d", &thirdHours, &thirdMinutes, &thirdSeconds);
	finalSeconds = firstSeconds + secondSeconds + thirdSeconds;
	finalMinutes = firstMinutes + secondMinutes + thirdMinutes;
	finalHours = firstHours + secondHours + thirdHours;
	 if (finalSeconds > 59)
	{
		finalMinutes = finalMinutes + finalSeconds / 60;
		finalSeconds = finalSeconds % 60;
		if (finalSeconds > 59)
		{
			finalMinutes = finalMinutes + finalSeconds / 60;
			finalSeconds = finalSeconds % 60;
			if (finalSeconds > 59)
			{
				finalMinutes = finalMinutes + finalSeconds / 60;
				finalSeconds = finalSeconds % 60;
				if (finalSeconds > 59)
				{
					finalMinutes = finalMinutes + finalSeconds / 60;
					finalSeconds = finalSeconds % 60;
				}
			}
		}
	} 
	 if (finalMinutes > 59)
	  {
			finalHours = finalHours + finalMinutes / 60;
			finalMinutes = finalMinutes % 60;
			if (finalMinutes > 59)
			{
				finalHours = finalHours + finalMinutes / 60;
				finalMinutes = finalMinutes % 60;
				if (finalMinutes > 59)
				{
					finalHours = finalHours + finalMinutes / 60;
					finalMinutes = finalMinutes % 60;
					if (finalMinutes > 59)
					{
						finalHours = finalHours + finalMinutes / 60;
						finalMinutes = finalMinutes % 60;
					}
				}
			}

	  }
	 if (finalMinutes<=59 && finalSeconds<=59)
	 {
		 printf("Total time : %d %d %d", finalHours, finalMinutes, finalSeconds);
	 }
	










	return 0;
}