// Modification timestamp: 2023-08-04 13:43:15
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00044.c

#include <stdio.h>
#include <stdlib.h>

struct T;

struct T {
    int x;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct T v;
    { struct T { int z; }; }
    v.x = atoi(argv[1]);
    if(v.x != 2)
        return 1;
    return 0;
}
