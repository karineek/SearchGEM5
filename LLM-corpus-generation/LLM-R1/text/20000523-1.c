
// Modification timestamp: 2023-08-10 16:33:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/NPB/SeqApplications/mg.C

int main(void) {
    long long x;
    int n;

    if (sizeof(long long) < 8)
        exit(0);

    n = 9;
    x = (((long long)n) << 55) / 0xff;

    if (x == 0)
        abort();

    x = (((long long)9) << 55) / 0xff;

    if (x == 0)
        abort();

    exit(0);
}
