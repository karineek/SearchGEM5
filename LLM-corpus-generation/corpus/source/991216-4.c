// Modification timestamp: 2023-08-14 13:58:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991216-4.c

#include <stdio.h>
#include <stdlib.h>

static void bug(int size, int tries)
{
    int i;
    int num = 0;
    while (num < size)
    {
        for (i = 1; i < tries; i++) num++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <size> <tries>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    int tries = atoi(argv[2]);

    bug(size, tries);
    exit (0);
}
