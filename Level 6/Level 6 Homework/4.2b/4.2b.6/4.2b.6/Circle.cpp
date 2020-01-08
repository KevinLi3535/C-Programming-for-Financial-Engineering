// Circle.cpp
// Author: Minghan Li
// This file contains the implementation of member functions, constructor, and destructor for the Circle class.
// Modification dates:
// 9-13-2019

// Preproccessor Directives
// This line is added to get MI_PI
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <sstream>
#include "Circle.hpp"
#include "Point.hpp"

namespace MinghanLi
{
	namespace CAD
	{
		Circle::Circle() :Shape(), m_radius(1.0), centre_point(0, 0)	// Default constructor: unit circle
		{
			// std::cout << "A circle is constructed using default constructor!\n";
		}

		Circle::Circle(const double& r, const Point& c) : Shape(), m_radius(r), centre_point(c)
		{
			// std::cout<< "\nA circle is constructed using the two input constructor!";
		}

		Circle::Circle(const Circle& circle_new) : Shape(circle_new), m_radius(circle_new.m_radius), centre_point(circle_new.centre_point)
		{
			// std::cout<< "A circle is constructed using copy constructor!\n";
		}

		Circle::~Circle()
		{
			// std::cout << "Bye, my Circle!\n";
		}

		// Member Functions
		// Getter functions
		double Circle::Radius() const
		{
			return m_radius;
		}

		const Point& Circle::CentrePoint() const
		{
			return centre_point;
		}

		// Setter functions	
		void Circle::Radius(const double& radius_new)
		{
			m_radius = radius_new;
		}
		void Circle::CentrePoint(const Point& center_new)
		{
			centre_point = center_new;
		}

		double Circle::Diameter() const // Returns the diameter of the circle
		{
			return m_radius * 2;
		}

		double Circle::Area() const		// Returns the area of the circle
		{
			return m_radius * m_radius * M_PI;
		}

		double Circle::Circumference() const	// Returns the circumference of the circle
		{
			return 2 * M_PI * m_radius;
		}

		// ToString returns a string of description of the Circle object
		std::string Circle::ToString() const
		{
			std::stringstream ss;

			// String s by calling ToString() of base class
			std::string s = Shape::ToString();

			// Attach s to the begining of the description
			ss << s << ", A Circle centered at " << centre_point.ToString() << " with a radius of " << m_radius;

			return ss.str();
		}

		// Draw function
		void Circle::Draw() const
		{
			std::cout << "Simulate drawing a Circle" << std::endl;
		}

		Circle& Circle::operator = (const Circle& source)		// Assignment operator
		{
			// Self-assginment prevention
			// this pointer should be equal to the address of the input if input is the object itself
			if (this == &source)
				std::cout << "You can not perform self assignment! Please try again.\n";
			else
			{
				// Copy the shape data by calling assignment operator of base class
				Shape::operator= (source);

				// Assign the center point and radius of input otherwise
				m_radius = source.m_radius;
				centre_point = source.centre_point;
			}

			return *this;	// Return this object to make possible chain operations
		}

		// << operator overloading
		// No longer need to make use of ToString function of Point Class
		// Friend class can assess data of c directly
		std::ostream& operator << (std::ostream& os, const Circle& c)
		{
			os << "A Circle centered at " << c.centre_point << " with a radius of " << c.m_radius;
			return os;
		}
	}
}