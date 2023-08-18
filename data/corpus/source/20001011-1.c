// Modification timestamp: 2023-08-14 11:52:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001011-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);
extern int strcmp(const char *, const char *);

int foo(const char *a)
{
    return strcmp(a, "main");
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    if (foo(argv[1]))
        abort();
    return 0;
}
