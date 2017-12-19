#ifdef Q_OS_WIN
#define COMPUTE_EXPORT __declspec(dllexport)
#else
#define COMPUTE_EXPORT
#endif

extern "C" COMPUTE_EXPORT double sum(double x, double y)
{
	return x + y;
}

extern "C" COMPUTE_EXPORT double average(double x, double y)
{
	return (x + y) / 2.0;
}

extern "C" COMPUTE_EXPORT double product(double x, double y)
{
	return x * y;
}

extern "C" COMPUTE_EXPORT double quotient(double x, double y)
{
	return x / y;
}

extern "C" COMPUTE_EXPORT double difference(double x, double y)
{
	return x - y;
}

/**
struct Compute
{
	double x, y;

	Compute()
		: x(0.0), y(0.0)
	{}

	Compute(double a, double b)
		: x(a), y(b)
	{}

	extern "C" COMPUTE_EXPORT double sum(double x, double y)
	{
		return x + y;
	}

	extern "C" COMPUTE_EXPORT double average(double x, double y)
	{
		return (x + y) / 2.0;
	}

	extern "C" COMPUTE_EXPORT double product(double x, double y)
	{
		return x * y;
	}

	extern "C" COMPUTE_EXPORT double quotient(double x, double y)
	{
		return x / y;
	}

	extern "C" COMPUTE_EXPORT double difference(double x, double y)
	{
		return x - y;
	}
};
*/
