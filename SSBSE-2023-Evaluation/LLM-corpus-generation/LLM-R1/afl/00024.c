// Modification timestamp: 2023-08-03 16:17:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00024.c
#include <stdio.h>
#include <stdlib.h>

typedef struct { int x; int y; } s;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value_x> <value_y>\n", argv[0]);
        return 1;
    }

    s v;
    v.x = atoi(argv[1]);
    v.y = atoi(argv[2]);
    return 3 - v.x - v.y;
}
