#include <math.h>

#include "stats.h"
#include "num.h"


Real
dcov1(Real *x, Real *y, Index n)
{
	Index i, j;
	Real aij, bij, ai, bi, di, a, b, d;
	Real *xi, *xj, *yi, *yj;

	a = 0;
	b = 0;
	d = 0;
	#pragma omp parallel for private(i, xi, yi, ai, bi, di, j, xj, yj, aij, bij) shared(x, y, n) reduction(+: a, b, d)
	for (i=0; i<n; ++i) {
		ai = 0;
		bi = 0;
		di = 0;
		xi = x+i;
		yi = y+i;
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
dcorr1(Real *x, Real *y, Index n)
{
	Index i, j;
	Real aij, bij, ai, bi, di, dix, diy, a, b, d, dx, dy;
	Real *xi, *xj, *yi, *yj;

	a = 0;
	b = 0;
	d = 0; dx = 0; dy = 0;
	#pragma omp parallel for private(i, xi, yi, ai, bi, di, dix, diy, j, xj, yj, aij, bij) shared(x, y, n) reduction(+: a, b, d, dx, dy)
	for (i=0; i<n; ++i) {
		ai = 0;
		bi = 0;
		di = 0; dix = 0; diy = 0;
		xi = x+i;
		yi = y+i;
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

