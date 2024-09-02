// Modification timestamp: 2023-08-03 16:17:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00023.c
#include <stdio.h>
#include <stdlib.h>

int x;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);
    return x;
}
