// Modification timestamp: 2023-08-14 11:59:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010711-1.c
void foo (int *a) {}

int main ()
{
  int a;
  if (&a == 0)
    abort ();
  else
    {
      foo (&a);
      exit (0);
    }
}
