// Modification timestamp: 2023-08-14 14:55:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34070-2.c
extern void abort (void);

int f(unsigned int x, int n)
{
    return ((int)x) / (1 << n);
}

int main()
{
  if (f(-1, 1) != 0)
    abort ();
  return 0;
}
