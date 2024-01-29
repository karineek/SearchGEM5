// Modification timestamp: 2023-08-03 13:30:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00014.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int *p;

    x = 1;
    p = &x;
    p[0] = 0;
    return x;
}
