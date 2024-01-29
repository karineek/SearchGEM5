// Modification timestamp: 2023-08-14 14:42:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/packed-2.c
#include <stdlib.h>

#include <stdio.h>

typedef struct s {
	unsigned short a;
	unsigned long b __attribute__ ((packed));
} s;

s t;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	t.b = atoi(argv[1]);
	return 0;
}
