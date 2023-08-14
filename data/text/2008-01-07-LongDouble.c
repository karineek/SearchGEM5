
// Modification timestamp: 2023-08-10 15:56:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/2008-01-07-LongDouble.c

#include <stdio.h>

int main(void) {
    long double x = 1.0;
    printf("%Lf %Lf\n", x, x);
    return 0;
}
