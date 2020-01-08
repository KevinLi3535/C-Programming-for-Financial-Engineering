// Macro.c
// Author: Minghan Li

// This simple C program demmonstrate the usage of two print macro calls. 
// PRINT1 prints the variable a, while PRINT2 prints the variables a and b.
// Both PRINT1 and PRINT2 accept arguments

#include <stdio.h>
// Preprossessor directives to include Macros previouly defined in Defs.h
#include "Defs.h"

int main()
{	
	// Define variables a and b
	char a = 'A';
	char b = 'B';

	printf("PRINT1: ");
	PRINT1(a);	//calls the Macro PRINT1 defined in Defs.h
	printf("\nPRINT2: ");
	PRINT2(a, b);  //calls the Macro PRINT2 defined in Defs.h
	
	return 0;
}