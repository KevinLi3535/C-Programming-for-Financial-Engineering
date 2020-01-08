// Point.hpp
// Author: Minghan Li
// This header file contains class declaration for Point class
// The Point class has two private data: x and y coordinates
// It also has two getter functions and two setter functions for x and y
// The ToString() const that returns a string description of the point
// Distance() const function calculates the distance to the origin (0, 0)
// Distance(const Point& p) const function calculates the distance between two points

#ifndef Point_Hpp
#define Point_Hpp

#include "Shape.hpp"
#include <sstream>
#include <iostream>

namespace MinghanLi 
{
	namespace CAD
	{
		class Point : public Shape
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
			void X(double ix);	// Setter function for X
			void Y(double iy);	// Setter function for Y

			std::string ToString() const;	// String description of the Point

			// Distance function
			double Distance() const; // Calculate the distance to the origin (0, 0).
			double Distance(const Point& p) const; // Calculate the distance between two points.

			// Draw function
			void Draw() const;

			// Operators
			Point operator - () const;					// Negate the coordinates.
			Point operator * (double factor) const;		// Scale the coordinates.
			Point operator + (const Point& p) const;	// Add coordinates.
			bool operator == (const Point& p) const;	// Equally compare operator.
			Point& operator = (const Point& source);	// Assignment operator.
			Point& operator *= (double factor);			// Scale the coordinates & assign.

			// << operator overloading (friend function)
			friend std::ostream& operator << (std::ostream& os, const Point& p); // Send to ostream.
		};
	}
	

}


#endif