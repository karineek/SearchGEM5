// Modification timestamp: 2023-08-14 14:30:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-2.c

#include <stdio.h>
#include <stdlib.h>

int a[2];

void f(int b)
{
    unsigned int i;
    for (i = 0; i < b; i++)
        a[i] = i - 2;
}

int main(int argc, char *argv[])
{
    a[0] = a[1] = 0;
    f(2);
    if (a[0] != -2 || a[1] != -1)
        abort();
    exit(0);
}
