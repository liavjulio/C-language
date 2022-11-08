/* Assignment: 4
Author: Liav Huli, ID: 314917808
*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define Fail 56 
int main() {
	int projectGrade, testGrade, workGrade1, workGrade2, workGrade3, workGrade4, workGrade5,workSum,a;	
	printf("Enter yout testgrade :\n");
	scanf_s("%d", &testGrade);
	if (testGrade < Fail)
	{
		printf("Your final grade is %d\n", testGrade);
		printf("FAIL");
	}
	else
	{
		printf("Enter your project and 5 work grades :");
		scanf_s("%d%d%d%d%d%d", &projectGrade, &workGrade1, &workGrade2, &workGrade3, &workGrade4, &workGrade5);
		workSum = (workGrade1 + workGrade2 + workGrade3 + workGrade4 + workGrade5) / 5;
		a = (int)((projectGrade * 0.1) + (testGrade * 0.7) + (workSum * 0.2));
		printf("your final grade is %d\n", a);
		
		if (a<Fail)
		{
			printf("FAIL");
		}
		else
		{
			printf("PASS");
		}
	}
	















	return 0;
}