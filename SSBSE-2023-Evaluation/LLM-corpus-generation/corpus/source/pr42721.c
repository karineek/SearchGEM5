// Modification timestamp: 2023-08-14 15:10:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42721.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

static unsigned long long foo(unsigned long long x, unsigned long long y)
{
    return x / y;
}

static int a, b;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    unsigned long long c = atoi(argv[1]);
    unsigned long long d = atoi(argv[2]);

    b ^= c && (foo(a, d) != 1L);
    if (b != 1)
        abort();
    return 0;
}
