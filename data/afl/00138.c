
// Modification timestamp: 2023-08-04 14:22:28
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00138.c

#include <stdio.h>
#include <stdlib.h>

#define M(x) x
#define A(a,b) a(b)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    char *a = A(M, argv[1]);
    return (a[1] == 'i') ? 0 : 1;
}
