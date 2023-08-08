// Modification timestamp: 2023-08-04 13:41:48
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00042.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    union { int a; int b; } u;
    u.a = atoi(argv[1]);
    u.b = atoi(argv[1]);

    if (u.a != u.b || u.b != u.b)
        return 1;
    return 0;
}
