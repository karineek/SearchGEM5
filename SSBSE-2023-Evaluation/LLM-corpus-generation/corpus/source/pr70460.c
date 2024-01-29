// Modification timestamp: 2023-08-14 15:50:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70460.c

#include <stdio.h>
#include <stdlib.h>

int c;

__attribute__((noinline, noclone)) void
foo(int x)
{
    static int b[] = { &&lab1 - &&lab0, &&lab2 - &&lab0 };
    void *a = &&lab0 + b[x];
    goto *a;
lab1:
    c += 2;
lab2:
    c++;
lab0:
    ;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    foo(x);
    if (c != 3)
        abort();
    foo(x);
    if (c != 4)
        abort();
    return 0;
}
