// Modification timestamp: 2023-08-14 16:09:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/shiftopt-1.c
//The converted code is:


#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void link_error(void);

void utest(unsigned int x)
{
    if (x >> 0 != x)
        link_error();

    if (x << 0 != x)
        link_error();

    if (0 << x != 0)
        link_error();

    if (0 >> x != 0)
        link_error();

    if (-1 >> x != -1)
        link_error();

    if (~0 >> x != ~0)
        link_error();
}

void stest(int x)
{
    if (x >> 0 != x)
        link_error();

    if (x << 0 != x)
        link_error();

    if (0 << x != 0)
        link_error();

    if (0 >> x != 0)
        link_error();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);

    utest(arg1);
    utest(0);

    stest(arg2);
    stest(0);

    return 0;
}

#ifndef __OPTIMIZE__
void link_error()
{
    abort();
}
#endif
