// Circle.hpp
// Author: Minghan Li
// This header file contains class declaration for Circle class
// The Circcle class has two private data fields, the centre point and the radius.
// The Circle class has member functons that return the radius, centre point, diameter, area, and circumference.
// The class also contains two setter functions for radius and centre point.

#ifndef Circle_Hpp
#define Circle_Hpp

#include "Point.hpp"
#include <iostream>

namespace MinghanLi
{
	namespace CAD
	{
		class Circle {
		private:
			double m_radius;
			Point centre_point;

		public:
			// Constructors and Destructor
			Circle();
			Circle(const double& r, const Point& c);
			Circle(const Circle& circle_new);
			~Circle();

			// Member Functions
			// Getter functions
			double Radius() const;
			const Point& CentrePoint() const;

			// Setter functions	
			void Radius(const double& radius_new);
			void CentrePoint(const Point& center_new);

			double Diameter() const;	// Returns the diameter of the circle
			double Area() const;		// Returns the area of the circle
			double Circumference() const;	// Returns the circumference of the circle

			// ToString returns a string of description of the Circle object
			std::string ToString() const;

			// Assignment operator
			Circle& operator = (const Circle& source);

			// << overloading, as a friend class
			friend std::ostream& operator << (std::ostream& os, const Circle& c);
		};
	}
}

#endif