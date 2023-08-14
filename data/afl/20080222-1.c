// Modification timestamp: 2023-08-14 13:13:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080222-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct container
{
    unsigned char data[1];
};

unsigned char space[6] = {1, 2, 3, 4, 5, 6};

int foo(struct container *p)
{
    return p->data[4];
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned char space_arg[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        space_arg[i] = atoi(argv[i + 1]);
    }

    if (foo((struct container *)space_arg) != 5)
        abort();
    return 0;
}
