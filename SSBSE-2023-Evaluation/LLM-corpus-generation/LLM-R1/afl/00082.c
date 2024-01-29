// Modification timestamp: 2023-08-04 14:01:43
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00082.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned long long x;

    x = 0;
    x = x + 1;
    if (x != 1)
        return 1;
    return 0;
}
