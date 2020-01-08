// NormalDistribution.hpp
// Author: Minghan Li
//
// This file contains the class declaration for NormalDistribution class.
// NormalDistribution class is wrapper class for boost::math::normal_distribution.
// The purpose of having NormalDistribution class is primarily to perform the CDF and PDF
// calculations for Normal(0, 1) distribution in option pricing formulas accurately.

#ifndef Normal_Distribution_Hpp
#define Normal_Distribution_Hpp

#include <boost/math/distributions/normal.hpp>

namespace MinghanLi
{
	template <typename T = double>
	class NormalDistribution
	{
	private:
		T m_mean;  // Mean 
		T m_stdev;  // Standard deviation
		boost::math::normal_distribution<T>* m_normal;  // Pointer to a boost library normal distribution object on the heap

	public:
		// Constructors and Destructor
		NormalDistribution();  // Default constructor
		NormalDistribution(const NormalDistribution<T>& source);  // Copy constructor
		NormalDistribution(const T& _mean, const T& _stdev); // Constructor that takes the mean and standerd devation as inputs
		~NormalDistribution();

		// Assignment Operator
		NormalDistribution<T>& operator = (const NormalDistribution<T>& source);
		
		// Member Functions
		void copy(const NormalDistribution<T>& source); // Copy privata data members
		T PDF(const double& x) const;
		T CDF(const double& x) const;
	};
}

#ifndef Normal_Distribution_Cpp
#include "NormalDistribution.cpp"
#endif

#endif