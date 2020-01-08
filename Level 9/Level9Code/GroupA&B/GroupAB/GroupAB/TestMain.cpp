// TestMain.cpp
// Author: Minghan Li
// 
// This program is a test program for fully testing each and every aspect of option pricing classes.
// The program calls many functions associated with pricing European Option and American Perpetual Options.
// The function calls are according to the instuctions from QuantNet C++ for Financial Engineering course.

#include <iostream>
#include <vector>
#include <cmath>
#include "Option.hpp"
#include "EuropeanOption.hpp"
#include "AmericanPerpetual.hpp"
#include "Mesher.hpp"

using MinghanLi::AmericanPerpetual;
using MinghanLi::EuropeanOption;

using namespace std;

// Global function to print an array with type T
template <typename T>
void PrintArray(const vector<T>& arr)
{ 
	for (typename vector<T>::const_iterator i = arr.begin(); i != arr.end(); i++)
		cout << *i << ", ";
}

// A function which is used for the overloaded Price() function for a price mesh
// The function prints out the title names, S and Price, followed by two columns
// of input S and output option prices.
void PrintMesh(const vector<double>& mesh, const vector<double>& price, string title1, string title2)
{
	cout << title1 << "\t" << title2 << endl;
	for (int i = 0; i < mesh.size(); i++)
		cout << mesh[i] << "\t" << price[i] << endl;
}

// We assume the order of the parameters in the array is S, T, sigma, K, r, and b
// This order is according to the thread on quantnet
void PrintMatrix(const vector<vector<double>>& mx, const vector<double>& var, string title)
{
	// Print the title for the output columns
	cout << "S" << "\t"; 
	if (mx[0].size() == 6)
		cout << "T" << "\t";
	else if (mx[0].size() == 5)
	{ }
	
	cout << "sigma" << "\t"
		<< "K" << "\t" << "r" << "\t" << "b" << "\t" << title << "\t" << endl;

	for (int i = 0; i < mx.size(); i++)
	{
		for (vector<double>::const_iterator itr = mx[i].begin(); itr != mx[i].end(); itr++)
			cout << *itr << "\t";

		cout << var[i] << endl;
	}
		
}

// This function serves to help us to conduct error analysis for approximation of 
// Option Sensitivities.
void Error_Matrix(EuropeanOption opt, const vector<double>& h_array)
{
	// cout << opt.GetK();

	cout << "h\t" << "Call Delta (e)\t" << "Call Gamma (e)\t"
		<< "Put Delta (e)\t" << "Put Gamma (e)\t" << endl;

	for (int i = 0; i < h_array.size(); i++)
	{
		cout << h_array[i] << "\t";
		cout << abs(opt.Delta() - opt.DeltaDD(h_array[i])) << "\t";
		cout << abs(opt.Gamma() - opt.GammaDD(h_array[i])) << "\t";
		/*cout << opt.Delta() << "\t";
		cout << opt.DeltaDD(h_array[i]) << "\t";*/

		opt.toggle();
		cout << abs(opt.Delta() - opt.DeltaDD(h_array[i])) << "\t";
		cout << abs(opt.Gamma() - opt.GammaDD(h_array[i])) << "\t" << endl;
		/*cout << opt.Delta() << "\t";
		cout << opt.DeltaDD(h_array[i]) << "\t" << endl;*/

		opt.toggle();
	}
}

int main()
{
	// A. Exact Solutions of One-Factor Plain Options
	// a) and b)

	//// EuropeanOption(double _S, double _T, double _sig, double _K, double _r, string _type = "C");
	EuropeanOption Batch1(60, 0.25, 0.30, 65, 0.08, "C");
	EuropeanOption Batch2(100, 1.0, 0.2, 100, 0.0, "C");
	EuropeanOption Batch3(5, 1.0, 0.50, 10, 0.12, "C");
	EuropeanOption Batch4(100.0, 30.0, 0.30, 100.0, 0.08, "C");

	// Batch 1 Put and Call Options Pricing
	cout << "Batch 1:" << endl;
	cout << "Call Price: " << Batch1.Price() << endl;
	cout << "Call Price from Put/Call Parity:  " << Batch1.PriceParity() << endl;
	Batch1.ParityMessage();

	Batch1.toggle();
	cout << "Put Price: " << Batch1.Price() << endl;
	cout << "Put Price from Put/Call Parity:  " << Batch1.PriceParity() << endl;
	Batch1.ParityMessage();
	cout << endl;
		
	// Batch 2 Put and Call Options Pricing
	cout << "Batch 2:" << endl;
	cout << "Call Price: " << Batch2.Price() << endl;
	cout << "Call Price from Put/Call Parity:  " << Batch2.PriceParity() << endl;
	Batch2.ParityMessage();

	Batch2.toggle();
	cout << "Put Price: " << Batch2.Price() << endl;
	cout << "Put Price from Put/Call Parity:  " << Batch2.PriceParity() << endl;
	Batch2.ParityMessage();
	cout << endl;

	// Batch 3 Put and Call Options Pricing
	cout << "Batch 3:" << endl;
	cout << "Call Price: " << Batch3.Price() << endl;
	cout << "Call Price from Put/Call Parity:  " << Batch3.PriceParity() << endl;
	Batch3.ParityMessage();
	
	Batch3.toggle();
	cout << "Put Price: " << Batch3.Price() << endl;
	cout << "Put Price from Put/Call Parity:  " << Batch3.PriceParity() << endl;
	Batch3.ParityMessage();
	cout << endl;

	// Batch 4 Put and Call Options Pricing
	cout << "Batch 4:" << endl;
	cout << "Call Price: " << Batch4.Price() << endl;
	cout << "Call Price from Put/Call Parity:  " << Batch4.PriceParity() << endl;
	Batch4.ParityMessage();

	Batch4.toggle();
	cout << "Put Price: " << Batch4.Price() << endl;
	cout << "Put Price from Put/Call Parity:  " << Batch4.PriceParity() << endl;
	Batch4.ParityMessage();
	cout << endl << endl;

	// A
	// c) 
	// Create a price mesh from 10 to 50
	vector<double> mesh = MeshArray(10, 50, 40);

	// Switch Batch4 from Put option to Call option
	Batch4.toggle();

	// Price Batch4 call option using price mesh from 10 to 50
	vector<double> Batch4_Prices = Batch4.Price(mesh);
	 cout << "Batch4:" << endl;
	PrintMesh(mesh, Batch4_Prices, "S", "Price");

	cout << endl << endl;

	// A
	// d)
	// Create a mesh for Expiry Time from 20 to 40
	vector<double> T_mesh = MeshArray(20, 40, 20);
	vector<vector<double>> Batch4_Matrix_T = EuropeanMatrix(Batch4, "T", T_mesh);

	PrintMatrix(Batch4_Matrix_T, Batch4.Price(Batch4_Matrix_T), "Price");
	
	cout << endl << endl; 

	// Create a mesh for Volitility (sig) from 0.1 to 10
	vector<double> sig_mesh = MeshArray(0.1, 1, 9);
	vector<vector<double>> Batch4_Matrix_sig = EuropeanMatrix(Batch4, "sig", sig_mesh);

	PrintMatrix(Batch4_Matrix_sig, Batch4.Price(Batch4_Matrix_sig), "Price");

	cout << endl << endl;

	// More generally, we can price a matrix of different options
	vector<vector<double>> my_matrix;

	my_matrix.push_back(Batch1.ParameterArray());
	my_matrix.push_back(Batch2.ParameterArray());
	my_matrix.push_back(Batch3.ParameterArray());
	my_matrix.push_back(Batch4.ParameterArray());
	
	PrintMatrix(my_matrix, Batch4.Price(my_matrix), "Price");

	cout << endl << endl;

	// Option Sensitivity
	// a)
	// EuropeanOption(double _S, double _T, double _sig, double _K, double _r, string _type = "C");
	
	EuropeanOption Batch5(105, 0.5, 0.36, 100, 0.1, 0, "C");

	// Batch 5 Put and Call Delta
	cout << "Batch 5:" << endl;
	cout << "Call Delta: " << Batch5.Delta() << endl;
	Batch5.toggle();
	cout << "Put Delta: " << Batch5.Delta() << endl;

	cout << endl;
	
	// b)
	// Switch Batch5 back to call option mode
	Batch5.toggle();

	vector<double> S_mesh = MeshArray(90, 110, 20);

	vector<double> Batch5_Delta = Batch5.Delta(S_mesh);

	PrintMesh(S_mesh, Batch5_Delta, "S", "Delta");

	cout << endl << endl;

	// c)
	// Create a mesh for K from 95 to 115
	vector<double> K_mesh = MeshArray(95, 115, 20);

	vector<vector<double>> Batch5_Matrix_K = EuropeanMatrix(Batch5, "K", K_mesh);

	PrintMatrix(Batch5_Matrix_K, Batch5.Delta(Batch5_Matrix_K), "Delta");

	cout << endl << endl;

	PrintMatrix(Batch5_Matrix_K, Batch5.Gamma(Batch5_Matrix_K), "Gamma");

	// More generally
	cout << endl << endl;

	my_matrix.push_back(Batch5.ParameterArray());

	PrintMatrix(my_matrix, Batch5.Gamma(my_matrix), "Gamma");

	cout << endl << endl;

	// d)
	// //cout << Batch5.Gettype() << endl;
	cout << "Batch 5:" << endl;
	cout << "Call Delta: " << Batch5.Delta() << endl;
	cout << "Call Delta Approximate: " << Batch5.DeltaDD(0.2) << endl;
	cout << "Approximate Error: " << Batch5.Delta() - Batch5.DeltaDD(0.2) << endl;
	cout << "Call Gamma: " << Batch5.Gamma() << endl;
	cout << "Call Gamma Approximate: " << Batch5.GammaDD(0.2) << endl;
	cout << "Approximate Error: " << Batch5.Gamma() - Batch5.GammaDD(0.2) << endl;

	cout << endl;

	Batch5.toggle();
	cout << "Put Delta: " << Batch5.Delta() << endl;
	cout << "Put Delta Approximate: " << Batch5.DeltaDD(0.2) << endl;
	cout << "Approximate Error: " << Batch5.Delta() - Batch5.DeltaDD(0.2) << endl;
	cout << "Put Gamma: " << Batch5.Gamma() << endl;
	cout << "Put Gamma Approximate: " << Batch5.GammaDD(0.2) << endl;
	cout << "Approximate Error: " << Batch5.Gamma() - Batch5.GammaDD(0.2) << endl;
	Batch5.toggle();

	cout << endl << endl;

	vector<double> Batch5_DeltaDD = Batch5.DeltaDD(S_mesh, 0.2);

	PrintMesh(S_mesh, Batch5_DeltaDD, "S", "DeltaDD");

	cout << endl << endl;
	// Error Analysis


	vector<double> h_mesh = MeshArray(0.1, 1, 9);

	Error_Matrix(Batch5, h_mesh);

	cout << endl << endl;

	// B. Perpetual American Options
	// a) and b)
	//AmericanPerpetual(double _S, double _sig, double _K, double _r, double _b, string _type = "C");	//	Overloaded constructor with 6 or 7 parameters as input
	AmericanPerpetual Batch6(110, 0.1, 100, 0.1, 0.02, "C");

	// Batch 6 Put and Call Options Pricing
	cout << "Batch 6:" << endl;
	cout << "Call Price: " << Batch6.Price() << endl;

	Batch6.toggle();
	cout << "Put Price: " << Batch6.Price() << endl;

	cout << endl << endl;

	// c)
	// Switch Batch6 from Put option to Call option
	Batch6.toggle();

	// Create a price mesh from 100 to 120
	vector<double> b6_mesh = MeshArray(100, 120, 20);

	// Price Batch6 call option using price mesh from 100 to 120
	vector<double> Batch6_Prices = Batch6.Price(b6_mesh);

	cout << "Batch6:" << endl;
	PrintMesh(b6_mesh, Batch6_Prices, "S", "Price");

	cout << endl << endl;

	// d)
	vector<vector<double>> Batch6_Matrix_K = PerpetualMatrix(Batch6, "K", b6_mesh);

	PrintMatrix(Batch6_Matrix_K, Batch6.Price(Batch6_Matrix_K), "Price");
	
	return 0;
}

