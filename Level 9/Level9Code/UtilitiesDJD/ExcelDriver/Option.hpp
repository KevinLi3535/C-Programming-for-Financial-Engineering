// Option.hpp
// Author: Minghan Li
//
// The file is modified from Option.hpp provided by Datasim
// In this version, the Option class is modified to be an abstract class
// Option class is a base class for AmericanPerpetual and EuropeanOption classes.
// Option class contains 7 essential elements to determine a option's characteristics.
//
// S = asset price
// K = strike price
// T = exercise (maturity data)
// r = risk-free interest rate
// sig = constant volatility
// b = cost of carry
// opType = Type of the option (Call or Put)
// 
// For the default constructor, the order of parameters inputed
// is according to an instruction post on QuantNet.
// The parameters function returns a vector of option parameters according to this order.
// 
// The class also contains an abstract function called Price, which reflects an original
// idea of pricing different types Options using a polymorphic design, the attempt failed
// due to limitations during implementation; however, it is worth further exploration.
// 
// (C) Datasim Component Technology BV 2003-2005
//

#ifndef Option_hpp
#define Option_hpp

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Option
{
public:

	// Constructors and Destructor
	Option();							// Default call option
	Option(const Option& option2);	// Copy constructor
	Option(const string& optionType);	// Create option type
	Option(const vector<double>& params);		// Create using a vector of inputs
	Option(double _S, double _T, double _sig, double _K, double _r, double _b, string _type = "C");	//	Overloaded constructor with 6 or 7 parameters as input

	virtual ~Option();

	Option& operator = (const Option& option2);

	void init();	// Initialise all default values
	void copy(const Option& o2);

	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double S;		// Current underlying price (e.g. stock, forward)
	double b;		// Cost of carry

	string optType;	// Option name (call, put)
	// string unam;	// Name of underlying asset

	double payoff(double S)const
	{
		if (optType == "P")
		{
			return max(S - K, 0.0);
		}
		else
		{
			return max(K - S, 0.0);
		}
	}

	// Parameters vectors function
	vector <double> parameters() const;

	// Virtual member functions of Option class (abstract)
	virtual double Price() const = 0; // Get price
	//virtual double Delta() const = 0; // Get Delta
	//virtual double Gamma() const = 0; // Get Gamma
};

#endif