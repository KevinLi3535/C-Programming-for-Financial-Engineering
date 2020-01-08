// 1.6.2.cpp
// Author: Minghan Li
// This is a C program which make use of Macros defined in Defs.h header file.
// Both MAX2 and MAX3 return the maximum value of the given arguments. 

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Defs.h"

int main()
{
	// Define the three variables.
	double x, y, z;

	// Prompting the user to enter values of the three variables.
	printf("Please enter the first number of your choice: ");
	scanf("%lf", &x);
	printf("Please enter the second number of your choice: ");
	scanf("%lf", &y);
	printf("Please enter the third number of your choice: ");
	scanf("%lf", &z);
	
	// Print the result of MAX2 and MAX3.
	printf("\nThe maximum between %.2lf and %.2lf is %.2lf.", x, y, MAX2(x, y));
	printf("\nThe maximum among %.2lf, %.2lf, and %.2lf is %.2lf.", x, y, z, MAX3(x, y, z));

	return 0;
}
