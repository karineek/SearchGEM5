c
// Modification timestamp: 2023-08-10 16:07:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/CoyoteBench/fp16-smoke.c

#include <stdio.h>

int main() {
    printf("printArg: 0x0p+0\n");
    printf("printArg: 0x1p+0\n");
    printf("printArg: -0x1p-8\n");
    printf("printArg: 0x1p+1\n");
    return 0;
}
