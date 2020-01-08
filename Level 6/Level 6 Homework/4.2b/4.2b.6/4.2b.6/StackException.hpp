// Stack.hpp
// Author: Minghan Li
// This header files contains class declarations and implementations for StackException class
// and two derived classes from it, StackFullException class and StackEmptyException
// class. There are exception classes that are thrown inside Pop and Push functions.
// The class implementations are in this file for simplicity.

#ifndef StackException_Hpp
#define StackException_Hpp

#include <iostream>
#include <sstream>
#include "Point.hpp"

using namespace std;

namespace MinghanLi
{
	namespace Containers
	{
		class StackException
		{
		public:
			// Superordinate class
			// Following the principle of classes to create these four items.
			// Constructor, Copy constuctor, Assignment operator, Destructor
			StackException() {};
			StackException(const StackException& source) {};
			StackException& operator = (const StackException& source) { return *this; };
			virtual ~StackException() {};

			// Memeber function
			// GetMessage is a abstract function, and needs inplementation by its derived class
			virtual std::string GetMessage() const = 0;
		};

		// Derived class StackFullException
		// Indicating the Stack is full
		class StackFullException : public StackException
		{
		public:
			// For completing the principle of classes
			// Constructors and Destructor
			StackFullException() : StackException() {};
			StackFullException(const StackFullException& source) : StackException(source) {};
			~StackFullException() {};

			// Assignment operator
			StackFullException& operator =(const StackFullException& source)
			{
				// Avoid self-assignment
				if (this == &source)
					std::cout << "You can not perform self assignment! Please try again.\n";
				else
					StackException::operator = (source);

				return *this;
			}

			// Overwritten GetMessage() function
			// Return a string with description that the stack is full.
			std::string GetMessage() const
			{
				stringstream ss;

				ss << "The Stack is full!";

				return ss.str();
			}
		};

		// Derived class StackEmptyException
		// Indicating the Stack is empty
		class StackEmptyException : public StackException
		{
		public:
			// For completing the principle of classes
			// Constructors and Destructor
			StackEmptyException() : StackException() {};
			StackEmptyException(const StackEmptyException& source) : StackException(source) {};
			~StackEmptyException() {};

			// Assignment Operator
			StackEmptyException& operator =(const StackEmptyException& source)
			{
				// Avoid self-assignment
				if (this == &source)
					std::cout << "You can not perform self assignment! Please try again.\n";
				else
					StackException::operator = (source);

				return *this;
			}

			// Overwritten GetMessage() function
			// Return a string with description that the stack is empty.
			std::string GetMessage() const
			{
				stringstream ss;

				ss << "The Stack is empty!";

				return ss.str();
			}
		};

	}
}


#endif
