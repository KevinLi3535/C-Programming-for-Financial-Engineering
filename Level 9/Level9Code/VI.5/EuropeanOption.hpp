// EuropeanOption.hpp
// Author: Minghan Li
//
// This file is modified from EuropeanOption.hpp from DataSim.
// In this version, we added:
// 1. Public Price(), Delta(), and Gamma() functions, each of which is implemented to take no
// argument, a vector of doubles (underlying prices), and a matrix of option parameters.
// 
// 2. Private functions CallPrice(double U), PutPrice(double U), CallDelta(double U), PutDelta(double U)
// CallPutGamma(), and CallPutGamma(double U) are added to perform the different functions as well as 
// to perform specific calculations in Price(), Delta(), and Gamma() functions.
// 
// 3. A pointer to ExactEuropean Pricing class
// 4. DeltaDD and GammaDD functions to approximate Gamma and Delta of the option using the divided difference method
// 5. PriceParity and its helper functions to check Put/Call price parity
// 
// Modifications:
// 1. N and n functions that calculate CDF and PDF of normal distribution using boost normal_distribuition
// 2. The EuropeanOption class is now a derived class of Option class


// Class that represents  solutions to European options. This is
// an implementation using basic C++ syntax only.
//
// (C) Datasim Component Technology BV 2003-2011
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include <string>
#include "Option.hpp"
#include "ExactEuropean.hpp"

using namespace std;
using MinghanLi::ExactEuropean;

namespace MinghanLi
{
	class EuropeanOption : public Option
	{
	private:
		ExactEuropean* pd;	// pd object created on the heap perferm the calculations in the EuropeanOption functions

		void copy(const EuropeanOption& o2);

		// 'Kernel' functions for option calculations

		double CallPrice(double U) const;	// Calculate the price of the Call option with underlying price U.
		double PutPrice(double U) const;	// Calculate the price of the Put option with underlying price U.
		double CallDelta(double U) const;	// Calculate the Delta of the Call option with underlying price U.
		double PutDelta(double U) const;	// Calculate the Delta of the Put option with underlying price U.
		double CallPutGamma() const;	// Calculate the Gamma of the option (Call or Put)
		double CallPutGamma(double U) const;	// Calculate the Gamma of the option (Call or Put) with underlying price U.


		
		// Gaussian functions
		/*double n(double x) const;
		double N(double x) const;*/


	public:	// Public functions
		EuropeanOption();							// Default call option
		EuropeanOption(const EuropeanOption& option2);	// Copy constructor
		EuropeanOption(const string& optionType);	// Create option type
		EuropeanOption(const vector<double>& params);		// Create using a vector of inputs
		EuropeanOption(double _S, double _T, double _sig, double _K, double _r, double _b, string _type = "C");	//	Overloaded constructor with 6 or 7 parameters as input
		EuropeanOption(double _S, double _T, double _sig, double _K, double _r, string _type = "C");

		~EuropeanOption();

		EuropeanOption& operator = (const EuropeanOption& option2);

		// Functions that calculate the current option price and sensitivities
		double Price() const;
		double Delta() const;
		double Gamma() const;
		
		// Functions that price vector (Mesh) and matrix of inputs
		vector<double> Price(const vector<double>& arr) const;	// Takes a vector of underlying prices
		vector<double> Price(const vector<vector<double>>& mx) const;	// Takes a matrix of option parameters

		// Functions that calculate Delta for a vector (Mesh) of inputs
		vector<double> Delta(const vector<double>& arr) const;	// Takes a vector of underlying prices
		vector<double> Delta(const vector<vector<double>>& mx) const;	// Takes a matrix of option parameters

		// Functions that calculate Gamma for a matrix of inputs
		vector<double> Gamma(const vector<double>& arr) const;	// Takes a vector of underlying prices
		vector<double> Gamma(const vector<vector<double>>& mx) const;	// Takes a matrix of option parameters

		// Check if the given call/put prices satisfy parity
		double PriceParity() const;
		bool ParityChecker(double tol = 0.000001) const;
		void ParityMessage(double tol = 0.000001) const;

		// Modifier functions
		void toggle();		// Change option type (C/P, P/C)

		// Getter functions for Option class data
		double GetS() const { return Option::S; };
		double GetK() const { return Option::K; };
		double GetT() const { return Option::T; };
		double Getr() const { return Option::r; };
		double Getsig() const { return Option::sig; };
		double Getb() const { return Option::b; };
		string Gettype() const { return Option::optType; };


		// Setter functions for Option class data
		void SetS(double _S) { Option::S = _S; };
		void SetK(double _K) { Option::K = _K; };
		void SetT(double _T) { Option::T = _T; };
		void Setr(double _r) { Option::r = _r; };
		void Setsig(double _sig) { Option::sig = _sig; };
		void Settype(const string& _type) { Option::optType = _type; };

		// Parameters vectors function
		vector <double> ParameterArray() const;

		// Approximations
		double DeltaDD(double h) const;
		vector<double> DeltaDD(vector<double> arr, double h) const;
		double GammaDD(double h) const;
		vector<double> GammaDD(vector<double> arr, double h) const;


	};
}


#endif