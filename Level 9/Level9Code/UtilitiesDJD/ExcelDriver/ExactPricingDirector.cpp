#ifndef Exact_Pricing_Director_Cpp
#define Exact_Pricing_Director_Cpp

#include "ExactPricingDirector.hpp"
#include <algorithm>

namespace MinghanLi
{
	// Constructors and Destructors
	ExactPricingDirector::ExactPricingDirector() {} // Default constructor

	ExactPricingDirector::ExactPricingDirector(const ExactPricingDirector& source)	// Copy constructor
	{
		
	}


	ExactPricingDirector::~ExactPricingDirector()	// Destructor
	{

	}
	
	// Assignment operator
	ExactPricingDirector& ExactPricingDirector::operator = (const ExactPricingDirector& source)
	{
		// Check to make sure not assigning to the object it self
		if (this == &source)
			std::cout << "You can not perform self assignment! Please try again.\n";

		return *this;
	}

	vector <double> ExactPricingDirector::CalculateMatrix(const vector<vector<double>>& mx, double (*f) (const vector<double>&)) const
	{

		vector <double> result(mx.size());

		std::transform(mx.begin(), mx.end(), result.begin(), f);

		return result;
	}

}

#endif