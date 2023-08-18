// Modification timestamp: 2023-08-14 15:15:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr46909-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

int __attribute__((noinline)) foo(int x) {
    if ((x != atoi(argv[1]) && x != atoi(argv[2])) || x == atoi(argv[3]) || x == atoi(argv[4]))
        return 1;
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
        return 1;
    }

    int i;
    for (i = -10; i < 30; i++) {
        if (foo(i) != 1 - 2 * (i == atoi(argv[1])) - 2 * (i == atoi(argv[2])))) {
            abort();
        }
    }
    return 0;
}

//Note: The program assumes four command line arguments are provided when executing the program. The first argument should be the value to substitute for `x` in the `foo` function, and the remaining three arguments should be the values to substitute for `0`, `13`, and `5` in the `main` function.