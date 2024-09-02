// Modification timestamp: 2023-08-14 13:17:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20090623-1.c

#include <stdio.h>
#include <stdlib.h>

int * __restrict__ x;

int foo (int y)
{
    *x = y;
    return *x;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int i = atoi(argv[1]);
    x = &i;
    if (foo(i) != i)
        return 1;

    return 0;
}
