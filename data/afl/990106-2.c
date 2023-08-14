// Modification timestamp: 2023-08-14 13:52:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990106-2.c

#include <stdio.h>
#include <stdlib.h>

unsigned calc_mp(unsigned mod)
{
    unsigned a,b,c;
    c=-1;
    a=c/mod;
    b=0-a*mod;
    if (b > mod) { a += 1; b-=mod; }
    return b;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned x = atoi(argv[1]);
    unsigned y = calc_mp(x);

    if ((sizeof (y) == 4 && y != 680)
        || (sizeof (y) == 2 && y != 134))
        abort ();
    return 0;
}

