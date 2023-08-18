// Modification timestamp: 2023-08-04 14:09:59
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00095.c

#include <stdio.h>
#include <stdlib.h>

int x;
int x = 3;
int x;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	x = atoi(argv[1]);
	if (x != 3)
		return 0;

	x = 0;
	return x;
}
