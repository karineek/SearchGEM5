// Modification timestamp: 2023-08-14 16:06:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/ptr-arith-1.c
char *
f (char *s, unsigned int i)
{
  return &s[i + 3 - 1];
}

main ()
{
  char *str = "abcdefghijkl";
  char *x2 = f (str, 12);
  if (str + 14 != x2)
    abort ();
  exit (0);
}
