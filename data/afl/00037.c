
// Modification timestamp: 2023-08-04 13:38:57
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00037.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x[2];
    int *p;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x[1] = atoi(argv[1]);
    p = &x[0];
    p = p + 1;

    if(*p != x[1])
        return 1;
    if(&x[1] - &x[0] != 1)
        return 1;

    return 0;
}
