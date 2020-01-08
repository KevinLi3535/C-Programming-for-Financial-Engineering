// Functor.cpp
// Author: Minghan Li
// Modification Date:
// 9/21/2019
// This source file contains the implementation for the functor class called SmallerThan
// The class has one private data memeber bound, which will be used in the overloaded operator
// () to be used in count_if algorithm in the test program
#ifndef Functor_Cpp
#define Functor_Cpp

#include "Functor.hpp"

// Consturctors and Destructors
template <typename T>
SmallerThan<T>::SmallerThan() : bound(0) {}	// Default constructor

template <typename T>
SmallerThan<T>::SmallerThan(const T& input_bound) : bound(input_bound) {}  // Constructor that accepts an inputed value

template <typename T>
SmallerThan<T>::SmallerThan(const SmallerThan<T>& source) : bound(source.bound) {} // Copy constructor

template <typename T>
SmallerThan<T>::~SmallerThan() {}	// Destructor

// Operators
template <typename T>
SmallerThan<T>& SmallerThan<T>::operator = (const SmallerThan<T>& source)  // Assignment operator
{
	if (this == &source)
		std::cout << "You can not perform self assignment! Please try again.\n";
	else
		bound = source.bound;

	return *this;

}

// Overloaded operator ()
// Used in count_if algorithm in the test program
template <typename T>
bool SmallerThan<T>::operator () (const T& value) const	// () operator overloading in order to perferm the function as a functor
{
	return value < bound;
}

#endif