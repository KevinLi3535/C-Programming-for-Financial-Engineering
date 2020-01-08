// 2.5.2.cpp
// Author: Minghan Li
// Create an array of pointers to the Point class following the steps below:
// 1. Create an array of Point pointers with 3 elements on the heap.
// 2. Create for each element in the array a point on the heap.
// 3. Iterate the arrayand print each point in the array.
// 4. Iterate the array againand delete each point in the array.
// 5. Delete the array itself.

#include <iostream>
#include "Point.hpp"

int main()
{
	// Create an integer for the array size to avoid hard coding
	int arr_size = 3;

	// Create an array of Point pointers
	Point** point_arr = new Point* [arr_size];

	if (point_arr == nullptr)
		std::cout << "No memory is avaiable.";
	else
	{
		// Create for each element in the array a point on the heap
		// The coordinates numbers are completely arbitrary
		point_arr[0] = new Point(10.0, 20.0);
		point_arr[1] = new Point(30.0, 12.0);
		point_arr[2] = new Point(13.0, 14.0);

		// Iterate the array and print each point in the array
		for (int i = 0; i < arr_size; i++)
			std::cout << *point_arr[i] << " ";

		std::cout << std::endl;

		// Iterate the array again and delete each point in the array
		for (int j = 0; j < arr_size; j++)
			delete point_arr[j];

		// Delete the array itself
		delete[] point_arr;
	}

	return 0;
}