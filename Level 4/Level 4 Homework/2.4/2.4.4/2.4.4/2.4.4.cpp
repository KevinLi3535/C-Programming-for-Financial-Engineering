// 2.4.4.cpp
// Author: Minghan Li
// This program is a test program for the operators added to Point, Line, and Circle classes
// In this version, all the << operator overloadings are done as friend functions to the respective classes,
// and no ToString() function is ever used again in their implementations.

#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

int main()
{
	// Declarations for variables in the Point class
	double x1, y1, x2, y2;

	// Prompt the user to input x and y coordinates for first and second points
	std::cout << "Let's test some Point operations using two points!\n\n";

	std::cout << "Please enter the x coordinate for the first point: ";
	std::cin >> x1;

	std::cout << "Please enter the y coordinate for the first point: ";
	std::cin >> y1;

	std::cout << "Please enter the x coordinate for the second point: ";
	std::cin >> x2;

	std::cout << "Please enter the y coordinate for the second point: ";
	std::cin >> y2;

	// Create Point p1 and Point p2
	Point p1(x1, y1);
	Point p2(x2, y2);

	std::cout << "\nAll the following descriptions of Point, Line, and Circle are printed using << operator overloading.\n";

	// Descriptions of p1 and p2 using operator overloading
	std::cout << "\nThe points we created are p1: " << p1 << " and p2: " << p2 << std::endl;

	// Test the negation, and print the description using operator overloading
	std::cout << "The point that negates the coordinates of p1 is -p1: " << (-p1) << std::endl;
	std::cout << "The point that negates the coordinates of p2 is -p2: " << (-p2) << std::endl;

	// Test the operator to scale coordinates, and print the description using operator overloading
	std::cout << "The point that multiplies the coordinates of p1 by 2 is p1*2: " << (p1 * 2) << std::endl;

	// Test the addition of coordinates operator, and print the description using operator overloading
	std::cout << "The point that adds the coordinates of p1 and p2: " << (p1 + p2) << std::endl;

	// Test the equally compare operator
	std::cout << "Are p1 and p2 equal? " << ((p1 == p2) ? "Yes" : "No");
	std::cout << "\nAre p1 and p1 equal? " << ((p1 == p1) ? "Yes" : "No");

	// Test the assignment operator of the Line class, and print the description of the Line using operator overloading
	Line MyLine(p1, p2);
	std::cout << std::endl << std::endl << "We just created a Line that starts from p1 and ends at p2 called MyLine:" << std::endl;
	std::cout << "MyLine: " << MyLine << std::endl;
	std::cout << "Check self-assignment MyLine = MyLine:\n";
	MyLine = MyLine;

	// Test the assignment operator of the Circle class, and print the description of the Circle using operator overloading
	Circle MyCircle(2, p1);
	std::cout << std::endl << "We just created a Circle that centered at p1 with a radius of 2 called MyCircle:" << std::endl;
	std::cout << "MyCircle: " << MyCircle << std::endl;
	std::cout << "Check self-assignment MyCircle = MyCircle:\n";
	MyCircle = MyCircle;

	// Create a point using default constructor, and print the description using operator overloading
	Point p3;
	std::cout << std::endl << "A point p3 is created using default constructor. p3: " << p3 << std::endl;

	// Test the chain assignment, and print the description using operator overloading
	p3 = p2 = p1;
	std::cout << "After the chain assignment p3 = p2 = p1, p3 becomes " << p3 << ", and p2 becomes " << p2 << std::endl;

	// Test the check for self-assignment
	std::cout << "Check self-assignment p1 = p1:\n";
	p1 = p1;

	// Test *= operator, and print the description of p1 using operator overloading
	p1 *= 3;
	std::cout << std::endl << "After p1*=3, p1: " << p1 << std::endl;

	return 0;
}