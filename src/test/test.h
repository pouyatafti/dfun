#include <time.h>
#include <stdio.h>

#define FORMAT_Real "%2.6f"
#define FORMAT_int "%d"


#define testpr(condition, descr, ...) { \
	char str[512]; \
	printf("testing " descr "... "); \
	if (condition) \
		printf("OK\n"); \
	else { \
		sprintf(str, __VA_ARGS__); \
		printf("FAILED [%s]\n", str); \
	} \
}

#define testrel(type, rel, lh, rh) { \
	type l=lh, r=rh; \
	testpr(l rel r, #lh " " #rel " " #rh, FORMAT_##type " not " #rel " " FORMAT_##type, l, r); \
}

#define testtime(n, statement) { \
	clock_t testtime_ts, testtime_te; \
	long testtime_i; \
	printf("timing %ld x " #statement "... ", n); \
	testtime_ts = clock(); \
	for (testtime_i = 0; testtime_i < n; ++testtime_i) { \
		statement; \
	} \
	testtime_te = clock(); \
	printf("%fs total, %fms per iteration\n", (double)(testtime_te-testtime_ts) / CLOCKS_PER_SEC, (double)1000*(testtime_te-testtime_ts) / (CLOCKS_PER_SEC*n)); \
}
