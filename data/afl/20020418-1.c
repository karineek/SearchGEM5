// Modification timestamp: 2023-08-14 12:15:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020418-1.c

#include <stdio.h>
#include <stdlib.h>

struct foo { int a; };

void gcc_crash(struct foo *p)
{
    if (__builtin_expect(p->a < atoi(argv[1]), 0))
        __builtin_trap();
 top:
    p->a++;
    if (p->a >= atoi(argv[2]))
        goto top;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    struct foo x;
    x.a = atoi(argv[1]);
    gcc_crash(&x);

    exit (0);
}
