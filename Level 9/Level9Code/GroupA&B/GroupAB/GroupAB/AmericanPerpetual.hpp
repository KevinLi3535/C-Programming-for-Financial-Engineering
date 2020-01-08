// AmericanPerpetual.hpp
// Author: Minghan Li
//
// This file contains the function declaration for class AmericanPerpetual, a derived class from Option.
// This class structure is similar to the EuropeanOption class, except the T variable in the parent Option
// class is always initialized to -100. The reason is that the T paramter technically does not exist for
// Perpetual American Options, and this initialization helps us to detect further complicated problems.
// Accordingly, the T parameter is made completely isolated from the public use. No getter or setter 
// functions are implemented, and the parameter function does not return T.
// The Gamma and Delta functions were not implemented for this class.
// The pricing component is delegated to an dynamically allocated ExactPerpetual pricing class.


#ifndef American_Perpetual_Hpp
#define American_Perpetual_Hpp

#include "Option.hpp"
#include "ExactPerpetual.hpp"

namespace MinghanLi
{
	class AmericanPerpetual : public Option
	{
	public:
		// Constructors and Destructor
		AmericanPerpetual();							// Default call option
		AmericanPerpetual(const AmericanPerpetual& option2);	// Copy constructor
		AmericanPerpetual(const string& optionType);	// Create option type
		AmericanPerpetual(double _S, double _sig, double _K, double _r, double _b, string _type = "C");	//	Overloaded constructor with 6 or 7 parameters as input
		AmericanPerpetual(double _S, double _sig, double _K, double _r, string _type = "C");
		~AmericanPerpetual();
		
		// Operator
		AmericanPerpetual& operator = (const AmericanPerpetual& option2);
		
		// Functions that calculate the current option price
		double Price() const;

		// Pricing functions that price vector (Mesh) and matrix of inputs
		vector<double> Price(const vector<double>& arr) const;
		vector<double> Price(const vector<vector<double>>& mx) const;

		// Modifier functions
		void toggle();		// Change option type (C/P, P/C)

		// Parameters vectors function
		vector <double> ParameterArray() const;

		// Getter functions for Option class data
		double GetS() const { return Option::S; };
		double GetK() const { return Option::K; };
		double Getr() const { return Option::r; };
		double Getsig() const { return Option::sig; };
		double Getb() const { return Option::b; };
		string Gettype() const { return Option::optType; };


		// Setter functions for Option class data
		void SetS(double _S) { Option::S = _S; };
		void SetK(double _K) { Option::K = _K; };
		void Setr(double _r) { Option::r = _r; };
		void Setsig(double _sig) { Option::sig = _sig; };
		void Settype(const string& _type) { Option::optType = _type; };

	private:
		double CallPrice(double U) const;
		double PutPrice(double U) const;

		ExactPerpetual* pd;	// pd object created on the heap perferm the calculations in the Pricing functions
	};
}
	
#endif

