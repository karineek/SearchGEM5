// Modification timestamp: 2023-08-14 13:59:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/align-nest.c

#include <stdio.h>

typedef struct
{
    int value;
} myint;

struct S
{
    int i[];
    unsigned int b:1;
    myint mi;
} __attribute__((packed)) __attribute__((aligned(4)));

void foo(int n, struct S s[2])
{
    int k;

    for (k = 0; k < 2; k++)
        s[k].mi.value = 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    struct S s[2];
    foo(n, s);
    return 0;
}
