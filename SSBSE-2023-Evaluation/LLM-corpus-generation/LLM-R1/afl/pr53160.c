// Modification timestamp: 2023-08-14 15:23:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr53160.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int a, c = 1, d, e, g;
volatile int b;
volatile char f;
long h;
short i;

void foo(void)
{
    for (e = 0; e; ++e)
        ;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);

    if (g)
        (void)b;
    foo();
    for (d = 0; d >= 0; d--)
    {
        short j = f;
        int k = x;
        i = j ? j : j << k;
    }
    h = c == 0 ? 0 : i;
    a = h;
    if (a != 0)
        abort();
    return 0;
}


Please note that since there are no constants in the original program, I added a command-line argument `x` and replaced the variable `k` with it.