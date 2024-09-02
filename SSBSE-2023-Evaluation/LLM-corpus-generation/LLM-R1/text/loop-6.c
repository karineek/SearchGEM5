// Modification timestamp: 2023-08-14 14:32:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-6.c
main()
{
  char c;
  char d;
  int nbits;
  c = -1;
  for (nbits = 1 ; nbits < 100; nbits++) {
    d = (1 << nbits) - 1;
    if (d == c)
      break;
  }
  if (nbits == 100)
    abort();
  exit(0);
}
