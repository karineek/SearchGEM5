// Modification timestamp: 2023-08-14 12:06:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011126-1.c
/* Produced a overflow in ifcvt.c, causing S to contain 0xffffffff7fffffff.  */

int a = 1;

int main ()
{
  long long s;

  s = a;
  if (s < 0)
    s = -2147483648LL;
  else
    s = 2147483647LL;

  if (s < 0)
    abort ();

  return 0;
}
