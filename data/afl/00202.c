
// Modification timestamp: 2023-08-04 14:41:38
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00202.c

#include <stdio.h>
#include <stdlib.h>

#define P(A,B) A ## B ; bob
#define Q(A,B) A ## B+

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int bob, jim = atoi(argv[1]);
    bob = P(jim,) *= 2;
    printf("jim: %d, bob: %d\n", jim, bob);
    jim = 60 Q(+,)3;
    printf("jim: %d\n", jim);
    return 0;
}
