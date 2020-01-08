// 5.1.3.cpp
// Author: Minghan Li
// In this program, we perform the tasks as instructed:
// 1. create a function that returns the variant. Within this function ask the user for the shape type
// to create.Then create the requested shapeand assign it to the variantand return it.
// 2. call the function and print the result by sending it to cout. Next try to
// assign the variant to a Line variable by using the global boost : get<T>() function.This will
// throw a boost::bad_get exception when the variant didn’t contain a line.
// 3. In the main program, create an instance of the visitor and use the boost::apply_visitor(visitor,
// variant) global function to move the shape.Print the shape afterwards to check if the visitor
// indeed changed the coordinates.

// Preprocessor Directives
#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Shape.hpp"
#include "Visitor.hpp"

// Include the boost variant header file
#include <boost/variant.hpp>

// Using Circle, Line, Shape, and Point class names stored in MinghanLI::CAD namespace
using MinghanLi::CAD::Circle;
using MinghanLi::CAD::Line;
using MinghanLi::CAD::Shape;
using MinghanLi::CAD::Point;
using MinghanLi::CAD::Visitor;

using namespace std;

typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType CreateShape()
{
	// Create the ShapeType variant object and the response char object
	ShapeType result;
	char res;

	// Keep asking for the response if the response is not desired
	do
	{
		cout << "Please enter the index corresponding to the shape you want to create (1 for Point, 2 for Line, 3 for Circle): ";
		cin >> res;
		cout << endl;

	} while (res != '1' && res != '2' && res != '3');
	

	// Assign shape objects to result according to the response
	switch (res)
	{
	case '1':
		result = Point(1.0, 1.5);
		break;
	case '2':
		result = Line(Point(1.0, 1.5), Point(3.0, 4.0));
		break;
	case '3':
		result = Circle(4.0, Point(1.0, 1.0));
		break;
	}

	return result;
}

int main()
{
	// Use the function to prompt the user to create a ShapeType object
	ShapeType shape_varient = CreateShape();

	// Print the shape created
	cout << "The shape you have created: " << shape_varient << endl << endl;

	try
	{
		// This will throw a boost::bad_get exception when the variant didn’t contain a line.
		cout << "Try to assign the variant to a Line variable." << endl;
		Line my_line = boost::get<Line>(shape_varient);
		cout << "Line: " << my_line << endl << endl;
	}
	catch (boost::bad_get& err)
	{
		cout << "Error: " << err.what() << endl << endl;
	}

	// Move te shape using boost::apply_visitor global function
	cout << "Move the shape to the right by 4.0 and up by 5.5" << endl;
	boost::apply_visitor(Visitor(4.0, 5.5), shape_varient);
	cout << shape_varient << endl;

	return 0;
}
