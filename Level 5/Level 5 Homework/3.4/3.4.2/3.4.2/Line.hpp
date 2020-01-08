// Line.hpp
// Author: Minghan Li
// This header file contains class declaration for Line class
// The Line class has two private data: Poinr start and Point end
// Other elements in the Line class:
// Default constructor (set the points to 0, 0).
// Constructor with a start - and end - point.
// Copy constructor.
// Destructor.
// Overloaded getters for the start - and end - point.
// Overloaded setters for the start - and end - point.
// A ToString() function that returns a description of the line.
// A Length() function that returns the length of the line.
// In this version, the Line class is inherited from Shape class, which contains a ID

#ifndef Line_Hpp
#define Line_Hpp

#include <iostream>
// Include all the Point class declaration
#include "Point.hpp"
#include "Shape.hpp"

namespace MinghanLi
{
	namespace CAD
	{
		class Line : public Shape
		{
			// Composition: start-point and end-point
		private:
			Point start;  // start-point
			Point end;	// end-point

		public:
			// Constructors and Destructor
			Line();
			// Constructor, passing the input points as reference to be more efficient
			Line(const Point& x, const Point& y);
			Line(const Line& l);	// Copy Constructor
			~Line();	//Destructor

			// Member functions:
			// Getter functions
			const Point& Start() const;
			const Point& End() const;

			// Setter functions 
			void Start(const Point& start_point);
			void End(const Point& end_point);

			std::string ToString() const;	// Returns description of the line
			double Length() const;		// Return the length of the line

			// Assignment operator
			Line& operator = (const Line& source);

			// << overloading, as a friend class
			friend std::ostream& operator << (std::ostream& os, const Line& l);
		};

	}
}


#endif
