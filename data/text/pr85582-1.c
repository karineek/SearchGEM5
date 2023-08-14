// Modification timestamp: 2023-08-14 16:01:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85582-1.c
/* PR target/85582 */

int a, b, d = 2, e;
long long c = 1;

int
main ()
{
  int g = 6;
L1:
  e = d;
  if (a)
    goto L1;
  g--;
  int i = c >> ~(~e | ~g);
L2:
  c = (b % c) * i;
  if (!e)
    goto L2;
  return 0;
}
