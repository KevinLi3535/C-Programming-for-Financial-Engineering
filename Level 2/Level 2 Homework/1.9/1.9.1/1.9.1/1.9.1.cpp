// 1.9.1.cpp
// Author: Minghan Li
// This is a C-program that reads the characters from the keyboard and shows them on screen 
// The inputted characters are displayed when the user hits 'enter', line by line.

// Preprossessot Directives
#include <stdlib.h>
#include <stdio.h>

int main() {
	// Initialize an integer type which will become the input character
	int c;

	// Prompt the user to input characters
	printf("Please enter characters from you keyboard and hit \"Enter\" to print them on the Screen.\nEnter ^A to exit the program:\n\n");

	// Keep get characters from the buffer until ^A appears
	while ((c = getchar()) != 1) {
		putchar(c);   // print the character on the screen
		
		if (c == 10)   // start a new line whenever a newline is entered
			putchar('\n');
	}
		
	printf("\n\nCTRL + A is a correct ending.\n");   // Print the message once the user terminates output

	return 0;
}