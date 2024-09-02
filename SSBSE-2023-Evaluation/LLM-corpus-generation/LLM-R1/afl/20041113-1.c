// Modification timestamp: 2023-08-14 12:59:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041113-1.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void test (int x, ...)
{
    va_list ap;
    int i;
    va_start (ap, x);
    if (va_arg (ap, int) != 1)
        abort ();
    if (va_arg (ap, int) != 2)
        abort ();
    if (va_arg (ap, int) != 3)
        abort ();
    if (va_arg (ap, int) != 4)
        abort ();
}

double a = 40.0;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    test(0, 1, 2, 3, atoi(argv[1]));
    exit(0);
}
