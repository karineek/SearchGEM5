
// Modification timestamp: 2023-08-10 16:33:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000519-1.c
#include <string.h>
#include <stdio.h>

#include <stdarg.h>
#include <stdlib.h>

int bar (int a, va_list ap) {
    int b;

    do {
        b = va_arg (ap, int);
    } while (b > 10);

    return a + b;
}

int foo (int a, ...) {
    va_list ap;

    va_start (ap, a);
    return bar (a, ap);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <int> <int> <int>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    if (foo (a, b, c) != 3)
        abort ();
    return 0;
}
