// Modification timestamp: 2023-08-14 13:44:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960301-1.c
struct foo {
  unsigned : 12;
  unsigned field : 4;
} foo;
unsigned oldfoo;

int
bar (unsigned k)
{
  oldfoo = foo.field;
  foo.field = k;
  if (k)
    return 1;
  return 2;
}

main ()
{
  if (bar (1U) != 1)
    abort ();
  exit (0);
}
