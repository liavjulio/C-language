#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define size 27
#define size1 80
void freq(char str1[size1], char str2[size], int arr[size]);
int* find(char* line, char* word, int* psize);
int main() {

	char str[size1];
	printf("enter str\n");
	gets(str);
	char str1[size] = {"abcdefghijklmnopqrstuvwxyz"};
	int arr1[size] = {0};
	freq(str, str1, arr1);
	int counter=0;
	char str2[size1];
	char str3[size1];
	printf("enter first string\n");
	gets(str2);
	printf("enter second string\n");
	gets(str3);
	int *arr = find(&str2,&str3,&counter);
	printf("%d\n", counter);
	printf("{");
		for (int i = 0; i < counter; i++)
		{	
			printf("%d,", arr[i]);
		}
	printf("}");
	return 0;
}
void freq(char str1[size1], char str2[size], int arr[size])
{
	int i, z;
	for ( i = 0; i < strlen(str1); i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (str1[i]==str2[j]||str1[i]==(str2[j]-' '))
			{
				arr[j]++;
				break;
			}
		}
	}
	char max1 = (' ');
	int max = 0;
	for ( z = 0; z < size; z++)
	{
		if (arr[z] >= max)
		{
			max = arr[z];
			max1 = str2[z];
		}
	}
	printf("%d %c \n", max, max1);
}
int* find(char* str1, char* str2, int* counter)
{
	int arr[size] = {NULL};
	int z = 0;
	for (int i = 0; i < strlen(str1); i++)
	{
		for (int j = 0; j < strlen(str2); j++)
		{
			if (str1[i] == str2[j])
			{
				(*counter)++;
			}
			if (str1[i] == str2[j] && str2[j+1]!=str1[i+1])
			{
				(*counter) = (*counter) - strlen(str1);
			}
			if (str2[j] == ' ')
			{
				i = 0;
			}
			if (str1[0] == str2[j])
			{
				*(arr+z) = j;
				z++;
			}
			i++;
		}
		break;
	}
	*counter = *counter/strlen(str1);
	if (*counter==0)
	{	
		return NULL;
	}
	else
	{
		return &arr;
	}
}