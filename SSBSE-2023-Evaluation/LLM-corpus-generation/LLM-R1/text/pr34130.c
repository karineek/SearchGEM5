// Modification timestamp: 2023-08-14 14:56:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34130.c
extern void abort (void);
int foo (int i)
{
  return -2 * __builtin_abs(i - 2);
}
int main()
{
  if (foo(1) != -2
      || foo(3) != -2)
    abort ();
  return 0;
}
