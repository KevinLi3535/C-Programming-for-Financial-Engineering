// 1.7.4.cpp
// Author: Minghan Li
// This is a C-program that has a function DayName() which can print the day of a given day-number. 
// General rule: 1 gives: Day 1 is a Sunday 7 gives: Day 7 is a Saturday. 
// *The day-name (1-7) should be written "hard-coded” into the program using an array of strings.

// Warnings is disabled to avoid compilaton error when using scanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

// As these "hard-coded" string variables will be used throughout the program,
// we choose to define them as global variables.
char Day0[7] = "Sunday";
char Day1[7] = "Monday";
char Day2[8] = "Tuesday";
char Day3[10] = "Wednesday";
char Day4[9] = "Thursday";
char Day5[7] = "Friday";
char Day6[9] = "Saturday";

// Initialize a array of pointers, which contains the names of the strings previously defined.
// Since strings are basically character arrays, Days is an array of the first elements of the strings.
char* Days[7] = { Day0, Day1, Day2, Day3, Day4, Day5, Day6 };

char* DayName(int day_num)
{
	// Return the pointer corresponding to the day number
	return *(Days+day_num);
}

int main() 
{
	// Initialize the variables for user input.
	int input_day1;
	int input_day2;
	int input_day3;

	// Prompt the user to enter three day numbers
	printf("Reference: 1 means Sunday, 2 means Monday, ......, 7 means Saturday\n");
	printf("Please enter the first day: ");
	scanf("%d", &input_day1);
	printf("Please enter the second day: ");
	scanf("%d", &input_day2);
	printf("Please enter the third day: ");
	scanf("%d", &input_day3);

	// Print the result by using DayName function.
	printf("\nDay %d is a %s.\nDay %d is a %s.\nDay %d is a %s.", input_day1, DayName(input_day1-1),
		input_day2, DayName(input_day2-1), input_day3, DayName(input_day3-1));

	return 0;
}