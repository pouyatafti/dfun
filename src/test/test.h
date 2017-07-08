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
	struct timespec testtime_ts, testtime_te; \
	double testtime_t; \
	long testtime_i; \
	printf("timing %ld x " #statement "... ", n); \
	clock_gettime(CLOCK_MONOTONIC, &testtime_ts); \
	for (testtime_i = 0; testtime_i < n; ++testtime_i) { \
		statement; \
	} \
	clock_gettime(CLOCK_MONOTONIC, &testtime_te); \
	testtime_t = (testtime_te.tv_sec-testtime_ts.tv_sec); \
	testtime_t += (testtime_te.tv_nsec-testtime_ts.tv_nsec) / 1000000000.0; \
	printf("%fs total, %fms per iteration\n", testtime_t, 1000*testtime_t/n); \
}
