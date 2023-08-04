
// Modification timestamp: 2023-08-04 14:25:57
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00153.c

#include <stdio.h>
#include <stdlib.h>

#define x f
#define y() f

typedef struct { int f; } S;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <x> <y>\n", argv[0]);
        return 1;
    }

    S s;
    s.x = atoi(argv[1]);
    return s.y();
}
