// Modification timestamp: 2023-08-04 14:22:09
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00136.c

#include <stdlib.h>
#include <stdio.h>

#define FOO

#ifdef FOO
	int a;
	int b;
	#undef FOO
	#ifndef FOO
		int c;
		int d;
	#else
		int e;
		int f;
	#endif
	int e;
	int f;
	#ifdef FOO
		int c_;
		int d_;
	#else
		int e_;
		int f_;
	#endif
	int e_;
	int f_;
int
main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	int x = atoi(argv[1]);
	return x - 4;
}
#else
	int j;
	int k;
	#ifdef FOO
		int j;
		int k;
	#else
		int n;
		int o;
	#endif
	int n;
	int o;
	#ifndef FOO
		int r;
		int s;
	#else
		int t;
		int u;
	#endif
	int t;
	int u;
	#error bad branch
#endif
