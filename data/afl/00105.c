
// Modification timestamp: 2023-08-04 14:11:26
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00105.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i;

	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	int x = atoi(argv[1]);

	for(i = 0; i < x; i++)
		if (!i)
			continue;

	return 0;
}
