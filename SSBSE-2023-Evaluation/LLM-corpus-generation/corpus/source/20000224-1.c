
// Modification timestamp: 2023-08-10 16:16:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000224-1.c
#include <string.h>
#include <stdio.h>

#include <stdlib.h>

int loop_1 = 100;
int loop_2 = 7;
int flag = 0;

int test(void) {
    int i;
    int counter = 0;

    while (loop_1 > counter) {
        if (flag & 1) {
            for (i = 0; i < loop_2; i++) {
                counter++;
            }
        }
        flag++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    loop_1 = atoi(argv[1]);

    if (test() != 1)
        abort();

    exit(0);
}
