// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//
// Modified by Minghan Li
// In this version, things added:
// 1. SD function/SE function: generic functions to compute the standard deviation and standard error.
// 2. Loops to write the output of Monte Carlos Simulation into a csv file for futher inspection.
// The output of the result for each Batch is stored in a csv file.
// Note that running test for large NSIM can take a couple of hours.


#include "OptionData.hpp" 
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/RNG/NormalGenerator.cpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors
	
	std::cout << std::endl << "Size of vector is " << myList.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	typename std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
			std::cout << *i << ",";

	}

	std::cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	// k is the delta t, x is from 0 to T mesh points
			// Vold + k * data -> r * Vold + k^1/2 * sigma * Vold *dW
	// Vold + T/N * (data -> r) * Vold + sigma * (T/N)^1/2 * Vold *dW
	/*VNew = VOld + (k * drift(x[index - 1], VOld))
		+ (sqrk * diffusion(x[index - 1], VOld) * dW);*/
	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace

template <class T>
double SD(const std::vector<T>& prices, T r, T eT)
{
	T CTj(0);
	T CTjsq(0);
	long M = prices.size();

	for (long i = 0; i < M; i++)
	{
		CTj += prices[i];
		CTjsq += prices[i] * prices[i];
	}

	return sqrt((CTjsq - (CTj * CTj) / M) / (M - 1.0)) * exp(-r * eT);
}

template <class T>
double SE(const std::vector<T>& prices, T r, T eT)
{
	return SD(prices, r, eT) / sqrt(prices.size());
}

int main()
{
	std::cout <<  "1 factor MC with explicit Euler\n";
	OptionData myOption;
	// Batch 1
	myOption.K = 65.0;
	myOption.T = 0.25;
	myOption.r = 0.08;
	myOption.sig = 0.3;
	myOption.type = 1;	// Put -1, Call +1
	double S_0 = 60;

	double actual_call = 2.13337;
	double actual_put = 5.84628;

	// Batch 2
	//myOption.K = 100.0;
	//myOption.T = 1.0;
	//myOption.r = 0.0;
	//myOption.sig = 0.2;
	//myOption.type = 1;	// Put -1, Call +1
	//double S_0 = 100;

	//double actual_call = 7.96557;
	//double actual_put = 7.96557;

	// Batch 4
	//myOption.K = 100.0;
	//myOption.T = 30.0;
	//myOption.r = 0.08;
	//myOption.sig = 0.3;
	//myOption.type = 1;	// Put -1, Call +1
	//double S_0 = 100;

	//double actual_call = 92.1757;
	//double actual_put = 1.2475;
	
	vector<long> N_list = { 100, 300, 500};
	vector<long> NSim_list = {10000, 100000, 1000000, 3000000, 5000000 };

	Range<double> range(0.0, myOption.T);

	std::ofstream os;
	os.open("MC_Output.csv");
	os << "N,NSim,Call Price,Call Error,Call SD,Call SE,Put Price,Put Error,Put SD,Put SE\n";

	// NormalGenerator is a base class
	NormalGenerator* myNormal = new BoostNormal();
	// NormalGenerator*myNormal =  new 

	using namespace SDEDefinition;
	SDEDefinition::data = &myOption;

	

	for (int z = 0; z < N_list.size(); z++)
	{
		std::vector<double> x = range.mesh(N_list[z]);
		double k = myOption.T / double(N_list[z]);
		double sqrk = sqrt(k);

		for (int j = 0; j < NSim_list.size(); j++)
		{
			int coun = 0; // Number of times S hits origin

			// Normal random number
			double dW;
			double price = 0.0;	// Option price

			vector<double> Ctj;	// This vector stores the price in each iteration for SD and SE calculations
// A.
			for (long i = 1; i <= NSim_list[j]; ++i)
			{ // Calculate a path at each iteration
				
			  // Create the basic SDE (Context class)
				double VOld = S_0;
				double VNew;

				if ((i / 10000) * 10000 == i)
				{// Give status after each 1000th iteration

					std::cout << i << std::endl;
				}

				VOld = S_0;
				for (unsigned long index = 1; index < x.size(); ++index)
				{

					// Create a random number
					dW = myNormal->getNormal();

					// The FDM (in this case explicit Euler)
					// k is the delta t, x is from 0 to T mesh points
					// Vold + k * (data -> r) * Vold + k^1/2 * sigma * Vold *dW
					// Vold + T/N * (data -> r) * Vold + sigma * (T/N)^1/2 * Vold *dW
					VNew = VOld + (k * drift(x[index - 1], VOld))
						+ (sqrk * diffusion(x[index - 1], VOld) * dW);

					VOld = VNew;

					// Spurious values
					if (VNew <= 0.0) coun++;
				}

				double tmp = myOption.myPayOffFunction(VNew);
				price += (tmp) / double(NSim_list[j]);

				Ctj.push_back(tmp);
			}

			// D. Finally, discounting the average price
			price *= exp(-myOption.r * myOption.T);

		
			std::cout << "Price, after discounting: " << price << ", " << std::endl;
			std::cout << "Number of times origin is hit: " << coun << endl;

			os << N_list[z] << "," << NSim_list[j] << "," << price << "," << abs(price - actual_call) << ","
				<< SD<double>(Ctj, myOption.r, myOption.T) << "," << SE<double>(Ctj, myOption.r, myOption.T) << ",";

			// Switch to put option mode
			myOption.type = -1;

			coun = 0; // Number of times S hits origin
	
			price = 0.0;	// Option price

			Ctj.clear();	// This vector stores the price in each iteration for SD and SE calculations
// A.
			for (long i = 1; i <= NSim_list[j]; ++i)
			{ // Calculate a path at each iteration

			  // Create the basic SDE (Context class)
				double VOld = S_0;
				double VNew;

				if ((i / 10000) * 10000 == i)
				{// Give status after each 1000th iteration

					std::cout << i << std::endl;
				}

				VOld = S_0;
				for (unsigned long index = 1; index < x.size(); ++index)
				{

					// Create a random number
					dW = myNormal->getNormal();

	
					VNew = VOld + (k * drift(x[index - 1], VOld))
						+ (sqrk * diffusion(x[index - 1], VOld) * dW);

					VOld = VNew;

					// Spurious values
					if (VNew <= 0.0) coun++;
				}

				double tmp = myOption.myPayOffFunction(VNew);
				price += (tmp) / double(NSim_list[j]);

				Ctj.push_back(tmp);
			}

			// D. Finally, discounting the average price
			price *= exp(-myOption.r * myOption.T);


			std::cout << "Price, after discounting: " << price << ", " << std::endl;
			std::cout << "Number of times origin is hit: " << coun << endl;

			os << price << "," << abs(price - actual_put) <<"," << SD<double>(Ctj, myOption.r, myOption.T) << "," 
				<< SE<double>(Ctj, myOption.r, myOption.T) << endl;

			myOption.type = 1;
				
		}
	}

	os.close();

	delete myNormal;


	//long N = 100;
	//std::cout << "Number of subintervals in time: ";
	//std::cin >> N;

	//// Create the basic SDE (Context class)
	//Range<double> range (0.0, myOption.T);
	//double VOld = S_0;
	//double VNew;

	//std::vector<double> x = range.mesh(N);

	//// Check what x is:
	////for (std::vector<double>::const_iterator itr = x.begin(); itr != x.end(); itr++)
	////	cout << *itr << endl;

	//// V2 mediator stuff
	//long NSim = 50000;
	//std::cout << "Number of simulations: ";
	//std::cin >> NSim;

	//double k = myOption.T / double (N);
	//double sqrk = sqrt(k);

	//// Normal random number
	//double dW;
	//double price = 0.0;	// Option price

	//
	//// NormalGenerator is a base class
	//NormalGenerator* myNormal = new BoostNormal();
	//// NormalGenerator*myNormal =  new 

	//using namespace SDEDefinition;
	//SDEDefinition::data = &myOption;

	//std::vector<double> res;
	//int coun = 0; // Number of times S hits origin

	//// A.
	//for (long i = 1; i <= NSim; ++i)
	//{ // Calculate a path at each iteration
	//		
	//	if ((i/10000) * 10000 == i)
	//	{// Give status after each 1000th iteration

	//			std::cout << i << std::endl;
	//	}

	//	VOld = S_0;
	//	for (unsigned long index = 1; index < x.size(); ++index)
	//	{

	//		// Create a random number
	//		dW = myNormal->getNormal();
	//			
	//		// The FDM (in this case explicit Euler)
	//		// k is the delta t, x is from 0 to T mesh points
	//		// Vold + k * (data -> r) * Vold + k^1/2 * sigma * Vold *dW
	//		// Vold + T/N * (data -> r) * Vold + sigma * (T/N)^1/2 * Vold *dW
	//		VNew = VOld  + (k * drift(x[index-1], VOld))
	//					+ (sqrk * diffusion(x[index-1], VOld) * dW);

	//		VOld = VNew;

	//		// Spurious values
	//		if (VNew <= 0.0) coun++;
	//	}
	//		
	//	double tmp = myOption.myPayOffFunction(VNew);
	//	price += (tmp)/double(NSim);
	//}
	//
	//// D. Finally, discounting the average price
	//price *= exp(-myOption.r * myOption.T);

	//// Cleanup; V2 use scoped pointer
	//delete myNormal;

	//std::cout << "Price, after discounting: " << price << ", " << std::endl;
	//std::cout << "Number of times origin is hit: " << coun << endl;

	return 0;
}