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
