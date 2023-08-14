// Modification timestamp: 2023-08-14 13:13:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080424-1.c

/* PR tree-optimization/36008 */

#include <stdio.h>
#include <stdlib.h>

int g[48][3][3];

void __attribute__((noinline)) bar(int x[3][3], int y[3][3])
{
    static int i;
    if (x != g[i + 8] || y != g[i++])
        abort();
}

static inline void __attribute__((always_inline)) foo(int x[][3][3])
{
    int i;
    for (i = 0; i < 8; i++)
    {
        int k = i + 8;
        bar(x[k], x[k - 8]);
    }
}

int main(int argc, char *argv[])
{
    foo(g);
    return 0;
}

Note: The `abort()` function is part of `<stdlib.h>`.