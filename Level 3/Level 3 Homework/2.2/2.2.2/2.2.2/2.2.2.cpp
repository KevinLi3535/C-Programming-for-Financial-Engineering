// 2.2.2.cpp
// Arthor: Minghan Li
// This file contains a test program with a main() function
// This program is an extension of 2.2.1.cpp
// In this program, we demonstrate the use of the two new functions, 
// DistanceOrigin() and Distance() implemented.

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
	Point Mypoint;
	Mypoint.SetX(x);
	Mypoint.SetY(y);

	// Print the description of the point returned by the ToString() function
	// Print the point coordinates using the get functions
	// Print the distance to the origin
	std::cout << "\nDescription of the point using ToString(): " << Mypoint.ToString();
	std::cout << "\nThe x coordinate: " << Mypoint.GetX();
	std::cout << "\nThe y coordinate: " << Mypoint.GetY();
	std::cout << "\nDistance to the origin (0, 0): " << Mypoint.DistanceOrigin();

	// Prompt the user to input x and y coordinates for the second point
	std::cout << "\n\nPlease enter the second x coordinate: ";
	std::cin >> x2;

	std::cout << "Please enter the second y coordinate: ";
	std::cin >> y2;

	// Create the new point using the second x and y coordinates inputs
	Point Newpoint;
	Newpoint.SetX(x2);
	Newpoint.SetY(y2);

	// Print the description of the new point returned by the ToString() function
	// Print the new point coordinates using the get functions
	// Print the distance from the new point to the origin
	std::cout << "\nDescription of the new point using ToString(): " << Newpoint.ToString();
	std::cout << "\nThe x coordinate of new point: " << Newpoint.GetX();
	std::cout << "\nThe y coordinate of new point: " << Newpoint.GetY();
	std::cout << "\nDistance from the new point to the origin (0, 0): " << Newpoint.DistanceOrigin();

	// Print the distance between the original point and new point using Distance() function
	std::cout << "\n\nDistance between the original point and the new point: " << Mypoint.Distance(Newpoint);

	return 0;
};