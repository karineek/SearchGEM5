// Modification timestamp: 2023-08-04 14:54:04
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00212.c
#include <stdio.h>

int main() {
#if defined(__LLP64__)
    if (sizeof(short) == 2
        && sizeof(int) == 4
        && sizeof(long int) == 4
        && sizeof(long long int) == 8
        && sizeof(void*) == 8) {
        (void)printf("Ok\n");
    } else {
        (void)printf("KO __LLP64__\n");
    }
#elif defined(__LP64__)
    if (sizeof(short) == 2
        && sizeof(int) == 4
        && sizeof(long int) == 8
        && sizeof(long long int) == 8
        && sizeof(void*) == 8) {
        (void)printf("Ok\n");
    } else {
        (void)printf("KO __LP64__\n");
    }
#elif defined(__ILP32__)
    if (sizeof(short) == 2
        && sizeof(int) == 4
        && sizeof(long int) == 4
        && sizeof(void*) == 4) {
        (void)printf("Ok\n");
    } else {
        (void)printf("KO __ILP32__\n");
    }
#else
    (void)printf("KO no __*LP*__ defined.\n");
#endif
}
