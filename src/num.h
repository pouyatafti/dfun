#ifndef __DFUN_NUM_H__
#define __DFUN_NUM_H__

#include "types.h"

Real ipow(Real base, int exp);
Real lpi(int p, Real *x, Index n);
Real lp(Real p, Real *x, Index n);

#ifndef POW
#ifdef SINGLE
#define POW powf
#else
#define POW pow
#endif
#endif

#ifndef SQRT
#ifdef SINGLE
#define SQRT sqrtf
#else
#define SQRT sqrt
#endif
#endif

#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif

#endif