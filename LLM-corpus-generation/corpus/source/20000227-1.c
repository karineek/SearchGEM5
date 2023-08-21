//C
// Modification timestamp: 2023-08-10 16:17:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/ASCI_Purple/20000227-1.c
#include <stdio.h>

#include <stdlib.h>

int main(int argc, char* argv[]) {
    static const unsigned char f[] = "\0\377";
    static const unsigned char g[] = "\0ˇ";

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int i = atoi(argv[1]);

    if (sizeof f != 3 || sizeof g != 3)
        abort();
    if (f[0] != g[0])
        abort();
    if (f[1] != g[1])
        abort();
    if (f[2] != g[2])
        abort();
    return 0;
}
