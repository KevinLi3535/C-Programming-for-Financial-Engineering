// Point.cpp
// Author: Minghan Li
// This file contains the implementation of member functions, constructor, and destructor.
// Modification dates:
// 9-6-2019
// This version added a copy constructor declaration and a new constructor that takes
// x and y coordinates as inputs.

#include <iostream>
#include <sstream>
#include <cmath>
#include "Point.hpp"

// Constructor
Point::Point() : m_x(0.0), m_y(0.0)  // Colon syntax: initialize both x and y to be 0
{
	std::cout << "A point is constructed!\n";
}

// New constructor using x and y coordinates inputs
Point::Point(double x, double y) : m_x(x), m_y(y) 
{
	std::cout << "A point is constructed using new constructor!\n";
}

// Destructor
Point::~Point() 
{
	std::cout << "\nBye, my point!";
} 

// Copy Constructor ( Colon syntax )
Point::Point(const Point& pt) : m_x(pt.m_x), m_y(pt.m_y)
{
	std::cout << "\nA point is constructed using copy constructor here!";
}

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

// Calculate the distance to the origin (0, 0)
double Point::DistanceOrigin()
{
	return sqrt(m_x*m_x + m_y*m_y);  // Pythagoras algorithm
}

// Calculate the distance between two points
double Point::Distance(Point p)
{
	// Using Pythagoras algorithm: distance = (x^2 + y^2)^(1/2)
	return (sqrt((m_x - p.m_x)*(m_x - p.m_x) + (m_y - p.m_y)*(m_y - p.m_y)));
}