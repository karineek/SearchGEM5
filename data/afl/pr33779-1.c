// Modification timestamp: 2023-08-14 14:54:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr33779-1.c

#include <stdio.h>
#include <stdlib.h>

int foo(int i)
{
    if (((unsigned)(i + 1)) * 4 == 0)
        return 1;
    return 0;
}

extern void abort(void);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int arg1 = atoi(argv[1]);
    
    if (foo(arg1) == 0)
        abort();

    return 0;
}
