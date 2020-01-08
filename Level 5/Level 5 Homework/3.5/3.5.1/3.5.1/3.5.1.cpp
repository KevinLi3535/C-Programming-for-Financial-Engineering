// 3.5.1.cpp
// Author: Minghan Li
// This is a test program for the inheritance relationship between Shape and its inherited classes
// We would like to know the behavior of the inherited class
// In this version, we try to test the behaviors of virtual member functions' behavior
// We try to call ToString() function on a Shape* that contains a Point object

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
	
	// Examine the shape objects we created
	cout << "Information about the shapes we created:\n";
	cout << s.ToString() << endl;// Print shape.
	cout << p.ToString() << endl;// Print point.
	cout << l.ToString() << endl << endl;// Print line

	// Print the ID of the shapes
	cout << "Print the ID of the shapes:\n";
	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point.
	cout << "Line ID: " << l.ID() << endl << endl; // ID of the line.

	// Create shape pointers to Line and Point objects
	Shape* sp; // Create pointer to a shape variable.
	Shape* sl; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable.
	sl = &l; // Line in a shape variable.

	// Call ToString() function on Shape* of Line and Point:
	cout << "Call virtual ToString() function on the Shape* of Line and Point:\n";
	cout << sp->ToString() << endl;
	cout << sl->ToString() << endl;
	
	// The last two line printed the information of the Point object and Line object.
	// This is unlike the case in 3.4.2, where the ToString() function of the base
	// class Shape is called, and the function prints the IDs.
	// This is because we have declared the function as virtual, and the compiler 
	// looks for the appropriate overwritten virtual function in the derived class to call.

	return 0;
}