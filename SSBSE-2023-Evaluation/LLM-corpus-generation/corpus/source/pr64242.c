// Modification timestamp: 2023-08-14 15:41:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr64242.c
#include <string.h>
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

void abort(void)
{
    printf("Abort called\n");
    exit(1);
}

__attribute__((noinline)) void broken_longjmp(void *p)
{
    void *buf[32];
    memcpy(buf, p, 5 * sizeof(void *));
    memset(p, 0, 5 * sizeof(void *));
    longjmp(buf, 1);
}

volatile int x = 0;
char *volatile p;
char *volatile q;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);

    void *buf[5];
    p = alloca(x);
    q = alloca(x);
    if (!setjmp(buf))
        broken_longjmp(buf);

    p = q + (q - p);

    if (p != alloca(x))
        abort();

    return 0;
}
