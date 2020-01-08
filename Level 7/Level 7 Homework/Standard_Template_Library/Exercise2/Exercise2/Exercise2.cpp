// Exercise2.cpp
// This is a test program for the Sum functions we have created in Sum.hpp.
// We test the function on various STL containers, including list, map, vector, set, and multiset

#include "Sum.hpp" 
#include <iostream>
#include <algorithm>
#include <iterator>

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
	cout << "l: ";
	for (list<double>::const_iterator i = l.begin(); i != l.end(); i++)
		cout << *i << " ";

	cout << endl << "First element of l: " << l.front() << endl;
	cout << "Last element of l: " << l.back() << endl;
	cout << "The sum of elements in l: " << Sum(l) << endl;
	cout << "The sum of elements from the first element to the second-to-the-last element in l: " << Sum(l.begin(), --l.end()) << endl << endl;

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


	// Test sum function on vector vec
	cout << endl << "The sum of elements in vec: " << Sum(vec) << endl;
	cout << "The sum of elements from the second element to the second-to-the-last element in vec: " << Sum(++vec.begin(), --vec.end()) << endl;

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

	// Test sum on map object
	cout << endl << "The sum of elements in m: " << Sum(m) << endl;
	cout << "The sum of elements from the second element to the second-to-the-last element in m: " << Sum<string, double>(++m.begin(), --m.end()) << endl;

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


	// Test sum function on vector vec
	cout << endl << "The sum of elements in deq: " << Sum(deq) << endl;
	cout << "The sum of elements from the second element to the second-to-the-last element in deq: " << Sum(++deq.begin(), --deq.end()) << endl;

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

	// Test calling Sum functions on set s
	cout << endl << "The sum of elements in s1: " << Sum(s1) << endl;
	cout << "The sum of elements from the second element to the second-to-the-last element in s1: " << Sum(++s1.begin(), --s1.end()) << endl;
	
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

	// Test calling Sum functions on set s
	cout << endl << "The sum of elements in s3: " << Sum(s3) << endl;
	cout << "The sum of elements from the second element to the second-to-the-last element in s3: " << Sum(++s3.begin(), --s3.end()) << endl;

	return 0;
}