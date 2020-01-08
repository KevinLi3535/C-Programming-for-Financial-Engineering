// Array.hpp
// Author: Minghan Li
// This header files contains class declaration for 
// the Array class, ArrayException class, and OutOfBondsException class.
// This header file also contains implementation for 
// Array Exception class and OutOfBondsException class for simlicity.
// In this version, we added a static variable indicating the default size
// used in the default constructor.

#ifndef Array_Hpp
#define Array_Hpp

#include <iostream>
#include <sstream>
#include "Point.hpp"

namespace MinghanLi
{
	namespace Containers
	{
		template <typename T>
		class Array
		{
			// Data members
		private:
			T* m_data;	// Dynamic C array of generic type T objects
			int m_size;		// Size of the array
			static unsigned int m_default_size;	// static data member indicating default size, which is non-negative

		public:
			// Constructors and Destructor
			Array();	// Default constructor
			Array(unsigned int size);	// Constructor with size as input
			Array(const Array<T>& arr);	// Copy constructor with Array as input
			~Array();		// Destructor

			// Getter for default size
			// Static member functions have a class scope and 
			// they do not have access to the this pointer of the class;
			// therefore, the getter for default size cannot be declared const
			static unsigned int DefaultSize();

			// Setter for default size
			static void DefaultSize(unsigned int size);

			// Operators
			Array<T>& operator = (const Array<T>& arr);
			T& operator [] (int index);
			const T& operator [] (int index) const;

			// Member functions
			int Size() const;	// Return the size of the Array
			void SetElement(const T& p, int index);		// Set the individual elements of the Array using the index
			const T& GetElement(int index) const;		// Get the individual elements of the Array using the index
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

// The codes below are included so that the client can keep including the header file 
// for template classes instead of the source file.
// Reason: 
// These preprocessor directives look for the inclusion of Arrap_Cpp,
// and if Array.cpp has not been included yet, include its codes following
// the class declaration of Array in Array.hpp.
// This way, we don't need to include the source file, since its code is included
// in the header file. Multiple inclusion is also avoided.

#ifndef Array_Cpp
#include "Array.cpp"
#endif

#endif