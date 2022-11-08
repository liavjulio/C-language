/*
Assignment: 2
Author: Liav Huli, ID: 314917808
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void randomGame(int,int,int);
int randomNum(int,int);
int check_Prime(int);
int primeGame(int,int);
long long twiceDigit(int);
int unique_digits(int);
int main()
{
	int game;
	printf("1 Guess game\n2 Twin primes\n3 Twice\n4 Distinct digits\n5 Quit\n");
	scanf_s("%d", &game);
	while (game > 5 || game < 1)
	{
		printf("INVALID INPUT TRY AGAIN\n");
		printf("1 Guess game\n2 Twin primes\n3 Twice\n4 Distinct digits\n5 Quit\n");
		scanf_s("%d", &game);
	}
	switch (game)
	{
		case 1:
		{
			int guesses, min, max;
			printf("Enter min and max\n");
			scanf_s("%d%d", &min, &max);
			printf("enter how much guesses\n");
			scanf_s("%d", &guesses);
			randomGame(guesses, min, max);
			break;
		}
		case 2:
		{
			int start, end, count = 0;
			printf("Enter start:");
			scanf_s("%d", &start);
			printf("Enter end:");
			scanf_s("%d", &end);
			primeGame(start, end);
			break;
		}
		case 3:
		{
			int N;
			printf("please enter your number :");
			scanf_s("%d", &N);
			printf("%lld",twiceDigit(N));
			break;
		}
		case 4:
		{	
			int n;
			printf("Enter your number :");
			scanf_s("%d", &n);
			printf("%d",unique_digits(n));
			break;
		}
		case 5:
		{
			printf("Goodbye");
			return 0;
			break;
		}
	}
	return 0;
	}
void randomGame(int guesses, int min, int max)
	{
	int  x, num;
	num = randomNum(min, max);
	printf("Enter your guess\n");
	scanf_s("%d", &x);
	while (guesses > 1)
	{
		if (x == num)
		{
			printf("Wow Good job\n");
			printf("The number is : %d", x);
			break;
		}
		else
		{
			if (x > max || x < min)
			{
				printf("OUT OF RANGE\n");
				printf("Enter your guess\n");
				scanf_s("%d", &x);
			}
			else
			{
				if (x > num)
				{
					printf("Enter lower number\n");
					guesses--;
					scanf_s("%d", &x);
				}
				else
				{
					printf("Enter higher number\n");
					guesses--;
					scanf_s("%d", &x);
				}
			}
		}
	}
	if (guesses == 1)
	{
		printf("Good bye\n");
		printf("the number is : %d", num);
	}
}
int randomNum(int x, int y)
{
	time_t t;
	srand((unsigned)time(&t));
	return (rand() % (x - y ) + 1 + x);
}
int check_Prime(int n)
{
		if (n == 1)
		{
			return 0;
		}

		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				// number is not prime
				return 0;
			}
		}

		// number is prime
		return 1;
}
int primeGame(int a, int b)
{
	if (a < b)
	{
		int count = 0;
		for (int i = a; i < b; i++)
		{
			if (check_Prime(i) && check_Prime(i + 2))
			{
				printf("{%d, %d}\n", i, i + 2);
				i = i + 1;
				count++;
			}

		}
		printf("%d", count);
	}
	return 0;
}
long long twiceDigit(int N)
{
		int i=0,divided=0,n=11,r;
		while (N != 0)
		{
			r = (N % 10) * n;
			divided = r + divided;
			N = N / 10;
			n = n * 100;
		}
	return divided;
}
int unique_digits(int n)
{
		const int Base = 10;

		int unique = 1;

		while (unique && n)
		{
			int digit = n % Base;
			int tmp = n /= Base;

			while (tmp && digit != tmp % Base) tmp /= Base;

			unique = tmp == 0;
		}

		return unique;
}