// Modification timestamp: 2023-08-04 14:31:14
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00172.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <a> <b>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int *d;
    int *e;
    d = &a;
    e = &b;
    printf("%d\n", *d);
    printf("%d\n", *e);
    printf("%d\n", d == e);
    printf("%d\n", d != e);
    d = e;
    printf("%d\n", d == e);
    printf("%d\n", d != e);

    return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
