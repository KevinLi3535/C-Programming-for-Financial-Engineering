// 3.5.4.cpp
// Author: Minghan Li
// In this program, we would like to investigate the behavior of an abstract class.
// We also call the abstract functions that are given implementations in the derived classes.

#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"

// Using Circle, Line, Shape, and Point class names stored in MinghanLI::CAD namespace
using MinghanLi::CAD::Circle;
using MinghanLi::CAD::Line;
using MinghanLi::CAD::Shape;
using MinghanLi::CAD::Point;

int main()
{
	Shape* shapes[6];

	// Create Point and Line objects on the heap
	// In this case, since Shape is an abstract class, and Draw() function has no implementation,
	// we cannot create a Shape object anymore. Instead, we can still create Shape* objects.
	shapes[0] = new Line;
	// shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	shapes[3] = new Point(1.4, 13);
	shapes[4] = new Point;
	shapes[5] = new Line(Point(4, 7), Point(0.3, 2.2));
	
	for (int i = 0; i != 6; i++) shapes[i]->Draw();	// Call draw function
	for (int i = 0; i != 6; i++) delete shapes[i];	// Delete all the items stored in shapes

	return 0;
}