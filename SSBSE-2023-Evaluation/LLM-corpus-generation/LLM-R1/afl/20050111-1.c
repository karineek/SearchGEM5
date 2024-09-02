// Modification timestamp: 2023-08-14 13:01:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050111-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned int foo(unsigned long long x) {
	unsigned int u;

	if (x == 0)
		return 0;
	u = (unsigned int)(x >> 32);
	return u;
}

unsigned long long bar(unsigned short x) {
	return (unsigned long long)x << 32;
}

extern void abort(void);

int main(int argc, char *argv[]) {
	if (sizeof(long long) != 8)
		return 0;

	if (foo(atoi(argv[1])) != atoi(argv[2]))
		abort();
	if (foo(0xffffffffULL) != atoi(argv[3]))
		abort();
	if (foo(0x25ff00ff00ULL) != atoi(argv[4]))
		abort();
	if (bar(atoi(argv[5])) != atoll(argv[6]))
		abort();
	if (bar(0x25) != atoll(argv[7]))
		abort();
	return 0;
}
