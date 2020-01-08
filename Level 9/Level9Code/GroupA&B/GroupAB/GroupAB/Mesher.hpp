// Mesher.cpp
// Author: Minghan Li
//
// A simple mesher on a 1d domain. We divide
// an interval into J+1 mesh points, J-1 of which
// are internal mesh points.
//
// This file is modified version of Mesher.hpp from DataSim
// In this version, we added:
// MeshArray global function, which generate a mesher vector of doubles seperated by equal distance.
// EuropeanMatrix and PerpetualMatrix global functions, which generate a matrix of option parameters for the same option,
// by altering one of the paramter for input option in each row of parameters.

#include <vector>
#include "EuropeanOption.hpp"
#include "AmericanPerpetual.hpp"

class Mesher
{
public:
		double a, b;	// In space

		Mesher()
		{
			a =0.0; b = 1.0;
		}

		Mesher (double A, double B)
		{ // Describe the domain of integration

			a = A;
			b = B;
		}

		std::vector<double> xarr(int J)
		{
			// NB Full array (includes end points)

			double h = (b - a) / double (J);
			
			int size = J+1;
			int start = 1;

			std::vector<double> result(size, start);
			result[0] = a;

			for (unsigned int j = 1; j < result.size(); j++)
			{
				result[j] = result[j-1] + h;
			}

			return result;
		}

		std::vector<double> Xarr(int J)
		{ // Return as an STL vector

			// NB Full array (includes end points)

			double h = (b - a) / double (J);
			
			int size = J+1;
			int start = 1;

			std::vector<double> result(size, start);
			result[0] = a;

			for (unsigned int j = 1; j < result.size(); j++)
			{
				result[j] = result[j-1] + h;
			}

			return result;
		}

		

};

using MinghanLi::EuropeanOption;
using MinghanLi::AmericanPerpetual;

// Global function that produces a mesh array of doubles separated by a mesh size h
std::vector <double> MeshArray(double start, double end, int size)
{
	// Create a Mesher object
	Mesher mx(start, end);

	// Return xarr with size specified
	return mx.xarr(size);
}

std::vector<vector<double>> EuropeanMatrix(const EuropeanOption& opt, string type, const vector<double>& var_arr)
{
	// Get the parameters for opt
	vector<double> parameter = opt.ParameterArray();
	
	// cout << parameter[0];

	int j;

	// The final matrix to be returned
	vector <vector <double>> eu_mx;
	
	// Pinpoint the position of the parameter that we want to modify
	if (type == "S")
		j = 0;
	else if (type == "T")
		j = 1;
	else if (type == "sig")
		j = 2;
	else if (type == "K")
		j = 3;
	else if (type == "r")
		j = 4;
	else if (type == "b")
		j = 5;
	else
	{
		cout << "The parameter type is not found. An empty matrix has been returned.\n";
		return eu_mx;
	}

	// Create the matrix with varying values for the parameter
	for (int i = 0; i < var_arr.size(); i++)
	{
		parameter[j] = var_arr[i];
		eu_mx.push_back(parameter);
	}

	return eu_mx;
}

std::vector<vector<double>> PerpetualMatrix(const AmericanPerpetual& opt, string type, const vector<double>& var_arr)
{
	// Get the parameters for opt
	vector<double> parameter = opt.ParameterArray();
	
	int j;

	// The final matrix to be returned
	vector <vector <double>> am_mx;

	// Pinpoint the position of the parameter that we want to modify
	if (type == "S")
		j = 0;
	else if (type == "sig")
		j = 1;
	else if (type == "K")
		j = 2;
	else if (type == "r")
		j = 3;
	else if (type == "b")
		j = 4;
	else
	{
		cout << "The parameter type is not found. An empty matrix has been returned.\n";
		return am_mx;
	}

	// Create the matrix with varying values for the parameter
	for (int i = 0; i < var_arr.size(); i++)
	{
		parameter[j] = var_arr[i];
		am_mx.push_back(parameter);
	}

	return am_mx;
}
