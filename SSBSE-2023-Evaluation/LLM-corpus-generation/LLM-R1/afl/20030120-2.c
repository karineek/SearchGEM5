// Modification timestamp: 2023-08-14 12:42:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030120-2.c

extern void abort();

int foo(int status)
{
    int s = 0;
    if (status == 1)
        s = 1;
    if (status == 3)
        s = 3;
    if (status == 4)
        s = 4;
    return s;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int status = atoi(argv[1]);
    if (foo(status) != status)
        abort();
    return 0;
}
