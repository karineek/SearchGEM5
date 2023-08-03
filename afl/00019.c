// Modification timestamp: 2023-08-03 16:15:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00019.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct S { struct S *p; int x; } s;

    s.x = atoi(argv[1]);
    s.p = &s;
    return s.p->p->p->p->p->x;
}
