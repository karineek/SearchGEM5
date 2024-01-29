// Modification timestamp: 2023-08-14 14:12:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/call-trap-1.c
/* Undefined behavior from a call to a function cast to a different
   type does not appear until after the function designator and
   arguments have been evaluated.  PR 38483.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-require-effective-target untyped_assembly } */

extern void exit (int);
extern void abort (void);

int
foo (void)
{
  exit (0);
  return 0;
}

void
bar (void)
{
}

int
main (void)
{
  ((long (*)(int))bar) (foo ());
  abort ();
}
