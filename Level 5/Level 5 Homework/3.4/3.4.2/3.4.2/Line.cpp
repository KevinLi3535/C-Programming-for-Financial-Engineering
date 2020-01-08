// Line.cpp
// Author: Minghan Li
// This file contains the implementation of member functions, constructor, and destructor for the Line class.
// Modification dates:
// 9-7-2019
// In this version, the Line class is inherited from Shape class, which contains a ID

#include <iostream>
#include <sstream>

#include "Point.hpp"
#include "Line.hpp"
using namespace std;	// Include this in order to not write std:: anymore

namespace MinghanLi
{
	namespace CAD
	{
		Line::Line() : Shape(), start(0, 0), end(0, 0)	// Default constructor using the constructor of Point (Colon syntax)
		{
			// cout << "A Line is constructed using default constructor!\n";
		}

		// Constructor with two input points
		Line::Line(const Point& x, const Point& y) : Shape(), start(x), end(y)
		{
			// cout << "\nA Line is constructed using two points as inputs!";
		}

		Line::Line(const Line& l) : Shape(l), start(l.start), end(l.end)	// Copy Constructor
		{
			// cout << "A Line is constructed using copy constructor!\n";
		}

		Line::~Line() //Destructor
		{
			// cout << "\nBye, my line!";
		}

		// Member functions:
		// Getter functions
		const Point& Line::Start() const
		{
			return start;
		}

		const Point& Line::End() const
		{
			return end;
		}

		// Setter functions 
		void Line::Start(const Point& start_point)
		{
			start = start_point;
		}
		void Line::End(const Point& end_point)
		{
			end = end_point;
		}

		string Line::ToString() const		// Returns description of the line
		{
			// Make use of Tostring() function that belongs ot the Point class
			stringstream ss;
			ss << "A Line that starts from " << start.ToString() << " and ends at " << end.ToString();
			return ss.str();
		}
		double Line::Length() const		// Return the length of the line
		{
			// Make use of the Distance function that belongs to Point class
			// "delegation"
			return start.Distance(end);
		}

		Line& Line::operator = (const Line& source)		// Assignment operator
		{
			// Self-assginment prevention
			// this pointer should be equal to the address of the input if input is the object itself
			if (this == &source)
				std::cout << "You can not perform self assignment! Please try again.\n";
			else
			{
				// Copy the shape data by calling assignment operator of base class
				Shape::operator= (source);

				// Assign the start and end points of input otherwise
				start = source.start;
				end = source.end;
			}

			return *this;	// Return this object to make possible chain operations
		}

		// << operator overloading
		// No longer need to make use of ToString function of Point Class
		// Friend class can assess data of l directly
		std::ostream& operator << (std::ostream& os, const Line& l)
		{
			os << "A Line that starts from " << l.start << " and ends at " << l.end;
			return os;
		}

	}
}