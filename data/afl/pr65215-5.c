// Modification timestamp: 2023-08-14 15:43:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65215-5.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) unsigned int
foo(unsigned char *p)
{
    return ((unsigned int)p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

__attribute__((noinline, noclone)) unsigned int
bar(unsigned char *p)
{
    return ((unsigned int)p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
}

struct S {
    unsigned int a;
    unsigned char b[5];
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct S s = {atoi(argv[1]), {2, 3, 4, 5, 6}};
    if (__CHAR_BIT__ != 8 || sizeof(unsigned int) != 4)
        return 0;
    if (foo(&s.b[1]) != 0x03040506U || bar(&s.b[1]) != 0x06050403U)
        __builtin_abort();
    return 0;
}

