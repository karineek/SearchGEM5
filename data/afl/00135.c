// Modification timestamp: 2023-08-04 14:21:54
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00135.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long long i;
    unsigned long long u;

    i = 1;
    i = -1;
    i = -1l;
    i = -1u;
    i = -1ll;
    i = -1ll & 3;
    i = -1ll < 0;

    u = 1;
    u = -1;
    u = -1l;
    u = -1u;
    u = -1ll;
    u = -1llu & 3;
    u = -1llu < 0;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    return 0;
}
