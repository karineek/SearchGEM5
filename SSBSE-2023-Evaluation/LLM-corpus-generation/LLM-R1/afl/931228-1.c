// Modification timestamp: 2023-08-14 13:40:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931228-1.c

#include <stdio.h>
#include <stdlib.h>

int f(int x)
{
    x &= 010000;
    x &= 007777;
    x ^= 017777;
    x &= 017770;
    return x;
}

int main(int argc, char *argv[])
{
    if (f(atoi(argv[1])) != 017770)
        abort();
    exit(0);
}
