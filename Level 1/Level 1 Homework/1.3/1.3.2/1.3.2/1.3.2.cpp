#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float area, base, height;
	printf("Please enter the base of the triangle: ");
	scanf("%f", &base);
	printf("Please enter the height of the triangle: ");
	scanf("%f", &height);

	area = 0.5 * height * base;
	printf("The area of the trangle is %f", area);

	return 0;
}
