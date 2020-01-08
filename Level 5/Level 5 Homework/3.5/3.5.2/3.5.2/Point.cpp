// Point.cpp
// Author: Minghan Li
// This file contains the implementation of member functions, constructor, and destructor for the Point class.
// Modification dates:
// 9-12-2019

#include <iostream>
#include <sstream>
#include <cmath>
#include "Point.hpp"

namespace MinghanLi
{
	namespace CAD
	{
		// Constructor
		Point::Point() : Shape(), m_x(0.0), m_y(0.0)  // Colon syntax: initialize both x and y to be 0
		{
			
			// std::cout << "A point is constructed!\n";
		}

		// New constructor using x and y coordinates inputs
		Point::Point(double x, double y) : Shape(), m_x(x), m_y(y)
		{
			// std::cout << "A point is constructed using new constructor!\n";
		}

		// Destructor
		Point::~Point()
		{
			// std::cout << "\nBye, my point!";
		}

		// Copy Constructor ( Colon syntax )
		Point::Point(const Point& pt) : Shape(pt), m_x(pt.m_x), m_y(pt.m_y)
		{
			// std::cout << "\nA point is constructed using copy constructor here!";
		}

		// X Setter
		// Modify data stored in m_x
		void Point::X(double ix)
		{
			m_x = ix;
		}

		// Y Setter
		// Modify data stored in m_y
		void Point::Y(double iy)
		{
			m_y = iy;
		}

		// Y Getter
		// Return data stored in m_y
		double Point::Y() const
		{
			return m_y;
		}

		// X Getter
		// Return data stored in m_x
		double Point::X() const
		{
			return m_x;
		}

		std::string Point::ToString() const
		{
			// Create a stringstream to capture the string's components
			std::stringstream sstream;
			
			// String s by calling ToString() of base class
			std::string s = Shape::ToString();
			
			// Attach s to the begining of the description
			sstream << s << ", Point(" << m_x << ", " << m_y << ")";

			return sstream.str(); // Retrieving the string from the string buffer 
		}

		// Calculate the distance to the origin (0, 0)
		double Point::Distance() const
		{
			return sqrt(m_x * m_x + m_y * m_y);  // Pythagoras algorithm
		}

		// Calculate the distance between two points
		double Point::Distance(const Point& p) const
		{
			// Using Pythagoras algorithm: distance = (x^2 + y^2)^(1/2)
			return (sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y)));
		}

		Point Point::operator - () const				// Negate the coordinates.
		{
			return Point(-m_x, -m_y);
		}

		Point Point::operator * (double factor) const		// Scale the coordinates.
		{
			return Point(m_x * factor, m_y * factor);
		}

		Point Point::operator + (const Point& p) const	// Add coordinates.
		{
			return Point(m_x + p.m_x, m_y + p.m_y);
		}

		bool Point::operator == (const Point& p) const	// Equally compare operator.
		{
			// This function compares whether the x and y are the same for the two Point objects
			return (m_x == p.m_x) && (m_y == p.m_y);
		}

		Point& Point::operator = (const Point& source)	// Assignment operator.
		{
			// Self-assginment prevention
			// this pointer should be equal to the address of the input if input is the object itself
			if (this == &source)
				std::cout << "You can not perform self assignment! Please try again.\n";
			else
			{
				// Copy the shape data by calling assignment operator of base class, test using this pointer
				Shape:: operator = (source);

				// Assign the x and y values of input otherwise
				m_x = source.m_x;
				m_y = source.m_y;

			}

			return *this;	// Return this object to make possible chain operations
		}

		Point& Point::operator *= (double factor)		// Scale the coordinates & assign.
		{
			m_x *= factor;
			m_y *= factor;	// Element-wise multiplication

			return *this;
		}

		// << operator overloading
		// No longer need to make use of ToString function of Point Class
		// Friend class can assess data of p directly
		std::ostream& operator << (std::ostream& os, const Point& p)
		{
			os << "Point(" << p.m_x << ", " << p.m_y << ")";
			return os;
		}
	}
}