// Modification timestamp: 2023-08-14 13:07:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20061031-1.c
#include <stdlib.h>

#include <stdio.h>

const signed char nunmap[] = { 17, -1, 1 };

__attribute__((noinline))
void ff(int i) {
    asm volatile("");
}

__attribute__((noinline))
void f(short delta)
{
    int argc = 2;
    char *argv[3] = {"./program", "0", "0"};

    short p0 = argv[1][0], s;
    for (s = argv[2][0]; s < argv[3][0]; s++)
    {
        p0 += delta;
        ff(s);
        if (nunmap[p0] == 17)
            asm volatile("");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    f(atoi(argv[1]));
    return 0;
}
