#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define size 15
struct car
{
	char* model;
	int year, price;
	long number;
};
int find_size();
struct car *create_array(int);
int find(struct car*, int counter, char* model, int year, int price);
int main()
{
	int counter = find_size();
	struct car* p = create_array(counter);
	int price, year;
	char model[size];
	printf("enter model\n");
	gets(model);
	printf("enter price\n");
	scanf_s("%d", &price);
	printf("enter year\n");
	scanf_s("%d", &year);
	int x = find(p, counter, model, year, price);
	printf("%d matches were found", x);
	for (int i = 0; i < counter; i++)
		free(p[i].model);
	free(p);
	return 0;
}
int find_size()
{	
	FILE* fp = NULL;
	char model[size];
	long number;
	int year, price;
	int counter = 0;
	fp = fopen("cars.txt", "r");
	if (fp==NULL)
	{
		printf("error\n");
		return 0;
	}
	while (fscanf(fp,"%ld %s %d %d",&number,model,&year,&price)!=EOF)
	{
		counter++;
	}
	fclose(fp);
	return counter;
}
struct car* create_array(int counter)
{
	char model[size];
	int year1, price1;
	long number1;
	struct car* p;
	FILE* fp = NULL;
	p = (struct car*)malloc(size * sizeof(struct car));
	if (p == NULL)
	{
		printf("error malloc failed");
		return 0;
	}
	int x = fopen_s(&fp, "cars.txt", "r");
	if (x)
	{
		printf("File doesnt exist\n");
		return 0;
	}
	for (int i = 0; i < counter; i++)
	{

		fscanf(fp, "%ld %s %d %d", &number1, model, &year1, &price1);
		p[i].model = (char*)malloc((strlen(model) + 1) * sizeof(char));
		if (p[i].model == NULL)
		{
			printf("error malloc failed");
			return 0;
		}
		strcpy(p[i].model, model);
		p[i].price = price1;
		p[i].year = year1;
		p[i].number = number1;
	}
	fclose(fp);
	return p;
}
int find(struct car* info, int counter, char* model, int year, int price)
{
	int count = 0;
	for (int i = 0; i < counter; i++)
	{
		if (strcmp(info[i].model, model) == 0 && info[i].price <= price && info[i].year >= year)
		{
			printf("%ld %s %d %d\n", info[i].number, info[i].model, info[i].year, info[i].price);
			count++;
		}
	}
	return count;
}