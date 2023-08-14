
// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2000-05-19-2.c

long x = -1L;

int main() {
    long b = (x != -1L);

    if (b)
        abort();

    exit(0);
}
