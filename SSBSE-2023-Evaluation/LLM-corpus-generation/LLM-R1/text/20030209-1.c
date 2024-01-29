// Modification timestamp: 2023-08-14 12:42:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030209-1.c
/* { dg-require-stack-size "8*100*100" } */

double x[100][100];
int main ()
{
  int i;

  i = 99;
  x[i][0] = 42;
  if (x[99][0] != 42)
    abort ();
  exit (0);
}
