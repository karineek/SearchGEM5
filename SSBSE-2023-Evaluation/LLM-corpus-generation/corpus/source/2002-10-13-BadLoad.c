// Modification timestamp: 2023-08-14 17:11:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-10-13-BadLoad.c
#include <stdlib.h>

#include <stdio.h>

unsigned long window_size = 0x10000;

unsigned test(unsigned long x) {
	return (unsigned)x;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	unsigned long x = strtoul(argv[1], NULL, 0);

	printf("%d\n", test(x));
	return 0;
}
