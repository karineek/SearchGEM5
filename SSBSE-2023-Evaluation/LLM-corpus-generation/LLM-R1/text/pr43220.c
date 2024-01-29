// Modification timestamp: 2023-08-14 15:11:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43220.c
/* { dg-require-effective-target int32plus } */
/* { dg-require-effective-target alloca } */

void *volatile p;

int
main (void)
{
  int n = 0;
lab:;
    {
      int x[n % 1000 + 1];
      x[0] = 1;
      x[n % 1000] = 2;
      p = x;
      n++;
    }

    {
      int x[n % 1000 + 1];
      x[0] = 1;
      x[n % 1000] = 2;
      p = x;
      n++;
    }

  if (n < 1000000)
    goto lab;

  return 0;
}
