// Modification timestamp: 2023-08-14 15:37:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr60072.c
/* PR target/60072 */

int c = 1;

__attribute__ ((optimize (1)))
static int *foo (int *p)
{
  return p;
}

int
main ()
{
  *foo (&c) = 2;
  return c - 2;
}
