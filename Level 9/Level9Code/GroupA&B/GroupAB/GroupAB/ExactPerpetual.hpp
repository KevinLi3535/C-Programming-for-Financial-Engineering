// ExactPerpetual.hpp
// Author: Minghan Li
// 
// This file contains the function declaration for class ExactPerpetual, a derived class from ExactPricingDirector.
// ExactPerpetual class performs the calculations of Price of Perpetual American Options using exact pricing formulas.
// Note that many of the member functions are declared as static, which is not an optimal inplementation;
// however, this is the only implementation possible so far to pass them into CalculateArray and CalculateMatrix functions
// as function pointers. The benefit of this level of flexibility is far more significant for the design. 
// The static functions are mostly made private to avoid interference from the user.
// CalculateArray function takes only 5 input arguments, different from CalculateArray function in ExactEuropean class,
// as Perpetual American Options don't have expiry time T.

#ifndef Exact_Perpetual_Hpp
#define Exact_Perpetual_Hpp

#include "ExactPricingDirector.hpp"
#include <vector>

using namespace std;

namespace MinghanLi
{
	class ExactPerpetual : public ExactPricingDirector
	{
	private:
		// The following private static functions perform calculations of Price for Call and 
		// Put options, taking the option data as input arguments
		static double CallPrice(double U, double sig, double K, double r, double b);
		static double PutPrice(double U, double sig, double K, double r, double b);

		static double CalculateArray(const vector<double>& arr, double(*f)(double, double, double, double, double));
		// vector <double> CalculateMatrix(const vector<vector<double>>& mx, double (*f)(const vector<double>&)) const;

	public:
		// Constructors and Destructor
		ExactPerpetual(); // Default constructor
		ExactPerpetual(const ExactPerpetual& source);	// Copy constructor
		virtual ~ExactPerpetual();	// Destructor

		// Operators
		ExactPerpetual& operator = (const ExactPerpetual& source); // Assignment operator

		// Price an array of option underlying prices
		static double CallPriceArray(const vector<double>& arr);
		static double PutPriceArray(const vector<double>& arr);

		// Price a matrix of option parameters
		vector<double> CallPriceMatrix(const vector<vector<double>>& mx) const;
		vector<double> PutPriceMatrix(const vector<vector<double>>& mx) const;

	};

}


#endif
