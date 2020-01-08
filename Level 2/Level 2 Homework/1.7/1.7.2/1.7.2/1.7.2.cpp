// 1.7.2.cpp
// Author: Minghan Li
// In this program, we are trying to implement the function Length(),
// which mimics the built-in function strlen().
// Function Length() determine the length of the string.

/* Calculate the length of a string */
#include <stdio.h>
#define MAXLINE 30
// String lenght declaration
int Length(char str[]);
int main()
{
	char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
	int c; // The input character
	int i = 0; // The counter
	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
	// Get the characters
	while ((c = getchar()) != EOF && c!=26 && i < MAXLINE)
	{
		// Append entered character to string
		string[i++] = (char)c;
	}
	string[i] = '\0'; // String must be closed with \0
	printf("String length is %d\n", Length(string));
	// printf("String length is %d\n", Length(string));
	return 0;
}

/* Implement the Length() function here */
int Length(char str[])
{
	int count = 0;

	// Since str is a pointer to the first element initially, 
	// we can increment it to get the next element.

	while (str[count++] != '\0');

	// Original version
	//while (*str != '\0') 
	//{
	//	// increment count when evaluate TRUE
	//	// go to the next element
	//	count++;
	//	str++;
	//}

	return count-1;
}
