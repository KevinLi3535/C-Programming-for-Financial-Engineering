// TestBSPDE1.cpp
//
// Modified by Minghan Li
//
// The orginal code is modified to compare the exact pricing with the FDM.
// Graphs of errors for each N is drawn, and so is a graph comparing the option prices obtained from each N.
// Outputs for J = 1, 3, 5 are stored in three Excel documents.
//
// Testing 1 factor BS model.
//
// (C) Datasim Education BV 2005-2011
//

#include "FdmDirector.hpp"

#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"
#include "EuropeanOption.hpp"
#include "Utilities.hpp"
using MinghanLi::EuropeanOption;

// #include "ExcelDriverLite.hpp"

namespace BS // Black Scholes
{
	// Batch 1
	double sig = 0.3;
	double K = 65.0;
	double T = 0.25;
	double r = 0.08;
	double D = 0.0; // aka q

	// Batch 2
	//double sig = 0.2;
	//double K = 100.0;
	//double T = 1.0;
	//double r = 0.0;
	//double D = 0.0; // aka q

	// Batch 3
	//double sig = 0.5;
	//double K = 10.0;
	//double T = 1.0;
	//double r = 0.12;
	//double D = 0.0; // aka q

	// Batch 4
	//double sig = 0.3;
	//double K = 100.0;
	//double T = 30.0;
	//double r = 0.08;
	//double D = 0.0; // aka q

	double mySigma (double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu (double x, double t)
	{
		
		return (r - D) * x;
	
	}

	double myB (double x, double t)
	{	
	
		return  -r;
	}

	double myF (double x, double t)
	{
		return 0.0;
	}

	double myBCL (double t)		
	{
		// Put
		return K *exp(-r * t);
	}

	double myBCR (double t)
	{
			
		// Put
		return 0.0; // P
	}

	double myIC (double x)
	{ // Payoff 
	
		// Put
		return max(K - x, 0.0);
	}

}


int main()
{
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	vector <int> J_list = {1, 3, 5};
	vector <int> N_list = {1000, 10000, 100000};

	auto fun = [](double S)
	{
		// Test Batch 1 Put Option
		EuropeanOption Batch(S, 0.25, 0.30, 65, 0.08, "P");		// Batch 1 Inputs
		//EuropeanOption Batch(S, 1.0, 0.2, 100, 0.0, "P");	// Batch 2 Inputs
		//EuropeanOption Batch(S, 1.0, 0.50, 10, 0.12, "P");		// Batch 3 Inputs
		//EuropeanOption Batch(S, 30.0, 0.30, 100.0, 0.08, "P");	// Batch 4 Inputs
		return Batch.Price();
	};

	/*ExcelDriver xl; 
	xl.MakeVisible(true);*/
	
	for (vector<int>::const_iterator i = J_list.begin(); i != J_list.end(); i++)
	{
		ExcelDriver xl;
		xl.MakeVisible(true);
		
		list<vector<double>> output;
		list<std::string> labels;

		int J = static_cast<int>(*i * BS::K);

		auto x = CreateMesh(J, 0.0, J);

		auto exact_price = CreateDiscreteFunction<std::vector<double>>(x, fun);
		
		double Smax = *i * BS::K;

		for (vector<int>::const_iterator j = N_list.begin();  j!= N_list.end(); j++)
		{

			int N = *j; // k = O(h^2) !!!!!!!!!

			cout << "start FDM\n";
			FDMDirector fdir(Smax, BS::T, J, N);

			fdir.doit();

			cout << "Finished\n";

			vector <double> diff(J+1);

			transform(fdir.current().begin(), fdir.current().end(), exact_price.begin(), diff.begin(), std::minus<double>());
			xl.CreateChart(x, diff, "Batch1 Error N = " + to_string(N));

			output.push_back(fdir.current());
			labels.push_back("Batch1 " + to_string(N));
		}

		xl.CreateChart(x, labels, output, "Batch1 FDM vs Batch1 Exact", "S", "Option Price");

	};
	
	//int J = static_cast<int>(3*BS::K);
	//
	//int N = 10000-1; // k = O(h^2) !!!!!!!!!

	//double Smax = 3*BS::K;			// Magix

	//cout << "start FDM\n";
	//FDMDirector fdir(Smax, BS::T, J, N);

	//fdir.doit();
	//
	//cout << "Finished\n";

	//auto fun1 = [](double S)
	//{
	//	// Test Batch 2 Put Option
	//	EuropeanOption Batch1(S, 0.25, 0.30, 65, 0.08, "P");
	//	return Batch1.Price();
	//};


	//auto vec1 = CreateDiscreteFunction< std::vector<double>>(fdir.xarr, fun1);
	//
	//std::list<std::string> labels;
	//labels.push_back("Batch 1 FDM");
	//labels.push_back("Batch 1 Exact");

	//std::list<std::vector<double> > curves;
	//curves.push_back(fdir.current());
	//curves.push_back(vec1);

	//ExcelDriver xl; xl.MakeVisible(true);
	//xl.CreateChart(fdir.xarr, labels, curves, "Batch 1 FDM vs Batch 1 Exact", "S", "Option Price");

	// Have you Excel installed (ExcelImports.cpp)
	// printOneExcel(fdir.xarr, fdir.current(), string("Value"));

	return 0;
}
