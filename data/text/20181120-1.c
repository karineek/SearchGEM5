// Modification timestamp: 2023-08-14 13:24:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20181120-1.c
/* PR rtl-optimization/85925 */
/* { dg-require-effective-target int32plus } */
/* Testcase by <sudi@gcc.gnu.org> */

int a, c, d;
volatile int b;
int *e = &d;

union U1 {
  unsigned f0;
  unsigned f1 : 15;
};
volatile union U1 u = { 0x4030201 };

int main (void)
{
  for (c = 0; c <= 1; c++) {
    union U1 f = {0x4030201};
    if (c == 1)
      b;
    *e = f.f1;
  }

  if (d != u.f1)
    __builtin_abort ();

  return 0;
}
