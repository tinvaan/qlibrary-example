#include "compute.h"

Compute::Compute()
	: m_result(0.0)
{}

Compute::Compute(double res)
	: m_result(res)
{}

double Compute::sum(double x, double y)
{
	m_result = x + y;
	return m_result;
}

double Compute::product(double x, double y)
{
	m_result = x * y;
	return m_result;
}

double Compute::average(double x, double y)
{
	m_result = (x + y)/2.0;
	return m_result;
}

double Compute::quotient(double x, double y)
{
	m_result = x / y;
	return m_result;
}

double Compute::difference(double x, double y)
{
	m_result = x - y;
	return m_result;
}

#include "compute_exports.cpp"
