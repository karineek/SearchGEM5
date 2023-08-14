// Modification timestamp: 2023-08-14 15:15:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr47148.c

#include <stdio.h>
#include <stdlib.h>

static inline unsigned bar(unsigned x, unsigned y)
{
    if (y >= 32)
        return x;
    else
        return x >> y;
}

static unsigned a = 1, b = 1;

static inline void foo(unsigned char x, unsigned y)
{
    if (!y)
        return;
    unsigned c = (0x7000U / (x - 2)) ^ a;
    unsigned d = bar(a, a);
    b &= ((a - d) && (a - 1)) + c;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <x> <y>\n", argv[0]);
        return 1;
    }

    unsigned char x = (unsigned char)atoi(argv[1]);
    unsigned y = atoi(argv[2]);

    foo(x, y);

    if (b && ((unsigned char)-1) == 255)
        abort();

    return 0;
}
