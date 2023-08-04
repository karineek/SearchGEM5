
// Modification timestamp: 2023-08-04 14:53:38
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00211.c

extern int printf(const char *format, ...);

#define ACPI_TYPE_INVALID       0x1E
#define NUM_NS_TYPES            ACPI_TYPE_INVALID+1
int array[NUM_NS_TYPES];

#define n 0xe
int main() {
    printf("n+1 = %d\n", n + 1);
    // printf("n+1 = %d\n", 0xe+1);
}
