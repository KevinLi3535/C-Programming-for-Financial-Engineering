// 2.5.1.cpp
// Author: Minghan Li
// Create Points on the heap and call Distance function
// Create an array of Point objects on the heap

#include <iostream>
#include "Point.hpp"

int main()
{
	std::cout << "Create Point object called p1 on the heap using the default constructor:" << std::endl;
	Point* p1 = new Point;  // Create using default constructor					
	
	// Check if the memory is available
	// If not, p1 returns NULL, same for p2, p3
	if (p1 == nullptr)
		std::cout << "No memory is available.";
	else
		std::cout <<"p1: "<< *p1 << std::endl;

	std::cout << "Create Point object called p2 on the heap using constructor with coordinates:" << std::endl;
	Point* p2 = new Point(15.0, 20.5);	// Create using constructor with coordinates
	if (p2 == nullptr)
		std::cout << "No memory is available.";
	else
		std::cout << "p2: " << *p2 << std::endl;

	std::cout << "Create Point object called p3 on the heap using constructor with coordinates:" << std::endl;
	Point* p3 = new Point(-2.0, 10.0);	// Create using constructor with coordinates
	if (p3 == nullptr)
		std::cout << "No memory is available.";
	else
		std::cout << "p3: " << *p3 << std::endl;
	
	std::cout << "Create Point object called p4 on the heap using copy constructor with p2" << std::endl;
	Point* p4 = new Point(*p2);  // Using copy constructor 
	if (p4 == nullptr)
		std::cout << "No memory is available.";
	else
		std::cout << "p4: " << *p4 << std::endl;

	// Call the Distance function on the pointers
	std::cout << std::endl << "Distance between p2 and p3: " << (*p2).Distance(*p3) << std::endl;
	std::cout << "Distance between p4 and p1: " << (*p4).Distance(*p1) << std::endl;

	// Delete the Point objects on the heap
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	// Prompt the user to enter the array size
	int arr_size;
	std::cout << std::endl << "Please enter size of array of points: ";
	std::cin >> arr_size;

	// Point arr[arr_size]; This line gives a compiler error
	// Arrays on the stack must have the size set at compile time
	
	// Create an array of points on the heap
	Point* point_arr = new Point[arr_size];

	// Check and take a look at the array
	if (point_arr == nullptr)
		std::cout << "No memory is available.";
	else
	{
		std::cout << std::endl << "Let's take a look at the array of points we created:\n";
		
		// Run a for loop through the array and print out its content
		for (int i = 0; i < arr_size; i++)
			std::cout << point_arr[i] << " ";

		// Delete the array of points on the heap if point_arr is not NULL
		delete[] point_arr;
	}

	return 0;
}