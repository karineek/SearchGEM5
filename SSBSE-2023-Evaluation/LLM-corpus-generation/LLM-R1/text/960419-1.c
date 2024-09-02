// Modification timestamp: 2023-08-14 13:46:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960419-1.c
static int i;

void
check(x)
     int x;
{
  if (!x)
    abort();
}

main()
{
  int *p = &i;

  check(p != (void *)0);
  exit (0);
}
