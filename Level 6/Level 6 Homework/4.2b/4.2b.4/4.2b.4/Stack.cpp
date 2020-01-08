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
#include <iostream>
using namespace std;

namespace MinghanLi
{
	namespace Containers
	{
		// Constructors and Destructor
		// Default constructor
		template <typename T>
		Stack<T>::Stack() : m_array(), m_current(0)
		{
			// cout << "Default constructor of Stack is called." << endl;
		}

		// Constructor with size as input
		template <typename T>
		Stack<T>::Stack(unsigned int size) : m_array(size), m_current(0)
		{
			// cout << "Constructor of Stack with size is called." << endl;
		}

		// Copy constructor with Array as input
		template <typename T>
		Stack<T>::Stack(const Stack<T>& source) : m_array(Array(source)), m_current(source.m_current)
		{
			// cout << "Copy constructor of Stack is called." << endl;
		}

		// Destructor
		template <typename T>
		Stack<T>::~Stack()
		{
			// std::cout << "Destructor of Stack is called." << std::endl;
		};

		template <typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& source)
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
		template<typename T>
		void Stack<T>::Push(const T& new_ele)
		{
			m_array[m_current] = new_ele;
			m_current++;
		}

		// LIFO principle, pop out the elements on top of the stack
		// Make sure the current index is not changed when the Array class throws an exception
		template<typename T>
		T Stack<T>::Pop()
		{
			// I don't think this is the logical trick, but it does do the job.
			// May I ask what the logical trick it for this one?

			// We get the object stored in the previous index, which is the object we just pushed in.
			// If m_current = 0, the line below should throw an exception already, and the later code, 
			// m_current -- , will not be executed, and m_current will stay 0 until some object is pushed.
			T result = m_array[m_current - 1];
			m_current--;
			return result;
		}
	}
	
}

#endif