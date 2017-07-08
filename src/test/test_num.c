#include <math.h>
#include <stdlib.h>

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

	testtime(1000000L, ipow((Real)10 * rand() / RAND_MAX, rand() % 15));
	testtime(1000000L, pow((Real)10 * rand() / RAND_MAX, rand() % 15));

}