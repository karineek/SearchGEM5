// Modification timestamp: 2023-08-14 13:24:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20190228-1.c
/* PR tree-optimization/89536 */
/* Testcase by Zhendong Su <su@cs.ucdavis.edu> */

int a = 1;

int main (void)
{
  a = ~(a && 1);
  if (a < -1)
    a = ~a;

  if (!a)
    __builtin_abort ();

  return 0;
}
