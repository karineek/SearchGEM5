// Modification timestamp: 2023-08-14 12:48:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030914-2.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct s { int i[18]; };

int f(struct s pa, int pb, ...)
{
    return pb;
}

struct s gs;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int pb = atoi(argv[1]);
    if (f(gs, pb) != pb)
        abort();

    exit(0);
}
