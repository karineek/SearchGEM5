// Modification timestamp: 2023-08-14 13:46:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960801-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned f(unsigned short us, unsigned long long ul, short s2)
{
    long long l2;
  
    ul = us = l2 = s2 = -1;
    return ul;
}

unsigned long long g(unsigned short us, unsigned long long ul, short s2)
{
    long long l2;
  
    ul = us = l2 = s2 = -1;
    return ul;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned short us = atoi(argv[1]);
    unsigned long long ul = atoi(argv[2]);
    short s2 = atoi(argv[3]);

    if (f(us, ul, s2) != (unsigned short)-1)
        abort();
    if (g(us, ul, s2) != (unsigned short)-1)
        abort();
    exit(0);
}
