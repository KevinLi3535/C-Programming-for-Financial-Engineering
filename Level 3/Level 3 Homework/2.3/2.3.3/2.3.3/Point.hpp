// Point.hpp
// Author: Minghan Li
// This header file contains class declaration for Point class
// The Point class has two private data: x and y coordinates
// It also has two getter functions and two setter functions for x and y
// The ToString() that returns a string description of the point
// Distance() function calculates the distance to the origin (0, 0)
// Distance(const Point& p) function calculates the distance between two points
// Function Overloadings:
// DistanceOrigin() function is changed to Distance()
// The setter and getter functions are all changed to X() and Y() with or without inputs


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
	Point(double x, double y);
	Point();
	~Point();

	// Copy constructor
	Point(const Point& pt);


	// Selectors
	double X();	// Getter function for X
	double Y();	// Getter function for Y

	// Modifiers
	void X(double ix);	// Setter function for X
	void Y(double iy);	// Setter function for Y

	std::string ToString();	// String description of the Point

	double Distance(); // Calculate the distance to the origin (0, 0).
	double Distance(const Point& p); // Calculate the distance between two points.
};

#endif