// Visitor.hpp
// Author: Minghan Li
// This header file contains the class declaration for the Visitor class, 
// a derived class from boost::static_visitor<void>. The operator () is
// overloaded to perform modification when it is applied to any shape varient.

#ifndef Visitor_Hpp
#define Visitor_Hpp

#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Shape.hpp"

// Include the boost variant header file
#include <boost/variant.hpp>

namespace MinghanLi
{
	namespace CAD
	{
		// A visitor is a class derived from boost::static_visitor<void>
		class Visitor : public boost::static_visitor<void>
		{
		// Private data members: 
		private:
			double m_dx;
			double m_dy;

		public:
			// Constructors and Destructor
			Visitor();  // Default constructor
			Visitor(double x, double y);  // Constructor with x and y set for changes
			Visitor(const Visitor& source);	 // Copy constructor
			~Visitor();	// Destructor

			// Operators overloading
			// Assignment operator
			Visitor& operator = (const Visitor& source);

			// Operator () overlaoding
			// The visitor is a modifier, and returns nothing (void)

			// Operaator overloading for Point class
			void operator () (Point& p) const;

			// Operaator overloading for Line class
			void operator () (Line& l) const;

			// Operaator overloading for Circle class
			void operator () (Circle& c) const;
		};
	}
}

#endif
