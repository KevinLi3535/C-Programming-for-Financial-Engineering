// 2.3.6.cpp
// Author: Minghan Li
// In this program, we would like to prompt the users to input parameters of a Circle,
// and construct a Circle object and call some member functions on it.
// It demonstrates the Circle as a class.

#include <iostream>
#include "Circle.hpp"
#include "Point.hpp"

int main()
{
	// Initialize x, y coordinates of the center and radius of the Circle
	double x, y, radius;

	// Explain to the user what to do
	std::cout << "Let's construct a Circle!\n";

	// Prompt user to enter a radius
	std::cout << "Please enter the radius of the Circle: ";
	std::cin >> radius;

	// Prompt user to enter the x and y coordinates for centre point
	std::cout << "Please enter the x coordinate for the center point: ";
	std::cin >> x;

	std::cout << "Please enter the y coordinate for the center point: ";
	std::cin >> y;

	// Create the center point
	Point center(x, y);

	// Create the Circle with the center point and the radius
	Circle Mycircle(radius, center);

	// Print out the information of the Circle using the member functions
	std::cout << "\n\nHere is some information about this Cirle we just created:\n";

	std::cout << Mycircle.ToString();	// The string description of the Circle
	
	std::cout << "\nCircle's radius : " << Mycircle.Radius();	// Print the radius

	std::cout << "\nCircle's diameter : " << Mycircle.Diameter();	// Print the diameter

	std::cout << "\nCircle's area : " << Mycircle.Area();	// Print the area

	std::cout << "\nCircle's circumference : " << Mycircle.Circumference();		// Print the circumference

	return 0;
}