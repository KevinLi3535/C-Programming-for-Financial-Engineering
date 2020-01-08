// 3.5.3.cpp
// Author: Minghan Li
// This is a test program the destructors
// We would like to know the behavior of the distructor when it is not declared as virtual
// and when it is declared as virtual.

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
	// Test code
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++) delete shapes[i];

	// Before making the destructor virtual, the proper destructors will not
	// be called. Only three base class destructors were called.
	// After making the destructor virutal, the proper destructors are called,
	// For the derived classes, the derived class destructors are called first,
	// and then the base class destructors are called.
	// The compiler looks for the appropriate derived class version of the function
	// for the three objects pointed by Shape* objects.

	return 0;
}