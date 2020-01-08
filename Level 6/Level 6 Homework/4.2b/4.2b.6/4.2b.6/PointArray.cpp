// PointArray.cpp
// Author: Minghan Li
// Modification dates:
// 9-16-2019
// This source files contains class implementation for the PointArray class, a derived
// class of Array<Point> class. A member function Length() is added to calculate
// the total length between the points in the array.

#ifndef PointArray_Cpp
#define PointArray_Cpp

#include <iostream>
#include "PointArray.hpp"
#include "Array.hpp"

namespace MinghanLi
{
	namespace Containers
	{
		// Default constructor
		PointArray::PointArray() : Array()
		{
			// cout << "Default constructor of PointArray is called." << endl;
		}

		// Constructor with size as input
		PointArray::PointArray(unsigned int size) : Array(size)
		{
			// cout << "Constructor of PointArray with size is called." << endl;
		}

		// Copy constructor with Array as input
		PointArray::PointArray(const PointArray& arr) : Array(arr)
		{
			// cout << "Copy constructor of PointArray is called." << endl;
		}

		// Destructor
		PointArray::~PointArray()
		{
			// std::cout << "Destructor of PointArray is called." << std::endl;
		};

		// Assignment Operator =
		PointArray& PointArray::operator = (const PointArray& source)
		{
			if (this == &source)
				std::cout << "You can not perform self assignment! Please try again.\n";
			else
				Array<Point>:: operator = (source);	// Call bases class assignment operator

			// Return *this to allow chain assginment
			return *this;
		}

		double PointArray::Length() const
		{
			double result = 0.0;

			if (this->Size() == 0)
			{
				// If there is not Point in the array, we need to inform the user.
				// We distinguish this case from an array with two Point objects with same coordinates.
				cout << "This is no Point object in the PointArray" << endl;
			}
			else if (this->Size() == 1)
			{
				// If there is only one Point object in the array, we need to inform the user.
				// We distinguish this case from an array with two Point objects with same coordinates.
				cout << "This is only one Point object in the PointArray" << endl;
			}
			else
			{
				for (int i = 0; i < (this->Size() - 1); i++)
					result += (*this)[i].Distance((*this)[i + 1]);
			}

			return result;
		}
	}
}
#endif