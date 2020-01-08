#ifndef Exact_European_Cpp
#define Exact_European_Cpp

#include <iostream>
#include <algorithm> 
#include "ExactPerpetual.hpp"

namespace MinghanLi
{
	// Constructors and Destructors
	ExactPerpetual::ExactPerpetual()
	{

	} // Default constructor

	ExactPerpetual::ExactPerpetual(const ExactPerpetual& source)	// Copy constructor
	{
	}


	ExactPerpetual::~ExactPerpetual()	// Destructor
	{

	}

	// Assignment operator
	ExactPerpetual& ExactPerpetual::operator = (const ExactPerpetual& source)
	{
		// Check to make sure not assigning to the object it self
		if (this == &source)
			std::cout << "You can not perform self assignment! Please try again.\n";

		return *this;
	}

	double ExactPerpetual::CallPrice(double U, double sig, double K, double r, double b)
	{
		double sig2 = sig * sig;
		double fac = b / sig2 - 0.5; fac *= fac;
		double y1 = 0.5 - b / sig2 + sqrt(fac + 2.0 * r / sig2);


		if (1.0 == y1)
			return U;

		double fac2 = ((y1 - 1.0) * U) / (y1 * K);
		double c = K * pow(fac2, y1) / (y1 - 1.0);

		return c;
	}

	double ExactPerpetual::PutPrice(double U, double sig, double K, double r, double b)
	{
		double sig2 = sig * sig;
		double fac = b / sig2 - 0.5; fac *= fac;
		double y2 = 0.5 - b / sig2 - sqrt(fac + 2.0 * r / sig2);

		if (0.0 == y2)
			return U;

		double fac2 = ((y2 - 1.0) * U) / (y2 * K);
		double p = K * pow(fac2, y2) / (1.0 - y2);

		return p;
	}

	double ExactPerpetual::CalculateArray(const vector<double>& arr, double(*f)(double, double, double, double, double))
	{
		return (*f)(arr[0], arr[1], arr[2], arr[3], arr[4]);
	}


	double ExactPerpetual::CallPriceArray(const vector<double>& arr)
	{
		return CalculateArray(arr, CallPrice);
	}

	double ExactPerpetual::PutPriceArray(const vector<double>& arr)
	{
		return CalculateArray(arr, PutPrice);
	}

	vector<double> ExactPerpetual::CallPriceMatrix(const vector<vector<double>>& mx) const
	{
		return CalculateMatrix(mx, CallPriceArray);
	}

	vector<double> ExactPerpetual::PutPriceMatrix(const vector<vector<double>>& mx) const
	{
		return CalculateMatrix(mx, PutPriceArray);
	}
}



#endif