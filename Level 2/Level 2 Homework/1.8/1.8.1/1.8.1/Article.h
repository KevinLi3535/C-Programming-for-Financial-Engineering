// Article.h
// Author: Minghan Li
// This header file contains function declaration for Print
// as well as Article structure declaration

#ifndef Article_H
#define Article_H

// Print() function declaration
void Print(struct Article* pp);

// Article Structure declaration
struct Article
{
	int Number;  // Article number
	int Quantity;  // Article quantity
	char Description[20]; // Article description
};

#endif
