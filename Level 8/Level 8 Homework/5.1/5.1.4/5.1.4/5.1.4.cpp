// 5.1.4.cpp
// Author: Minghan Li
// Template from: "TestRandom101.cpp, Basic functionality to show how Random works, (C) Datasim Education BV 2010-2011>>"

#include <map>	// Include STL container map header
#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>	// std::time alternative
#include <boost/Random/detail/const_mod.hpp> // LCG class
#include <iomanip>      // std::setprecision

using namespace std;

int main()
{
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;
	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);

	map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome; // Current outcome
	int num_trials;	// The number of trials

	// Prompt the user to input the number of trials
	cout << "How many trials? "; cin >> num_trials;
	
	// a) Generate a large number of trials and place their frequencies in map.
	for (int i = 0; i < num_trials; i++)
	{
		outcome = six(myRng);
		statistics[outcome]++;
	}

	// set the precision to four decimal places
	cout << endl << setprecision(4) << fixed;

	// b) Produce the desired output
	// Because the map is ordered container, we use iterators to iterate through the map
	// and print the keys and content. We can also check if there is any unexpected results
	for (map<int, long>::iterator itr = statistics.begin(); itr != statistics.end(); itr++)
		cout << "Trial " << itr -> first << " has " << (double)itr->second / (double) num_trials * 100 << "% outcomes" << endl;

	return 0;

}