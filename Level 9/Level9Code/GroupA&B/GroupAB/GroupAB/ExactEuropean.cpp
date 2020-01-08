#ifndef Exact_European_Cpp
#define Exact_European_Cpp

#include <iostream>
#include <algorithm> 
#include "ExactEuropean.hpp"
#include "NormalDistribution.hpp"


namespace MinghanLi
{

	NormalDistribution<double>* ExactEuropean::m_normal = new NormalDistribution <double> (0, 1);

	// Constructors and Destructors
	ExactEuropean::ExactEuropean() 
	{
		// m_normal = new NormalDistribution<double>(0, 1);
	} // Default constructor

	ExactEuropean::ExactEuropean(const ExactEuropean& source)	// Copy constructor
	{
		// m_normal = new NormalDistribution<double>(0, 1);
	}


	ExactEuropean::~ExactEuropean()	// Destructor
	{
		// delete m_normal;
	}

	// Assignment operator
	ExactEuropean& ExactEuropean::operator = (const ExactEuropean& source)
	{
		// Check to make sure not assigning to the object it self
		if (this == &source)
			std::cout << "You can not perform self assignment! Please try again.\n";
		/*else
			m_normal = new NormalDistribution<double>(0, 1);*/

		return *this;
	}

	double ExactEuropean::n(double x)
	{
		return m_normal->PDF(x);
	}

	double ExactEuropean::N(double x)
	{
		return m_normal->CDF(x);
	}


	double ExactEuropean::CallPrice(double _U, double _T, double _sig, double _K, double _r, double _b)
	{
		double tmp = _sig * sqrt(_T);

		double d1 = (log(_U / _K) + (_b + (_sig * _sig) * 0.5) * _T) / tmp;
		double d2 = d1 - tmp;


		return (_U * exp((_b - _r) * _T) * N(d1)) - (_K * exp(-_r * _T) * N(d2));
	}

	double ExactEuropean::PutPrice(double U, double T, double sig, double K, double r, double b)
	{
		double tmp = sig * sqrt(T);
		double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
		double d2 = d1 - tmp;

		return (K * exp(-r * T) * N(-d2)) - (U * exp((b - r) * T) * N(-d1));
	}

	double ExactEuropean::CallDelta(double U, double T, double sig, double K, double r, double b)
	{
		double tmp = sig * sqrt(T);

		double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;


		return exp((b - r) * T) * N(d1);
	}

	double ExactEuropean::PutDelta(double U, double T, double sig, double K, double r, double b)
	{
		double tmp = sig * sqrt(T);

		double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;

		return exp((b - r) * T) * (N(d1) - 1.0);
	}

	double ExactEuropean::CallPutGamma(double U, double T, double sig, double K, double r, double b)
	{
		double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));

		return (n(d1) * exp((b - r) * T)) / (U * sig * sqrt(T));
	}

	// We assume the order of the parameters in the array is S, T, sigma, K, r, and b
	// This order is according to the thread on quantnet
	double ExactEuropean::CalculateArray(const vector<double>& arr, double(*f)(double, double, double, double, double, double))
	{
		return (*f)(arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
	}

	double ExactEuropean::CallPriceArray(const vector<double>& arr)
	{
		return CalculateArray(arr, CallPrice);
	}

	double ExactEuropean::PutPriceArray(const vector<double>& arr)
	{
		return CalculateArray(arr, PutPrice);
	}

	//vector <double> ExactEuropean::CalculateMatrix(const vector<vector<double>>& mx, double (*f) (const vector<double>&)) const
	//{

	//	vector <double> result(mx.size());
	//	
	//	std::transform(mx.begin(), mx.end(), result.begin(), f);

	//	return result;
	//}

	vector<double> ExactEuropean::CallPriceMatrix(const vector<vector<double>> & mx) const
	{
		return CalculateMatrix(mx, CallPriceArray);
	}

	vector<double> ExactEuropean::PutPriceMatrix(const vector<vector<double>>& mx) const
	{
		return CalculateMatrix(mx, PutPriceArray);
	}
	
	// Calculate the Gamma for a given array of option parameters
	double ExactEuropean::CallDeltaArray(const vector<double>& arr)
	{
		return CalculateArray(arr, CallDelta);
	}

	double ExactEuropean::PutDeltaArray(const vector<double>& arr)
	{
		return CalculateArray(arr, PutDelta);
	}

	// Calculate the Gamma for a given array of option parameters
	double ExactEuropean::GammaArray(const vector<double>& arr)
	{
		return CalculateArray(arr, CallPutGamma);
	}

	// Calculate the Delta for a matrix of option parameters
	vector<double> ExactEuropean::CallDeltaMatrix(const vector<vector<double>>& mx) const
	{
		return CalculateMatrix(mx, CallDeltaArray);
	}

	vector<double> ExactEuropean::PutDeltaMatrix(const vector<vector<double>>& mx) const
	{
		return CalculateMatrix(mx, PutDeltaArray);
	}

	vector<double> ExactEuropean::GammaMatrix(const vector<vector<double>>& mx) const
	{
		return CalculateMatrix(mx, GammaArray);
	}

}

#endif