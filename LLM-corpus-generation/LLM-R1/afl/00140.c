// Modification timestamp: 2023-08-04 14:22:50
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00140.c

#include <stdarg.h>
#include <stdio.h>

struct foo {
	int i, j, k;
	char *p;
	float v;
};

int f1(struct foo f, struct foo *p, int n, ...) {
	if (f.i != p->i)
		return 0;
	return p->j + n;
}

int main(int argc, char* argv[]) {
	struct foo f;

	f.i = f.j = 1;
	f1(f, &f, 2);
	f1(f, &f, 2, argc, argv, f, &f);

	return 0;
}
