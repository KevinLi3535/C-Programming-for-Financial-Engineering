// 2.2.1.cpp
// Arthor: Minghan Li
// This file contains a test program with a main() function
// The program asks the user for input the x and y coordinates,
// and then create a Point object with them and print it on the screen using ToString().
// Print the x and y coordinates using getter functions

// Preprossessor Directives
#include <iostream>
#include "Point.hpp"

int main()
{
	// Initialize x and y coordinates variables
	double x, y;

	// Prompt the user to input x and y coordinates
	std::cout << "Please enter your x coordinate: ";
	std::cin >> x;

	std::cout << "Please enter your y coordinate: ";
	std::cin >> y;

	// Create the point using x and y inputs
	Point Mypoint;
	Mypoint.SetX(x);
	Mypoint.SetY(y);

	// Print the description of the point returned by the ToString() function
	// Print the point coordinates using the get functions
	std::cout << "\nDescription of the point using ToString(): " << Mypoint.ToString();
	std::cout << "\nThe x coordinate: " << Mypoint.GetX();
	std::cout << "\nThe y coordinate: " << Mypoint.GetY();
	std::cout << "\nDescription of the point using get functions: Point(" << Mypoint.GetX()<< ", " << Mypoint.GetY() << ")";

	return 0;
}