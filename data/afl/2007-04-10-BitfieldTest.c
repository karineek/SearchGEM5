// Modification timestamp: 2023-08-14 17:23:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2007-04-10-BitfieldTest.c

#include <stdio.h>
#include <stdlib.h>

union u {
    struct {
        unsigned int a : 8;
        unsigned int b : 3;
        unsigned int c : 3;
        unsigned int d : 3;
        unsigned int e : 3;
        unsigned int f : 3;
        unsigned int g : 3;
        unsigned int h : 3;
        unsigned int i : 3;

        unsigned int n : 8;
        unsigned int o : 8;
        unsigned int p : 8;
        unsigned int q : 8;
    } s;
    unsigned long long token;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    union u uu;
    uu.token = strtoull(argv[1], NULL, 16);
    printf("p = 0x%02X\n", uu.s.p);
    return 0;
}
