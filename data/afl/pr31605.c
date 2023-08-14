// Modification timestamp: 2023-08-14 14:54:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr31605.c

#include <stdio.h>
#include <stdlib.h>

void put_field(unsigned int start, unsigned int len) {
    int cur_bitshift = ((start + len) % 8) - 8;
    if (cur_bitshift > -8)
        exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <start> <len>\n", argv[0]);
        return 1;
    }

    unsigned int start = atoi(argv[1]);
    unsigned int len = atoi(argv[2]);

    put_field(start, len);
    abort();
}
