c
// Modification timestamp: 2023-08-04 14:13:47
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00121.c

#include <stdio.h>
#include <stdlib.h>

int f(int a), g(int a), a;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int arg = atoi(argv[1]);

    return f(arg) - g(arg);
}

int f(int a) {
    return a;
}

int g(int a) {
    return a;
}
