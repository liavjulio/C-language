/* Assignment: 3
Author: Liav Huli, ID: 314917808
*/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {

	char x;
	printf("Enter your char :");
	scanf_s("%c",&x);

	if (x>='a' && x<='z')//בדיקה האם הוכנסה אות קטנה
	{
		printf("%c", (x - 'a' + 'A'));
	}

			else if (x<='Z' && x>='A')//בדיקה האם הוכנסה אות גדולה
		{
		printf("%c", x + 'a' - 'A');
		}

	else
	{
			printf("%c", x);//הדפסת תו
	}
	return 0;
}