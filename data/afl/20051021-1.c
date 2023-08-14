// Modification timestamp: 2023-08-14 13:05:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20051021-1.c

/* Verify that TRUTH_AND_EXPR is not wrongly changed to TRUTH_ANDIF_EXPR.  */

#include <stdlib.h>

extern void abort(void);

int count = 0;

int foo1(void)
{
    count++;
    return 0;
}

int foo2(void)
{
    count++;
    return 0;
}

int main(int argc, char *argv[])
{
    if ((foo1() == atoi(argv[1])) & (foo2() == atoi(argv[2])))
        abort();

    if (count != 2)
        abort();

    return 0;
}

Note: In this case, the program expects the values of `foo1()` and `foo2()` to be passed as command-line arguments `argv[1]` and `argv[2]` respectively.