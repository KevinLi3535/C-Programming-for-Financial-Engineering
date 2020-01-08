// Point.hpp
// Author: Minghan Li
// This header file contains class declaration for Point class
// The Point class has two private data: x and y coordinates
// It also has two getter functions and two setter functions for x and y
// The ToString() const that returns a string description of the point
// Distance() const function calculates the distance to the origin (0, 0)
// Distance(const Point& p) const function calculates the distance between two points
// In this version, the getter functions are implemented using Normal Inline method,
// and the setter functions are implemented using Default Inline method.

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
	double X() const;	// Getter function for X
	double Y() const;	// Getter function for Y

	// Modifiers
	void X(double ix) { m_x = ix; }		// Default inline Setter function for X
	void Y(double iy) { m_y = iy; }		// Fefault inline Setter function for Y

	std::string ToString() const;	// String description of the Point

	double Distance() const; // Calculate the distance to the origin (0, 0).
	double Distance(const Point& p) const; // Calculate the distance between two points.
};

inline double Point::X() const { return m_x; }		// Normal inline X getter function
inline double Point::Y() const { return m_y; }		// Normal inline Y getter function

#endif