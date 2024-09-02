// Modification timestamp: 2023-08-14 15:56:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr81588.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) int bar(int x)
{
    __asm volatile("" : : "g"(x) : "memory");
}

__attribute__((noinline, noclone)) int foo(unsigned x, long long y)
{
    if (y < 0)
        return 0;
    if (y < (long long)(4 * x))
    {
        bar(y);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <x> <y>\n", argv[0]);
        return 1;
    }

    unsigned x = atoi(argv[1]);
    long long y = atoll(argv[2]);

    if (foo(x, y) != 0)
        __builtin_abort();
    y = -1;
    if (foo(x, y) != 0)
        __builtin_abort();
    y = 0;
    if (foo(x, y) != 1)
        __builtin_abort();
    y = 39;
    if (foo(x, y) != 1)
        __builtin_abort();
    y = 40;
    if (foo(x, y) != 0)
        __builtin_abort();
    y = 10000;
    if (foo(x, y) != 0)
        __builtin_abort();
    return 0;
}
