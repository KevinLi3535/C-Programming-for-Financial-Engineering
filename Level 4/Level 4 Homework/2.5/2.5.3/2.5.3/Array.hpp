// Array.hpp
// Author: Minghan Li
// This header files contains class declaration for the Array class

#ifndef Array_Hpp
#define Array_Hpp

#include <iostream>
#include "Point.hpp"

class Array
{
	// Data members
private:
	Point* m_data;	// Dynamic C array of Point objects
	int m_size;		// Size of the array

public:
	// Constructors and Destructor
	Array();	// Default constructor
	Array(int size);	// Constructor with size as input
	Array(const Array& arr);	// Copy constructor with Array as input
	~Array();		// Destructor

	// Operators
	Array& operator = (const Array& arr);
	Point& operator [] (int index);

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
	const Point& operator [] (int index) const;

	// Member functions
	int Size() const;	// Return the size of the Array
	void SetElement(const Point& p, int index);		// Set the individual elements of the Array using the index
	const Point& GetElement(int index) const;		// Get the individual elements of the Array using the index
};

#endif

