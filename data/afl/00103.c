
// Modification timestamp: 2023-08-04 14:11:04
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00103.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x;
    void *foo;
    void **bar;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);

    foo = (void*)&x;
    bar = &foo;

    return **(int**)bar;
}
