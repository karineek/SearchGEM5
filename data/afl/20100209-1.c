// Modification timestamp: 2023-08-14 13:17:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20100209-1.c

#include <stdio.h>
#include <stdlib.h>

int bar(int foo)
{
    return (int)(((unsigned long long)(long long)foo) / 8);
}

extern void abort (void);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int foo = atoi(argv[1]);

    if (sizeof (long long) > sizeof (int) && bar(foo) != foo)
        abort();

    return 0;
}
