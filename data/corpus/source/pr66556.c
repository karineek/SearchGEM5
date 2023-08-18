// Modification timestamp: 2023-08-14 15:45:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr66556.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct {
	unsigned f2;
	unsigned f3 : 15;
	unsigned f5 : 3;
	short f6;
} b = {0x7f8000, 6, 5, 0}, g = {8, 0, 5, 0};

short d, l;
int a, c, h = 8;
volatile char e[237] = {4};
short *f = &d;
short i[5] = {3};
char j;
int *k = &c;

int fn1(unsigned p1) {
	return -p1;
}

void fn2(char p1) {
	a = p1;
	e[0];
}

short fn3() {
	*k = 4;
	return *f;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	unsigned m;
	short *n = &i[4];

	m = fn1((h && j) <= b.f5);
	l = m > g.f3;
	*n = atoi(argv[1]);
	fn2(b.f2 >> 15);
	if ((a & 0xff) != 0xff)
		abort();

	return 0;
}