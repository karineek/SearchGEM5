// Modification timestamp: 2023-08-14 13:14:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080529-1.c
/* PR target/36362 */

extern void abort (void);

int
test (float c)
{
  return !!c * 7LL == 0;
}

int
main (void)
{
  if (test (1.0f) != 0)
    abort ();
  return 0;
}
