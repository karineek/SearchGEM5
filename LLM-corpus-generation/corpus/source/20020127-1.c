// Modification timestamp: 2023-08-14 12:09:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020127-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

unsigned long foo(unsigned long n)
{
    return (~n >> 3) & 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned long n = atoi(argv[1]);

    if (foo(1 << 3) != 0)
        abort();

    if (foo(0) != 1)
        abort();

    exit(0);
}
