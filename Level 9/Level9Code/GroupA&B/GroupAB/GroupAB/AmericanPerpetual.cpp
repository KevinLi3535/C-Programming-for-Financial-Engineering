// AmericanPerpetual.cpp
// Author: Minghan Li
//
// This file contains the function implementation for class AmericanPerpetual, a derived class from Option.

#ifndef American_Perpetual_Cpp
#define American_Perpetual_Cpp

#include "AmericanPerpetual.hpp"

namespace MinghanLi
{
	// For all the constructors, T is set to -100
	AmericanPerpetual::AmericanPerpetual() : Option(), pd(new ExactPerpetual)
	{ // Default call option
		T = -100;
	}

	AmericanPerpetual::AmericanPerpetual(const AmericanPerpetual& o2)
	{ // Copy constructor
		Option::copy(o2);
		pd = new ExactPerpetual;
	}

	AmericanPerpetual::AmericanPerpetual(const string& optionType)
	{	// Create option type

		init();
		optType = optionType;
		T = -100;

		if (optType == "c")
			optType = "C";

		if (optType == "p")
			optType = "P";

		
	}

	AmericanPerpetual::AmericanPerpetual(double _S, double _sig, double _K, double _r, double _b, string _type) : Option(_S, -100, _sig, _K, _r, _b, _type), pd(new ExactPerpetual)
	{

	}

	AmericanPerpetual::AmericanPerpetual(double _S, double _sig, double _K, double _r, string _type) : Option(_S, -100, _sig, _K, _r, _r, _type), pd(new ExactPerpetual)
	{

	}

	AmericanPerpetual::~AmericanPerpetual()
	{
		delete pd;
	}


	AmericanPerpetual& AmericanPerpetual::operator = (const AmericanPerpetual& option2)
	{

		if (this == &option2) return *this;

		copy(option2);
		pd = new ExactPerpetual;

		return *this;
	}

	// We assume the order of the parameters in the array is S, T, sigma, K, r, and b
	// This order is according to the thread on quantnet
	vector <double> AmericanPerpetual::ParameterArray() const
	{

		vector<double> parameter = parameters();
		// Deletes the second element T, and return the new parameter array
		parameter.erase(parameter.begin() + 1);

		return parameter;
	}

	double AmericanPerpetual::Price() const
	{
		// vector <double> params = ParameterArray();

		if (optType == "C")
			return pd->CallPriceArray(ParameterArray());
		else
			return pd->PutPriceArray(ParameterArray());
	}

	vector<double> AmericanPerpetual::Price(const vector<double>& arr) const
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

	vector<double> AmericanPerpetual::Price(const vector<vector<double>>& mx) const
	{
		if (optType == "C")
			return pd->CallPriceMatrix(mx);
		else
			return pd->PutPriceMatrix(mx);
	}

	// Kernel Functions (Haug)
	double AmericanPerpetual::CallPrice(double U) const
	{
		vector <double> params = ParameterArray();

		params[0] = U;
		return pd->CallPriceArray(params);


	}

	double AmericanPerpetual::PutPrice(double U) const
	{
		vector <double> params = ParameterArray();

		params[0] = U;
		return pd->PutPriceArray(params);

	}

	void AmericanPerpetual::toggle()
	{ // Change option type (C/P, P/C)

		if (optType == "C")
			optType = "P";
		else
			optType = "C";
	}

}

#endif
