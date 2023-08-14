// Modification timestamp: 2023-08-14 14:26:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/extzvsi.c

#include <stdio.h>
#include <stdlib.h>

#if __INT_MAX__ < 2147483647
int main(void) {
    exit(0);
}
#else
struct ieee {
    unsigned int negative:1;
    unsigned int exponent:11;
    unsigned int mantissa0:20;
    unsigned int mantissa1:32;
} x;

unsigned int foo(void) {
    unsigned int exponent;
    exponent = x.exponent;
    if (exponent == 0)
        return 1;
    else if (exponent > 1)
        return 2;
    return 0;
}

int main(void) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x.exponent = atoi(argv[1]);
    if (foo() != 0)
        abort();
    return 0;
}
#endif
