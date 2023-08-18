// Modification timestamp: 2023-08-14 14:49:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr24135.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern void abort(void);

int x(int a, int b)
{
    __label__ xlab;
    __label__ xlab2;

    void y(int b)
    {
        switch (b)
        {
            case 1:
                goto xlab;
            case 2:
                goto xlab;
        }
    }

    a = a + 2;
    y(b);

xlab:
    return a;

xlab2:
    a++;
    return a;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    int i = atoi(argv[1]);
    int j = atoi(argv[2]);

    for (int k = 1; k <= i; ++k)
        for (int l = 1; l <= j; ++l)
        {
            int a = x(k, l);
            if (a != 2 + k)
                abort();
        }

    return 0;
}

//Note: In this generated code, the program expects two command-line arguments representing `i` and `j`.