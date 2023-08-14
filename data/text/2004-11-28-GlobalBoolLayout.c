// Modification timestamp: 2023-08-14 17:16:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2004-11-28-GlobalBoolLayout.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct S { _Bool X, Y; char str[100]; };

struct S G = { 1, 1, "fooo" };

int main() {
	int X = strlen(G.str);
	if (X == 10) {
	  scanf("%d, %d\n", &G.X, &G.Y);
        }
	printf("%d %d %d\n", G.X, G.Y, X);
	return X-4;
}

