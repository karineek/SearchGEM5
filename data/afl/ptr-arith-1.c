// Modification timestamp: 2023-08-14 16:06:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/ptr-arith-1.c

#include <stdio.h>
#include <stdlib.h>

char *f (char *s, unsigned int i)
{
    return &s[i + 3 - 1];
}

int main(int argc, char *argv[]) {
    char *str = argv[1];
    char *x2 = f (str, atoi(argv[2]));
    if (str + atoi(argv[3]) != x2)
        abort ();
    exit (0);
}
