// Array.hpp
// Author: Minghan Li
// This header files contains class declaration for 
// the Array class, ArrayException class, and OutOfBondsException class.
// This header file also contains implementation for 
// Array Exception class and OutOfBondsException class for simlicity.

#ifndef Array_Hpp
#define Array_Hpp

#include <iostream>
#include <sstream>
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

		// Exception hierarchy implementation
		// Abstract Class/ Interface
		class ArrayException
		{
		public:
			// Superordinate class
			// Following the principle of classes to create these four items.
			// Constructor, Copy constuctor, Assignment operator, Destructor
			ArrayException() {};
			ArrayException(const ArrayException& source) {};
			ArrayException& operator = (const ArrayException& source) { return *this; };
			virtual ~ArrayException() {};

			// Memeber function
			// GetMessage is a abstract function, and needs inplementation by its derived class
			virtual std::string GetMessage() const =0;
		};

		// Derived class
		class OutOfBoundsException : public ArrayException
		{
		private:
			// Stores the given index number
			int m_index;

		public:
			// For completing the principle of classes
			// Constructors and Destructor
			OutOfBoundsException() : ArrayException(), m_index(0) {};

			// The Constructor that that takes in an int as argument which indicates the 
			// erroneous array index and store it in a data member
			OutOfBoundsException(int index) : ArrayException(), m_index(index) {};
			OutOfBoundsException(const OutOfBoundsException& source) : ArrayException(source), m_index(source.m_index) {};
			OutOfBoundsException& operator =(const OutOfBoundsException& source)
			{
				// Avoid self-assignment
				if (this == &source)
					std::cout << "You can not perform self assignment! Please try again.\n";
				else
				{
					m_index = source.m_index;
					ArrayException::operator = (source);
				}

				return *this;
			}

			~OutOfBoundsException() {};

			// Overwritten GetMessage() function
			// Return a string with description that the given index is out of bounds.
			std::string GetMessage() const
			{
				std::stringstream ss;

				ss << "Index " << m_index << " is out of bounds.";

				return ss.str();
			}
		};

	}
}

#endif