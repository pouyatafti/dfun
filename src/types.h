#ifndef __DFUN_TYPES_H__
#define __DFUN_TYPES_H__

typedef struct IEEEDouble IEEEDouble;
struct IEEEDouble {
	unsigned long long base : 52;
	unsigned int exp : 11;
	unsigned int sign: 1;	
};

typedef union Double Double;
union Double {
	double f;
	IEEEDouble ieee;
};

typedef struct IEEESingle IEEESingle;
struct IEEESingle {
	unsigned long base : 23;
	unsigned int exp : 8;
	unsigned int sign: 1;
};

typedef union Single Single;
union Single {
	float f;
	IEEESingle ieee;
};

typedef long Index;

#ifdef SINGLE

typedef float Real;

#else

typedef double Real;

#endif

#endif