/* Assignment: 2
Author: Liav huli, ID: 314917808
*/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define pie 3.14
enum {triangle=1,square,rectangle,circle};
int main() {
	int shape;
	float base, height, length, lattiude, radius;
	printf("choose your shape \n1-triangle\n2-square\n3-rectangle\n4-circle\n");
	scanf_s("%d", &shape);
	switch (shape)
	{
	case 1: 
			printf("Enter base :\n");
		    scanf_s("%f", &base);
			printf("Enter height :\n");
		    scanf_s("%f", &height);
		    printf("Area is : %.3f ", (base * height / 2));
			break;
	case 2: 
		printf("Enter length :\n");
		scanf_s("%f", &length);
		printf("Enter lattitude :\n");
		scanf_s("%f", &lattiude);
		printf("Area is : %.3f", (length * lattiude));
		break;
	case 3:
		printf("Enter length :\n");
		scanf_s("%f", &length);
		printf("Area is : %.3f", (length * length));
		break;
	case 4:
		printf("Enter radius :\n");
		scanf_s("%f", &radius);
		printf("Area is : %.3f", (radius*radius*pie));
		break;
	default: printf("ERROR");
	break;
	}




















	return 0;
}