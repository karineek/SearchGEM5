// Modification timestamp: 2023-08-03 10:15:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00009.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);
    x = x * 10;
    x = x / 2;
    x = x % 3;
    return x - 2;
}
