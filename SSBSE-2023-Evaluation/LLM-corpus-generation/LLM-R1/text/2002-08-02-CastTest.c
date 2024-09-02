// Modification timestamp: 2023-08-14 17:11:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-08-02-CastTest.c
#include <stdio.h>

unsigned test(unsigned X) {
  return (unsigned char)X;
}

int main() {
	printf("%d\n", test(123456));
        return 0;
}

