// Modification timestamp: 2023-08-14 15:20:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr51466.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

__attribute__((noinline, noclone)) int foo(int i, int arg1)
{
    volatile int v[4];
    int *p;
    v[i] = arg1;
    p = (int *)&v[i];
    return *p;
}

__attribute__((noinline, noclone)) int bar(int i, int arg1)
{
    volatile int v[4];
    int *p;
    v[i] = arg1;
    p = (int *)&v[i];
    *p = 8;
    return v[i];
}

__attribute__((noinline, noclone)) int baz(int i, int arg1)
{
    volatile int v[4];
    int *p;
    v[i] = arg1;
    p = (int *)&v[0];
    *p = 8;
    return v[i];
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage: %s <arg1> <arg2> <arg3> <arg4>\n", argv[0]);
        return 1;
    }

    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);
    int arg3 = atoi(argv[3]);
    int arg4 = atoi(argv[4]);

    if (foo(3, arg1) != 6 || bar(2, arg2) != 8 || baz(0, arg3) != 8 ||
        baz(1, arg4) != 6)
        abort();
    return 0;
}
