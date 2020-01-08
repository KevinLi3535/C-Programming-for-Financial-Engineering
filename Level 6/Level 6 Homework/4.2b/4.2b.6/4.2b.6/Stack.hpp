// Stack.hpp
// Author: Minghan Li
// Modification dates:
// 9-17-2019
// This source files contains class declaraton for the Stack class, which delegates
// the storage of elements to Array class. Stack class has two memeber functions,  for
// assigning and accessing elements in the stack. Push() adds an object to the top of the
// stack, while Pop() returns the object on the top of the stack, which will no longer
// be a member of the stack.

#ifndef Stack_Hpp
#define Stack_Hpp

// Preprocessor Directives
#include "Array.hpp"
#include <iostream>
#include <sstream>

namespace MinghanLi
{
	namespace Containers
	{
		template <typename T, unsigned int size>
		class Stack
		{
		private:
			int m_current;	// The current position
			Array<T> m_array;	// Arreay serving as a storage

		public:
			// Constructors and Destructor
			Stack();	// Default constructor
			Stack(const Stack<T, size>& source);	// Copy constructor with Array as input
			~Stack();		// Destructor

			// Operators
			Stack <T, size>& operator= (const Stack<T, size>& source);

			// Member functions
			// Add a Pop() function that decrements the current position and then returns the element at that position.
			T Pop();
			
			// It should store the element at the current position in theembedded array. Increment the current position afterwards.
			void Push(const T& new_ele);
		};
	}
}

#ifndef Stack_Cpp
#include "Stack.cpp"
#endif


#endif