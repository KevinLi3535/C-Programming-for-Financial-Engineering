// 4.2a.1.cpp
// Author: Minghan Li
// In this program, we would like to test the getter and setter functions in Array class
// after implementing exception handling in these two functions like in 3.6.2.
// This time, we modified the implementation of the Array class to follow templates in C++.
// Member functions of the Array class are implemented as generic functions.
// In the end of this test program, we created an Array of Line objects, which shows our success
// in implementing generic programming.

#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Array.hpp"

// Using Circle, Line, Shape, and Point class names stored in MinghanLI::CAD namespace
using MinghanLi::CAD::Circle;
using MinghanLi::CAD::Line;
using MinghanLi::CAD::Shape;
using MinghanLi::CAD::Point;
using MinghanLi::Containers::Array;
using MinghanLi::Containers::OutOfBoundsException;
using MinghanLi::Containers::ArrayException;

using namespace std;

int main()
{
	int size = 5;
	// Create an array with 5 elements
	Array <Point> points(size);

	//arr1.SetElement(Point(4.2, 5.0), 1);
	//arr1.SetElement(Point(1, 2), 6);

	// If try...catch block is not present, the 
	// program will have a run-time error
	try
	{
		// Asses the out-of-range
		cout << points.GetElement(1) << endl;
		cout << points.GetElement(10) << endl;
	}
	catch (ArrayException& err)
	{
		// Print the error message
		cout << err.GetMessage() << endl;
	}
	catch (...)
	{
		// Error message for all other types of exceptions
		cout << "An unhandled exception has occurred" << endl;
	}

	// Test the exception for SetElement
	try
	{
		// This line works
		points.SetElement(Point(6.4, 19), 1);

		// This line is setting value for an element out of bounds
		points.SetElement(Point(7, 4), 6);

		// This line works, but will not be executed
		points.SetElement(Point(6.5, 20), 2);
	}
	catch (ArrayException& err2)
	{
		// Print the error message
		cout << err2.GetMessage() << endl;
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	// Take a look at points
	// Although an exception has occured, the first line of code,
	// points.SetElement(Point(7, 4), 6); has been executed.
	// points.SetElement(Point(6.5, 20), 2); is not executed 
	// because it is after the exception throw
	std::cout << "points:\n";
	for (int i = 0; i < points.Size(); i++)
		cout << points[i] << " ";

	// Let's also test the const Array object and copy constructor
	cout << endl << endl << "Create a const Array of Point objects points_const by calling copy constructor on points.\n";
	const Array<Point> points_const(points);

	// Print the content of points_const, test if [] operator would work on const arrays
	std::cout << "points_const:\n";
	for (int i = 0; i < points_const.Size(); i++)
		cout << points_const[i] << " ";

	
	// Let's also create an array of Line objects with same size as points
	// This should test if generic programming worked in our case
	cout << endl << endl << "Create an Array of Line objects by calling default constructor.\n";
	const Array<Line> lines(size);

	// Print the content of lines
	std::cout << "lines:\n";
	for (int i = 0; i < lines.Size(); i++)
		cout << lines[i] << endl;
	
	cout << endl;

	return 0;
}