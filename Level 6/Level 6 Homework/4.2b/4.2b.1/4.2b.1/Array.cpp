// Array.hpp
// Author: Minghan Li
// This cpp files contains implementation for the Array class
// Modification dates:
// 9-15-2019
// In this version, we added a static variable indicating the default size
// used in the default constructor.

#ifndef Array_Cpp
#define Array_Cpp

#include "Array.hpp"
#include <iostream>

using MinghanLi::CAD::Point;
using namespace std;

namespace MinghanLi
{
	namespace Containers
	{

		// Constructors and Destructor
		template <typename T>
		Array<T>::Array() : m_size(m_default_size), m_data(new T[m_default_size])	// Default constructor
		{
			if (m_data == nullptr)
				std::cout << "No memory is available." << std::endl;
			/*else
				std::cout << "Default constructor is called." << std::endl;*/
		}

		// Constructor with size as argument
		template <typename T>
		Array<T>::Array(unsigned int size) :m_size(size), m_data(new T[size])
		{
			if (m_data == nullptr)
				std::cout << "No memory is available." << std::endl;
			/*else
				std::cout << "Constructor with size is called." << std::endl;*/
		}

		// Copy constructor with Array as input
		// Manually get the features of the Arr object input
		template <typename T>
		Array<T>::Array(const Array<T>& arr) : m_size(arr.m_size), m_data(new T[arr.m_size])
		{
			if (m_data == nullptr)
				std::cout << "No memory is available." << std::endl;
			else
			{
				// Iterate through the input Array and copy each element individually
				for (int i = 0; i < m_size; i++)
					m_data[i] = arr.m_data[i];
			}

			// std::cout << "Copy constructor is called." << std::endl;
		}

		template <typename T>
		Array<T>::~Array()		// Destructor
		{
			// Delete the m_data array allocated on the heap
			delete[] m_data;
			std::cout << "Destructor is called." << std::endl;
		}

		// Initialize m_default_size to 10
		template <typename T>
		unsigned int Array<T>::m_default_size = 10;

		// Getter for default size

		template <typename T>
		unsigned int Array<T>::DefaultSize()
		{
			return m_default_size;
		}

		// Setter for default size
		template <typename T>
		void Array<T>:: DefaultSize(unsigned int size)
		{
			m_default_size = size;
		}

		// Operators
		// Assignment operator
		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& arr)
		{
			if (this == &arr)
				std::cout << "Please don't perform self assignment. Try again!" << std::endl;
			else
			{
				// Delete the original m_data in case the new Array has a different size
				delete[] m_data;

				// Perform the same task as copy constuctor
				// Manually get the features of the Arry object input
				m_size = arr.m_size;
				m_data = new T[arr.m_size];

				if (m_data == nullptr)
					std::cout << "No memory is available." << std::endl;
				else
				{
					// Iterate through the input Array and copy each element individually
					for (int i = 0; i < m_size; i++)
						m_data[i] = arr.m_data[i];
				}
			}

			// Returns a reference to enable chain assignment
			return *this;
		}

		template <typename T>
		T& Array<T>::operator [] (int index)
		{
			// Check to make sure index number isn't out of bounds
			if (index >= m_size || index < 0)
				throw OutOfBoundsException(index);
			else
				return m_data[index];
		}

		template <typename T>
		const T& Array<T>::operator [] (int index) const
		{
			// Check to make sure index number isn't out of bounds
			if (index >= m_size || index < 0)
				throw OutOfBoundsException(index);
			else
				return m_data[index];
		}

		// Member functions
		// Size () return the size of the Array
		template <typename T>
		int Array<T>::Size() const
		{
			return m_size;
		}

		// The setter function according to the index provided
		template <typename T>
		void Array<T>::SetElement(const T& p, int index)
		{
			if (index >= m_size || index < 0)
				throw OutOfBoundsException(index);
			else
				(*this).m_data[index] = p;
		}

		// The getter function accoriding to the index provided
		template <typename T>
		const T& Array<T>::GetElement(int index) const
		{
			if (index >= m_size || index < 0)
				throw OutOfBoundsException(index);
			else
				return m_data[index];
		}

	}
}

#endif