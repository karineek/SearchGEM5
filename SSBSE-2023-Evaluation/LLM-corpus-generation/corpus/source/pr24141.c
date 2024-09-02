// Modification timestamp: 2023-08-14 14:49:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr24141.c

#include <stdio.h>
#include <stdlib.h>

int i;

void g(void)
{
    i = 1;
}

void f(int a, int b)
{
    int c = 0;
    if (a == 0)
        c = 1;
    if (c)
        return;
    if (c == 1)
        c = 0;
    if (b == 0)
        c = 1;
    if (c)
        g();
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <value> <value>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
  
    f(a, b);
    if (i != 1)
        abort();
    return 0;
}
