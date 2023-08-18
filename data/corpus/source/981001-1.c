// Modification timestamp: 2023-08-14 13:51:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/981001-1.c

#include <stdio.h>
#include <stdlib.h>

#define NG 0x100L

unsigned long flg = 0;

long sub(int n) {
    int a, b;

    if (n >= 2) {
        if (n % 2 == 0) {
            a = sub(n / 2);

            return (a + 2 * sub(n / 2 - 1)) * a;
        } else {
            a = sub(n / 2 + 1);
            b = sub(n / 2);

            return a * a + b * b;
        }
    } else
        return (long) n;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if (sub(n) != 832040L)
        flg |= NG;
    
    if (flg)
        abort();
    
    exit(0);
}
