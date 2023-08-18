// Modification timestamp: 2023-08-04 14:10:53
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00102.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	int x = atoi(argv[1]);
	if ((x << 1) != 2)
		return 1;

	return 0;
}
