// Sum.hpp
// This file contains the function declaration and implementations for Sum function, which does the following:
// 1. Accepts the template argument T as input and returns a double. The template argument will be a container.
// 

#ifndef Sum_Hpp
#define Sum_Hpp

// Preprocessor 
#include <map>
#include <list>	
#include <vector>
#include <deque>
#include <set>

using namespace std;

// Function Declarations
// We need two extra declarations for Sum in order to account for the cases for iterators for map and map.
template<typename T> 
double Sum(const T& container);

template<typename T>
double Sum(const T& begin, const T& end);

template<typename T, typename U>
double Sum(const map<T, U>& container);

template<typename T, typename U> 
double Sum(typename map<T, U>::const_iterator begin, typename map<T, U>::const_iterator end);

// Function inplementations
template <typename T>
double Sum(const T& container)
{
	double result = 0.0;
	typename T::const_iterator end = container.end();

	for (typename T::const_iterator i = container.begin(); i != end; i++)
		result += *i;

	return result;
}


template<typename T, typename U>
double Sum(const map<T, U>& container)
{
	double result = 0.0;
	typename map<T, U>::const_iterator end = container.end();

	for (typename map<T, U>::const_iterator i = container.begin(); i != end; i++)
		result += (i->second);

	return result;
}

template<typename T>
double Sum(const T& begin, const T& end)
{
	double result = 0;

	for (T i = begin; i != end; i++)
		result += (*i);

	return result;
}


template<typename T, typename U>
double Sum(typename map<T, U>::const_iterator begin, typename map<T, U>::const_iterator end)
{
	double result = 0;
	for (typename map<T, U>::const_iterator i = begin; i != end; i++)
		result += (i->second);

	return result;
}


#endif
