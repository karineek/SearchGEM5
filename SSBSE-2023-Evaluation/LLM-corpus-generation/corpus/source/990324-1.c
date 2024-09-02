// Modification timestamp: 2023-08-14 13:53:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990324-1.c

#include <stdio.h>
#include <stdlib.h>

void f(long i)
{
    if ((signed char)i < 0 || (signed char)i == 0)
        abort ();
    else
        exit (0);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long i = atol(argv[1]);
    f(i);
    return 0;
}
