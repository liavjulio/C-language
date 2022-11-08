#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define size1 30
void Norepeat(char str[]);
int Even(int num);
int Same(int num);
int samefirstdigit(int arr[], int size);
int sumOddNumbers(int arr[], int size);
int between(int arr[], int size, int min, int max);
int copy(char[]);
int high(int num);
int main()
{
	//1:
	printf("Enter your string\n");
	char str[size1];
	gets(str);
	Norepeat(str);
	printf("\n");
	//2:
	int x,t;
	printf("Enter your number\n");
	scanf_s("%d", &x);
	t = Even(x);
	if (t==1)
	{
		printf("all digit even,%d\n", t);
	}
	else
	{
		printf("not all digit even,%d\n", t);
	}
	//3:
	int x1;
	printf("enter your number\n");
	scanf_s("%d", &x1);
	int z;
	z = Same(x1);
	if (z==1)
	{
	printf("all digit equals %d\n", z);
	}
	else
	{
		printf("digits isnt equals :%d\n", z);
	}
	//4:
	int size,y;
	printf("Enter your size of array\n");
	scanf_s("%d", &size);
	int *arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL)
	{
		return 0;
	}
	printf("enter your numbers\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf("returned : %d\n", samefirstdigit(arr, size));
	//5:
	int size2 ,x2;
	printf("Enter your size of array\n");
	scanf_s("%d", &size2);
	int* arr1 = (int*)malloc(size2 * sizeof(int));
	printf("enter numbers\n");
	for (int i = 0; i < size2; i++)
	{
		scanf_s("%d", &arr1[i]);
	}
	printf("the sum of odd numbers is : %d\n", sumOddNumbers(arr1, size2));
	//6:
	int max, min, size6;
	printf("enter max\n");
	scanf_s("%d", &max);
	printf("enter min\n");
	scanf_s("%d", &min);
	printf("enter size of array\n");
	scanf_s("%d", &size6);
	int* arr6 = (int*)malloc(size6 * sizeof(int));
	if (arr6==NULL)
	{
		printf("malloc failed");
		return 0;
	}
	printf("enter your numbers\n");
	for (int i = 0; i < size6; i++)
	{
		scanf_s("%d", &arr6[i]);
	}
	printf("you have %d numbers between %d and %d\n", between(arr6, size6, min, max),min,max);
	////7
	char str1[size1];
	printf("enter your string number\n");
	getchar();
	gets(str1);
	printf("%d\n",copy(str1));
	//8
	int num;
	printf("Enter your number\n");
	scanf_s("%d", &num);
	printf("The highest digit is :%d\n", high(num));
	free(arr6);
	free(arr);
	return 0;
}

void Norepeat(char str[])
{	
	if (str[0] == 0)
	{
		return;
	}
	if (str[0] == str[1])
	{
		return Norepeat(str+1);
	}
	else
	{
		printf("%c", str[0]);
		return Norepeat(str+1);
	}
}
int Even(int num)
{
	if (num == 0)
	{
		return 1;
	}
	
	if ((num % 10) % 2 == 0)
	{
		return Even(num/10);
	}
	else
	{
		return 0;
	}
	
}
int Same(int num)
{
	if (num == 0)
	{
		return 1;
	}
	if ((num<10))
	{
		return 1;
	}
	if ((num%100)/10 == num % 10)
	{
		return Same(num/10);
	}
	else
	{
		return 0;
	}
		
}
int samefirstdigit(int arr[],int size)
{
	if (size==1)
	{
		return 1;
	}
	if (samefirstdigit(arr+1, size - 1) == 1)
	{
		if (arr[0] % 10 == arr[1]%10)
		{
			return 1;
		}
	}
	return 0;
}
int sumOddNumbers(int arr[], int size)
{
	if (size == 0)
	{
		return 0;
	}
	if (arr[0] % 2 == 1)
	{
		return arr[0]+sumOddNumbers(arr + 1, size - 1);
	}
		return sumOddNumbers(arr + 1, size - 1);
}
int between(int arr[], int size, int min, int max)
{
	if (size==0)
	{
		return 0;
	}
	if (arr[0] >= min && arr[0] <= max)
	{
		return 1 + between(arr+1,size-1,min,max);
	}

	return between(arr + 1, size - 1, min, max);

}
int copy(char *str)
{
	if (strlen(str)==1)
	{
		return (str[0] - '0');
	}
	if (str[0]>'0')
	{
		return ((str[0] - '0')*(pow(10,strlen(str)-1))) + copy(str + 1);
	}
	else
	{
		return 0;
	}
}
int high(int num)
{
	if (num%100/10>num%10)
	{
		return high(num / 10);
	}
	if (num < 10)
	{
		return num;
	}
	else
	{
		return high((num/10)-(num % 100/10) + (num % 10));
	}
}