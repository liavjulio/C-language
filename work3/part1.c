/* Assignment: 3 , Part : 1
Author: Liav huli , ID: 314917808
*/
#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#define N 10 
#define size1 8 
#define size2 5 
void digits(int arr[], int size, int statistics[N]);
void histogram(char[]);
int same(char [], char []);

int main()
{
	int statistics1[N] = {0} , statistics2[N] = {0};
	int arr1[size1], arr2[size2];
	
	printf("Enter your number arr1 numbers:\n");
	
	for (int i = 0; i < size1 ; i++)
	{
		scanf_s("%d", &arr1[i]);
	}
	digits(arr1, size1, statistics1);
	
	printf("Enter your arr2 numbers:\n");
	
	for (int i = 0; i < size2; i++)
	{
		scanf_s("%d", &arr2[i]);
	}
	
	digits(arr2, size2, statistics2);

	char str1[80];
	printf("Enter your string : \n");
	
	getchar();
	gets(str1);
	histogram(str1);

	char str2[80], str3[80];
	
	printf("Please enter first string\n");
	
	gets(str2);
	
	printf("please enter second string\n");
	gets(str3);
	
	if (same(str2,str3)==1)
	{
		printf("EQUALS");
	}
	else
	{
		printf("DIFFERENT");
	}

	return 0;
}

void digits(int arr[], int size, int statistics[N])
{	
	int i,num=0;
	for ( i = 0; i < size; i++)
	{
		int num = arr[i];
		if (num==0)
			{
				statistics[0]++;
			}
		while (num!=0)
		{
			if (num/10!=0)
			{
				statistics[num%10]++;
				num /= 10;
			}
			else
			{	
				statistics[num]++;
				num /= 10;
			}
		}
	}
	for ( i = 0; i < N; i++)
	{
		printf("%d	",statistics[i]);
	}
	printf("\n");
}
void histogram(char str2[])
{	
	int counter[27] = {0};
	char str1[27] = { "abcdefghijklmnopqrstuvwxyz" };
	for (int i = 0; str2[i]!='\0'; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			if ((str2[i] == str1[j])||(str2[i]==str1[j]-(' ')))
			{
				counter[j]++;
			}	
		}
	}
	for (int r = 0; r < 27; r++)
	{
		if (counter[r] != 0)
		{
			printf("%c ", str1[r]);
			for ( int w = 0;  w < counter[r]; w++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
}
int same(char str1[], char str2[])
{	
	int x = 0, y = 0;
	
	for (int i = 0; i < strlen(str1); i++)
	{
		for (int j = 0; j < strlen(str2); j++)
		{
			if (str1[i] == str2[j] || str1[i] == str2[j] + (' ')|| str1[i] == str2[j] - (' '))
			{
				x++;
				break;
			}
		}
	}
	for (int j = 0; j < strlen(str2); j++)
	{
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str2[j] == str1[i] || str2[j] == str1[i] + (' ') || str2[j] == str1[i] - (' '))
			{
				y++;
				break;
			}
		}
	}
	if ( (x==strlen(str1)) && (y==strlen(str2)) )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}