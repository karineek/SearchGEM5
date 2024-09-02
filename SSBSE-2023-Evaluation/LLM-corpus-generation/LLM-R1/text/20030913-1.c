// Modification timestamp: 2023-08-14 12:48:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030913-1.c
/* Assignments via pointers pointing to global variables were being killed
   by SSA-DCE.  Test contributed by Paul Brook <paul@nowt.org>  */

int glob;

void
fn2(int ** q)
{
  *q = &glob;
}

void test()
{
  int *p;

  fn2(&p);

  *p=42;
}

int main()
{
  test();
  if (glob != 42) abort();
  exit (0);
}
