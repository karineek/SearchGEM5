// Modification timestamp: 2023-08-14 13:12:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071216-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

static int x;

int
__attribute__((noinline))
bar(void)
{
    return x;
}

int
foo(void)
{
    int b = bar();
    if ((unsigned) b < -4095)
        return b;
    if (-b != 38)
        b = -2;
    return b + 1;
}

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);
    if (foo() != x) {
        abort();
    }

    return 0;
}
