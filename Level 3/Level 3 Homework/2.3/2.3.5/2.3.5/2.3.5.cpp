// 2.3.5.cpp
// Author: Minghan Li
// This program serves as a test program for the Line class
// Some member functions are called here to demonstrate their uses

#include <iostream>

// 
#include "Line.hpp"

int main()
{
	// Initialize x and y coordinates variables
	double x1, y1, x2, y2;

	// Explain to the user the process
	std::cout << "Let's build a Line object! We would need two Points from you.\n\n";

	// Prompt the user to input x and y coordinates for the start point
	std::cout << "Please enter the x coordinate for the start point: ";
	std::cin >> x1;

	std::cout << "Please enter the y coordinate for the start point: ";
	std::cin >> y1;

	Point start_point(x1, y1);	// Construct the first point using the point constructor

	// Prompt the user to input x and y coordinates for the end point
	std::cout << "\n\nPlease enter the x coordinate for the end point: ";
	std::cin >> x2;

	std::cout << "Please enter the y coordinate for the end point: ";
	std::cin >> y2;

	Point end_point(x2, y2);	// Construct the second point using the point constructor

	Line Myline(start_point, end_point);	// Construct a Line with the start and end points

	// Description of the Myline objects
	std::cout << "\nThe Line's start point: " << Myline.Start().ToString();		
	std::cout << "\nThe Line's end point: " << Myline.End().ToString();		// Use ToString function in Point class
	std::cout << "\nThe length of the Line: " << Myline.Length();		// Length of the line using "delegation"
	std::cout << "\n\nDescription of the Line using ToString(): \n" << Myline.ToString();	// ToString function for Line class

	// Destructors executed here
	return 0;
};