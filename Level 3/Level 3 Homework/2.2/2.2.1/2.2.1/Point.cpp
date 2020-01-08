// Point.cpp
// Author: Minghan Li
// This file contains the implementation of member functions, constructor, and destructor.
// Modification dates:
// 9-5-2019

#include <iostream>
#include <sstream>

#include "Point.hpp"

// Constructor
Point::Point() 
{
	m_x = 0.0;
	m_y = 0.0;  // initialize both x and y to be 0
}

// Destructor
Point::~Point() {} // destructor has nothing else to do

// X Setter
// Modify data stored in m_x
void Point::SetX(double ix)
{
	m_x = ix;
}

// Y Setter
// Modify data stored in m_y
void Point::SetY(double iy)
{
	m_y = iy;
}

// Y Getter
// Return data stored in m_y
double Point::GetY()
{
	return m_y;
}

// X Getter
// Return data stored in m_x
double Point::GetX()
{
	return m_x;
}


std::string Point::ToString()
{
	// Create a stringstream to capture the string's components
	std::stringstream sstream;

	sstream << "Point(" << m_x << ", " << m_y << ")";

	return sstream.str(); // Retrieving the string from the string buffer 
}
