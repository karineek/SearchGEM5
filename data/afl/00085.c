
// Modification timestamp: 2023-08-04 14:03:08
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00085.c

#include <stdio.h>
#include <stdlib.h>

#define ZERO_0() argv[1]
#define ZERO_1(A) argv[1]
#define ZERO_2(A, B) argv[1]
#define ZERO_VAR(...) argv[1]
#define ZERO_1_VAR(A, ...) argv[1]

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	if (atoi(ZERO_0()))
		return 1;
	if (atoi(ZERO_1(1)))
		return 1;
	if (atoi(ZERO_2(1, 2)))
		return 1;
	if (atoi(ZERO_VAR(1)))
		return 1;
	if (atoi(ZERO_VAR(1, 2)))
		return 1;
	if (atoi(ZERO_1_VAR(1, 2)))
		return 1;
	if (atoi(ZERO_1_VAR(1, 2, 3)))
		return 1;

	return 0;
}
