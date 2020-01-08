// Line.cpp
// Author: Minghan Li
// This file contains the implementation of member functions, constructor, and destructor for the Line class.
// Modification dates:
// 9-6-2019

#include <iostream>
#include <sstream>

#include "Point.hpp"
#include "Line.hpp"
using namespace std;	// Include this in order to not write std:: anymore

Line::Line() : start(0, 0), end(0, 0)	// Default constructor using the constructor of Point (Colon syntax)
{
	cout << "A Line is constructed using default constructor!\n";
}

// Constructor with two input points
Line::Line(const Point& x, const Point& y) : start(x), end(y)
{
	cout << "\nA Line is constructed using two points as inputs!";
}

Line::Line(const Line& l): start(l.start), end(l.end)	// Copy Constructor
{
	cout << "A Line is constructed using copy constructor!\n";
}

Line::~Line() //Destructor
{
	cout << "\nBye, my line!";
}

// Member functions:
// Getter functions
Point Line::Start() const
{
	return start;
}

Point Line::End() const
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