#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int factorial(unsigned int x);

int main() {
	int i;
	printf("6 factorial is %d.\n\n", factorial(6));
	printf("Please enter a positive integer number: ");
	scanf("%d", &i);
	printf("\n%d factorial is %d.", i, factorial(i)); 

	return 0;
}

int factorial(unsigned int x) {
	if (x == 0)
		return 1;
	else if (x == 1)
		return 1;
	else
		return x*factorial(x - 1);

}