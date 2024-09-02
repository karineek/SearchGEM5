// Modification timestamp: 2023-08-14 15:08:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42006.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

static unsigned int my_add(unsigned int si1, unsigned int si2)
{
    return (si1 > (50 - si2)) ? si1 : (si1 + si2);
}

static unsigned int my_shift(unsigned int left, unsigned int right)
{
    return (right > 100) ? left : (left >> right);
}

static int func_4(unsigned int p_6)
{
    int count = 0;
    for (p_6 = atoi(argv[1]); p_6 < atoi(argv[2]); p_6 = my_add(p_6, atoi(argv[3])))
    {
        if (count++ > 1)
            abort();

        if (my_shift(p_6, p_6))
            return 0;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
        return 1;
    }

    func_4(atoi(argv[1]));
    return 0;
}

