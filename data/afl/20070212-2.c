// Modification timestamp: 2023-08-14 13:08:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070212-2.c

#include <stdio.h>
#include <stdlib.h>

int f(int k, int i1, int j1)
{
    int *f1;
    if (k)
        f1 = &i1;
    else
        f1 = &j1;
    i1 = atoi(argv[3]);
    return *f1;
}

extern void abort(void);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <k> <i1> <j1>\n", argv[0]);
        return 1;
    }

    int k = atoi(argv[1]);
    int i1 = atoi(argv[2]);
    int j1 = atoi(argv[3]);

    if (f(k, i1, j1) != 0)
        abort();
    return 0;
}
