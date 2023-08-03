// Modification timestamp: 2023-08-03 16:16:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00021.c
#include <stdio.h>
#include <stdlib.h>

int foo(int a, int b) {
    return 2 + a - b;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    return foo(a, b);
}
