// 2.4.2.cpp
// Author: Minghan Li
// In this program, we explore the significance of explicit declaration

#include <iostream>
#include "Point.hpp"

int main()
{
	// Without the "explicit" declaration of the constructor with single double,
	// the following code will compile and the (p == 1.0) evaluate to be true.
	/*Point p(1.0, 1.0);
	if (p == 1.0) std::cout << "Equal!" << std::endl;
	else std::cout << "Not equal" << std::endl;*/
	// This is due to implicit use of the constructor to convert 1.0 to a Point object.

	// After the declaration of the constructor as explicit, the code no longer compiles.
	// Instead, we need to use Point(1.0) to convert 1.0 to a Point object.

	Point p(1.0, 1.0);
	if (p == Point(1.0)) std::cout << "Equal!" << std::endl;
	else std::cout << "Not equal" << std::endl;
}