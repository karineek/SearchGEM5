// Modification timestamp: 2023-08-02 15:30:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00049.c

#include <stdio.h>
#include <stdlib.h>

struct S {int a; int *p;};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    struct S s = { .p = &x, .a = 1};

    if(s.a != 1)
        return 1;
    if(*s.p != x)
        return 2;
    return 0;
}
