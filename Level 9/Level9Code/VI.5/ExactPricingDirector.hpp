// ExactPricingDirector.hpp
// Author: Minghan Li
//
// This header file contains class declaration for ExactPricingDirector class, a parent class for
// all classes that perform exact pricing calculations for options.

// This class reflects an orginal attempt to imbed a pointer to a pricing director in Option class and store the
// corresponding different derived classes of pricing directors in the derived classes of Option class.
// This attempt failed, but is still worth exploring.

#ifndef Exact_Pricing_Director_Hpp
#define Exact_Pricing_Director_Hpp

#include <iostream>
#include <vector>
using namespace std;

namespace MinghanLi
{
	class ExactPricingDirector
	{
	public:
		// Constructors and Destructor
		ExactPricingDirector(); // Default constructor
		ExactPricingDirector(const ExactPricingDirector& source);	// Copy constructor
		virtual ~ExactPricingDirector();	// Destructor

		// Operators
		ExactPricingDirector& operator = (const ExactPricingDirector& source); // Assignment operator

		// Calculate the result of a function for each row of option parameter inputs, and return a vector of calculation result
		vector <double> CalculateMatrix(const vector<vector<double>>& mx, double (*f)(const vector<double>&)) const;
	};


}

#endif