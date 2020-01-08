#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int drunk;
	printf("Are you drunk? ( 0 = No || 1 = Yes)  ");
	if (scanf("%d", &drunk) == 1) {
		printf("The person in front of the screen is %s \n", drunk ? "drunk" : "not drunk");
	};
	
	system("pause");
	return 0;
}