C
// Modification timestamp: 2023-08-10 16:17:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/ASCI_Purple/20000227-1.c

static const unsigned char f[] = "\0\377";
static const unsigned char g[] = "\0ˇ";

int main(void) {
    if (sizeof f != 3 || sizeof g != 3)
        abort();
    if (f[0] != g[0])
        abort();
    if (f[1] != g[1])
        abort();
    if (f[2] != g[2])
        abort();
    return 0;
}
