// Modification timestamp: 2023-08-14 14:59:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36691.c

#include <stdio.h>
#include <stdlib.h>

unsigned char g_5;

void func_1(void) {
    for (g_5 = atoi(argv[1]); g_5 >= atoi(argv[2]); g_5 -= atoi(argv[3]))
        ;
}

extern void abort(void);
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <initial_value> <condition_value> <decrement_value>\n", argv[0]);
        return 1;
    }

    func_1();
    if (g_5 != 0)
        abort();
    return 0;
}

Please provide the initial value, condition value, and decrement value as command-line arguments when running the program.