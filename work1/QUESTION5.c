/* Assignment: 5
Author: Liav Huli, ID: 314917808
*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
	int num1, num2, num3, num4, sum1, sum2, sum3, sum4;
	printf("Please enter 4 numbers :");
	scanf_s("%d%d%d%d", &num1, &num2, &num3, &num4);
	if (num1 >= 0 && num1 <= 9999 && num2 >= 0 && num2 <= 9999 && num3 >= 0 && num3 <= 9999 && num4 >= 0 && num4 <= 9999)//בדיקה שאין קלט שלילי
	{
		sum1 = (num1 % 10 * 1000) + (num2 % 10 * 100) + (num3 % 10 * 10) + (num4 % 10);
		sum2 = (num1 % 100 /10 * 1000) + (num2 % 100 / 10 * 100) + (num3 % 100 /10 *10) + (num4 % 100 /10);
		sum3 = (num1 % 1000 / 100 * 1000) + (num2 % 1000 / 100 * 100) + (num3 % 1000 / 100 * 10) + (num4 % 1000 / 100);
		sum4 = (num1 % 10000 / 1000 * 1000) + (num2 % 10000 / 1000 * 100) + (num3 % 10000 / 1000 * 10) + (num4 % 10000 / 1000);
		printf("%d\t%d\t%d\t%d", sum1, sum2,sum3,sum4);

	}
	else
	{
		printf("ERROR");
	}

	return 0;
}