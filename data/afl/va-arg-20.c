// Modification timestamp: 2023-08-14 16:58:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-20.c

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void foo(va_list v)
{
    unsigned long long x = va_arg(v, unsigned long long);
    if (x != 16LL)
        abort();
}

void bar(char c, char d, ...)
{
    va_list v;
    va_start(v, d);
    foo(v);
    va_end(v);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    bar(argv[1][0], argv[1][1], strtoull(argv[1] + 2, NULL, 10));
    exit(0);
}
