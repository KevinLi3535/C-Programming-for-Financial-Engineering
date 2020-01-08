// 2.6.1.cpp
// Author: Minghan Li
// In this program, we try to test our classes which are now put into a common namespace called MinghanLi.
// We try to call the functions and constructors of different classes using differenct methods to access
// the namespace, such as explicit qualification and declaration.

#include <iostream>
#include "Circle.hpp"
#include "Array.hpp"
#include "Line.hpp"
#include "Point.hpp"

int main()
{
	// Using full namespace for the Point class.
	MinghanLi::CAD::Point p1(12, 29);
	MinghanLi::CAD::Point p2(3, 21);
	std::cout << "p1: " << p1 << std::endl;
	std::cout << "p2: " << p2 << std::endl;

	// Using declaration for using a single class (Line)
	using MinghanLi::CAD::Line;

	// Since the single class declaration is used, we can use Line class directly
	std::cout << std::endl << "Create a line called L1 with p1 as start input and p2 as end input." << std::endl;
	Line L1(p1, p2);
	std::cout << "L1: " << L1 << std::endl;

	// Using declaration for a complete namespace (Containers)
	using namespace MinghanLi::Containers;
	
	// Create arr and assign the first element to p1 and second element to p2
	std::cout << "\nCreate a new array arr with two elements.\n";
	std::cout << "Assign the first element to p1 and second element to p2.\n";

	// Array class implementation is included in Containers namespace
	Array arr(2);
	arr.SetElement(p1, 0);
	arr.SetElement(p2, 1);
	std::cout << "arr:\n";
	for (int i = 0; i < arr.Size(); i++)
		std::cout << arr[i] << " ";

	// Short alias for MinghanLi::CAD
	namespace  MHL = MinghanLi::CAD;

	std::cout << "\n\nCreate a Circle called C1 centered at Point(3, 8) with radius 2.\n";
	// Use alias for both Circle class and Point class
	MHL::Circle C1(2, MHL::Point(3, 8));
	std::cout << "C1: " << C1 << std::endl;

	return 0;
}