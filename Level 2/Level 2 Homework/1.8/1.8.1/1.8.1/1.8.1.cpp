// 1.8.1.cpp
// Author: Minghan Li
// This is a C-program that prints the contents of a struct called Article. 
// An Article has the three characteristics: Article Number, Quantity, and Description.

// Preprocessor Directives
#include <stdlib.h>
#include <stdio.h>

// Article.h contains declaration of Article structure
#include "Article.h"

// Print function which prints the three fields of an Article structure.
// Here, we use "->" to access the fields with pointers.
void Print(struct Article* pp)
{
	printf("Article number: %d\nQuantity: %d\nDescription: %s",
		pp->Number, pp->Quantity, pp->Description
	);
}

int main()
{
	// Article test object initialization
	// All fields are assigned at initialization level
	struct Article test = { 3, 10, "Article No.3" };

	// Pass the reference of test as the address to Print() function
	Print(&test);

	return 0;
}