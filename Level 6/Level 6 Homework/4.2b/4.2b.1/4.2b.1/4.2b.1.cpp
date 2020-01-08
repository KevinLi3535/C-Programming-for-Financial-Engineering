// 4.2b.1.cpp
// Author: Minghan Li
// In this program, we would like to test the behavior of static variable in classes
// that are created using templates. The getter and setter functions of this static
// variable are called.

#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Array.hpp"

// Using Circle, Line, Shape, and Point class names stored in MinghanLI::CAD namespace
using MinghanLi::CAD::Circle;
using MinghanLi::CAD::Line;
using MinghanLi::CAD::Shape;
using MinghanLi::CAD::Point;
using MinghanLi::Containers::Array;
using MinghanLi::Containers::OutOfBoundsException;
using MinghanLi::Containers::ArrayException;

using namespace std;

int main()
{
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;
	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;
	intArray1.DefaultSize(15);
	cout << intArray1.DefaultSize() << endl;
	cout << intArray2.DefaultSize() << endl;
	cout << doubleArray.DefaultSize() << endl;

	// The printed result was:
	//10
	//10
	//10
	//15
	//15
	//10

	// Explanation:
	// The first three 10's are values for the m_default_size 
	// that are initialized in the Array source file.
	// When the setter function for m_default_size is called on 
	// intArray1 object, the static variable that belongs to
	// the Array<int> class is modified to 15. This explains why
	// the DefaultSize() getter functions called on two Array<int>
	// objects later returned 15 instead of 10. However, the static
	// variable for Array<double> class is not changed. The point
	// here is that static variables in class have a class scope,
	// and Array<double> and Array<int> for two different classes.

	return 0;
}