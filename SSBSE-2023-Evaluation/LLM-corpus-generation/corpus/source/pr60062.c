// Modification timestamp: 2023-08-14 15:37:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr60062.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a;

static void foo(const char *p1, int p2)
{
    if (strcmp(p1, "hello") != 0)
        abort();
}

static void bar(const char *p1)
{
    if (strcmp(p1, "hello") != 0)
        abort();
}

__attribute__((optimize (0))) int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    foo("hello", a);
    bar("hello");
    return 0;
}
