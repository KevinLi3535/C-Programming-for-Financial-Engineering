
#ifndef Normal_Distribution_Cpp
#define Normal_Distribution_Cpp

#include "NormalDistribution.hpp"

namespace MinghanLi
{
	using namespace boost::math;

	template <typename T>
	NormalDistribution<T>::NormalDistribution() : m_normal(new normal_distribution<T>()) {}   // Default constructor 

	// Override constructor passes into the initial mean/std deviation that boost library normal_distribution requires - if omitted will default to (0,1)
	template <typename T>
	NormalDistribution<T>::NormalDistribution(const T& _mean, const T& _stdev) : m_mean(_mean), m_stdev(_stdev), m_normal(new normal_distribution<T>(_mean, _stdev)) {}

	// Copy Constructor
	template <typename T>
	NormalDistribution<T>::NormalDistribution(const NormalDistribution<T>& source) : m_mean(source._mean), m_stdev(source.m_stdev), m_normal(new normal_distribution<T>(source._mean, source._stdev)) {}

	template <typename T>
	NormalDistribution<T>& NormalDistribution<T>::operator = (const NormalDistribution<T>& source) // Assignment operator
	{
		// Check to make sure not assigning to the object it self
		if (this == &source)
			std::cout << "You can not perform self assignment! Please try again.\n";
		else
		{
			m_mean = source.m_mean;
			m_stdev = source.m_stdev;
			m_normal = new normal_distribution<T>(source.m_mean, source.m_stdev);
		}
			
		return *this;
	}

	template <typename T>
	NormalDistribution<T>::~NormalDistribution() { delete m_normal; }  // Destructor
																	 

	template <typename T>
	void NormalDistribution<T>::copy(const NormalDistribution<T>& source)   // Copy private data members
	{
		m_normal = new normal_distribution<T>(this->Mean, this->StandardDeviation);  //Create new pointer to normal_distribution boost library
	}

	template <typename T>
	T NormalDistribution<T>::PDF(const double& x) const
	{
		return pdf(*m_normal, x);  // Call pdf function in boost::math::normal_distribution library via pointer
	}

	template <typename T>
	T NormalDistribution<T>::CDF(const double& x) const
	{
		
		return cdf(*m_normal, x);  // Call cdf function in boost::math::normal_distribution library via pointer
	}

}

#endif