
// Modification timestamp: 2023-08-04 14:08:35
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00088.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int (*fptr)() = 0;

    if (fptr)
        return 1;
    return 0;
}
