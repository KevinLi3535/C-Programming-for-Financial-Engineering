#include <stdio.h>
#include <stdlib.h>
#include "Printnumber.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int x;
	printf("Please enter an integer: ");
	
	if (scanf("%d", &x) == 1) {
		printf("\nPrinting %d digit by digit using putchar():\n", x);
		printnumber(x);
	}
		
	
	return 0;
}

void printnumber(int i) {
	
	// First we deal with negative numbers
	if (i < 0)
	{
		putchar('-');
		putchar(' ');
		i = -i;
	}

	// Keep dividing the integer until 
	// it is less than 10.
	if (i >= 10)
		printnumber(i / 10);
		
	// Once the number is 
	putchar('0' + i % 10);
	putchar(' ');
}
