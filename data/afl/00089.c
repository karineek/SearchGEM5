c
// Modification timestamp: 2023-08-04 14:08:46
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00089.c

#include <stdio.h>
#include <stdlib.h>

int zero()
{
	return 0;
}

struct S
{
	int (*zerofunc)();
} s = { &zero };

struct S * anon()
{
	return &s;
}

typedef struct S * (*fty)();

fty go()
{
	return &anon;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	int x = atoi(argv[1]);
	return go()()->zerofunc();
}
