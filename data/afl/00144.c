c
// Modification timestamp: 2023-08-04 14:24:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00144.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, *q;
    void *p;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    i = atoi(argv[1]);
    p = i ? (void *) 0 : 0;
    p = i ? 0 : (void *) 0;
    p = i ? 0 : (const void *) 0;
    q = i ? 0 : p;
    q = i ? p : 0;
    q = i ? q : 0;
    q = i ? 0 : q;

    return (int) q;
}
