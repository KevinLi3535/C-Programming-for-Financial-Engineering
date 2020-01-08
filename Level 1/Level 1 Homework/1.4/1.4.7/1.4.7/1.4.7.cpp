#include <stdio.h>
#include <stdlib.h>

int main() {
	int zero = 0;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int other = 0;
	char character;

	printf("Please enter your input and end your input with Control + Z (EOF):\n");

	while ((character = getchar()) != 4 && character != EOF && character != 26 && character != -1)
	{
		switch (character)
		{
		default:
			other++; break;
		case '0':
			zero++; break;
		case '1':
			one++; break;
		case '2':
			two++; break;
		case '3':
			three++; break;
		case '4':
			four++; break;
		}
	}

	printf("\n\nThe number of times 0 was typed:\t%d", zero);
	printf("\nThe number of times 1 was typed:\t%d", one);
	printf("\nThe number of times 2 was typed:\t%d", two);
	switch (three)
	{
	case 0:  printf("\nNumber three appears zero time."); break;
	case 1:  printf("\nNumber three appears one time."); break;
	case 2:  printf("\nNumber three appears two times."); break;
	default: printf("\nThe number three appears more than two times."); break;

	}
	printf("\nThe number of times 4 was typed:\t%d", four);
	printf("\nThe number of times other characters were typed:\t%d", other);

	return 0;
}