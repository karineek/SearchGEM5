
// Modification timestamp: 2023-08-04 14:13:37
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00120.c

#include <stdio.h>
#include <stdlib.h>

struct {
	enum { X } x;
} s;


int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	int X = atoi(argv[1]);
	return X;
}
