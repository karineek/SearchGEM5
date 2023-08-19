// Modification timestamp: 2023-08-14 17:11:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-10-12-StructureArgs.c
#include <stdio.h>

struct vec2 { double X, Y; };

void print(struct vec2 S, struct vec2 T) {
	printf("%f, %f, %f, %f\n", S.X, S.Y, T.X, T.Y);
}

int main() {
	struct vec2 U, V;
	U.X = .5; U.Y = 1.2;
	V.X = -123.01; V.Y = 1/3.0;
	print(U, V);
	return 0;
}
