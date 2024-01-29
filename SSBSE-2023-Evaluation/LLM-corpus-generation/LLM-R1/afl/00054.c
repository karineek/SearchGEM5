// Modification timestamp: 2023-08-04 13:49:02
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00054.c

#include <stdio.h>
#include <stdlib.h>

enum E {
	x,
	y,
	z,
};

int main(int argc, char *argv[]) {
	enum E e;

	if(x != atoi(argv[1]))
		return 1;
	if(y != atoi(argv[2]))
		return 2;
	if(z != atoi(argv[3]))
		return 3;

	e = x;
	return e;
}
