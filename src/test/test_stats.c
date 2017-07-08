#include <math.h>
#include <stdlib.h>

#include <stats.h>

#include "test.h"

int
main()
{
	Real x1[] = {-2,-1,0,1,2},
		x2[] = {1, 0, 2, 2, 0},
		y1[] = {3, 0, 6, 6, 0},
		y2[] = {0,10,0,0,20},
		X[100000], Y[100000];
	Index n = 5, N = 100000, i;

	testrel(Real, ==, round(1e5*dcov1(y1,n,y1,n)), 599040);
	testrel(Real, ==, round(1e5*dcorr1(x2,n,y1,n)), 100000);
	testrel(Real, ==, round(1e5*dcorr1(x2,n,y2,n)), 76181);
	testrel(Real, ==, round(1e5*dcorr1(x1,n,y2,n)), round(1e5*dcov1(x1,n,y2,n) / sqrt(dcov1(x1,n,x1,n)*dcov1(y2,n,y2,n))));

	for (i = 0; i < N; ++i) {
		X[i] = (Real)rand() / RAND_MAX;
		Y[i] = X[i]*X[i];
	}
	testtime(1L, dcorr1(X,N,Y,N));
}
