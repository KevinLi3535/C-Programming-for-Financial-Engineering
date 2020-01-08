// PointArray.hpp
// Author: Minghan Li
// This header files contains class declaration for the PointArray class, a derived
// class of Array<Point> class. A member function Length() is added to calculate
// the total length between the points in the array.

#ifndef PointArray_Hpp
#define PointArray_Hpp

#include "Array.hpp"
#include "Point.hpp"

using MinghanLi::CAD::Point;
#include <iostream>
#include <sstream>

namespace MinghanLi
{
	namespace Containers
	{
		// No need for template since template type Point is given 
		class PointArray : public Array<Point>
		{
		public:
			// Constructors and Destructor
			PointArray();
			PointArray(unsigned int size);
			PointArray(const PointArray& arr);
			~PointArray();

			// Assignment operator
			PointArray& operator = (const PointArray& source);

			// Length() functions
			// Returns the total length between the points in the array.
			double Length() const;
		};
	}
}


#endif
