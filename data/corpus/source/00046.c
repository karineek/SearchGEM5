// Modification timestamp: 2023-08-04 13:46:03
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00046.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    union {
        int b1;
        int b2;
    };
    struct { union { struct { int c; }; }; };
    struct {
        int d;
    };
} s;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <a>\n", argv[0]);
        return 1;
    }

    s v;

    v.a = atoi(argv[1]);
    v.b1 = 2;
    v.c = 3;
    v.d = 4;

    if (v.a != 1)
        return 1;
    if (v.b1 != 2 && v.b2 != 2)
        return 2;
    if (v.c != 3)
        return 3;
    if (v.d != 4)
        return 4;

    return 0;
}
