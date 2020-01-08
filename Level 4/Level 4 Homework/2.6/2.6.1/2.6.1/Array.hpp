// Array.hpp
// Author: Minghan Li
// This header files contains class declaration for the Array class

#ifndef Array_Hpp
#define Array_Hpp

#include <iostream>
#include "Point.hpp"

namespace MinghanLi
{
	namespace Containers
	{
		class Array
		{
			// Data members
		private:
			CAD::Point* m_data;	// Dynamic C array of Point objects
			int m_size;		// Size of the array

		public:
			// Constructors and Destructor
			Array();	// Default constructor
			Array(int size);	// Constructor with size as input
			Array(const Array& arr);	// Copy constructor with Array as input
			~Array();		// Destructor

			// Operators
			Array& operator = (const Array& arr);
			CAD::Point& operator [] (int index);

			const CAD::Point& operator [] (int index) const;

			// Member functions
			int Size() const;	// Return the size of the Array
			void SetElement(const CAD::Point& p, int index);		// Set the individual elements of the Array using the index
			const CAD::Point& GetElement(int index) const;		// Get the individual elements of the Array using the index
		};

	}
}


#endif

