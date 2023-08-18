// Modification timestamp: 2023-08-14 16:09:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/shiftdi.c

#include <stdio.h>

typedef unsigned long long uint64;

void g(uint64 x, int y, int z, uint64 *p)
{
    unsigned w = ((x >> y) & 0xffffffffULL) << (z & 0x1f);
    *p |= (w & 0xffffffffULL) << z;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    uint64 a = 0;
    g(0xdeadbeef01234567ULL, atoi(argv[1]), atoi(argv[2]), &a);
    return (a == 0x01234567) ? 0 : 1;
}
