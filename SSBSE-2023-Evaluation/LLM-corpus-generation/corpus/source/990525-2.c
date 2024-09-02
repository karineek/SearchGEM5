// Modification timestamp: 2023-08-14 13:55:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990525-2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int v[4];
} Test1;

Test1 func2(int *args);

int func1(int *args)
{
    Test1 test;
    test = func2(args);

    if (test.v[0] != args[0])
        abort();
    if (test.v[1] != args[1])
        abort();
    if (test.v[2] != args[2])
        abort();
    if (test.v[3] != args[3])
        abort();
}

Test1 func2(int *args)
{
    Test1 tmp;
    tmp.v[0] = args[0];
    tmp.v[1] = args[1];
    tmp.v[2] = args[2];
    tmp.v[3] = args[3];
    return tmp;
}

int main(int argc, char *argv[])
{
    if (argc != 5) {
        printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
        return 1;
    }

    int args[4];
    for (int i = 0; i < 4; i++) {
        args[i] = atoi(argv[i+1]);
    }

    func1(args);
    exit(0);
}
