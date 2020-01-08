// Shape.hpp
// Author: Minghan Li
// This file contains the class declaration for the Shape class, 
// which has one data member, m_id
// A default constructor that initializes the id using a random number.
// A copy constructor that copies the id member.
// An assignment operator that copies the id member.
// ToString() function that returns the id as string e.g.“ID: 123”.
// ID() function the retrieve the id of the shape.
// Shape class is the base class for Line, Point, and Circle classes.

#ifndef Shape_Hpp
#define Shape_Hpp

#include <iostream>

namespace MinghanLi
{
	namespace CAD
	{
		class Shape
		{
		private:
			
			// ID number
			int m_id;

		public:
			// Constructors and Destructor
			Shape();	// Default constructor
			Shape(const Shape& sp);		// Copy constructor
			virtual ~Shape();	// Destructor

			// Operators
			Shape& operator = (const Shape& source);
			
			// Member functions
			// Getter function
			int ID() const;
			virtual std::string ToString() const;	// ID string

			// Abstract function
			// This function makes Shape and abstract class
			virtual void Draw() = 0;

			// Print() function Template Method
			void Print();
		};
	}
}

#endif