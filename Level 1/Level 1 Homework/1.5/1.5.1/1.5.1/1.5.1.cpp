#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int minus(int a, int b);

int main() {
	int a, b;

	printf("Please enter the first integer: ");
	scanf("%d", &a);
	printf("Please enter the second integer: ");
	scanf("%d", &b);

	printf("\n%d minus %d is equal to %d", a, b, minus(a, b));

	return 0;
}

int minus(int a, int b) {
	return a - b;
}
