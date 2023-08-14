// Modification timestamp: 2023-08-14 16:05:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr89434.c

#include <stdio.h>
#include <stdlib.h>

#if __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ == 8 && __CHAR_BIT__ == 8
long g = 0;

static inline unsigned long long foo(unsigned long long u, unsigned *x)
{
    __builtin_mul_overflow(-1, g, x);
    u |= (unsigned)u < (unsigned short)*x;
    return *x - u;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned long long x = foo(atoll(argv[1]), &argc);
    if (x != atoll("0xfffffffdddddddde"))
        abort();
    return 0;
}
#else
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    return 0;
}
#endif

