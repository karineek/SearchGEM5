// Modification timestamp: 2023-08-14 13:13:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080502-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

long double __attribute__((noinline)) foo(long double x)
{
    return __builtin_signbit(x) ? 3.1415926535897932384626433832795029L : 0.0;
}

int main(int argc, char *argv[])
{
    long double x = atof(argv[1]);
    if (foo(x) != 3.1415926535897932384626433832795029L)
        abort();
    return 0;
}
