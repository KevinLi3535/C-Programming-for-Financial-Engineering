// 4.2b.6.cpp
// Author: Minghan Li
// In this program, we would like to test the Stack class. Specifically, we would like
// to create two stacks, one of Point objects and the other of doubles. We call Push and
// Pop functions on them respectively.
// We try to let the Stack classes throw a StackException object instead of
// ArrayException object when the Stack is full or empty.
// In this version, we modified the Stack classto use Value Template. 
// The integer size is passed as a template variable, which is then used to set stack size.

// Preprocessor Directives
#include <iostream>
#include "Circle.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Array.hpp"
#include "NumericArray.hpp"
#include "PointArray.hpp"
#include "Stack.hpp"
#include "StackException.hpp"

// Using Circle, Line, Shape, and Point class names stored in MinghanLI::CAD namespace
using MinghanLi::CAD::Circle;
using MinghanLi::CAD::Line;
using MinghanLi::CAD::Shape;
using MinghanLi::CAD::Point;
using MinghanLi::Containers::Array;
using MinghanLi::Containers::NumericArray;
using MinghanLi::Containers::OutOfBoundsException;
using MinghanLi::Containers::ArrayException;
using MinghanLi::Containers::UnequalSizeException;
using MinghanLi::Containers::PointArray;
using MinghanLi::Containers::Stack;
using MinghanLi::Containers::StackException;
using MinghanLi::Containers::StackFullException;
using MinghanLi::Containers::StackEmptyException;

using namespace std;

int main()
{
	// Set the default size
	const int size = 3;		// Need to make size const in order to make it an argument

	// Create a Stack of doubles and a Stack of Point objects
	Stack<double, size> double_stack;
	Stack<Point, size> point_stack;

	// Try to call Pop on the empty Stack double_stack
	// When the Stack is empty, a StackException object is caught.
	try
	{
		double_stack.Pop();
	}
	catch (StackException& err)
	{
		cout << err.GetMessage();
	}
	catch (...)
	{
		// Error message for all other types of exceptions
		cout << "An unhandled exception has occurred" << endl;
	}

	cout << endl << endl;

	// Push in double objects onto double_stack
	// When the upper bounded is reached, a StackException object is caught.
	for (int i = 0; i < size + 3; i++)
	{
		try
		{
			double_stack.Push(i * 2.0);
		}
		catch (StackException& err)
		{
			cout << err.GetMessage() << endl;
		}
		catch (...)
		{
			// Error message for all other types of exceptions
			cout << "An unhandled exception has occurred" << endl;
		}

	}

	cout << endl;

	// Test the Pop function.
	// When the Stack is empty, a StackException object is caught.
	for (int i = 0; i < size + 3; i++)
	{
		try
		{
			cout << double_stack.Pop() << " ";
		}
		catch (StackException& err)
		{
			cout << endl << err.GetMessage();
		}
		catch (...)
		{
			// Error message for all other types of exceptions
			cout << "An unhandled exception has occurred" << endl;
		}
	}

	cout << endl << endl;

	// Push in Point objects onto point_stack
	// When the upper bounded is reached, a StackException object is caught.
	for (int i = 0; i < size + 3; i++)
	{
		try
		{
			point_stack.Push(Point(i, 2.0 * i));
		}
		catch (StackException& err)
		{
			cout << err.GetMessage() << endl;
		}
		catch (...)
		{
			// Error message for all other types of exceptions
			cout << "An unhandled exception has occurred" << endl;
		}

	}

	cout << endl;

	// Test the Pop function.
	// When the Stack is empty, a StackException object is caught.
	for (int i = 0; i < size + 3; i++)
	{
		try
		{
			cout << point_stack.Pop() << " ";
		}
		catch (StackException& err)
		{
			cout << endl << err.GetMessage();
		}
		catch (...)
		{
			// Error message for all other types of exceptions
			cout << "An unhandled exception has occurred" << endl;
		}
	}

	cout << endl;

	return 0;
}