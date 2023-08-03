// Modification timestamp: 2023-08-03 16:16:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00022.c
#include <stdio.h>
#include <stdlib.h>

typedef int x;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x v = atoi(argv[1]);
    return v;
}
