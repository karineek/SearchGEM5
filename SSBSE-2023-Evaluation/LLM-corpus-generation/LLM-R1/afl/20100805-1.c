// Modification timestamp: 2023-08-14 13:18:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20100805-1.c

#include <stdio.h>

unsigned int foo(unsigned int a, unsigned int b)
{
    unsigned int i;
    a = a & 1;
    for (i = 0; i < b; ++i)
        a = a << 1 | a >> (sizeof(unsigned int) * 8 - 1);
    return a;
}

extern void abort(void);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    unsigned int a = atoi(argv[1]);
    unsigned int b = atoi(argv[2]);

    if (foo(a, b) != 2)
        abort();
  
    return 0;
}
