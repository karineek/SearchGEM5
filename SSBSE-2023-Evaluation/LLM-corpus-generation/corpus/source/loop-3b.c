// Modification timestamp: 2023-08-14 14:31:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-3b.c
#include <stdio.h>

#include <limits.h>
#include <stdlib.h>

int n = 0;

void g(int i) {
    n++;
}

void f(int m) {
    int i;
    i = m;
    do {
        g(i * 4);
        i -= INT_MAX / 8;
    } while (i > 0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int m = atoi(argv[1]);

    f(m);

    if (n != 4)
        abort ();

    exit(0);
}
