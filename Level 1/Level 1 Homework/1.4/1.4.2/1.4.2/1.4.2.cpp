#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>>

#include <stdio.h>			// C style I/O
#include <ctype.h>          //This include file declares the narrow character (char) classification functionality.

int main() {
	
	char character = 0;
	char pre_char = 0;   //The character before the current character
	int nlines = 1;   //Number of lines
	int nwords = -1;   //Number of words
	int nchar = -1;    //Number of characters
	
	printf("Please enter some text (sentence, words, newlines) and use Control + D to end your input:\n");

	do {
		if (character == '\n')
			nlines++;

		if (!isspace(character) && (isspace(pre_char) || pre_char == 0))
			nwords++;

		nchar++;
		pre_char = character;
	} while ((character = getchar()) != EOF && character != 4);
	
	printf("\nNumber of characters: %d\n", nchar);
	printf("Number of words: %d\n", nwords);
	printf("Number of lines: %d\n", nlines);

	return 0;
}