// NumericArray.hpp
// Author: Minghan Li
// This header files contains class declaration for the NumericArray class, a derived
// class from Array class with additional operators to support numerical operations.
// The file also has class declaration for UnequalSizeException, a derived class
// from ArrayException. It specify a new type of Exception specifying that the 
// two arrays on two sides of + operatro don't have the same size.
// The implementation for UnequalSizeException class is also left in this file.

#ifndef NumericArray_Hpp
#define NumericArray_Hpp

#include "Array.hpp"

#include <iostream>
#include <sstream>

namespace MinghanLi
{
	namespace Containers
	{
		template <typename T>
		class NumericArray : public Array<T>
		{
		public:
			// Constructors and Destructor
			NumericArray();	// Default constructor
			NumericArray(unsigned int size);	// Constructor with size as input
			NumericArray(const NumericArray<T>& arr);	// Copy constructor with Array as input
			~NumericArray();		// Destructor

			// Operators added
			
			NumericArray<T> operator +  (const NumericArray<T>& numeric_arr) const;
			NumericArray<T> operator *  (T c) const;
			NumericArray<T>& operator = (const NumericArray<T>& source);

			// DotProduction function
			T DotProduct(const NumericArray<T>& numeric_arr) const;
		};

		class UnequalSizeException : public ArrayException
		{
		public:
			// Following the principle of classes to create these four items.
			// Constructor, Copy constuctor, Assignment operator, Destructor
			UnequalSizeException() : ArrayException() {};
			UnequalSizeException(const UnequalSizeException& source) : ArrayException(source) {};
			UnequalSizeException& operator = (const UnequalSizeException& source)
			{
				// Avoid self-assignment
				if (this == &source)
					std::cout << "You cannot perform self assignment! Please try again.\n";
				else
					ArrayException::operator = (source);

				return *this;
			}
			
			~UnequalSizeException() {}

			// Memeber function
			// GetMessage is an abstract function, and needs inplementation by its derived class
			std::string GetMessage() const
			{
				stringstream ss;

				ss << "The size of the two Array objects are not equal." << endl;
				return ss.str();
			};

		};
	}
}

#ifndef NumericArray_Cpp
#include "NumericArray.cpp"
#endif

#endif
