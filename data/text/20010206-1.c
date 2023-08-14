// Modification timestamp: 2023-08-14 11:57:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010206-1.c
int foo (void)
{
  int i;
#line 1 "20010206-1.c"
  if (0) i = 1; else i
#line 1 "20010206-1.c"
    = 26;
  return i;
}

int main ()
{
  if (foo () != 26)
    abort ();
  exit (0);
}
