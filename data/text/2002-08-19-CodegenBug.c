
// Modification timestamp: 2023-08-10 14:44:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2002-08-19-CodegenBug.c

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char *validate_array;

    validate_array = (unsigned char *)malloc(64);
    if (validate_array == 0) {
        printf("FAILURE!\n");
        exit(1);
    }

    printf("SUCCESS\n");
    return 0;
}
