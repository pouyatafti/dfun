#include <math.h>

#include "stats.h"
#include "num.h"


Real
dcov1(Real *x, Index nx, Real *y, Index ny)
{
	Index i, j, n;
	Real aij, bij, ai, bi, di, a, b, d;
	Real *xi, *xj, *yi, *yj;

	n = nx < ny ? nx : ny;

	a = 0;
	b = 0;
	d = 0;
	xi = x;
	yi = y;
	for (i=0; i<n; ++i, ++xi, ++yi) {
		ai = 0;
		bi = 0;
		di = 0;
		xj = x;
		yj = y;
		for (j=0; j<n; ++j, ++xj, ++yj) {
			aij = ABS(*xi - *xj);
			bij = ABS(*yi - *yj);
			ai += aij;
			bi += bij;
			di += aij * bij;
		}
		a += ai/n;
		b += bi/n;
		d += (di - 2*ai*bi/n)/n;
	}
	d += a*b/n;
	return d/n;
}

Real
dcorr1(Real *x, Index nx, Real *y, Index ny)
{
	Index i, j, n;
	Real aij, bij, ai, bi, di, dix, diy, a, b, d, dx, dy;
	Real *xi, *xj, *yi, *yj;

	n = nx < ny ? nx : ny;

	a = 0;
	b = 0;
	d = 0; dx = 0; dy = 0;
	xi = x;
	yi = y;
	for (i=0; i<n; ++i, ++xi, ++yi) {
		ai = 0;
		bi = 0;
		di = 0; dix = 0; diy = 0;
		xj = x;
		yj = y;
		for (j=0; j<n; ++j, ++xj, ++yj) {
			aij = ABS(*xi - *xj);
			bij = ABS(*yi - *yj);
			ai += aij;
			bi += bij;
			di += aij * bij;
			dix += aij * aij;
			diy += bij * bij;
		}
		a += ai/n;
		b += bi/n;
		d += (di - 2*ai*bi/n)/n;
		dx += (dix - 2*ai*ai/n)/n;
		dy += (diy - 2*bi*bi/n)/n;
	}
	d += a*b/n;
	dx += a*a/n;
	dy += b*b/n;

	return d/SQRT(dx*dy);
}

