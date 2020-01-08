# include <stdio.h>

int main()
{
	int x = 2;
	int y;
	int z;

	x *= 3 + 2;
	printf("x=%d\n", x); // Output is 10; addition first, and then multiply;

	x *= y = z = 4;
	printf("x=%d\n", x); // Output is 40; y and z both assigned to 4;

	x = y == z;
	printf("x=%d\n", x); // Output is 1, which stands for TRUE;

	return 0;

}