// Modification timestamp: 2023-08-14 14:55:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34070-1.c
extern void abort (void);

int f(unsigned int x)
{
    return ((int)x) % 4;
}

int main()
{
  if (f(-1) != -1)
    abort ();
  return 0;
}
