// Modification timestamp: 2023-08-14 15:28:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57568.c
/* PR target/57568 */

extern void abort (void);
int a[6][9] = { }, b = 1, *c = &a[3][5];

int
main ()
{
  if (b && (*c = *c + *c))
    abort ();
  return 0;
}
