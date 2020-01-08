// 3.5.2.cpp
// Author: Minghan Li
// This is a test program for the inheritance relationship between Shape and its inherited classes
// We would like to know the behavior of the inherited class
// In this version, we try to attach the base call ToString() description to the derived classes

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
	Circle c; // Create a Circle

	// Examine the shape objects we created
	cout << "Information about the shapes we created:\n";
	cout << s.ToString() << endl;// Print shape.
	cout << p.ToString() << endl;// Print point.
	cout << l.ToString() << endl; // Print line
	cout << c.ToString() << endl << endl; // Print Circle

	// Print the ID of the shapes
	cout << "Print the ID of the shapes:\n";
	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point.
	cout << "Line ID: " << l.ID() << endl; // ID of the line.
	cout << "Circle ID: " << c.ID() << endl << endl; // ID of the circle.

	// Create shape pointers to Line and Point objects
	Shape* sp; // Create pointer to a shape variable.
	Shape* sl; // Create pointer to a shape variable.
	Shape* sc; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable.
	sl = &l; // Line in a shape variable.
	sc = &c; // Circle in a shape variable.

	// Call ToString() function on Shape* of Line and Point:
	cout << "Call virtual ToString() function on the Shape* of Line, Circle, and Point:\n";
	cout << sp->ToString() << endl;
	cout << sl->ToString() << endl;
	cout << sc->ToString() << endl;

	return 0;
}