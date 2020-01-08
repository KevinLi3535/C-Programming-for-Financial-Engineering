// 1.9.2.cpp
// Author: Minghan Li
// This is a C-program that reads the characters from the keyboard 
// and writes them into a file whose directory is specified by the user.
// The inputted characters are printed when the user hits 'enter', line by line.

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main() {
	// Initialize an integer type which will become the input character
	int c;

	// Initialize the string for file directory input by user
	char file_dir[80];

	// Initialize the file handle
	FILE* fp;

	// Prompt the user to enter the file directory
    // My test directory: C:/Users/13105/Documents/C++ for Financial Engineering/Level 2/1.9/HW1.9.2.txt
	printf("Please enter the directory of the file in which you want to print your input characters:\n");
	scanf("%[^\n]", file_dir);  // We want to let scanf read the whole line instead of being interrupted by spaces


	// assign file handle result of fopen
	fp = fopen(file_dir, "w");
	

	// Prompt the user to input characters
	printf("\nPlease enter characters from you keyboard and hit \"Enter\" to print them into the file.\nEnter ^A to exit the program:\n\n");

	c = getchar(); // This line is to resolve the newline character in the buffer resulted from hitting enter

	// Keep get characters from the buffer until ^A appears
	while ((c = getchar()) != 1)
		fputc(c, fp);  // write the characters to the file

	printf("\nCTRL + A is a correct ending.\n");   // Print the message once the user terminates output
	
	fclose(fp);
	return 0;
}