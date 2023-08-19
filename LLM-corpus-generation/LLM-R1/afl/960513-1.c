// Modification timestamp: 2023-08-14 13:46:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960513-1.c

#include <stdio.h>
#include <stdlib.h>

long double f(long double d, int i) {
    long double e;

    d = -d;
    e = d;
    if (i == 1)
        d *= 2;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    return d;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <d> <i>\n", argv[0]);
        return 1;
    }

    long double d = atof(argv[1]);
    int i = atoi(argv[2]);

    if (!(int)(f(d, i))) {
        abort();
    }

    exit(0);
}
