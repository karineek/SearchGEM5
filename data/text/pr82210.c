// Modification timestamp: 2023-08-14 15:57:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr82210.c
/* PR c/82210 */
/* { dg-require-effective-target alloca } */

void
foo (int size)
{
  int i;
  struct S {
    __attribute__((aligned (16))) struct T { short c; } a[size];
    int b[size];
  } s;

  for (i = 0; i < size; i++)
    s.a[i].c = 0x1234;
  for (i = 0; i < size; i++)
    s.b[i] = 0;
  for (i = 0; i < size; i++)
    if (s.a[i].c != 0x1234 || s.b[i] != 0)
      __builtin_abort ();
}

int
main ()
{
  foo (15);
  return 0;
}
