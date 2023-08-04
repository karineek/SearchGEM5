
// Modification timestamp: 2023-08-04 14:33:47
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00178.c

#include <stdio.h>

int main() {
    char a;
    int b;
    double c;

    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(b));
    printf("%d\n", sizeof(c));

    printf("%d\n", sizeof(!a));

    return 0;
}

