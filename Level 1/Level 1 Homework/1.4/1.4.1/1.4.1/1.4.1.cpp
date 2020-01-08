#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>>

int main() {
	char character = 0;
	char pre_char = 0;   //The character before the current character
	int nlines = 1;   //Number of lines
	int nwords = 0;   //Number of words
	int nchar = 0;    //Number of characters
	
	printf("Please enter some text (sentence, words, newlines) and use Control + D to end your input:\n");

	while ((character = getchar()) != EOF && character != 4)
	{

		if (character == '\n')
			nlines++;

		if (!isspace(character) && (isspace(pre_char) || pre_char == 0))
			nwords++;

		nchar++;
		pre_char = character;
	};

	printf("\nNumber of characters: %d\n", nchar);
	printf("Number of words: %d\n", nwords);
	printf("Number of lines: %d\n", nlines);

	return 0;
}