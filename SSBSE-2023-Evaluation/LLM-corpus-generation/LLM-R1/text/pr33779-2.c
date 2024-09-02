// Modification timestamp: 2023-08-14 14:54:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr33779-2.c
int foo(int i)
{
  return ((int)((unsigned)(i + 1) * 4)) / 4;
}

extern void abort(void);
int main()
{
  if (foo(0x3fffffff) != 0)
    abort ();
  return 0;
}
