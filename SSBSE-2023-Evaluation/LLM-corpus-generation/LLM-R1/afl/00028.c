// Modification timestamp: 2023-08-03 17:16:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00028.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x;
    x = atoi(argv[1]);
    x = x & 3;
    return x - 1;
}
