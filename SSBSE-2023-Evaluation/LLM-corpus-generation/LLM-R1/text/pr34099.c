// Modification timestamp: 2023-08-14 14:56:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34099.c
int foo (int b, int c)
{
  int x;
  if (b)
    return x & c;
  else
    return 1;
}
extern void abort (void);
int main()
{
  if (foo(1, 0) != 0)
    abort ();
  return 0;
}
