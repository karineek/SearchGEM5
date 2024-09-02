// Modification timestamp: 2023-08-14 12:42:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030120-2.c
/* PR 8848 */

extern void abort ();

int foo(int status)
{
  int s = 0;
  if (status == 1) s=1;
  if (status == 3) s=3;
  if (status == 4) s=4;
  return s;
}

int main()
{
  if (foo (3) != 3)
    abort ();
  return 0;
}
