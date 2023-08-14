// Modification timestamp: 2023-08-14 13:51:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980929-1.c
void f(int i)
{
  if (i != 1000)
    abort ();
}


int main()
{
  int n=1000;
  int i;

  f(n);
  for(i=0; i<1; ++i) {
    f(n);
    n=666;
    &n;
  }

  exit (0);
}
