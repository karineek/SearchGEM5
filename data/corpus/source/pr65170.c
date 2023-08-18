// Modification timestamp: 2023-08-14 15:42:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65170.c

#include <stdio.h>
#include <stdlib.h>

#ifdef __SIZEOF_INT128__
typedef unsigned __int128 V;
typedef unsigned long long int H;
#else
typedef unsigned long long int V;
typedef unsigned int H;
#endif

__attribute__((noinline, noclone)) void foo(V b, V c)
{
    V a;
    b &= (H)-1;
    c &= (H)-1;
    a = b * c;
    if (a != 1)
        __builtin_abort();
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <b> <c>\n", argv[0]);
        return 1;
    }

    V b = atoi(argv[1]);
    V c = atoi(argv[2]);

    foo(b, c);
    return 0;
}
