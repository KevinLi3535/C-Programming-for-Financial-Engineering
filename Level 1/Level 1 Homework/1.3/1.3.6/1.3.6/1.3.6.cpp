#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int input;  

	printf("Please Enter any integer you wish to shift: ");
	if (scanf("%d", &input) == 1) {
		input = input >> 2;
	};

	input < 0 ? printf("Input number was negative.\nArithmetic shift is performed.") :printf("Input number was positive.\nLogical shift is performed.");

	printf("\nThe number shifted two places to the right is: %d \n", input);

	return 0;
}