// Exercise3.cpp
// Author: Minghan Li
// This is a test program for the count_if algorithm on various containers.
// For each container, we call two versions of the algorithms.
// The first version takes in a global funciton called Smaller.
// The second version takes in a functor called Smaller than, which we declareed and 
// implemented in source and header files, Functor.hpp and Functor.cpp.

#include "Functor.hpp" 
#include <list>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include "Functor.hpp"

using namespace std;

// Create a global function that checks the 
// double input is smaller than a certain value.
bool Smaller(double input)
{
	double bound = 5.0;
	return input < bound;
}

int main()
{
	// Create my own bound to check in count_if functions.
	// This value will be the input argument in SmallerThan functor.
	double my_bound = 6.0;

	// Create a list of doubles
	list<double> l;

	// Push_back method add two data
	l.push_back(7.2);
	l.push_back(8.2);

	// Push front method add one data
	l.push_front(3.3);

	// Print the first and last element using front() and back() functions
	cout << "Create a list of doubles called l." << endl;
	cout << "l: ";
	for (list<double>::const_iterator i = l.begin(); i != l.end(); i++)
		cout << *i << " ";

	cout << endl << "First element of l: " << l.front() << endl;
	cout << "Last element of l: " << l.back() << endl;
	
	// Test the count_if functions with different versions of SmallerThan
	cout << "Number of elements smaller than 5 in l: " << count_if(l.begin(), l.end(), Smaller) << endl;
	cout << "Number of elements smaller than " << my_bound << " in l: " << count_if(l.begin(), l.end(), SmallerThan<double>(my_bound)) << endl << endl;

	// Create a vector object
	vector<double> vec;
	vec.reserve(10);

	// Use push_back method to add elements to vector until the capacity is reached
	for (int i = 0; i < vec.capacity(); ++i)
		vec.push_back(i + 1.0);

	// Assign the second element to be 5
	vec[1] = 5.0;

	cout << "Create a vector called vec." << endl;
	cout << "Elements in vec:" << endl;

	for (int i = 0; i < vec.size(); ++i)
		cout << "Element " << i << ": " << vec[i] << endl;


	// Test the count_if functions with different versions of SmallerThan
	cout << endl << "Number of elements smaller than 5 in vec: " << count_if(vec.begin(), vec.end(), Smaller) << endl;
	cout << "Number of elements smaller than " << my_bound << " in vec: " << count_if(vec.begin(), vec.end(), SmallerThan<double>(my_bound)) << endl;

	// Print some characters of vec
	cout << endl << "Size : " << vec.size() << endl;
	cout << "Max size : " << vec.max_size() << endl;
	cout << "Capacity : " << vec.capacity() << endl;


	// Create a deque
	deque<double> deq;

	// Use push_back method to add elements to deque until the capacity is reached
	for (int i = 0; i < 5; ++i)
		deq.push_back(i * 2.0);

	// Assign the second element to be 5
	deq.pop_front();
	deq.push_front(5);

	cout << endl << "Create a deque called deq." << endl;
	cout << "Elements in deq:" << endl;

	for (int i = 0; i < deq.size(); i++)
		cout << "Element " << i << ": " << deq[i] << endl;

	// Test the count_if functions with different versions of SmallerThan
	cout << endl << "Number of elements smaller than 5 in deq: " << count_if(deq.begin(), deq.end(), Smaller) << endl;
	cout << "Number of elements smaller than " << my_bound << " in deq: " << count_if(deq.begin(), deq.end(), SmallerThan<double>(my_bound)) << endl;

	// Create a set of doubles using an array
	double arr[6] = { 5.3, 6.2, 4.1, 8.5, 6.5, 1.1 };
	set<double> s1(arr, arr + 6);

	// Insert another item into the set
	s1.insert(9.4);

	// Print the elements in the set
	cout << endl << "Create a set called s1." << endl;
	cout << "Elements in the set:" << endl;
	for (set<double>::const_iterator i = s1.begin(); i != s1.end(); i++)
		cout << *i << " ";

	// Test the count_if functions with different versions of SmallerThan
	cout << endl << "Number of elements smaller than 5 in s1: " << count_if(s1.begin(), s1.end(), Smaller) << endl;
	cout << "Number of elements smaller than " << my_bound << " in s1: " << count_if(s1.begin(), s1.end(), SmallerThan<double>(my_bound)) << endl;

	// Create an array called arr2 that has the different values from arr
	double arr2[6] = { 5.8, 6.2, 4.4, 8.9, 6.1, 0.5 };

	// Create a set called s2 taking arr2 initial values
	multiset<double> s2(arr2, arr2 + 6);

	// Create another set called s3
	multiset<double, std::greater<double> > s3;

	// Set the values for s3 as the union of s1 and s2 
	set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));

	// Print the elements in the set
	cout << endl << "Create a multiset called s3." << endl;
	cout << "Elements in the multiset:" << endl;
	for (multiset<double>::const_iterator i = s3.begin(); i != s3.end(); i++)
		cout << *i << " ";

	// Test the count_if functions with different versions of SmallerThan
	cout << endl << "Number of elements smaller than 5 in s3: " << count_if(s3.begin(), s3.end(), Smaller) << endl;
	cout << "Number of elements smaller than " << my_bound << " in s3: " << count_if(s3.begin(), s3.end(), SmallerThan<double>(my_bound)) << endl;

	return 0;
}