// Modification timestamp: 2023-08-14 13:08:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070212-2.c
int f(int k, int i1, int j1)
{
  int *f1;
  if(k)
   f1 = &i1;
  else
   f1 = &j1;
  i1 = 0;
  return *f1;
}

extern void abort (void);

int main()
{
  if (f(1, 1, 2) != 0)
    abort ();
  return 0;
}
