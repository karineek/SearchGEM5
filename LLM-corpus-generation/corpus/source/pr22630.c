// Modification timestamp: 2023-08-14 14:47:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22630.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);

int j;

void bla(int *r)
{
    int *p, *q;

    p = q = r;
    if (!p)
        p = &j;

    if (p != q)
        j = 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int *r = atoi(argv[1]);
    bla(r);
    if (!j)
        abort();
    return 0;
}
