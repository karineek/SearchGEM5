// Modification timestamp: 2023-08-14 15:18:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49712.c
#include <stdlib.h>

#include <stdio.h>

int a[2], b, c, d, e;

void foo(int x, int y)
{
}

int bar(void)
{
    int i;
    for (; d <= 0; d = 1)
        for (i = 0; i < 4; i++)
            for (e = 0; e; e = 1)
                ;
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    for (b = 0; b < 2; b++)
        while (c)
            foo(a[b] = atoi(argv[1]), bar());
    return 0;
}
