/* Assingment: 1
author : Liav huli , ID : 314917808 
*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
	int num1, num2, num3, num4, num5,d;
	
	printf("Please enter your 5 numbers:");
	
	scanf_s("%d%d%d%d%d", &num1, &num2, &num3, &num4, &num5);
	
	printf("Please enter your d number:");
	
	scanf_s("%d", &d);
	
	if (d!=0)
	{
		if (num1 % d != 0 && num2 % d != 0 && num3 % d != 0 && num4 % d != 0 && num5 % d != 0)
		{
			printf("No number divided by %d", d);
		}
		else
		{
			printf("Numbers divided by %d is :", d);
			if (num1 % d == 0)
			{
				printf("%d  ", num1);
			}
			if (num2 % d == 0)
			{
				printf("%d  ", num2);
			}
			if (num3 % d == 0)
			{
				printf("%d  ", num3);
			}
			if (num4 % d == 0)
			{
				printf("%d  ", num4);
			}
			if (num5 % d == 0)
			{
				printf("%d  ", num5);
			}
		}
		
		
	}
	else {
		printf("Error");
	}
	









	return 0;
} 