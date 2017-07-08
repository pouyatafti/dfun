#include <math.h>

#include <num.h>

#include "test.h"

int
main()
{
	Real x[] = {1,0,2,2,0};
	Index nx = 5;

	testrel(Real, ==, ipow(2.0, 3), pow(2.0, 3));
	testrel(Real, ==, ipow(2.0,-3), pow(2.0, -3));

	testrel(Real, ==, lpi(2,x,nx), 3.0);

	testrel(Real, ==, lp(1.0,x,nx), 5.0);
	testrel(Real, ==, lp(2.0,x,nx), 3.0);
}