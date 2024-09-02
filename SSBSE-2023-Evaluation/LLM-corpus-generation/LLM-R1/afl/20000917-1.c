// Modification timestamp: 2023-08-14 11:52:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000917-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct int3 { int a, b, c; } int3;

int3 one(void)
{
    int3 result;
    result.a = 1;
    result.b = 1;
    result.c = 1;
    return result;
}

int3 zero(void)
{
    int3 result;
    result.a = 0;
    result.b = 0;
    result.c = 0;
    return result;
}

int main()
{
    int3 a;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    *({ ({ one (); &a; }); }) = zero ();
    if (a.a && a.b && a.c)
        abort ();
    exit (0);
}
