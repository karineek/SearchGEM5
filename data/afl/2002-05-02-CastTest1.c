
// Modification timestamp: 2023-08-04 16:59:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/programs/single-source/2002-05-02-CastTest1.c

int printf(const char *, ...);

int main(int argc, char** argv) {
  signed char c0  = argc;
  unsigned char c1 = atoi(argv[1]);
  printf("bs0  = %d %d\n", c0, c1);
  return 0;
}
