// Modification timestamp: 2023-08-14 16:00:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85169.c

#include <stdio.h>
#include <stdlib.h>

typedef char V __attribute__((vector_size(64)));

static void __attribute__((noipa)) foo(V *p)
{
    V v = *p;
    v[63] = 1;
    *p = v;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    V v = (V){};
    foo(&v);
    for (unsigned i = 0; i < 64; i++)
        if (v[i] != (i == atoi(argv[1])))
            __builtin_abort();
    return 0;
}
