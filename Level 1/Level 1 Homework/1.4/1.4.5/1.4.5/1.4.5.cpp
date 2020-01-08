#include <stdio.h>

int main() {
	float Celsius;

	printf("\n   Celsius\t\tFahrenheit\n");
	
	for (Celsius = 0; Celsius <= 19; Celsius++)
		printf("%10.1f\t\t%10.1f\n", Celsius, Celsius * 9.0 / 5.0 + 32);

	return 0;
}