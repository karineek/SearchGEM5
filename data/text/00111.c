
// Modification timestamp: 2023-08-04 14:12:21
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00111.c
#include <stdio.h>

int main() {
    short s = 1;
    long l = 1;

    s -= l;
    return s;
}
