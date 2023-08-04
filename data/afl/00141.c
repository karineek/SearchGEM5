
// Modification timestamp: 2023-08-04 14:23:02
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00141.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <foo> <bar> <CAT_foo_bar> <XCAT_FOO_BAR>\n", argv[0]);
        return 1;
    }

    int foo = atoi(argv[1]);
    int bar = atoi(argv[2]);
    int foobar = atoi(argv[3]);

    CAT(foo,bar) = foo + bar;
    XCAT(FOO,BAR) = foo + bar;
    return 0;
}
