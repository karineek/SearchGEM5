// Modification timestamp: 2023-08-04 14:53:38
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00211.c

#include <stdio.h>
#include <stdlib.h>

extern int printf(const char *format, ...);

#define ACPI_TYPE_INVALID       0x1E
#define NUM_NS_TYPES            ACPI_TYPE_INVALID+1
int array[NUM_NS_TYPES];

#define n argv[1]

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    printf("n+1 = %d\n", atoi(n) + 1);
    // printf("n+1 = %d\n", 0xe+1);
}
