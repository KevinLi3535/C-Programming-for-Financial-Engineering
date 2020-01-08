#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Print.hpp"

void print(float i);
int main() {
	float i;
	printf("Please enter a number: ");
	scanf("%f", &i);
	
	print(i);
}