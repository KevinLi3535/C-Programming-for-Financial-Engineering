// NumericArray.cpp
// Author: Minghan Li
// Modification dates:
// 9-16-2019
// This source files contains class implementation for the NumericArray class, a derived
// class from Array class with additional operators to support numerical operations.

#ifndef NumericArray_Cpp
#define NumericArray_Cpp

#include "NumericArray.hpp"
#include <iostream>
using namespace std;

namespace MinghanLi
{
	namespace Containers
	{
		// Constructors and Destructor
		// Default constructor
		template <typename T>
		NumericArray<T>::NumericArray(): Array<T> ()
		{
			// cout << "Default constructor of NumericArray is called." << endl;
		}

		// Constructor with size as input
		template <typename T>
		NumericArray<T>::NumericArray(unsigned int size) : Array<T> (size)
		{
			// cout << "Constructor of NumericArray with size is called." << endl;
		}

		// Copy constructor with Array as input
		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& arr) : Array<T>(arr)
		{
			// cout << "Copy constructor of NumericArray is called." << endl;
		}

		// Destructor
		template <typename T>
		NumericArray<T>::~NumericArray() 
		{
			// std::cout << "Destructor of NumericArray is called." << std::endl;
		};

		// Operators added
		template <typename T>
		NumericArray<T> NumericArray<T>:: operator +  (const NumericArray<T>& numeric_arr) const
		{
			// Check if the size of two arrays are equal
			if (this->Size() != numeric_arr.Size())
				throw UnequalSizeException();
			else
			{
				// Create a new numeric array with same size as the original array
				NumericArray<T> NewArray(numeric_arr);
				
				// Iterate throught the two arrays and assign the sum 
				// to corresponding element in the NewArray.
				for (int i = 0; i < this-> Size(); i++)
					NewArray[i] += (*this)[i];
				
				return NewArray;
			}
		}

		template <typename T>
		NumericArray<T> NumericArray<T>::operator *  (T c) const
		{
			// Create a new numeric array by copying the original array
			NumericArray<T> NewArray(*this);

			// Iterate throught the two arrays and assign the product 
			// to corresponding element in the NewArray.
			for (int i = 0; i < this->Size();i++)
				NewArray[i] *= c;

			return NewArray;
		}
		
		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
		{
			if (this == &source)
				std::cout << "You can not perform self assignment! Please try again.\n";
			else
				Array:: operator = (source);	// Call the assignment operator of the base class

			// Return *this to allow chain assginment
			return *this;
		}

		// DotProduction function
		template <typename T>
		T NumericArray<T>::DotProduct(const NumericArray<T>& numeric_arr)
		{
			// Check if the size of two arrays are equal
			if (this->Size() != numeric_arr.Size())
				throw UnequalSizeException();
			else
			{
				// Initialize result to be zero
				T result (0);

				// Iterate throught the two arrays and add the product 
				// to result element that is eventually returned.
				for (int i = 0; i < this->Size();i++)
					result += ((*this)[i] * numeric_arr[i]);

				return result;
			}
		}
	}
}




#endif