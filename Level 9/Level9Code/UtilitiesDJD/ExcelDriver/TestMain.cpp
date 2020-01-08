// TestMain.cpp
// Author: Minghan Li
// This file is created for the test of Excel Visualization of computed option price for a monotonically increasing range 
// of underlying values of S. In this case, we chose to test Batch2 put option and Batch 4 call option for illustration.
// The steps are taken to mimic the implementation of TestingSingleCurve.cpp and TestMultipleCurve.cpp.

// Include these files created in GroupA&B projects for European Option Exact Pricing
#include "ExcelDriverLite.hpp"
#include "Utilities.hpp"
#include "EuropeanOption.hpp"
#include "ExactPricingDirector.hpp"
#include "ExactEuropean.hpp"

#include <cmath>
#include <list>
#include <string>
#include <vector>


using MinghanLi::EuropeanOption;

int main()
{
	long N = 100;

	// Create a Mesh Array of S from 50 too 150 using the CreateMesh function already created
	double A = 50.0; double B = 150.0; // Interval
	auto S = CreateMesh(N, A, B);

	auto fun2 = [](double S)
	{
		// Test Batch 2 Put Option
		EuropeanOption Batch2(S, 1.0, 0.2, 100, 0.0, "P");
		return Batch2.Price();
	};

	auto fun4 = [](double S)
	{
		// Test Batch 4 Call Option
		EuropeanOption Batch4(S, 30.0, 0.30, 100.0, 0.08, "C");
		return Batch4.Price();
	};
	
	// Create the output required by passing the two function as arguments
	auto vec2 = CreateDiscreteFunction< std::vector<double>>(S, fun2);
	auto vec4 = CreateDiscreteFunction< std::vector<double>>(S, fun4);

	std::list<std::string> labels;
	labels.push_back("Batch 2");
	labels.push_back("Batch 4");

	std::list<std::vector<double> > curves;
	curves.push_back(vec2);
	curves.push_back(vec4);

	std::cout << "Data has been created\n";

	ExcelDriver xl; xl.MakeVisible(true);
	xl.CreateChart(S, labels, curves, "Batch 2 Put vs Batch 4 Call", "S", "Option Price");

	ExcelDriver x2; x2.MakeVisible(true);
	x2.CreateChart(S, vec4, "Batch4", "S", "Option Price");
}