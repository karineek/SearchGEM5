
// Modification timestamp: 2023-08-04 13:45:27
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00045.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <x> <y> <p>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    long y = atol(argv[2]);
    int *p = (int *) strtol(argv[3], NULL, 16);

    if (x != 5)
        return 1;
    if (y != 6)
        return 2;
    if (*p != 5)
        return 3;

    return 0;
}
