// Modification timestamp: 2023-08-14 15:30:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58385.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int a, b = 1;

int foo()
{
    b = 0;
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int arg = atoi(argv[1]);

    ((arg || a) & foo() >= 0) <= 1 && 1;
    if (b)
        abort();
    return 0;
}

Note: In this case, I added a command-line argument `arg` to simulate the replacement of the constant `0` in the expression `((0 || a) & foo() >= 0)`.