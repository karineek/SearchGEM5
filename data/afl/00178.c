
// Modification timestamp: 2023-08-04 14:33:47
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00178.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char a;
    int b;
    double c;

    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(b));
    printf("%d\n", sizeof(c));

    printf("%d\n", sizeof(!a));

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    return 0;
}
