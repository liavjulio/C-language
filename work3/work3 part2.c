#include <stdio.h>
#include <stdlib.h>
#define CRT_SECURE_NO_WARNINGS	
#define N 5
int check(int arr1[], int size);
void sequence(int arr2[][N]);
int main()
{
	int mat[N][N] = {{12,11,10,9,8},{7,12,11,10,18},{3,6,12,24,48},{22,14,13,12,24},{16,21,14,36,12}};
	sequence(mat);
	return 0;

}
int check(int arr1[], int size)
{	
	int x = 0, y = 0, z = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr1[0] == arr1[i])
		{
			x++;
		}
		else
		{
			break;
		}
	}
	if (x==(size-1))
	{
		return 1;
	}
	int d = arr1[1] - arr1[0];
	for (int i = 1; i < size-1; i++)
	{
		if (arr1[i+1]-arr1[i]==d)
		{
			y++;
		}
		else
		{
			break;
		}
	}
	if (y==(size-2))
	{
		return 2;
	}
	float q = arr1[1]/arr1[0];
	for (int i = 1; i < size-1; i++)
	{
		if (arr1[i+1]/arr1[i]==q)
		{
			z++;
		}
		else
		{
			break;
		}
	}
	if (z==(size-2))
	{
		return 3;
	}
	return 0;
}
void sequence(int mat[][N])
{
	int i, j, x;
	int arrHelp[N] = { 0 };
	for (i = 0; i < N; i++)
	{
		x = check(&mat[i][0], N);
		switch (x)
		{
		case 1:
			printf("line %d:constant sequence\n", i);
			break;
		case 2:
			printf("line %d:arithmetic sequence\n", i);
			break;
		case 3:
			printf("line %d:geometric sequence\n", i);
			break;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			arrHelp[j] = mat[j][i];
		}
		x = check(&arrHelp[0], N);
		switch (x)
		{
		case 1:
			printf("col %d:constant sequence\n", i);
			break;
		case 2:
			printf("col %d:arithmetic sequence\n", i);
			break;
		case 3:
			printf("col %d:geometric sequence\n", i);
			break;
		}
	}
	for (i = j = 0; i < N && j < N; i++, j++)
	{
		arrHelp[j] = mat[j][i];
	}
	x = check(&arrHelp[0], N);
	switch (x)
	{
	case 1:
		printf("diagonal 1:constant sequence\n");
		break;
	case 2:
		printf("diagonal 1:arithmetic sequence\n");
		break;
	case 3:
		printf("diagonal 1:geometric sequence\n");
		break;
	}
	for (i = N - 1, j = 0; i >= 0 && j < N; i--, j++)
	{
		arrHelp[j] = mat[i][j];
	}
	x = check(&arrHelp[0], N);
	switch (x)
	{
	case 1:
		printf("diagonal 2:constant sequence\n");
		break;
	case 2:
		printf("diagonal 2:arithmetic sequence\n");
		break;
	case 3:
		printf("diagonal 2:geometric sequence\n");
		break;
	}
}