// Modification timestamp: 2023-08-14 13:32:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921208-1.c

#include <stdio.h>
#include <stdlib.h>

double f(double x) {
    return x * x;
}

double Int(double (*f)(double), double a) {
    return (*f)(a);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    double result = Int(&f, atof(argv[1]));
    if (result != atof(argv[2])) {
        abort();
    }

    exit(0);
}
