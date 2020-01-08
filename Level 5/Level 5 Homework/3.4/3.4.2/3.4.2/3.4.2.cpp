// 3.4.2.cpp
// Author: Minghan Li
// This is a test program for the inheritance relationship between Shape and its inherited classes
// We would like to know the behavior of the inherited class

#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

// Using Circle, Line, Shape, and Point class names stored in MinghanLI::CAD namespace
using MinghanLi::CAD::Circle; 
using MinghanLi::CAD::Line;
using MinghanLi::CAD::Shape;
using MinghanLi::CAD::Point;

// Avoid using std::cout.
using namespace std;

int main()
{
	Shape s;// Create shape.
	Point p(10, 20);// Create point.

	Line l(Point(1, 2), Point(3, 4)); // Create line.
	cout << s.ToString() << endl;// Print shape.
	cout << p.ToString() << endl;// Print point.
	cout << l.ToString() << endl;// Print line
	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?

	// This works. Since the Point classes inherits the public member functions of
	// the Shape base class, calling ID() on p is possible and returns the m_id 
	// the base class data member

	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?

	// This works. Since the Line classes inherits the public member functions of
	// the Shape base class, calling ID() on p is possible and returns the m_id 
	// the base class data member

	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible?

	// Yes, this is possible. Since p is a Point object, which is an inherited class 
	// from the Shape class and it follows the substitability principle

	cout << sp->ToString() << endl;// What is printed?
	// This prints the ID of the point, which is stored as private data memeber of the 
	// the base class. In another word, the ToString of Shape class is called.

	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call
	// the base class assignment in point?

	// The ID is not copied if we don't call the base class assignment operator.

	return 0;
}