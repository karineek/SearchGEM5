// Modification timestamp: 2023-08-14 12:15:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020411-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float imag;
} complex_float;

typedef struct {
    double real;
    double imag;
} complex_double;

complex_float foo(void)
{
    complex_float f[1];
    f[0].real = 1.0;
    f[0].imag = 1.0;
    f[0].real = -f[0].real;
    return f[0];
}

int main(int argc, char *argv[]) {
    complex_double d[1];
    complex_float temp = foo();
    d[0].real = temp.real;
    d[0].imag = temp.imag;
    if (d[0].real != 1.0 || d[0].imag != -1.0) {
        abort();
    }
    exit(0);
}
