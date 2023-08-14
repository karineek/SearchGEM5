// Modification timestamp: 2023-08-14 12:48:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030914-1.c

#include <stdio.h>
#include <stdlib.h>

struct s { 
    int val[16]; 
};

long double f (int pa, struct s pb, long double pc)
{
    int i;

    for (i = 0; i < 16; i++)
        pc += pb.val[i];
    return pc;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct s x;
    int i;

    for (i = 0; i < 16; i++)
        x.val[i] = i + 1;
    if (f(1, x, atof(argv[1])) != 10136.0L)
        abort();
    exit(0);
}
