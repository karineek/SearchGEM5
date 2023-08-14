// Modification timestamp: 2023-08-14 15:14:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr46316.c
extern void abort (void);

long long __attribute__((noinline,noclone))
foo (long long t)
{
  while (t > -4)
    t -= 2;

  return t;
}

int main(void)
{
  if (foo (0) != -4)
    abort ();
  return 0;
}
