// Option.cpp
// Author: Minghan Li
//
// The file is modified from Option.cpp provided by Datasim
// This file constains class implementation for the Option class.
// Option class is a base class for AmericanPerpetual and EuropeanOption classes.



#ifndef Option_cpp
#define Option_cpp

#include "Option.hpp"
#include <cmath>
#include <iostream>

void Option::init()
{	// Initialise all default values

	// Default values
	r = 0.05;
	sig = 0.2;
	S = 50.0;
	K = 110.0;
	T = 0.5;

	b = r;			// Black and Scholes stock option model (1973)

	optType = "C";		// European Call Option (this is the default type)

}


Option::Option()
{ // Default call option

	init();
}

void Option::copy(const Option& o2)
{

	r = o2.r;
	sig = o2.sig;
	K = o2.K;
	T = o2.T;
	b = o2.b;
	S = o2.S;

	optType = o2.optType;


}



Option::Option(const Option& o2)
{ // Copy constructor

	copy(o2);
}

Option::Option(const string& optionType)
{	// Create option type

	init();
	optType = optionType;

	if (optType == "c")
		optType = "C";

	if (optType == "p")
		optType = "P";

}

//	Option constructor with 6 or 7 parameters as input
Option::Option(double _S, double _T, double _sig, double _K, double _r, double _b, string _type ) : S(_S), T(_T), sig(_sig), K(_K), r(_r), b(_b), optType(_type)
{

}

// Option constructor with a vector as input
Option::Option(const vector<double>& params) : S(params[0]), T(params[1]), sig(params[2]), K(params[3]), r(params[4]), b(params[5])	 // Create using a vector of inputs
{
	if (params.size() == 6)
		optType = "C";
	else if (params.size() == 7)
		optType = params[6];
}

Option& Option::operator = (const Option& option2)
{

	if (this == &option2) return *this;

	copy(option2);

	return *this;
}

Option::~Option()
{

}

// Parameters vectors function
vector <double> Option::parameters() const
{
	vector <double> result(6);
	result[0] = S;
	result[1] = T;
	result[2] = sig;
	result[3] = K;
	result[4] = r;
	result[5] = b;

	return result;
}

#endif