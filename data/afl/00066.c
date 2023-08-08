// Modification timestamp: 2023-08-04 13:55:22
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00066.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if(FOO(1, 2, atoi(argv[1])) != 6)
		return 1;
	return FOO(0, 0, atoi(argv[1]));
}
