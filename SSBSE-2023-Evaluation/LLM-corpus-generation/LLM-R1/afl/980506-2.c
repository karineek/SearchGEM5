// Modification timestamp: 2023-08-14 13:49:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980506-2.c

#include <stdio.h>
#include <stdlib.h>

static void *self(void *p)
{
    return p;
}

int f(int argc, char *argv[])
{
    struct
    {
        int i;
    } s, *sp;
    int *ip = &s.i;

    s.i = atoi(argv[1]);
    sp = self(&s);

    *ip = atoi(argv[2]);
    return sp->i + 1;
}

int main(int argc, char *argv[])
{
    if (f(argc, argv) != 1)
    {
        abort();
    }
    else
    {
        exit(0);
    }
}
