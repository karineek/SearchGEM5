
// Modification timestamp: 2023-08-10 15:56:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/2008-01-07-LongDouble.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long double x = atof(argv[1]);
    printf("%Lf %Lf\n", x, x);
    return 0;
}
