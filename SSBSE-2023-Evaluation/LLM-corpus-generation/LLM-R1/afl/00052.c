// Modification timestamp: 2023-08-04 13:48:29
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00052.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct T { int x; };
    {
        struct T s;
        s.x = atoi(argv[1]);
        return s.x;
    }
}
