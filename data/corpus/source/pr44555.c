// Modification timestamp: 2023-08-14 15:13:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44555.c

#include <stdio.h>
#include <stdlib.h>

struct a {
    char b[100];
};

int foo(struct a *a)
{
    if (a->b)
        return 1;
    return 0;
}

extern void abort(void);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    if (foo((struct a *)atoi(argv[1])) != 0)
        abort();
    return 0;
}
