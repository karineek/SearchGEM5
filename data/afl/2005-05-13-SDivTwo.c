
// Modification timestamp: 2023-08-10 15:10:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Benchmarks/Misc/2005-05-13-SDivTwo.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int i;
    for (i = 0; i != atoi(argv[1]); ++i) {
        printf("%d\n", ((signed char)i) / (signed char)2);
    }
    return 0;
}
