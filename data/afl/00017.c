// Modification timestamp: 2023-08-03 15:00:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00017.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <x_value> <y_value>\n", argv[0]);
        return 1;
    }

    struct { int x; int y; } s;

    s.x = atoi(argv[1]);
    s.y = atoi(argv[2]);
    return s.y - s.x - 2;
}
