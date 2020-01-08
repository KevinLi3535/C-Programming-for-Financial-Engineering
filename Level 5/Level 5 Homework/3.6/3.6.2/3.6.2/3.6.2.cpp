// 3.6.2.cpp
// Author: Minghan Li
// In this program, we would like to test the getter and setter functions in Array class
// after implementing exception handling in these two functions
// This time, we want to throw and catch objects belonging to ArrayException class, which
// we created in Array.hpp

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
	// Create an array with 5 elements
	Array arr1(5);

	//arr1.SetElement(Point(4.2, 5.0), 1);
	//arr1.SetElement(Point(1, 2), 6);

	// If try...catch block is not present, the 
	// program will have a run-time error
	try
	{
		// Asses the out-of-range
		cout << arr1.GetElement(1) << endl;
		cout << arr1.GetElement(10) << endl;
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
		arr1.SetElement(Point(6.4, 19), 1);

		// This line is setting value for an element out of bounds
		arr1.SetElement(Point(7, 4), 6);

		// This line works, but will not be executed
		arr1.SetElement(Point(6.5, 20), 2);
	}
	catch (ArrayException &err2)
	{
		// Print the error message
		cout << err2.GetMessage() << endl;
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred" << endl;
	}

	// Take a look at arr1
	// Although an exception has occured, the first line of code,
	// arr1.SetElement(Point(7, 4), 6); has been executed.
	// arr1.SetElement(Point(6.5, 20), 2); is not executed 
	// because it is after the exception throw
	std::cout << "arr1:\n";
	for (int i = 0; i < arr1.Size(); i++)
		cout << arr1[i] << " ";

	cout << endl;

	return 0;
}