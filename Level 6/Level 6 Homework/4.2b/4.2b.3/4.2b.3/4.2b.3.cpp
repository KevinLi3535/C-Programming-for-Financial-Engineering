// 4.2b.3.cpp
// Author: Minghan Li
// In this program, we would like to test the memeber functions and operators in class
// PointArray, a derived class from Array.

// Preprocessor Directives
#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "NumericArray.hpp"
#include "PointArray.hpp"

// Using Circle, Line, Shape, and Point class names stored in MinghanLI::CAD namespace
using MinghanLi::CAD::Circle;
using MinghanLi::CAD::Line;
using MinghanLi::CAD::Shape;
using MinghanLi::CAD::Point;
using MinghanLi::Containers::Array;
using MinghanLi::Containers::NumericArray;
using MinghanLi::Containers::OutOfBoundsException;
using MinghanLi::Containers::ArrayException;
using MinghanLi::Containers::UnequalSizeException;
using MinghanLi::Containers::PointArray;

using namespace std;

int main()
{
	int size = 5;
	// Create a PointArray
	PointArray arr1(size);
	
	// Let's also test the const Array object and copy constructor
	cout << "Create a PointArray called arr1.\n";

	// Print the content of arr1, test if [] operator would work
	std::cout << "arr1:\n";
	for (int i = 0; i < arr1.Size(); i++)
		cout << arr1[i] << " ";

	for (int i = 0; i < arr1.Size(); i++)
		arr1[i] = Point(1.0 * i, 2.0 * i);

	cout << endl << endl << "We assign new values to arr1.\n";

	// Print the content of arr1, test if [] operator would work
	std::cout << "arr1:\n";
	for (int i = 0; i < arr1.Size(); i++)
		cout << arr1[i] << " ";

	// Create another PointArray with default constructor
	PointArray arr2;

	// Check the assignment operator by assigning arr1 to arr2
	arr2 = arr1;
	cout << endl << endl << "Create a PointArray called arr2 using assignment operator = of PointArray.\n";
	// Print the content of arr2
	std::cout << "arr2:\n";
	for (int i = 0; i < arr2.Size(); i++)
		cout << arr2[i] << " ";

	// Get the total length between the points in the arr1
	cout << endl << endl << "The total length between the points in the arr1 now: " << arr1.Length() << endl;

	return 0;
}