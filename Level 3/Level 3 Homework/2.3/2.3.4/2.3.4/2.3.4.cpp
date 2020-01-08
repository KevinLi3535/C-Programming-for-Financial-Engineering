// 2.3.4.cpp
// Arthor: Minghan Li
// This file contains a test program with a main() function
// This program is an extension of 2.3.3.cpp
// In this version, Distance(), ToString(), and the getter functions
// are changed to const functions as they don't change the point object at all.

// Preprossessor Directives
#include <iostream>
#include "Point.hpp"

int main()
{

	const Point cp(1.5, 3.9);

	// cp.X(0.3); // Gives a compiler error: you can not change a const object
	
	// This would have given an error if you don't specify the getters as const member functions
	// The compiler does not know if the getter changes input.
	std::cout << cp.X(); 

	return 0;
};