#include <math.h>

#include "num.h"


Real
ipow(Real base, int exp)
{
	int posexp = exp > 0;
	Real result = 1;

	if (!posexp)
		exp = -exp;

	while (exp) {
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
	
	return posexp ? result : 1/result;
}

Real
lpi(int p, Real *x, Index n)
{
	Index i;
	Real sum = 0;

	for (i = 0; i < n; ++i)
		sum += fabs(ipow(*x++, p));

	return POW(sum, 1.0/p);
}

Real
lp(Real p, Real *x, Index n)
{
	Index i;
	Real sum = 0;

	for (i = 0; i < n; ++i)
		sum += fabs(POW(*x++, p));

	return POW(sum, 1.0/p);
}