// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00009.c
#include <stdio.h>

int main() {
    int x;

    x = 1;
    x = x * 10;
    x = x / 2;
    x = x % 3;
    return x - 2;
}
