// TestEuler.cpp
//
// Showing instabilty in Euler for an ordinary
// differential equation (ODE) if dt is too big.
//
// ODE du/dt + au = 0, u(0) = 1
// Exact solution exp(-at).
//
// Quiz: determine dt in order to avoid oscillations.
//
// (C) Datasim Education BV 2017
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
	double a = 100.0; // Bigger N => smaller dt
	double T = 1.0;
	
	int N;
	std::cout << "How many steps (small N => OSC)? "; std::cin >> N;
	double dt = T / static_cast<double> (N);
	// Euler
	std::vector<double> y(N);
	y[0] = 1.0;

	// Scheme (watch for alternating signs)
	double error = 0.0;
	for (std::size_t j = 1; j < y.size(); ++j)
	{
		y[j] = (1.0 - a*dt)*y[j-1];
		error = std::max<double>(error, std::abs(y[j] - std::exp(-a*j*dt)));
	}
	
	for (auto elem : y)
	{
	//	std::cout << elem << ",";
	}

	std::cout << "Error: " << error << '\n';

	return 0;
}