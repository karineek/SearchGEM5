
// Modification timestamp: 2023-08-04 14:41:52
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00203.c

#include <stdio.h>

int main() {
    long long int res = 0;

    if (res < -2147483648LL) {
        printf("Error: 0 < -2147483648\n");
        return 1;
    }
    else if (2147483647LL < res) {
        printf("Error: 2147483647 < 0\n");
        return 2;
    }
    else {
        printf("long long constant test ok.\n");
    }
    return 0;
}
