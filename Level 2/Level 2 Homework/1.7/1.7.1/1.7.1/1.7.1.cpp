// 1.7.1.cpp
// Author: Minghan Li
// This program is to show the implementation of Swap function,
// which exchange the values of two variables.
// Example: if i=123 and j=456, then i=456 and j=123 after the Swap() function has been called.

#include <stdlib.h>
#include <stdio.h>

void Swap(int*x, int*y);

int main() {

	// Declare and initialize i and j
	int i = 123;
	int j = 456;

	// Print the values for i and j
	printf("The original values for i and j:\n i = %d, j = %d", i, j);

	// Swap the two values by pass the reference of i and j respectively
	Swap(&i, &j);
	printf("\n\nAfter the Swap function:\n i = %d, j = %d", i, j);

	return 0;
}

// Swap function takes two pointers as arguments
// In this case, the pointers represent variables that store the addresses of i and j
void Swap(int* x, int* y) 
{
	// We first create a temporary object which stores value restored in the first address
	int temp = *x;
	
	// Change the value stored in x to the value stored in y
	// Change the value stored in y to the value of temporary object, 
	// which is equal to the original value stored in x
	*x = *y;
	*y = temp;
}