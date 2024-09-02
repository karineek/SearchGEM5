// Modification timestamp: 2023-08-04 14:08:59
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00090.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a[3] = {0, 1, 2};

	if (argc != 4) {
		printf("Usage: %s <a[0]> <a[1]> <a[2]>\n", argv[0]);
		return 1;
	}

	a[0] = atoi(argv[1]);
	a[1] = atoi(argv[2]);
	a[2] = atoi(argv[3]);

	if (a[0] != 0)
		return 1;
	if (a[1] != 1)
		return 2;
	if (a[2] != 2)
		return 3;

	return 0;
}
