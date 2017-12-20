#include <string>
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


double loadFromHeader(int );
double loadFromLibrary(int );

int main(int argc, char *argv[])
{
	int operation = -1;
	std::string choice;

	std::cout << "Operation ('add', 'sub', 'div', 'avg') : ";
	std::cin >> choice;

	if (choice == "add" || choice == "Add")
		operation = 1;
	else if (choice == "sub" || choice == "Sub")
		operation = 2;
	else if (choice == "mul" || choice == "Mul")
		operation = 3;
	else if (choice == "div" || choice == "Div")
		operation = 4;
	else if (choice == "avg" || choice == "Avg")
		operation = 5;
	else {
		std::cerr << "Invalid operation " << std::endl;
		return -1;
	}

#if LIBRARY
	double result = loadFromLibrary(operation);
#else
	double result = loadFromHeader(operation);
#endif

	std::cout << "Result = " << result << std::endl;

	return 0;
}

double loadFromHeader(int op)
{
	double res;
	Compute c;

	switch(op) {
		case 1:
			res = c.sum(4.4, 10);
			break;
		case 2:
			res = c.difference(4.4, 10);
			break;
		case 3:
			res = c.product(4.4, 10);
			break;
		case 4:
			res = c.quotient(4.4, 10);
			break;
		case 5:
			res = c.average(4.4, 10);
			break;
		default: break;
	}

	return res;
}

double loadFromLibrary(int op)
{
	double res = 0.0;
	bool error = false;
	QLibrary computeLib("compute");

	if (computeLib.load()) { 
		if (computeLib.isLoaded()) {

			switch(op) {
				case 1: {
					SumFunction sum = (SumFunction)computeLib.resolve("sum");

					if (sum)
						res = sum(4.4, 10);
					else
						error = true;

					break;
				}
				case 2: {
					DifferenceFunction difference = (DifferenceFunction)computeLib.resolve("Compute::difference");

					if (difference)
						res = difference(4.4, 10);
					else
						error = true;

					break;
				}
				case 3: {
					ProductFunction product = (ProductFunction)computeLib.resolve("Compute::product");

					if (product)
						res = product(4.4, 10);
					else
						error = true;

					break;
				}
				case 4: {
					QuotientFunction quotient = (QuotientFunction)computeLib.resolve("Compute::quotient");

					if (quotient)
						res = quotient(4.4, 10);
					else
						error = true;

					break;
				}
				case 5: {
					AverageFunction average = (AverageFunction)computeLib.resolve("Compute::average");

					if (average)
						res = average(4.4, 10);
					else
						error = true;

					break;
				}
				default: break;
			}
		} else
			error = true;
	} else
		error = true;

	if (error)
		std::cerr << "\nError : " << computeLib.errorString().toStdString() << std::endl;

	if (computeLib.isLoaded())
		computeLib.unload();

	return res;
}
