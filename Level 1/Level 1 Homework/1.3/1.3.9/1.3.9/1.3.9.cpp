#include <stdio.h>
int main()
{
	int x = 1;
	int y = 1;
	int z = 1;
	
	x += y += x;  // x = 3, y = 2
	
	printf("%d\n\n", (x < y) ? y : x); // Output: 3
	printf("%d\n", (x < y) ? x++ : y++); // Output: 2, y++ executed
	printf("%d\n", x); // Output: 3
	printf("%d\n", y); // Output 3
	return 0;
}