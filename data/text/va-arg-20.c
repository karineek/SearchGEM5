// Modification timestamp: 2023-08-14 16:58:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-20.c
#include <stdarg.h>

void foo(va_list v)
{
    unsigned long long x = va_arg (v, unsigned long long);
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

int main(void)
{
    bar(0, 0, 16LL);
    exit(0);
}
