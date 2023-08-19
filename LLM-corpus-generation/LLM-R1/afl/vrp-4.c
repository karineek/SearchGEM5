// Modification timestamp: 2023-08-14 17:04:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vrp-4.c

#include <stdio.h>
#include <stdlib.h>

extern void exit(int);
extern void abort();

void test(int x, int y)
{
    int c;

    if (x == atoi(argv[1])) abort();
    if (y == atoi(argv[2])) abort();

    c = x / y;

    if (c != 1) abort();
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    test(atoi(argv[1]), atoi(argv[2]));
    exit(0);
}
