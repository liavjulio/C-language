#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 20
int main()
{
	int size;
	int** arr = NULL;
	printf("How much names you want to enter\n");
	scanf_s("%d", &size);
	char arr1[20];
	arr = (int**)malloc((size) * sizeof(int*));
	if (arr == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		scanf_s("%s", &arr1);
		*(arr+i) = (char*)malloc((strlen(arr1) * sizeof(char)));
		if (( * (arr + i)) == NULL)
		{
			printf("malloc failed\n");
			return 0;
		}
		for (int j = 0; j < strlen(arr1); j++)
		{
			**(arr+j) = arr1[j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		puts(**arr);
	}
	return 0;
}