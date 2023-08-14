
// Modification timestamp: 2023-08-10 16:17:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Benchmarks/Misc/20000313-1.c

unsigned int buggy(unsigned int *param) {
    unsigned int accu, zero = 0, borrow;
    accu = -*param;
    borrow = -(accu > zero);
    *param += accu;
    return borrow;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <param>\n", argv[0]);
        return 1;
    }

    unsigned int param = atoi(argv[1]);
    unsigned int borrow = buggy(&param);

    if (param != 0)
        abort();
    if (borrow + 1 != 0)
        abort();
    return 0;
}
