#include <iostream>

// Qt includes
#include <QLibrary>

#include "compute.h"

#define LIBRARY 1

typedef double (*SumFunction)(double, double);
typedef double (*ProductFunction)(double, double);
typedef double (*AverageFunction)(double, double);
typedef double (*QuotientFunction)(double, double);
typedef double (*DifferenceFunction)(double, double);


double loadFromHeader();
double loadFromLibrary();

int main(int argc, char *argv[])
{
#if LIBRARY
	double result = loadFromLibrary();
#else
	double result = loadFromHeader();
#endif

	std::cout << "Result = " << result << std::endl;

	return 0;
}

double loadFromHeader()
{
	Compute c;
	return c.sum(4.4, 10);
}

double loadFromLibrary()
{
	double res;
	bool error = false;
	QLibrary computeLib("compute");

	if (computeLib.load()) { 
		if (computeLib.isLoaded()) {
			SumFunction sum = (SumFunction)QLibrary::resolve("compute", "sum");

			if (sum)
				res = sum(4.4, 10);
			else
				error = true;
		} else
			error = true;
	} else
		error = true;

	if (error)
		std::cerr << "\nError : " << computeLib.errorString().toStdString() << std::endl;

	computeLib.unload();
}
