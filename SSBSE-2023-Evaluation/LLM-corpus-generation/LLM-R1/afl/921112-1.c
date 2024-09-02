// Modification timestamp: 2023-08-14 13:31:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921112-1.c

#include <stdio.h>
#include <stdlib.h>

union u {
    struct { int i1, i2; } t;
    double d;
} x[2], v;

void f(union u *x, union u v) {
    *++x = v;
}

int main(int argc, char *argv[]) {
    x[1].t.i1 = x[1].t.i2 = 0;
    v.t.i1 = atoi(argv[1]);
    v.t.i2 = atoi(argv[2]);
    f(x, v);
    if (x[1].t.i1 != atoi(argv[3]) || x[1].t.i2 != atoi(argv[4])) {
        abort();
    }
    exit(0);
}


Note: The code assumes that the command-line arguments `argv[1]`, `argv[2]`, `argv[3]`, and `argv[4]` are provided during the execution of the program.