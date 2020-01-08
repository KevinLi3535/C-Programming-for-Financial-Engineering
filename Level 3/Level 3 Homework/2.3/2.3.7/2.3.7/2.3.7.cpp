// 2.3.7.cpp
// Arthor: Minghan Li
// This file contains a test program with a main() function
// This program is an extension of 2.3.4.cpp
// In this version, the getter functions are implemented using Normal Inline method,
// and the setter functions are implemented using Default Inline method.

// Preprossessor Directives
#include <iostream>
#include "Point.hpp"

int main()
{
	// Initialize x and y coordinates variables
	double x, y, x2, y2;

	// Prompt the user to input x and y coordinates
	std::cout << "Please enter your x coordinate: ";
	std::cin >> x;

	std::cout << "Please enter your y coordinate: ";
	std::cin >> y;

	// Create the point using x and y inputs
	Point Mypoint(x, y);	// Construct Mypoint using the new constructor

	// Print the description of the point returned by the ToString() function
	// Print the point coordinates using the get functions
	// Print the distance to the origin
	std::cout << "\nDescription of the point using ToString(): " << Mypoint.ToString();
	std::cout << "\nThe x coordinate: " << Mypoint.X();
	std::cout << "\nThe y coordinate: " << Mypoint.Y();
	std::cout << "\nDistance to the origin (0, 0): " << Mypoint.Distance();

	// Prompt the user to input x and y coordinates for the second point
	std::cout << "\n\nPlease enter the second x coordinate: ";
	std::cin >> x2;

	std::cout << "Please enter the second y coordinate: ";
	std::cin >> y2;

	// Create the new point using the second x and y coordinates inputs
	Point Newpoint(x2, y2);

	// Print the description of the new point returned by the ToString() function
	// Print the new point coordinates using the get functions
	// Print the distance from the new point to the origin
	std::cout << "\nDescription of the new point using ToString(): " << Newpoint.ToString();
	std::cout << "\nThe x coordinate of new point: " << Newpoint.X();
	std::cout << "\nThe y coordinate of new point: " << Newpoint.Y();
	std::cout << "\nDistance from the new point to the origin (0, 0): " << Newpoint.Distance();

	// Print the distance between the original point and new point using Distance() function
	std::cout << "\n\nDistance between the original point and the new point: " << Mypoint.Distance(Newpoint);

	// Destructors executed here
	return 0;
};