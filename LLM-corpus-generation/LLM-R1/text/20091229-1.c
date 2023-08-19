// Modification timestamp: 2023-08-14 13:17:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20091229-1.c
long long foo(long long v) { return v / -0x080000000LL; }
int main(int argc, char **argv) { if (foo(0x080000000LL) != -1) abort(); exit (0); }
