// Modification timestamp: 2023-08-04 14:01:03
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00080.c

#include <stdio.h>
#include <stdlib.h>

void voidfn() {
    return;
}

int main(int argc, char *argv[]) {
    voidfn();
    return 0;
}
