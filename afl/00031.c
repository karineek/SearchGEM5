// Modification timestamp: 2023-08-03 18:00:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00031.c
#include <stdio.h>
#include <stdlib.h>

int zero() {
    return 0;
}

int one() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x;
    int y;

    x = atoi(argv[1]);
    y = ++x;
    if (x != 1)
        return 1;
    if (y != 1)
        return 1;

    x = atoi(argv[1]);
    y = --x;
    if (x != 0)
        return 1;
    if (y != 0)
        return 1;

    x = atoi(argv[1]);
    y = x++;
    if (x != 1)
        return 1;
    if (y != 0)
        return 1;

    x = atoi(argv[1]);
    y = x--;
    if (x != 0)
        return 1;
    if (y != 1)
        return 1;

    return 0;
}
