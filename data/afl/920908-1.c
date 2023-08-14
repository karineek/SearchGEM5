// Modification timestamp: 2023-08-14 13:29:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920908-1.c

#include <stdarg.h>
#include <stdlib.h>

typedef struct {
    int A;
} T;

T f(int x, ...) {
    va_list ap;
    T X;
    va_start(ap, x);
    X = va_arg(ap, T);
    if (X.A != 10) abort();
    X = va_arg(ap, T);
    if (X.A != 20) abort();
    va_end(ap);
    return X;
}

int main(int argc, char *argv[]) {
    T X, Y;
    int i;
    X.A = atoi(argv[1]);
    Y.A = atoi(argv[2]);
    f(2, X, Y);
    exit(0);
}
