// Modification timestamp: 2023-08-14 17:32:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-06-16-VolatileError.c

extern int volatile test;
int volatile test = 0;

int main(int argc, char *argv[]) {
  return 0;
}
