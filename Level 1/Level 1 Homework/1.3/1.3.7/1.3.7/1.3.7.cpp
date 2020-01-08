#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int input;
	int power;
	int result;

	printf("Please enter the number you like: ");
	if (scanf("%d", &input) == 1) {
		printf("Which power n (2^n) do you want to multiply? ");
	}
	
	if (scanf("%d", &power) == 1) {
		result = input << power;
		printf("%d multiplied by 2^%d is equal to %d\n", input, power, result);
	}
	
	system("pause");
	return 0;
}