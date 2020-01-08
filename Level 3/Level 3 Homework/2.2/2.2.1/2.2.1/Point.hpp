// Point.hpp
// Author: Minghan Li
// This header file contains class declaration for Point class
// The Point class has two private data: x and y coordinates
// It also has two getter functions and two setter functions for x and y
// The ToString() that returns a string description of the point

#ifndef Point_Hpp
#define Point_Hpp

#include <sstream>
#include <iostream>

class Point 
{
private:
	double m_x;    // x coordinates
	double m_y;    // y coordinates

public:
	// Constructor and Destructor
	Point();
	~Point();

	// Selectors
	double GetX();	// Getter function for X
	double GetY();	// Getter function for Y

	// Modifiers
	void SetX(double ix);	// Setter function for X
	void SetY(double iy);	// Setter function for Y

	std::string ToString();	// String description of the Point
};

#endif