// Shape.cpp
// Author: Minghan Li
// This file contains the implementation of Shape class
// Modification dates:
// 9-12-2019

#include <iostream>
#include <sstream>
#include "stdlib.h"
#include "Shape.hpp"

namespace MinghanLi
{
	namespace CAD
	{
		// Default constructor
		Shape::Shape() : m_id(rand())
		{
			// std::cout << "A Shape is constructed using default constructor!\n";
		}

		// Copy constructor
		Shape::Shape(const Shape& sp) : m_id(sp.m_id)
		{
			// std::cout<< "A Shape is constructed using copy constructor!\n";
		}

		// Destructor
		Shape::~Shape()
		{
			std::cout << "\nBye, my Shape!";
		}

		// Assignment operator
		Shape& Shape::operator = (const Shape& source)
		{
			// Self-assginment prevention
			// this pointer should be equal to the address of the input if input is the object itself
			if (this == &source)
				std::cout << "You can not perform self assignment! Please try again.\n";
			else
				m_id = source.m_id;

			return *this;	// Return this object to make possible chain operations
		}

		// Member functions
		// Getter function
		int Shape::ID() const
		{
			return m_id;
		}

		std::string Shape::ToString() const	// ID string
		{
			// Print the id of the shape
			std::stringstream ss;
			ss << "ID:" << m_id ;

			return ss.str();
		}
	}

}