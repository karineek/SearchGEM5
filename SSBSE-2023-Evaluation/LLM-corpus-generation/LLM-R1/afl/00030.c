// Modification timestamp: 2023-08-03 17:17:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00030.c
#include <stdio.h>
#include <stdlib.h>

int f() {
    return 100;
}

int main(int argc, char *argv[]) {
    if (argc != 7) {
        printf("Usage: %s <val1> <val2> <val3> <val4> <val5> <val6>\n", argv[0]);
        return 1;
    }

    if (atoi(argv[1]) > 1000)
        return 1;
    if (atoi(argv[2]) >= 1000)
        return 1;
    if (1000 < atoi(argv[3]))
        return 1;
    if (1000 <= atoi(argv[4]))
        return 1;
    if (1000 == atoi(argv[5]))
        return 1;
    if (100 != atoi(argv[6]))
        return 1;
    return 0;
}
