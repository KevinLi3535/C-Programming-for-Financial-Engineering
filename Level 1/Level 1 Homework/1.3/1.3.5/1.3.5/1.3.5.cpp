#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	printf("Please Enter a integer: ");
	if (scanf("%d", &i) == 1){
		printf("The original value of i is %d\n\n", i);
	};
	
	int temp = i;
	printf("Value of pre-reduction --i is %d , and the new value of --i after pre-reduction is %d.\n", --i, i );
	i = temp;
	printf("Value of post-reduction i-- is %d , and the new value of i-- after post-eduction is %d.\n", i--, i);
	
	return 0;
}