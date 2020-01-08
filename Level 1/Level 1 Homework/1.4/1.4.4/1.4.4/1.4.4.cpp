#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float start, end, interval, Fahre, Celsius;

	printf("Please enter the starting value in Fahrenheit:\n");
	scanf("%f", &start);

	printf("Please enter the ending value in Fahrenheit:\n");
	scanf("%f", &end);

	printf("What stepsize would you like?\n");
	scanf("%f", &interval);

	Fahre = start;

	if (Fahre > end) {
		printf("Error: start value is greater than the ending value");
		return 0;
	}
	
	printf("\n--------------------------------------------\n");
	printf("\nFahrenheit\t\t   Celsius\n");
	while (Fahre <= end)
	{
		Celsius = 5.0 * (Fahre - 32.0) / 9.0;
		printf("%10.1f\t\t%10.1f\n", Fahre, Celsius);
		Fahre += interval;
	}

	return 0;
}