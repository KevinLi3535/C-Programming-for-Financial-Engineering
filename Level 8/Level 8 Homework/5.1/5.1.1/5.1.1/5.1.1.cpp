// 5.1.1.cpp
// Author: Minghan Li
// The purpose of this program is to show that The boost::shared_ptr<T> class stores a 
// pointer and will delete the object automatically when nobody is referencing the object anymore.
// We create an array with shared pointers for shapes, and fill it with various shapes and print them. 
// In the end, we check if the shapes are automatically deleted.
// We checked this using two methods:
// 1. Create an array of shared pointers directly, and count the number of destructors being executed.
// 2. Create three shared pointers to shape objects, and count their number of references before and 
// after the array goes about of the scope. In the end, we count the number of destructors being executed,
// and show that they correspond to the objects pointed by the three share pointers.

// Preprocessor Directives
#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "NumericArray.hpp"
#include "PointArray.hpp"

// Include the shared pointer header file
#include <boost/shared_ptr.hpp>

// Using Circle, Line, Shape, and Point class names stored in MinghanLI::CAD namespace
using MinghanLi::CAD::Circle;
using MinghanLi::CAD::Line;
using MinghanLi::CAD::Shape;
using MinghanLi::CAD::Point;
using MinghanLi::Containers::Array;
using MinghanLi::Containers::NumericArray;
using MinghanLi::Containers::OutOfBoundsException;
using MinghanLi::Containers::ArrayException;
using MinghanLi::Containers::UnequalSizeException;

int main()
{
	// Create a default size
	int size = 5;

	// Use the following typedefs according to the instruction
	// Typedef for a shared pointer to shape and
	// a typedef for an array with shapes stored as shared pointers.
	typedef boost::shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;
	{
		// Create an array of three shared pointers
		ShapeArray shape_arr(3);
		shape_arr[0] = ShapePtr(new Line());
		shape_arr[1] = ShapePtr(new Circle());
		shape_arr[2] = ShapePtr(new Point());

		cout << "Created an array of three shared pointers to different shape objects. " << endl;

		// Print the elements in the array
		cout << "The elements in the array:" << endl;
		for (int i = 0; i < 3; i++)
			shape_arr[i]->Print();
	}

	// After the array of shared pointers goes out of scope, the number of shape destructors 
	// executed correspond to each of the three objects we created, which shows that the 
	// elements in the array is automatically deleted.


	// Let's also show this phenomenon by counting the reference to certain shape pointers
	// Create three different shared pointers to different objects.
	cout << endl << endl << "Let's also show this phenomenon by counting the reference to certain shape pointers" << endl;
	ShapePtr shape1(new Point(1.5, 0.5));
	ShapePtr shape2(new Line(Point(3.0, 4.0), Point(5.0, 1.5)));
	ShapePtr shape3(new Circle(4.0, Point(0.0, 0.0)));

	// Print out their current use_counts
	cout << endl << "Created three shared pointers to different shapes. " << endl;
	cout << "Print out their use counts now: " << endl;
	cout << "Shape 1: " << shape1.use_count() << endl;
	cout << "Shape 2: " << shape2.use_count() << endl;
	cout << "Shape 3: " << shape3.use_count() << endl << endl;

	// Create the ShapeArray inside the scope to 
	{
		// Create an array with shared pointers to shapes
		ShapeArray shape_arr2(size);

		// Assign shape element in the three shape shared pointers
		for (int i = 0; i < size; i++)
		{
			// Assign the i-th element of the array to 
			// the three shared pointers alternatively.

			switch (i % 3)
			{
			case 0: shape_arr2[i] = shape1;
				break;
			case 1: shape_arr2[i] = shape2;
				break;
			case 2: shape_arr2[i] = shape3;
				break;
			}
		}

		cout << "Created an array of shared pointers to different shape objects. " << endl;

		// Print the elements in the array
		cout << "The elements in the array:" << endl;
		for (int i = 0; i < size; i++)
			shape_arr2[i]->Print();
		
		// Print out their current use_counts after assignment
		cout << endl << "Print out their use counts now: " << endl;
		cout << "Shape 1: " << shape1.use_count() << endl;
		cout << "Shape 2: " << shape2.use_count() << endl;
		cout << "Shape 3: " << shape3.use_count() << endl;

	}

	// Print out their current use_counts after the array goes out of scope
	cout << endl << "After the array goes out of scope." << endl;
	cout << "Print out their use counts now: " << endl;
	cout << "Shape 1: " << shape1.use_count() << endl;
	cout << "Shape 2: " << shape2.use_count() << endl;
	cout << "Shape 3: " << shape3.use_count() << endl << endl;

	// As we observe in the debugging, the use_counts are returned to 1's after
	// the array of shared pointers went out of scope. Therefore, the shared
	// pointers references are automatically deleted when the array goes
	// out of scope. In the end, when counting the destructors called,
	// we would find they correspond to the three pointers to the shape objects
	// we have created.

}