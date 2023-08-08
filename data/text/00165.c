// Modification timestamp: 2023-08-04 14:29:16
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00165.c

#include <stdio.h>

#define FRED 12
#define BLOGGS(x) (12*(x))

int main() {
    printf("%d\n", FRED);
    printf("%d, %d, %d\n", BLOGGS(1), BLOGGS(2), BLOGGS(3));

    return 0;
}
