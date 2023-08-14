
// Modification timestamp: 2023-08-10 16:20:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/MultiSource/Applications/oggenc/oggenc_main.c

#include <stdio.h>
#include <stdlib.h>

int f(int a, int *y) {
    int x = a;

    if (a == 0)
        return *y;

    return f(a - 1, &x);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int y = atoi(argv[1]);
    if (f(100, &y) != 1)
        abort();
    exit(0);
}
