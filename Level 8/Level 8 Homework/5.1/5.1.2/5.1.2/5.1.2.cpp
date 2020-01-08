// 5.1.2.cpp
// Author: Minghan Li
// In this program, we would like to test the use of tuples in boost library.
// Instruction: create a typedef for a Person tuple that contains a name, age and length. Also
// create a function that prints the person tuple.Use the get<T>() member functions the retrieve
// the data. Create a few person tuple instances and print them. Also increment the age of one of the persons.

// Include the boost libraries of tuples
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <string>
#include <iostream>

using namespace std;

// Create a alia for Person tuple
typedef boost::tuple<string, int, double> Person;

// Print function which takes in a const reference to a person tuple
void Print(const Person& person)
{
	// Print the informations about the Person using get<T> member functions to retrive info
	cout << "Name: " << person.get<0>() << endl << "Age: " << person.get<1>() << endl <<
		"Length: " << person.get<2>() << endl << endl;
}

int main()
{
	// Create Person tuples with multiple methods
	Person p1 = boost::make_tuple(string("Kevin"), 21, 187.5);
	Person p2(string("Tong"), 21, 161.2);
	Person p3 = boost::make_tuple(string("Sam"), 22, 178.2);

	// Print the tuples with Print function
	cout << "Create three Person tuples." << endl;
	Print(p1);
	Print(p2);
	Print(p3);

	// Increment Tong's age
	p2.get<1>()++;

	// Print the tuples with Print function after the increment
	cout << "After Tong's birthday:" << endl;
	Print(p1);
	Print(p2);
	Print(p3);

	// Try the "<<" operator overloadings
	cout << "Try using \"<< \" operator overloading:" << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl << endl;

	return 0;
}