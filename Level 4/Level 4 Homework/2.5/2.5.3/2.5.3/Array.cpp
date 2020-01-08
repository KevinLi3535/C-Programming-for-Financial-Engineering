// Array.hpp
// Author: Minghan Li
// This cpp files contains implementation for the Array class
// Modification dates:
// 9-9-2019

#include "Array.hpp"
#include <iostream>
// Constructors and Destructor
Array::Array() : m_size(10), m_data(new Point[10])	// Default constructor
{
	if (m_data == nullptr)
		std::cout << "No memory is available." << std::endl;
	/*else
		std::cout << "Default constructor is called." << std::endl;*/
}

Array::Array(int size) :m_size(size), m_data(new Point[size])	// Constructor with size as input
{
	if (m_data == nullptr)
		std::cout << "No memory is available." << std::endl;
	/*else
		std::cout << "Constructor with size is called." << std::endl;*/
}

// Copy constructor with Array as input
// Manually get the features of the Arr object input
Array::Array(const Array& arr): m_size(arr.m_size), m_data(new Point[arr.m_size])
{
	if (m_data == nullptr)
		std::cout << "No memory is available." << std::endl;
	else
	{
		// Iterate through the input Array and copy each element individually
		for (int i = 0; i < m_size; i++)
			m_data[i] = arr.m_data[i];
	}

	// std::cout << "Copy constructor is called." << std::endl;
}

Array::~Array()		// Destructor
{
	// Delete the m_data array allocated on the heap
	delete[] m_data;
	std::cout << "Destructor is called." << std::endl;
}

// Operators
// Assignment operator
Array& Array::operator = (const Array& arr)
{
	if (this == &arr)
		std::cout << "Please don't perform self assignment. Try again!" << std::endl;
	else
	{
		// Delete the original m_data in case the new Array has a different size
		delete[] m_data;

		// Perform the same task as copy constuctor
		// Manually get the features of the Arry object input
		m_size = arr.m_size;
		m_data = new Point[arr.m_size];
		
		if (m_data == nullptr)
			std::cout << "No memory is available." << std::endl;
		else
		{
			// Iterate through the input Array and copy each element individually
			for (int i = 0; i < m_size; i++)
				m_data[i] = arr.m_data[i];
		}
	}

	// Returns a reference to enable chain assignment
	return *this;
}

Point& Array::operator [] (int index)
{
	// Check to make sure index number isn't out of bounds
	if (index >= m_size || index < 0 )
	{
		std::cout << "The index is out of bounds. The first element is returned. Try again!" << std::endl;
		return m_data[0];
	}
	else
		return m_data[index];
}

// Reason for including this const version of operator []:
// Normally when we have an Array object of points, we can modify the elements
// using the arr[index] method, which returns a reference.
// However, we also may have cases where we construct a const Array or 
// an Array of const Point objects, which can not be modified. In this case, the compiler does not know 
// if it is safe to return a reference, since a reference can modify the Point object
// the [] operator would not work in this case. We added a const in front to specify 
// a const reference as the return type so that the compiler knows it would not 
// modify the object. Since we can not modify the data member any more, we should also
// speficy the function as const to avoid naming conflict with original operator[] declaration.

const Point& Array::operator [] (int index) const
{
	// Check to make sure index number isn't out of bounds
	if (index >= m_size || index < 0)
	{
		std::cout << "The index is out of bounds. The first element is returned. Try again!" << std::endl;
		return m_data[0];
	}
	else
		return m_data[index];
}

// Member functions
// Size () return the size of the Array
int Array::Size() const
{
	return m_size;
}

// The setter function according to the index provided
void Array::SetElement(const Point& p, int index)
{
	if (index >= m_size || index < 0)
		std::cout << "The index is out of bounds. The Setter is ignored. Try again!" << std::endl;
	else
		(*this).m_data[index] = p;
}

// The getter function accoriding to the index provided
const Point& Array::GetElement(int index) const
{
	if (index >= m_size || index < 0)
		std::cout << "The index is out of bounds. The first element is returned. Try again!";
	else
		return m_data[index];
}