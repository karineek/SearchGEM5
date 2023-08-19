// Modification timestamp: 2023-08-14 13:33:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930429-1.c
char *
f (char *p)
{
  short x = *p++ << 16;
  return p;
}

main ()
{
  char *p = "";
  if (f (p) != p + 1)
    abort ();
  exit (0);
}
