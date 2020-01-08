// 3.4.1.cpp
// Author: Minghan Li
// In this program, we are trying to test how the use of colon syntax affect
// the number of constructors called

#include <iostream>
#include "Line.hpp"
#include "Point.hpp"
#include "Circle.hpp"

using namespace MinghanLi::CAD;

int main()
{
	// Comment:
	// Before the using colon syntax for Line and Circle classes,
	// Number of point constructors called = 6
	// Number of assignment operators called = 3
	// Number of destructors called = 6

	// After the using colon syntax for Line and Circle classes,
	// Number of point constructors called = 3
	// Number of assignment operators called = 0
	// Number of destructors called = 3

	// Colon syntax allows the constructors to construct the member 
	// Point objects by calling the constructor of the Point object,
	// therefore avoiding constructing redundant Point objects
	// and the use of assignment operators.

	// Test Program for constructing a Line object using default constructor
	Line l;
 
	// Test Program for constructing a Circle object using default constructor
	Circle c;

	return 0;
}