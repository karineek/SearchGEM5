// Modification timestamp: 2023-08-04 14:00:11
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00077.c

#include <stdio.h>
#include <stdlib.h>

int foo(int x[100]) {
    int y[100];
    int *p;

    y[0] = 2000;

    if (x[0] != 1000) {
        return 1;
    }

    p = x;

    if (p[0] != 1000) {
        return 2;
    }

    p = y;

    if (p[0] != 2000) {
        return 3;
    }

    if (sizeof(x) != sizeof(void *)) {
        return 4;
    }

    if (sizeof(y) <= sizeof(x)) {
        return 5;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int x[100];

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x[0] = atoi(argv[1]);

    return foo(x);
}
