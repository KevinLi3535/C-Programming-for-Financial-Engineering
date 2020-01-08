// 2.5.3.cpp
// Author: Minghan Li
// This program is a test program for the Class Array
// All member functions are tested along with the operators
// A const Array is created in the end of the program, and the fact that we can
// access the elements in the const Array using [] operator proves the effect
// of adding const Point& GetElement(int index) const into Class Array.

#include <iostream>
#include "Point.hpp"
#include "Array.hpp"

int main()
{
	// Create some points for later use
	Point p1(10, 12);
	Point p2(14, 28);
	std::cout << "Create two Point objects p1 and p2." << std::endl;
	std::cout << "p1: " << p1 << std::endl;
	std::cout << "p2: " << p2 << std::endl << std::endl;

	// Create an array using default constructor
	Array arr1;
	std::cout << "Create a Array using default constructor called arr1." << std::endl;
	
	// Test the Size function and GetElement function
	std::cout << "Size of arr1: " << arr1.Size() << std::endl;
	std::cout << "The element in arr1 with index four: " << arr1.GetElement(4) << std::endl;
	std::cout << "arr1:\n";
	for (int i = 0; i < arr1.Size(); i++)
		std::cout << arr1[i] << " ";

	// Test the SetElement function
	std::cout << "\n\nSet the Point with index 0 to p1 and Point with index 6 to p2.\n";
	arr1.SetElement(p1, 0);
	arr1.SetElement(p2, 6);
	std::cout << "arr1:\n";
	for (int i = 0; i < arr1.Size(); i++)
		std::cout << arr1[i] << " ";

	// Test the [] operator
	std::cout << "\n\narr1[0]: " << arr1[0] << std::endl;
	std::cout << "arr1[3]: " << arr1[3] << std::endl;
	std::cout << "arr1[6]: " << arr1[6] << std::endl;

	// Test copy constructor
	std::cout << "\nCreate a new array arr2 that copies arr1 using copy constructor.\n";
	Array arr2(arr1);
	std::cout << "arr2:\n";
	for (int i = 0; i < arr2.Size(); i++)
		std::cout << arr2[i] << " ";

	// Create a Array object with size two
	std::cout << "\n\nCreate a new array arr3 with two elements.\n";
	std::cout << "Assign the first element to p1 and second element to p2.\n";

	// Create arr 3 and assign the first element to p1 and second element to p2
	Array arr3(2);
	arr3.SetElement(p1, 0);
	arr3.SetElement(p2, 1);
	std::cout << "arr3:\n";
	for (int i = 0; i < arr3.Size(); i++)
		std::cout << arr3[i] << " ";

	// Test SetElement and GetElement with out of bound indexes
	std::cout << "\n\nTry to set the element with index 2 of arr3:\n";
	arr3.SetElement(p2, 2);
	std::cout << "Try to get the element with index 2 of arr3:\n";
	arr3.GetElement(2);
	// arr3.GetElement(-1);

	// Test Assignment operator
	std::cout << "\n\nAssign arr3 to arr2 using assignment operator.\n";
	std::cout << "After arr2 = arr3,\narr2:\n";
	arr2 = arr3;
	for (int i = 0; i < arr2.Size(); i++)
		std::cout << arr2[i] << " ";
	
	// Test if arr1 is changed after arr2 = arr2
	// If not, it proves the copy constructor performs deep copy
	std::cout << "\narr1:\n";
	for (int i = 0; i < arr1.Size(); i++)
		std::cout << arr1[i] << " ";

	// Test the [] operator on a const Array object and copy constructor
	std::cout << "\n\nCreate a const Array arr4 by copying arr3 and access the data member using [].\n";
	const Array arr4(arr3);
	std::cout << "arr4[0]: " << arr4[0] << std::endl;
	std::cout << "arr4[1]: " << arr4[1] << std::endl;

	return 0;
}