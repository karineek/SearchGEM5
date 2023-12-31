// Modification timestamp: 2023-08-14 14:49:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr24851.c
/* We used to handle pointer addition wrongly
   at the time of recombining to an ARRAY_REF
   in the case of
     p + -4B
   where -4B is represented as unsigned.  */

void abort(void);
int main()
{
  int a[10], *p, *q;
  q = &a[1];
  p = &q[-1];
  if (p >= &a[9])
    abort ();
  return 0;
}
