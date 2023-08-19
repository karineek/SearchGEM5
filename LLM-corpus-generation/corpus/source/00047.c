// Modification timestamp: 2023-08-04 13:46:20
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00047.c

#include <stdio.h>
#include <stdlib.h>

struct { int a; int b; int c; } s;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <a> <b> <c>\n", argv[0]);
        return 1;
    }

    s.a = atoi(argv[1]);
    s.b = atoi(argv[2]);
    s.c = atoi(argv[3]);

    if (s.a != 1)
        return 1;
    if (s.b != 2)
        return 2;
    if (s.c != 3)
        return 3;

    return 0;
}
