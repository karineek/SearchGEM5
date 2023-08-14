// Modification timestamp: 2023-08-14 15:14:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr46316.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

long long __attribute__((noinline, noclone))
foo(long long t)
{
    while (t > -4)
        t -= 2;

    return t;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long long t = atoll(argv[1]);
    if (foo(t) != -4)
        abort();
    return 0;
}
