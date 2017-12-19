#include <iostream>

#include <QLibrary>


typedef double (*SumFunction)(double, double);
typedef double (*ProductFunction)(double, double);
typedef double (*AverageFunction)(double, double);
typedef double (*QuotientFunction)(double, double);
typedef double (*DifferenceFunction)(double, double);

int main(int argc, char *argv[])
{
	bool error = false;
	QLibrary computeLib("compute");

	if (computeLib.load()) { 
		if (computeLib.isLoaded()) {
			SumFunction sum = (SumFunction)QLibrary::resolve("compute", "sum");

			if (sum) {
				double res = sum(4.4, 10);
				std::cout << "Result = " << res << std::endl;
			} else
				error = true;
		} else
			error = true;
	} else
		error = true;

	if (error)
		std::cerr << "\nError : " << computeLib.errorString().toStdString() << std::endl;

	computeLib.unload();
 
	return 0;
}
