// Modification timestamp: 2023-08-14 17:11:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-10-12-StructureArgsSimple.c
#include <stdio.h>

struct vec2 { double X, Y; };

void print(struct vec2 S) {
	printf("%f, %f\n", S.X, S.Y);
}

int main() {
	struct vec2 U;
	U.X = .5; U.Y = 1.2;
	print(U);
	return 0;
}
