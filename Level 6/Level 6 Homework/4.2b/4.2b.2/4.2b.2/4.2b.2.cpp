// 4.2b.2.cpp
// Author: Minghan Li
// In this program, we would like to test the memeber functions and operators in class
// NumericArray, a derived class from Array. We would also like to test the limitations
// of the class. In particular, whether the array of Point objects can be created, and 
// whether the operators can be used on arrays of Point objects.

#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "NumericArray.hpp"

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

using namespace std;


int main()
{
	// Set default size for testing
	int size = 5;

	// Create an array of doubles with given elements
	NumericArray <double> arr_1(size);

	// Assign values for each element of arr_1
	for (int i = 0; i < arr_1.Size(); i++)
		arr_1[i] = i * 2.0;

	// Print the content of arr_1
	cout << "Create an Array of doubles called arr_1.\n";
	std::cout << "arr_1:\n";
	for (int i = 0; i < arr_1.Size(); i++)
		cout << arr_1[i] << " ";

	// Test the assignment operator and the *operator
	NumericArray <double> arr_2 = arr_1 * 3;

	// Print the content of arr_2
	cout << endl << endl << "Create an Array of doubles called arr_2 by scaling arr_1 by factor of 3:\n";
	cout << "arr_2:\n";
	for (int i = 0; i < arr_2.Size(); i++)
		cout << arr_2[i] << " ";

	// Test the + operator
	NumericArray <double> arr_3 = arr_1 + arr_2;

	// Print the content of arr_3
	cout << endl << endl << "Create an Array of doubles called arr_3 by summing arr_1 and arr_2:\n";
	cout << "arr_3:\n";
	for (int i = 0; i < arr_3.Size(); i++)
		cout << arr_3[i] << " ";

	// Test DotProduct function
	cout << endl << endl << "The DotProduct of arr_2 and arr_3: " << arr_2.DotProduct(arr_3);


	// Create an array of double object with one less element
	NumericArray <double> arr_4(size -1);
	for (int i = 0; i < arr_4.Size(); i++)
		arr_4[i] = i;

	// Print arr_4
	cout << endl << endl << "Create an Array of doubles called arr_4.\n";
	std::cout << "arr_4:\n";
	for (int i = 0; i < arr_4.Size(); i++)
		cout << arr_4[i] << " ";

	try
	{
		cout << endl << endl << "Try creating an Array of doubles called arr_5 by summing arr_4 and arr_3:\n";
		NumericArray <double> arr_5 = arr_4 + arr_3;
	}
	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}
	catch (...)
	{
		// Error message for all other types of exceptions
		cout << "An unhandled exception has occurred" << endl;
	}


	try
	{
		cout << endl << "Try performing DotProduct on arr3 and arr4:\n";
		cout << arr_4.DotProduct(arr_3);
	}
	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}
	catch (...)
	{
		// Error message for all other types of exceptions
		cout << "An unhandled exception has occurred" << endl;
	}

	// Create an array of Point objects with given elements
	NumericArray <Point> points_1(size);

	// Print the content of points
	cout << endl << endl << "Create an Array of Point objects called points_1.\n";
	std::cout << "points_1:\n";
	for (int i = 0; i < points_1.Size(); i++)
		cout << points_1[i] << " ";

	NumericArray <Point> points_2(size);

	// Print the content of points
	cout << endl << endl << "Create an Array of Point objects called points_2.\n";
	std::cout << "points_2:\n";

	for (int i = 0; i < points_2.Size(); i++)
		points_2[i] = Point(i, i+1.0);

	for (int i = 0; i < points_2.Size(); i++)
		cout << points_2[i] << " ";

	cout << endl;
	// Test the + operator on point array
	// NumericArray <Point> points_3 = points_1 + points_2;

	// The code line above produces an error in compile time
	// Error: binary '+=': 'T' does not define this operator or a conversion
	// to a type acceptable to the predefined operator
	// We can create a numeric array of Point objects; however, we cannot perform 
	// any numeric operations on them.

	// Assumption:
	// When making these operators for NumericArray class with template argument,
	// we are assuming that type T has all these operators. When type T does not,
	// like in the case of Point type, the operation cannot be performed.

	return 0;
}