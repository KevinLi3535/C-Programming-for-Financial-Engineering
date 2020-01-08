// ExactEuropean.hpp
// Author: Minghan Li
// 
// This file contains the function declaration for class ExactEuropean, a derived class from ExactPricingDirector.
// ExactEuropean class performs the calculations of Price, Gamma, and Delta for European Options using exact pricing formulas.
// Note that many of the member functions and member data are declared as static, which is not an optimal inplementation;
// however, this is the only implementation possible so far to pass them into CalculateArray and CalculateMatrix functions
// as function pointers. The benefit of this level of flexibility is far more significant for the design. 
// The static functions are mostly made private to avoid interference from the user.

#ifndef Exact_European_Hpp
#define Exact_European_Hpp

#include "NormalDistribution.hpp"
#include "ExactPricingDirector.hpp"
#include <vector>

using namespace std;
// using MinghanLi::NormalDistribution;	// Include the Normal

namespace MinghanLi
{
	class ExactEuropean : public ExactPricingDirector
	{

	private:
		static NormalDistribution<double>* m_normal;	// Pointer to a dynamically allocated NormalDistribution object

		// Gaussian functions
		static double n(double x);	// Calculate the PDF for a given x
		static double N(double x);	// Calculate the CDF for a given x
		
		// The following private static functions perform calculations of Delta, Gamma, and Price for Call and 
		// Put options, taking the option data as input arguments
		static double CallPrice(double U, double T, double sig, double K, double r, double b);
		static double PutPrice(double U, double T, double sig, double K, double r, double b);
		static double CallDelta(double U, double T, double sig, double K, double r, double b);
		static double PutDelta(double U, double T, double sig, double K, double r, double b);
		static double CallPutGamma(double U, double T, double sig, double K, double r, double b);

		// Calculate the result of a function that takes a vector of parameters of the option
		// double CalculateArray(const vector<double>& arr, double (ExactEuropean::*f)(double, double, double, double, double, double)) const;
		static double CalculateArray(const vector<double>& arr, double(*f)(double, double, double, double, double, double));
		// vector <double> CalculateMatrix(const vector<vector<double>>& mx, double (*f)(const vector<double>&)) const;

	public:
		// Constructors and Destructor
		ExactEuropean(); // Default constructor
		ExactEuropean(const ExactEuropean& source);	// Copy constructor
		virtual ~ExactEuropean();	// Destructor

		// Operators
		ExactEuropean& operator = (const ExactEuropean& source); // Assignment operator

		// Calculate the Price for a given array of underlying prices
		static double CallPriceArray(const vector<double>& arr);
		static double PutPriceArray(const vector<double>& arr);

		// Calculate the Price for a given matrix of option parameters
		vector<double> CallPriceMatrix(const vector<vector<double>>& mx) const;
		vector<double> PutPriceMatrix(const vector<vector<double>>& mx) const;

		// Calculate the Delta for a given array of option prices or a given matrix of option parameters
		static double CallDeltaArray(const vector<double>& arr);
		static double PutDeltaArray(const vector<double>& arr);

		// Calculate the Delta for a given array of option prices or a given matrix of option parameters
		vector<double> CallDeltaMatrix(const vector<vector<double>>& mx) const;
		vector<double> PutDeltaMatrix(const vector<vector<double>>& mx) const;

		// Calculate the Gamma for a given array of option prices or a given matrix of option parameters
		static double GammaArray(const vector<double>& arr);
		vector<double> GammaMatrix(const vector<vector<double>>& mx) const;

	};

	// Failed Experiment:
	//// Wrapper function uses a global to remember the object:
	//ExactEuropean* object_which_will_handle_signal;
	//void Fred_memberFn_wrapper()
	//{
	//	object_which_will_handle_signal->CallPrice(0,0,0,0,0,0);
	//}
}


#endif