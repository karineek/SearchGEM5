// Modification timestamp: 2023-08-03 15:01:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00018.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <x_value> <y_value>\n", argv[0]);
        return 1;
    }

    struct S { int x; int y; } s;
    struct S *p;

    p = &s;
    s.x = atoi(argv[1]);
    p->y = atoi(argv[2]);
    return p->y + p->x - 3;
}
