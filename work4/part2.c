#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int* build(int* psize);
int* Union(int* group1, int size1, int* group2, int size2, int* psize);
int* intersection(int* group1, int size1, int* group2, int size2, int* psize);
int* minus(int* group1, int size1, int* group2, int size2, int* psize);
void print(int* group, int size);
int main()
{
	int psize1, psize2, psize3 = 0 , psize4=0,psize5=0;
	printf("Please enter your size of group:\n");
	scanf_s("%d", &psize1);
	printf("Please enter your size of group:\n");
	scanf_s("%d", &psize2);
	int* arr1 = build(&psize1);
	int* arr2 = build(&psize2);
	int* arr3 = Union(&arr1[0], psize1, &arr2[0], psize2, &psize3);
	int* arr4 = intersection(&arr1[0], psize1, &arr2[0], psize2, &psize4);
	int* arr5 = minus(&arr1[0], psize1, &arr2[0], psize2, &psize5);
	printf("The union of group 1 and 2 is:");
	print(arr3, psize3);
	printf("The intersection of group 1 and 2 is:");
	print(arr4, psize4);
	printf("The minus of group 1 and 2 is:");
	print(arr5, psize5);
	free(arr3);
	free(arr4);
	free(arr5);
	return 0;
}
int* build(int* psize) 
{
	int x = *psize;
	int *arr=NULL;
	arr = (int*)malloc((x)*sizeof(int));
	if (arr == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}
	printf("Enter your numbers:\n");
	for (int i = 0; i < x; i++)
	{
		scanf_s("%d", &arr[i]);
		for (int j = 0; j < i; j++)
		{
			if (*(arr+i) == *(arr+j))
			{
				*(arr+i) = 0;
				i--;
				printf("ERROR,DUPLICATE NUMBER\n");
				printf("PLEASE ENTER AGAIN\n");
				break;
			}
		}
	}
	return &arr[0];
}
int* Union(int* group1, int size1, int* group2, int size2, int* psize)
{
	int flag = 0;
	int size3 = size1;
	int* arr1 = NULL;
	arr1 = (int*)malloc((size1 + size2) * sizeof(int));
	if (arr1 == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}
	if (size1==0)
	{
		for ( int i = 0; i < size2 ;i++)
		{
			*(arr1 + i) = *(group2 + i);
			(*psize)++;
		}
	}
	if (size2 == 0)
	{
		for (int i = 0; i < size1;i++)
		{
			*(arr1 + i) = *(group1 + i);
			(*psize)++;
		}
	}
	else
	{
		for (int i = 0; i < size1; i++)
		{
			*(arr1 + i) = *(group1 + i);
			(*psize)++;
		}
		for (int i = 0; i < size2; i++)
		{
			for (int j = 0; j < size1; j++)
			{
				if (*(group2 + i) != *(arr1 + j))
				{
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				*(arr1 + (size3)) = *(group2 + i);
				size3++;
				(*psize)++;
				flag = 0;
			}
		}
	}
	return &arr1[0];
}
int* intersection(int* group1, int size1, int* group2, int size2, int* psize)
{
	int z = 0;
	int* arr1 = NULL;
	arr1 = (int*)malloc((size1 + size2) * sizeof(int));
	if (arr1 == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}
	if (size1 > size2)
	{
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				if (*(group1+i) == *(group2 + j))
				{
					*(arr1+z) = *(group1+i);
					(*psize)++;
					z++;
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < size2; i++)
		{
			for (int j = 0; j < size1; j++)
			{
				if (*(group2 + i) == *(group1 + j))
				{
					*(arr1+ z) = *(group2+i);
					(*psize)++;
					z++;
					break;
				}
			}
		}
	}
	return &arr1[0];
}
int* minus(int* group1, int size1, int* group2, int size2, int* psize)
{
	int flag = 0, z = 0;
	int* arr1 = NULL;
	arr1 = (int*)malloc((size1 + size2) * sizeof(int));
	if (arr1 == NULL)
	{
		printf("malloc failed\n");
		return 0;
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (*(group1 + i) == *(group2 + j))
			{
				flag = 0;
				break;
			}
			else
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			*(arr1 + z) = *(group1 + i);
			z++;
			(*psize)++;
		}
	}
	return &arr1[0];
}
void print(int* group, int size)
{
	printf("{");
	for (int i = 0; i < size; i++)
	{
		printf("%d,", group[i]);
	}
	printf("}\n");
}