// Modification timestamp: 2023-08-14 14:56:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34154.c

#include <stdio.h>
#include <stdlib.h>

int foo(unsigned long long aLL)
{
    switch (aLL)
    {
        case 1000000000000000000ULL ... 9999999999999999999ULL:
            return 19;
        default:
            return 20;
    }
}

extern void abort(void);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned long long aLL = strtoull(argv[1], NULL, 10);
    if (foo(aLL) != 19)
        abort();

    return 0;
}
