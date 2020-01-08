// Stack.cpp
// Author: Minghan Li
// Modification dates:
// 9-17-2019
// This source files contains class implementation for the Stack class, which delegates
// the storage of elements to Array class. Stack class has two memeber functions,  for
// assigning and accessing elements in the stack. Push() adds an object to the top of the
// stack, while Pop() returns the object on the top of the stack, which will no longer
// be a member of the stack.

#ifndef Stack_Cpp
#define Stack_Cpp

#include "Stack.hpp"
#include "StackException.hpp"
#include <iostream>
using namespace std;

namespace MinghanLi
{
	namespace Containers
	{
		// Constructors and Destructor
		// Default constructor
		template <typename T, unsigned int size>
		Stack<T, size>::Stack() : m_array(Array<T>(size)), m_current(0)
		{
			// cout << "Default constructor of Stack is called." << endl;
		}


		// Copy constructor with Array as input
		template <typename T, unsigned int size>
		Stack<T, size>::Stack(const Stack<T, size>& source) : m_array(Array<T>(source)), m_current(source.m_current)
		{
			// cout << "Copy constructor of Stack is called." << endl;
		}

		// Destructor
		template <typename T, unsigned int size>
		Stack<T, size>::~Stack()
		{
			// std::cout << "Destructor of Stack is called." << std::endl;
		};

		template <typename T, unsigned int size>
		Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source)
		{
			if (this == &source)
				std::cout << "You can not perform self assignment! Please try again.\n";
			else
			{
				m_array = source.m_array;	// Call the assignment operator of Array class
				m_current = source.m_current;
			}

			// Return *this to allow chain assginment
			return *this;
		}

		// Add elements to the top of the stack
		template<typename T, unsigned int size>
		void Stack<T, size>::Push(const T& new_ele)
		{
			try
			{
				m_array[m_current] = new_ele;
				m_current++;
			}
			catch (ArrayException& err)
			{
				// If an ArrayException reference is caught, it must be OutOfBoundException
				// since ArrayException object cannot by itself be initialized.
				// Instead of cout << the message, we throw another StackFullException object.
				throw StackFullException();
			}
			catch (...)
			{
				// Error message for all other types of exceptions
				cout << "An unhandled exception has occurred" << endl;
			}
		}

		// LIFO principle, pop out the elements on top of the stack
		// Make sure the current index is not changed when the Array class throws an exception
		template<typename T, unsigned int size>
		T Stack<T, size>::Pop()
		{
			try
			{
				T result = m_array[m_current - 1];
				m_current--;
				return result;
			}
			catch (ArrayException& err)
			{
				// If an ArrayException reference is caught, it must be OutOfBoundException
				// since ArrayException object cannot by itself be initialized.
				// Instead of cout << the message, we throw another StackEmptyException object.
				throw StackEmptyException();
			}
			catch (...)
			{
				// Error message for all other types of exceptions
				cout << "An unhandled exception has occurred" << endl;
			}
		}
	}
	
}

#endif