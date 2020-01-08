// Exercise 1.cpp
// Author: Minghan Li
// In this program, we will do the following using containers in STL.
// Create a list of doubles and add some data. 
// Use the front() and back() functions to access the first and last element.
// Create a vector of doublesand add some data.
// Then use the index operator to access some elements.Also make the vector grow.
// Create a map that maps strings to doubles.
// Fill the mapand access elements using the square bracket operator.

// Preprocessors to include the STL containers
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
	// Create a list of doubles
	list<double> l;

	// Push_back method add two data
	l.push_back(7.2);
	l.push_back(8.2);

	// Push front method add one data
	l.push_front(3.3);

	// Print the first and last element using front() and back() functions
	cout << "Create a list of doubles called l." << endl;
	cout << "First element of l: " << l.front() << endl;
	cout << "Last element of l: " << l.back() << endl << endl;

	// Create a vector object
	vector<int> vec;
	vec.reserve(10);

	// Use push_back method to add elements to vector until the capacity is reached
	for (int i = 0; i < vec.capacity(); ++i)
		vec.push_back(i + 1);
	
	// Assign the second element to be 5
	vec[1] = 5;

	cout << "Create a vector called vec." << endl;
	cout << "Elements in vec:" << endl;

	for (int i = 0; i < vec.size(); ++i)
		cout << "Element " << i << ": " << vec[i] << endl;

	// Print some characters of vec
	cout << endl << "Size : " << vec.size() << endl;
	cout << "Max size : " << vec.max_size() << endl;
	cout << "Capacity : " << vec.capacity() << endl;

	// Create a map object
	map<string, double> m;

	// Fill the map using insert method
	m.insert(make_pair("Element1", 3.3));
	m.insert(make_pair("Element2", 3.7));

	// Fill the map using [] method
	m["Element3"] = 8.8;
	m["Element4"] = 10.8;

	// Print the elements in the map using square bracket operator
	cout << endl << "Create a map called m." << endl;
	cout << "Elements in m:" << endl;

	cout << m["Element1"] << ", ";
	cout << m["Element2"] << ", ";
	cout << m["Element3"] << ", ";
	cout << m["Element4"] << endl;

	return 0;
}