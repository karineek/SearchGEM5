// Modification timestamp: 2023-08-14 13:00:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041218-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int test(int n)
{
    struct s { char b[n]; } __attribute__((packed));
    n++;
    return sizeof(struct s);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (test(n) != n)
        abort();
    return 0;
}
