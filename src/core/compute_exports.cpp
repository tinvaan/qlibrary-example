extern "C" COMPUTE_EXPORT Compute* _compute()
{
	return new Compute();
}

extern "C" COMPUTE_EXPORT double _sum(double x, double y)
{
	Compute *c = _compute();
	return c->sum(x, y);
}

extern "C" COMPUTE_EXPORT double _diff(double x, double y)
{
	Compute *c = _compute();
	return c->difference(x, y);
}

extern "C" COMPUTE_EXPORT double _mul(double x, double y)
{
	Compute *c = _compute();
	return c->product(x, y);
}

extern "C" COMPUTE_EXPORT double _div(double x, double y)
{
	Compute *c = _compute();
	return c->quotient(x, y);
}

extern "C" COMPUTE_EXPORT double _avg(double x, double y)
{
	Compute *c = _compute();
	return c->average(x, y);
}
