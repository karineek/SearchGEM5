
// Modification timestamp: 2023-08-10 16:15:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2002-02-05-1.c

static int f(int a) {
    if (a == 0)
        return 0;
    do
        if (a & 128)
            return 1;
    while (f(0));
    return 0;
}

int main(void) {
    if (f(~128))
        abort();
    exit(0);
}
