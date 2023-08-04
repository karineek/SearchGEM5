
// Modification timestamp: 2023-08-04 14:38:22
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00191.c

#include <stdio.h>

int main() {
    int a;

    for (a = 0; a < 2; a++) {
        int b = a;
    }

    printf("it's all good\n");

    return 0;
}
