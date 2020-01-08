// Functor.hpp
// Author: Minghan Li
// This header file contains the implementation for the functor class called SmallerThan
// The class has one private data memeber bound, which will be used in the overloaded operator
// () to be used in count_if algorithm in the test program
#ifndef Functor_Hpp
#define Functor_Hpp

template <typename T>
class SmallerThan
{
private:
	T bound;	// Stores the value to which the function object compares the given values

public:

	// Consturctors and Destructors
	SmallerThan();	// Default constructor
	SmallerThan(const T& input_bound);  // Constructor that accepts an inputed value
	SmallerThan(const SmallerThan<T>& source);  // Copy constructor
	~SmallerThan();

	// Operators
	SmallerThan<T>& operator = (const SmallerThan<T>& source);  // Assignment operator
	bool operator () (const T& value) const;	// () operator overloading in order to perferm the function comparison as a functor
};

// Included to let the main program only include hpp file.
#ifndef Functor_Cpp
#include "Functor.cpp"
#endif


#endif