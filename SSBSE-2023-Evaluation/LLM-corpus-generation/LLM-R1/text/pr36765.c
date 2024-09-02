// Modification timestamp: 2023-08-14 14:59:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36765.c
int __attribute__((noinline))
foo(int i)
{
  int *p = __builtin_malloc (4 * sizeof(int));
  *p = 0;
  p[i] = 1;
  return *p;
}
extern void abort (void);
int main()
{
  if (foo(0) != 1)
    abort ();
  return 0;
}
