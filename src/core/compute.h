#ifndef COMPUTE_H
#define COMPUTE_H

#include "exports.h"

class COMPUTE_EXPORT Compute
{
public:
	explicit Compute();
	explicit Compute(double );

	double sum(double, double );
	double product(double, double );
	double average(double, double );
	double quotient(double, double );
	double difference(double, double );

private:
	double m_result;	
};

#endif // COMPUTE_H
