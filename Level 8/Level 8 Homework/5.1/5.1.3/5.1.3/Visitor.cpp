// Visitor.cpp
// Author: Minghan Li
// This file contains the implementation of Vistor class
// Modification dates:
// 9-23-2019

#include "Visitor.hpp"

namespace MinghanLi
{
	namespace CAD
	{
		Visitor::Visitor() : m_dx(0.0), m_dy(0.0) {} // Default constructor

		Visitor::Visitor(double x, double y) : m_dx(x), m_dy(y) {}	// Constructor with x and y set for changes
		
		Visitor::Visitor(const Visitor& source) : m_dx(source.m_dx), m_dy(source.m_dy) {}	// Copy constructor
		
		Visitor::~Visitor() {};	// Destructor

		// Operators overloading
		// Assignment operator
		Visitor& Visitor::operator = (const Visitor& source)
		{
			// Self-assginment prevention
			// this pointer should be equal to the address of the input if input is the object itself
			if (this == &source)
				std::cout << "You can not perform self assignment! Please try again.\n";
			else
			{
				m_dx = source.m_dx;
				m_dy = source.m_dy;
			}

			return *this;	// Return this object to make possible chain operations
		}

		// Operator () overlaoding
		// The visitor is a modifier, and returns nothing (void)

		// Operator overloading for Point class
		void Visitor::operator () (Point& p) const
		{
			p.X(p.X() + m_dx);
			p.Y(p.Y() + m_dy);
		}

		// Operator overloading for Line class
		void Visitor::operator () (Line& l) const
		{
			// Create two new Point objects with modified arguments and assign to the Start and End
			l.Start(Point(l.Start().X() + m_dx, l.Start().Y()+ m_dy));
			l.End(Point(l.End().X() + m_dx, l.End().Y() + m_dy));
		}

		// Operator overloading for Circle class
		void Visitor::operator () (Circle& c) const
		{
			c.CentrePoint(Point(c.CentrePoint().X() + m_dx, c.CentrePoint().Y() + m_dy));
		}
	}

}