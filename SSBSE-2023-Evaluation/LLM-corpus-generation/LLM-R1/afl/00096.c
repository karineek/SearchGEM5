// Modification timestamp: 2023-08-04 14:10:07
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00096.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x, x = atoi(argv[1]), x;

    if (x != atoi(argv[1]))
        return 0;

    x = 0;
    return x;
}
