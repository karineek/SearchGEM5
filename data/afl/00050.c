// Modification timestamp: 2023-08-04 13:47:20
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00050.c

#include <stdio.h>
#include <stdlib.h>

struct S1 {
    int a;
    int b;
};

struct S2 {
    int a;
    int b;
    union {
        int c;
        int d;
    };
    struct S1 s;
};

int main(int argc, char *argv[]) {
    struct S2 v = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), {atoi(argv[4]), atoi(argv[5])}};

    if (v.a != 1)
        return 1;
    if (v.b != 2)
        return 2;
    if (v.c != 3 || v.d != 3)
        return 3;
    if (v.s.a != 4)
        return 4;
    if (v.s.b != 5)
        return 5;

    return 0;
}
