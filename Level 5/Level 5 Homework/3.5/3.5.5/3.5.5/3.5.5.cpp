// 3.5.5.cpp
// Author: Minghan Li
// In this program, we would like to test the Print() function that is declared
// and implemented only in the Shape class and uses polymorphic function ToString().
// The design patter is called "Template Method Pattern"

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
	// Create an array of Shape*
	Shape* shapes[5];

	// Create Point, Line, and Circle objects on the heap
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	shapes[3] = new Point(1.4, 13);
	shapes[4] = new Circle;

	for (int i = 0; i != 5; i++) shapes[i]->Print();	// Call Print() function
	for (int i = 0; i != 5; i++) delete shapes[i];	// Delete all the items stored in shapes

	// Even though Print() function is only implemented for the base Shape class,
	// it is inherited by the derived classes, and the derived classes call their own
	// ToString() functions respectively.
	// This mechanism is an often used design pattern called the “Template Method Pattern”.

	return 0;
}

