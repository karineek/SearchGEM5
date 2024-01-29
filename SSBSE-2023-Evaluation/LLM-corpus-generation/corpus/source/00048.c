// Modification timestamp: 2023-08-04 13:46:45
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00048.c

#include <stdio.h>
#include <stdlib.h>

struct S {int a; int b;};
struct S s;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    s.a = atoi(argv[1]);
    s.b = atoi(argv[2]);

    if (s.a != 1)
        return 1;
    if (s.b != 2)
        return 2;
    return 0;
}
