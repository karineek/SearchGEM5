
// Modification timestamp: 2023-08-04 16:58:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2002-05-02-ArgumentTest.c

extern int printf(const char *str, ...);

void testfunc(short s, float X, char C, long long LL, int I, double D) {
    printf("%d, %f, %d, %lld, %d, %f\n", s, X, C, LL, I, D);
}

int main() {
    testfunc(12, 1.245f, 'x', 123456677890LL, -10, 45e14);
    return 0;
}
