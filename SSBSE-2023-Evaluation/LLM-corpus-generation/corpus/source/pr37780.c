// Modification timestamp: 2023-08-14 15:00:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr37780.c

#include <stdio.h>
#include <stdlib.h>

#define VAL (8 * sizeof (int))

int __attribute__ ((noinline, noclone))
fooctz(int i)
{
    return (i == 0) ? VAL : __builtin_ctz(i);
}

int __attribute__ ((noinline, noclone))
fooctz2(int i)
{
    return (i != 0) ? __builtin_ctz(i) : VAL;
}

unsigned int __attribute__ ((noinline, noclone))
fooctz3(unsigned int i)
{
    return (i > 0) ? __builtin_ctz(i) : VAL;
}

int __attribute__ ((noinline, noclone))
fooclz(int i)
{
    return (i == 0) ? VAL : __builtin_clz(i);
}

int __attribute__ ((noinline, noclone))
fooclz2(int i)
{
    return (i != 0) ? __builtin_clz(i) : VAL;
}

unsigned int __attribute__ ((noinline, noclone))
fooclz3(unsigned int i)
{
    return (i > 0) ? __builtin_clz(i) : VAL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int result = 0;
    int arg = atoi(argv[1]);

    if (arg == 0)
    {
        result = VAL;
    }
    else
    {
        result = __builtin_ctz(arg);
    }
    
    if (result != VAL)
    {
        __builtin_abort();
    }

    return 0;
}
