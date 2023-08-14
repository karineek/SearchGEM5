
// Modification timestamp: 2023-08-10 15:10:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Benchmarks/Misc/2005-05-13-SDivTwo.c

#include <stdio.h>

int main() {
    int i;
    for (i = 0; i != 258; ++i) {
        printf("%d\n", ((signed char)i) / (signed char)2);
    }
    return 0;
}
