// Modification timestamp: 2023-08-14 13:55:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990531-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned long bad(int reg, unsigned long inWord) {
    union {
        unsigned long word;
        unsigned char byte[sizeof(unsigned long)];
    } data;

    data.word = inWord;
    data.byte[reg] = 0;

    return data.word;
}

int main(int argc, char *argv[]) {
    /* XXX This test could be generalized.  */
    if (sizeof(long) != 4)
        exit(0);

    if (bad(atoi(argv[1]), strtoul(argv[2], NULL, 0)) == strtoul(argv[3], NULL, 0))
        abort();
    exit(0);
}


Note: The `bad` function now takes the `reg` parameter from command line arguments and the `inWord` parameter is converted from a hexadecimal string to an unsigned long using `strtoul`. The comparison in the `main` function also uses `strtoul` to convert the hexadecimal literals to unsigned long.