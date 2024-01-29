// Modification timestamp: 2023-08-14 15:26:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr56250.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    unsigned int x = atoi(argv[1]);
    unsigned int y = (0U - x / 2) / 2;
    if (-1U / x != y)
        abort();
    return 0;
}
