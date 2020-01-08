// EurpeanOption.cpp
//
//	Author: Daniel Duffy
//
// (C) Datasim Component Technology BV 2003-2011
//

#ifndef EuropeanOption_Cpp
#define EuropeanOption_Cpp

#include "EuropeanOption.hpp"
#include "NormalDistribution.hpp"
#include "ExactEuropean.hpp"
#include <cmath>
#include <iostream>

using MinghanLi::NormalDistribution;
using namespace MinghanLi;

//////////// Gaussian functions /////////////////////////////////

// In general, we would use similar functions in Boost::Math Toolkit
//
//double EuropeanOption::n(double x) const
//{ 
//	NormalDistribution<double> A(0.0, 1.0);
//
//	return A.PDF(x);
//
//}
//
//double EuropeanOption::N(double x) const
//{ // The approximation to the cumulative normal distribution
//
//	NormalDistribution<double> A(0.0, 1.0);
//
//	return A.CDF(x);
//
//}


// Kernel Functions (Haug)
double EuropeanOption::CallPrice(double U) const
{
	vector <double> params = ParameterArray();

	params[0] = U;
	return pd -> CallPriceArray(params);

	
	/*double tmp = sig * sqrt(T);

	double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
	double d2 = d1 - tmp;


	return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));*/

}

double EuropeanOption::PutPrice(double U) const
{
	vector <double> params = ParameterArray();

	params[0] = U;
	return pd-> PutPriceArray(params);

}

double EuropeanOption::CallDelta(double U) const
{
	vector <double> params = ParameterArray();

	params[0] = U;

	return pd->CallDeltaArray(params);

}

double EuropeanOption::PutDelta(double U) const
{
	vector <double> params = ParameterArray();

	params[0] = U;

	return pd->PutDeltaArray(params);

	//double tmp = sig * sqrt(T);

	//double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;

	//return exp((b-r)*T) * (N(d1) - 1.0);
}

double EuropeanOption::CallPutGamma() const
{
	return pd->GammaArray(ParameterArray());
	/*double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));

	return (n(d1) * exp((b - r) * T)) / (S * sig * sqrt(T));*/
}

double EuropeanOption::CallPutGamma(double U) const
{
	vector <double> params = ParameterArray();
	params[0] = U;

	return pd->GammaArray(params);
}

/////////////////////////////////////////////////////////////////////////////////////


void EuropeanOption::copy( const EuropeanOption& o2)
{

	r	= o2.r;
	sig = o2.sig;	
	K	= o2.K;
	T	= o2.T;
	b	= o2.b;
	S   = o2.S;

	pd = new ExactEuropean;
	
	optType = o2.optType;
	
}

// We assume the order of the parameters in the array is S, T, sigma, K, r, and b
// This order is according to the thread on quantnet
vector <double> EuropeanOption::ParameterArray() const
{
	return parameters();
}

EuropeanOption::EuropeanOption() : Option(), pd(new ExactEuropean)
{ // Default call option
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor
	Option::copy(o2);
	copy(o2);
}

EuropeanOption::EuropeanOption (const string& optionType)
{	// Create option type

	init();
	optType = optionType;

	if (optType == "c")
		optType = "C";

	if (optType == "p")
		optType = "P";

}

EuropeanOption::EuropeanOption(double _S, double _T, double _sig, double _K, double _r, double _b, string _type) : Option(_S, _T, _sig, _K, _r, _b, _type), pd(new ExactEuropean)
{

}

EuropeanOption::EuropeanOption(double _S, double _T, double _sig, double _K, double _r, string _type) : Option(_S, _T, _sig, _K, _r, _r, _type), pd(new ExactEuropean)
{

}

// Option constructor with a vector as input
EuropeanOption::EuropeanOption(const vector<double>& params) : Option(params), pd(new ExactEuropean) 	// Create using a vector of inputs
{

}

EuropeanOption::~EuropeanOption()
{
	delete pd;
}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{

	if (this == &option2) return *this;

	copy (option2);

	return *this;
}

// Functions that calculate option price and sensitivities
// Price() function returns the price based on the the information stored in the option
double EuropeanOption::Price() const
{
	// vector <double> params = ParameterArray();

	if (optType == "C")
	{	
		return pd -> CallPriceArray(ParameterArray());
		// cout << "calling call\n";
		// return CallPrice(S);
	}
	else
	{
		// cout << "calling put\n";
		return pd -> PutPriceArray(ParameterArray());
	}
}	

// This function calculate the put/call prices from the put/call parity function
double EuropeanOption::PriceParity() const
{
	// vector <double> params = ParameterArray();

	if (optType == "C")
	{
		return pd->PutPriceArray(ParameterArray()) + S - K*exp(-r * T);
	}
	else
	{
		return pd->CallPriceArray(ParameterArray()) + K * exp(-r * T) - S;
	}
}

// This function check if a given set of put/call prices satisfy parity
// The function has a tolerance input for difference between the parity
// price and the price from exact formula. 
// The default argument for tolerance is 0.000001
bool EuropeanOption::ParityChecker(double tol) const
{
	// return (Price() == PriceParity());
	return (abs(Price() - PriceParity()) < tol);
}

// This function prints the result for the parity check, and output
// to inform the user whether the put/call prices satisfy parity.
void EuropeanOption::ParityMessage(double tol) const
{
	if (ParityChecker(tol))
		cout << "Parity Check result: The Put/Call prices satisfy parity" << endl;
	else
		cout << "Parity Check result: The Put/Call prices do not satisfy parity" << endl;
}

vector<double> EuropeanOption::Price(const vector<double>& arr) const
{
	vector<double> result(arr.size());
	
	if (optType == "C")
	{
		for (int i = 0; i < arr.size(); i++)
			result[i] = CallPrice(arr[i]);
	}
	else
	{
		for (int i = 0; i < arr.size(); i++)
			result[i] = PutPrice(arr[i]);
	}
	
	return result;
	
}

vector<double> EuropeanOption::Price(const vector<vector<double>>& mx) const
{
	if (optType == "C")
		return pd->CallPriceMatrix(mx);
	else
		return pd->PutPriceMatrix(mx);
}

// We assume the order of the parameters in the array is S, T, sigma, K, r, and b
// This order is according to the thread on quantnet
//double EuropeanOption::CalculateArray(const vector<double>& arr, double(ExactEuropean::*f)(double, double, double, double, double, double)) const
//{
//	return f(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
//}
//
//double EuropeanOption::PriceArray(const vector<double>& arr) const
//{
//	if (optType == "C")
//	{
//
//		return CalculateArray(arr, (*pd).*(*pd).ExactEuropean::CallPrice);
//	}
//		
//	else
//		return CalculateArray(arr, (*pd).*(*pd).ExactEuropean::PutPrice);
//}

double EuropeanOption::Delta() const 
{
	if (optType == "C")
		return pd->CallDeltaArray(ParameterArray());
	else
		return pd->PutDeltaArray(ParameterArray());

}

vector<double> EuropeanOption::Delta(const vector<double>& arr) const
{
	vector<double> result(arr.size());

	if (optType == "C")
	{
		for (int i = 0; i < arr.size(); i++)
			result[i] = CallDelta(arr[i]);
	}
	else
	{
		for (int i = 0; i < arr.size(); i++)
			result[i] = PutDelta(arr[i]);
	}

	return result;
}

vector<double> EuropeanOption::Delta(const vector<vector<double>>& mx) const
{
	if (optType == "C")
		return pd->CallDeltaMatrix(mx);
	else
		return pd->PutDeltaMatrix(mx);
}


double EuropeanOption::Gamma() const
{
	return CallPutGamma();
}

vector<double> EuropeanOption::Gamma(const vector<double>& arr) const
{
	vector<double> result(arr.size());

	for (int i = 0; i < arr.size(); i++)
		result[i] = CallPutGamma(arr[i]);

	return result;
}

vector<double> EuropeanOption::Gamma(const vector<vector<double>>& mx) const
{
	return pd->GammaMatrix(mx);
}


// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)

	if (optType == "C")
		optType = "P";
	else
		optType = "C";
}

// Approximations
double EuropeanOption::DeltaDD(double h) const
{
	if (optType == "C")
		return (CallPrice(S + h) - CallPrice(S - h)) / (2 * h);
	else
		return (PutPrice(S + h) - PutPrice(S - h)) / (2 * h);
}

vector<double> EuropeanOption::DeltaDD(vector<double> arr, double h) const
{
	vector<double> result(arr.size());

	if (optType == "C")
	{
		for (int i = 0; i < arr.size(); i++)
			result[i] = (CallPrice(arr[i] + h) - CallPrice(arr[i] - h)) / (2 * h);
	}
	else
	{
		for (int i = 0; i < arr.size(); i++)
			result[i] = (PutPrice(arr[i] + h) - PutPrice(arr[i] - h)) / (2 * h);
	}

	return result;
}
double EuropeanOption::GammaDD(double h) const
{
	if (optType == "C")
		return (CallPrice(S + h) - 2 * Price() + CallPrice(S - h)) / (h * h);
	else
		return (PutPrice(S + h) - 2 * Price() + PutPrice(S - h)) / (h * h);
}

vector<double> EuropeanOption::GammaDD(vector<double> arr, double h) const
{
	vector<double> result(arr.size());

	if (optType == "C")
	{
		for (int i = 0; i < arr.size(); i++)
			result[i] = (CallPrice(S + h) - 2 * Price() + CallPrice(S - h)) / (h * h);
	}
	else
	{
		for (int i = 0; i < arr.size(); i++)
			result[i] = (PutPrice(S + h) - 2 * Price() + PutPrice(S - h)) / (h * h);
	}

	return result;
}

#endif
