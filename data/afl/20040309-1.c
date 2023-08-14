// Modification timestamp: 2023-08-14 12:51:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040309-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();

int foo(unsigned short x)
{
    unsigned short y;
    y = x > atoi(argv[1]) ? x - atoi(argv[2]) : atoi(argv[3]);
    return y;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
        return 1;
    }

    if (foo(0) != atoi(argv[3]))
        abort();
    if (foo(atoi(argv[1])) != atoi(argv[3]))
        abort();
    if (foo(atoi(argv[2])) != atoi(argv[3]))
        abort();
    if (foo(atoi(argv[2]) + 1) != atoi(argv[2]) - atoi(argv[1]))
        abort();
    if (foo(65535) != atoi(argv[1]))
        abort();
    return 0;
}
